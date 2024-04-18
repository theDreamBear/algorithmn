/*
 * @lc app=leetcode.cn id=LCR 093 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 093] 最长的斐波那契子序列的长度
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
#include <tuple>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq_brute(vector<int>& arr) {
        int max_len = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int len = 2;
                int prepre = arr[i], pre = arr[j];
                long long next = prepre + pre;
                int k = j + 1;
                while (next < INT_MAX and k < arr.size()) {
                    while (k < arr.size() and arr[k] != next) {
                        k++;
                    }
                    if (k < arr.size()) {
                        prepre = pre;
                        pre = next;
                        next = prepre + pre;
                        ++len;
                        k++;
                    }
                }
                if (len > 2) {
                    max_len = max(max_len, len);
                }
            }
        }
        return max_len;
    }

    int lenLongestFibSubseq2(vector<int>& arr) {
        int max_len = 0;
        unordered_map<int, int> idx_mp;
        for (int i = 0; i < arr.size(); i++) {
            idx_mp[arr[i]] = i;
        }
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int j = 0; j < arr.size(); j++) {
            for (int i = j - 1; i > 0 and arr[j] < (arr[i] << 1); i--) {
                if (!idx_mp.count(arr[j] - arr[i])) {
                    continue;
                }
                int k = idx_mp[arr[j] - arr[i]];
                dp[i][j] = max(dp[k][i] + 1, 3);
                max_len = max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }

    int lenLongestFibSubse3(vector<int>& arr) {
        int max_len = 0;
        unordered_map<int, int> idx_mp;
        for (int i = 0; i < arr.size(); i++) {
            idx_mp[arr[i]] = i;
        }
        int n = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int len = 2;
                int prepre = arr[i], pre = arr[j];
                while (idx_mp.count(prepre + pre)) {
                    int next = prepre + pre;
                    prepre = pre;
                    pre = next;
                    len++;
                }
                if (len > 2) {
                    max_len = max(max_len, len);
                }

            }
        }
        return max_len;
    }

    // 前向dp
    int lenLongestFibSubseq(vector<int>& arr) {
        int max_len = 0;
        unordered_map<int, int> idx_mp;
        for (int i = 0; i < arr.size(); i++) {
            idx_mp[arr[i]] = i;
        }
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (!idx_mp.count(arr[i] + arr[j])) {
                    continue;
                }
                int k = idx_mp[arr[i] + arr[j]];
                if (dp[i][j] == 0) {
                    dp[j][k] = 3;
                } else {
                    dp[j][k] = dp[i][j] + 1;
                }
                max_len = max(max_len, dp[j][k]);
            }
        }
        return max_len;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,7,11,12,14,18]\n
// @lcpr case=end

 */

