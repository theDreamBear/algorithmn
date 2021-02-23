/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    /*
     */
    void dfs(set<vector<int>>& ans, vector<int> temp, int pos,
             const vector<int>& nums) {
        // 边界
        if (pos >= nums.size()) {
            if (temp.size() > 1) {
                ans.insert(temp);
            }
            return;
        }
        // 不取 pos
        dfs(ans, temp, pos + 1, nums);

        // 取 pos
        if (temp.empty() || temp.back() <= nums[pos]) {
            temp.push_back(nums[pos]);
            dfs(ans, temp, pos + 1, nums);
        }
    }

    /*

    */
    void dfs_optimize(set<vector<int>>& ans, vector<int> temp, int pos,
                      const vector<int>& nums) {
        // 提前剪枝
        // if (pos >= nums.size()) {
        if (temp.size() > 1) {
            ans.insert(temp);
        }
        //     return;
        //}
        // dfs(ans, temp, pos + 1, nums);
        unordered_set<int> visited;
        for (int k = pos; k < nums.size(); ++k) {
            if (visited.count(nums[k]) == 0 &&
                (temp.empty() || temp.back() <= nums[k])) {
                visited.insert(nums[k]);
                temp.push_back(nums[k]);
                dfs_optimize(ans, temp, k + 1, nums);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        dfs(ans, {}, 0, nums);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    /*
        bfs
        0个元素 -> 1 个元素 -> 2 个元素 一层层扩充, 一层层保证最终序列只有一个
    */
    vector<vector<int>> findSubsequences_bfs(vector<int>& nums) {
        vector<vector<int>> ans;
        queue<pair<int, vector<int>>> q;
        q.push({-1, {}});
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto pr = q.front();
                q.pop();
                if (pr.second.size() > 1) {
                    ans.emplace_back(pr.second);
                }
                bitset<300> added;
                for (int pos = pr.first + 1; pos < nums.size(); ++pos) {
                    if (added[nums[pos] + 100] == 0 &&
                        (pr.second.empty() || pr.second.back() <= nums[pos])) {
                        added[nums[pos] + 100] = 1;
                        vector<int> temp = pr.second;
                        temp.emplace_back(nums[pos]);
                        q.push({pos, temp});
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end


/*
 官方的 hash 算法
*/
class Solution1 {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    unordered_set<int> s;
    int n;

    void findSubsequences(int mask, vector<int>& nums) {
        temp.clear();
        for (int i = 0; i < n; ++i) {
            if (mask & 1) {
                temp.push_back(nums[i]);
            }
            mask >>= 1;
        }
    }

    bool check() {
        for (int i = 1; i < temp.size(); ++i) {
            if (temp[i] < temp[i - 1]) {
                return false;
            }
        }
        return temp.size() >= 2;
    }

    int getHash(int base, int mod) {
        int hashValue = 0;
        for (const auto &x: temp) {
            hashValue = 1LL * hashValue * base % mod + (x + 101);
            hashValue %= mod;
        }
        return hashValue;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < (1 << n); ++i) {
            findSubsequences(i, nums);
            int hashValue = getHash(263, int(1E9) + 7);
            if (check() && s.find(hashValue) == s.end()) {
                ans.push_back(temp);
                s.insert(hashValue);
            }
        }
        return ans;
    }
};

/*
    方法 3 可以多研究研究
*/
class Solution3 {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int last, vector<int>& nums) {
        if (cur == nums.size()) {
            if (temp.size() >= 2) {
                ans.push_back(temp);
            }
            return;
        }
        if (nums[cur] >= last) {
            temp.push_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            temp.pop_back();
        }
        if (nums[cur] != last) {
            dfs(cur + 1, last, nums);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, INT_MIN, nums);
        return ans;
    }
};


class Solution4 {
public:
   // 判重代码；
    bool is_first(const vector<int> &num, int last, int pos) {
        for(int i = last+1; i < pos; i++) {
            if(num[i] == num[pos]) {
                return false;
            }
        }
        return true;
    }
    void dfs(const vector<int> &nums, int last, int pos, vector<int> &stack, vector<vector<int>> &anw) {
        if(nums.size() == pos) { return; } //到达末尾，直接返回吧
        // 检查 nums[pos] 是否符合要求
        if((stack.empty() || nums[pos] >= stack.back()) && is_first(nums, last, pos)) {
            stack.push_back(nums[pos]);
            if(stack.size() >= 2) { //大于 2 了，那就放进去吧
                anw.push_back(stack);
            }
            dfs(nums, pos, pos+1, stack, anw); // 继续处理下一个。
            stack.pop_back(); // 将当前放入这个吐出来。
        }
        dfs(nums, last, pos+1, stack, anw);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> anw;
        vector<int> stack;
        dfs(nums, -1, 0, stack, anw);
        return anw;
    }
};


class Solution5 {
public:
    int pre[15];
    // 判重代码；
    bool is_first(const vector<int> &num, int last, int pos) {
        return !(last < pre[pos] && pre[pos] < pos);
    }
    void dfs(const vector<int> &nums, int last, int pos, vector<int> &stack, vector<vector<int>> &anw) {
        if(nums.size() == pos) { return; } //到达末尾，直接范围吧
        // 检查 nums[pos] 是否符合要求
        if((stack.empty() || nums[pos] >= stack.back()) && is_first(nums, last, pos)) {
            stack.push_back(nums[pos]);
            if(stack.size() >= 2) { //大于 2 了，那就放进去吧
                anw.push_back(stack);
            }
            dfs(nums, pos, pos+1, stack, anw); // 继续处理下一个。
            stack.pop_back(); // 将当前放入这个吐出来。
        }
        dfs(nums, last, pos+1, stack, anw);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            pre[i] = -1;
            for(int j = i-1; j >= 0; j--) {
                if(nums[j] == nums[i]) { pre[i] = j; break; }
            }
        }
        vector<vector<int>> anw;
        vector<int> stack;
        dfs(nums, -1, 0, stack, anw);
        return anw;
    }
};


int main() {
    vector<int> nums = {4, 6, 7, 7};
    Solution{}.findSubsequences(nums);
}
