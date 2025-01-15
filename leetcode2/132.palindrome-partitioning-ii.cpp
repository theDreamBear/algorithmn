/*
 * @lc app=leetcode.cn id=132 lang=cpp
 * @lcpr version=30204
 *
 * [132] 分割回文串 II
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
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> isP(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int left = i, right = i;
            while (left >= 0 and right < n and s[left] == s[right]) {
                isP[left][right] = 1;
                left--, right++;
            } 
            left = i, right = i + 1;
            while (left >= 0 and right < n and s[left] == s[right]) {
                isP[left][right] = 1;
                left--, right++;
            }
        }
        vector<int> memo(n, INT_MAX / 2);
        for (int i = 0; i < n; i++) {
            if (isP[0][i]) memo[i] = 0;
            else {
                for (int j = 1; j <= i; j++) {
                    if (isP[j][i]) {
                        memo[i] = min(memo[i], memo[j - 1] + 1);
                    }
                }   
            }
        }
        return memo[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n
// @lcpr case=end

 */

