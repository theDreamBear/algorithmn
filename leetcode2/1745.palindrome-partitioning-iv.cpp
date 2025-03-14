/*
 * @lc app=leetcode.cn id=1745 lang=cpp
 * @lcpr version=30204
 *
 * [1745] 分割回文串 IV
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
    // 1278. 分割回文串 III
    int palindromePartition(string& s, int k) {
        int n = s.size();
        vector min_change(n, vector<int>(n));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                min_change[i][j] = min_change[i + 1][j - 1] + (s[i] != s[j] ? 1 : 0);
            }
        }

        auto f = move(min_change[0]);
        for (int i = 1; i < k; i++) {
            for (int r = n - k + i; r >= i; r--) {
                f[r] = INT_MAX;
                for (int l = i; l <= r; l++) {
                    f[r] = min(f[r], f[l - 1] + min_change[l][r]);
                }
            }
        }
        return f[n - 1];
    }
    
public:
    bool checkPartitioning(string s) {
        return palindromePartition(s, 3) == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcbdd"\n
// @lcpr case=end

// @lcpr case=start
// "bcbddxy"\n
// @lcpr case=end

 */

