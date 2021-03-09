/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference1(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                ans.clear();
                ans.push_back({arr[i - 1], arr[i]});
            } else if (diff == minDiff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }

    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> diff_vec(arr.size());
        adjacent_difference(arr.begin(), arr.end(), diff_vec.begin());
        // 注意diff_vec第一个值无效
        int minDiff = *min_element(diff_vec.begin() + 1, diff_vec.end());
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff == minDiff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};
// @lc code=end

