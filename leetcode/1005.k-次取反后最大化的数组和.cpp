/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include <ranges.h>
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
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int zero_ct = 0;
        int absmin = 100;
        int pre_sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (abs(A[i]) < absmin) {
                absmin = abs(A[i]);
            }
            if (A[i] < 0) {
                ++zero_ct;
            }
            pre_sum += A[i];
        }
        int m = min(K, zero_ct);
        for (int i = 0; i < m; ++i) {
            pre_sum += 2 * abs(A[i]);
            --K;
            --zero_ct;
        }
        if (K <= zero_ct || absmin == 0 || K % 2 == 0) {
            return pre_sum;
        } else {
            return pre_sum - 2 * absmin;
        }
    }
};
// @lc code=end
