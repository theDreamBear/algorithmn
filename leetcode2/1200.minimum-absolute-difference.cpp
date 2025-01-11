/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 * @lcpr version=30204
 *
 * [1200] 最小绝对差
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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        ranges::sort(arr);
        vector<vector<int>> ans;
        int mm = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            mm = min(mm, arr[i] - arr[i - 1]);
        } 
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == mm) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        } 
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,6,10,15]\n
// @lcpr case=end

// @lcpr case=start
// [3,8,-10,23,19,-4,-14,27]\n
// @lcpr case=end

 */

