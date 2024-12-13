// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2615 lang=cpp
 * @lcpr version=30204
 *
 * [2615] 等值距离和
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<pair<long long, long long>>> hs;
        int n = nums.size();
        vector<long long> ans(n);
        for (int i = 0; i < n; i++) {
            if (!hs.count(nums[i])) {
                hs[nums[i]].push_back({0, i});
            }
            hs[nums[i]].push_back({i + hs[nums[i]].back().first, i});
        }
        for (auto& [k, vec]: hs) {
            if (vec.size() == 2) {
                ans[vec[1].second] = 0;
                continue;
            }
            for (int i = 1; i < vec.size(); i++) {
                long long left = vec[i].second * i - vec[i].first;
                long long right = i + 1 == vec.size() ? 0: vec.back().first - vec[i - 1].first - vec[i].second * (vec.size() - i);
                ans[vec[i].second] = left + right;
            }
        }
        return ans;
    }

    // 考虑增量
    // s+(2−n)⋅(a[1]−a[0])
    vector<long long> distance(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i)
            groups[nums[i]].push_back(i); // 相同元素分到同一组，记录下标

        vector<long long> ans(n);
        for (auto &[_, a]: groups) {
            int m = a.size();
            long long s = 0;
            for (int x: a)
                s += x - a[0]; // a[0] 到其它下标的距离之和
            ans[a[0]] = s;
            for (int i = 1; i < m; ++i)
                // 从计算 a[i-1] 到计算 a[i]，考虑 s 增加了多少
                ans[a[i]] = s += (long long) (i * 2 - m) * (a[i] - a[i - 1]);
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=distance
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,3,1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,5,3]\n
// @lcpr case=end

 */

