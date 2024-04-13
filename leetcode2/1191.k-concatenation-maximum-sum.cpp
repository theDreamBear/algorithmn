/*
 * @lc app=leetcode.cn id=1191 lang=cpp
 * @lcpr version=30122
 *
 * [1191] K 次串联后最大子数组之和
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
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int mid_sum = 0, mid = 0;
        for (auto v : arr) {
            if (mid_sum <= 0) {
                mid_sum = v;
            } else {
                mid_sum += v;
            }
            mid = max(mid, mid_sum);
        }
        if (k == 1) {
            return mid;
        }
        int left_sum = 0, left = 0;
        for (int i = 0; i < arr.size(); i++) {
            left_sum += arr[i];
            left = max(left, left_sum);
        }
        int right_sum = 0, right = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            right_sum += arr[i];
            right = max(right, right_sum);
        }

        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum > 0) {
            return (((long long)(k - 2) * sum)%(int)(1e9 + 7) + right + left)%(int)(1e9 + 7);
        } else {
            return max(mid, left + right);
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,-2,1]\n5\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2]\n7\n
// @lcpr case=end

 */

