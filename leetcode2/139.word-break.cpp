/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30204
 *
 * [139] 单词拆分
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
mt19937 rng(random_device{}());
int rnd(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}
long long MOD = 1e18 + rnd(0, 1e9), BASE = 233 + rnd(0, 1e3);

struct HashObj {
    vector<__int128_t> P, H;
    HashObj(auto& s) {
        int n = s.size();
        P.resize(n + 1);
        P[0] = 1; 
        for (int i = 1; i <= n; i++) P[i] = (P[i - 1] * BASE) % MOD;
        H.resize(n + 1);
        H[0] = 0;
        for (int i = 1; i <= n; i++) H[i] = (H[i - 1] * BASE + s[i - 1]) % MOD;
    }

    long long query(int l, int r) {
        if (l > r) return 0;
        return (H[r + 1] - H[l] * P[r - l + 1] % MOD + MOD) % MOD;
    }
};

class Solution {
public:
    bool wordBreak1(string s, vector<string>& wordDict) {
        HashObj hs(s);
        int n = wordDict.size();
        map<int, set<long long>> dic;
        //vector<long long> whs(n);
        for (int i = 0; i < wordDict.size(); i++) {
            HashObj wh(wordDict[i]);
            //whs[i] = wh.query(0, wordDict[i].size() - 1);
            dic[wordDict[i].size()].insert(wh.query(0, wordDict[i].size() - 1));
        }
        n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        // dp
        for (int i = 0; i < n; i++) {
            for (auto& [k, vec]: dic) {
                if (k > i + 1) {
                    break;
                }
                if (!dp[i - k + 1]) {
                    continue;
                }
                auto code = hs.query(i + 1 - k, i);
                if (vec.contains(code)) {
                    dp[i + 1] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }

    bool wordBreak2(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end()); 
        int max_len = ranges::max(wordDict, {}, &string::size).size();
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        // dp
        for (int i = 0; i < n; i++) {
            // 枚举长度
            for (int j = 1; j <= min(i + 1, max_len); j++) {
                if (dp[i - j + 1] and words.contains(s.substr(i - j + 1, j))) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end()); 
        int max_len = ranges::max(wordDict, {}, &string::size).size();
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        // dp
        for (int i = 0; i < n; i++) {
            // 枚举左端点
            for (int j = i; j >= max(0, i + 1 - max_len); j--) {
                // j - 1, [j, i]
                if (dp[j] and words.contains(s.substr(j, i - j + 1))) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */

