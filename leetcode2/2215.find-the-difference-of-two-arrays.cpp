/*
 * @lc app=leetcode.cn id=2215 lang=cpp
 * @lcpr version=30204
 *
 * [2215] 找出两数组的不同
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
    vector<vector<int>> findDifference1(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> s1, s2;
        for (auto v: nums1) s1.insert(v);
        for (auto v: nums2) s2.insert(v);
        for (auto v: nums1) {
            if (!s2.contains(v)) ans[0].push_back(v);
        }
        for (auto v: nums2) {
            if (!s1.contains(v)) ans[1].push_back(v);
        }
        ranges::sort(ans[0]);
        ranges::sort(ans[1]);
        ans[0].erase(unique(ans[0].begin(), ans[0].end()), ans[0].end());
        ans[1].erase(unique(ans[1].begin(), ans[1].end()), ans[1].end());
        return ans;
    }

    vector<vector<int>> findDifference2(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a1, a2;
        unordered_set<int> s1, s2;
        for (auto v: nums1) s1.insert(v);
        for (auto v: nums2) s2.insert(v);
        for (auto v: nums1) {
            if (!s2.contains(v)) a1.insert(v);
        }
        for (auto v: nums2) {
            if (!s1.contains(v)) a2.insert(v);
        }
        return {{a1.begin(), a1.end()}, {a2.begin(), a2.end()}};
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> s1, s2;
        for (auto v: nums1) s1.insert(v);
        for (auto v: nums2) s2.insert(v);
        for (auto v: s1) {
            if (!s2.contains(v)) ans[0].push_back(v);
        }
        for (auto v: s2) {
            if (!s1.contains(v)) ans[1].push_back(v);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[2,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,3]\n[1,1,2,2]\n
// @lcpr case=end

 */

