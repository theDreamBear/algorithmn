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
        去重麻烦, 有问题解法

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
        dfs(ans, temp, pos + 1, nums);
        for (int k = pos; k < nums.size(); ++k) {
            if (temp.empty() || temp.back() <= nums[k]) {
                temp.push_back(nums[k]);
                dfs(ans, temp, k + 1, nums);
                temp.pop_back();
            }
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
            if (visited.count(nums[k]) == 0 && (temp.empty() || temp.back() <= nums[k])) {
                visited.insert(nums[k]);
                temp.push_back(nums[k]);
                dfs_optimize(ans, temp, k + 1, nums);
                temp.pop_back();
            }
        }
    }


    vector<vector<int>> findSubsequences1(vector<int>& nums) {
        set<vector<int>> ans;
        dfs_optimize(ans, {}, 0, nums);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    /*
        bfs
        0个元素 -> 1 个元素 -> 2 个元素 一层层扩充
    */
    vector<vector<int>> findSubsequences(vector<int>& nums) {
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
                for (int pos = pr.first + 1; pos < nums.size(); ++ pos) {
                    if (added[nums[pos] + 100] == 0 && (pr.second.empty() || pr.second.back() <= nums[pos])) {
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

int main() {
    vector<int> nums = {4, 6, 7, 7};
    Solution{}.findSubsequences(nums);
}
