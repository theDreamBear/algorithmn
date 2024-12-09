

/*
 * @lc app=leetcode.cn id=2976 lang=cpp
 * @lcpr version=30204
 *
 * [2976] 转换字符串的最小成本 I
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
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // 
        int dp[26][26];
        for (int i = 0; i < 26; i++) {
            dp[i][i] = 0;
            for (int j = 0; j < 26; j++) {
                dp[i][j] = INT_MAX / 2;
            }
        }
        int n = original.size();
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a', v = changed[i] - 'a', w = cost[i];
            dp[u][v] = min(dp[u][v], w);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) continue;
            int u = source[i] - 'a', v = target[i] - 'a';
            if (dp[u][v] == INT_MAX / 2) {
                return -1;
            }
            ans += dp[u][v];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcd"\n"acbe"\n["a","b","c","c","e","d"]\n["b","c","b","e","b","e"]\n[2,5,5,1,2,20]\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n"bbbb"\n["a","c"]\n["c","b"]\n[1,2]\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"abce"\n["a"]\n["e"]\n[10000]\n
// @lcpr case=end

 */

