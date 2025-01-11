/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 * @lcpr version=30204
 *
 * [1122] 数组的相对排序
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        map<int, int> freq;
        for (auto v: arr1) freq[v]++;
        vector<int> ans;
        vector<int> add;
        for (auto v: arr2) {
            if (freq.contains(v)) {
                for (int x = 0; x < freq[v]; x++) {
                    ans.push_back(v);
                }
                freq.erase(v);
            }
        }
        for (auto& [k, t]: freq) {
            for (int x = 0; x < t; x++) {
                ans.push_back(k);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]\n
// @lcpr case=end

// @lcpr case=start
// [28,6,22,8,44,17]\n[22,28,8,6]\n
// @lcpr case=end

 */

