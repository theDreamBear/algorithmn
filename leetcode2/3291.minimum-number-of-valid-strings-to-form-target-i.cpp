/*
 * @lc app=leetcode.cn id=3291 lang=cpp
 * @lcpr version=30204
 *
 * [3291] 形成目标字符串需要的最少字符串数 I
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int     rnd(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

long long MOD = 1e18+ rnd(0, 1e9), BASE = 233 + rnd(0, 1e3);

struct HashObj {
    vector<__int128> P, H;

    template<typename T>
    HashObj(T& s) {
        int n = s.size();
        P.resize(n + 1);
        H.resize(n +1);
        P[0] = 1;
        for (int i = 1; i <= n; i++) {
            P[i] = P[i - 1] * BASE % MOD;
        }
        H[0] = 0;
        for (int i = 1; i <= n; i++) {
            H[i] = (H[i - 1] * BASE + s[i - 1]) % MOD;
        }
    }
    
    long long query(int l, int r) {
        if (l > r) {
            return 0;
        }
        return (MOD + H[r + 1] - H[l] * P[r - l + 1] % MOD) % MOD;
    }
};
class Solution {
  public:
    struct AcNode {
        vector<AcNode*> child;
        AcNode*         fail;
        int             depth = 0;
        AcNode() : child(26), fail(nullptr) {}
    };

    AcNode* root = new AcNode;

    void insert(string& word) {
        AcNode* node = root;
        int     d    = 0;
        for (auto ch : word) {
            if (!node->child[ch - 'a']) {
                node->child[ch - 'a'] = new AcNode;
            }
            node        = node->child[ch - 'a'];
            node->depth = ++d;
        }
    }

    void insert(vector<string>& words) {
        for (auto& s : words) {
            insert(s);
        }
    }

    void build_fail() {
        queue<AcNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (int i = 0; i < node->child.size(); i++) {
                if (node->child[i]) {
                    AcNode *fafail = node->fail, *y = node->child[i];
                    while (fafail and !fafail->child[i]) {
                        fafail = fafail->fail;
                    }
                    if (!fafail) {
                        y->fail = root;
                    } else {
                        y->fail = fafail->child[i];
                    }
                    q.push(y);
                }
            }
        }
    }

    int run(vector<string>& words, string& target) {
        insert(words);
        build_fail();
        AcNode*     node = root;
        int         n    = target.size();
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 1; i <= target.size(); i++) {
            char ch = target[i - 1];
            while (!node->child[ch - 'a'] and node->fail) {
                node = node->fail;
            }
            if (!node) {
                return -1;
            }
            node = node->child[ch - 'a'];
            if (!node) {
                return -1;
            }
            dp[i] = min(dp[i], dp[i - node->depth] + 1);
        }
        return dp[n] >= INT_MAX / 2 ? -1 : dp[n];
    }

    int minValidStrings1(vector<string>& words, string target) {
        return run(words, target);
    }

    // 超时, 查后缀没有单调性
    int minValidStrings_ttl(vector<string>& words, string target) {
        int n = target.size();
        // 枚举长度
        unordered_map<int, unordered_set<long long>> hs;
        for (auto& word: words) {
            HashObj obj(word);
            for (int i = 1; i <= word.size(); i++) {
                hs[i].insert(obj.query(0, i - 1));
            }
        }
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        int m = hs.size();
        HashObj obj(target);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                auto code = obj.query(i - j, i - 1);
                if (hs[j].contains(code)) {
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        }
        return dp[n] >= INT_MAX / 2 ? -1 : dp[n];
    }
    
    // 前往后有单调性
    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        // 枚举长度
        unordered_map<int, unordered_set<long long>> hs;
        for (auto& word: words) {
            HashObj obj(word);
            for (int i = 1; i <= word.size(); i++) {
                hs[i].insert(obj.query(0, i - 1));
            }
        }
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        int m = hs.size();
        HashObj obj(target);
        for (int i = 0; i < n; i++) {
            int low = 1, high = min(n - i, m);
            while (low + 1 < high) {
                int mid = (low + high) >> 1;
                auto code = obj.query(i, i - 1 + mid);
                if (hs[mid].contains(code)) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            auto code = obj.query(i, i - 1 + high);
            if (hs[high].contains(code)) {
                low = high;
            } else {
                code = obj.query(i, i - 1 + low);
                if (!hs[low].contains(code)) {
                    continue;
                }
            }
            for (int j = 1; j <= low; j++) {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[n] >= INT_MAX / 2 ? -1 : dp[n];
    }

    vector<int> calz(const string& s) {
        int n = s.size();
        vector<int> z(n);
        z[0] = n;
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (z[i] + i < n and s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    // z函数
    int minValidStrings3(vector<string>& words, string target) {
        int n = target.size();
        // 枚举长度
        // zz
        vector<int> max_jump(n);
        for (auto& word: words) {
            auto z = calz(word + "#" + target);
            for (int i = 0; i < n; i++) {
                max_jump[i] = max(max_jump[i], z[i + word.size() + 1]);
            }
        }
        auto jump = [&]() {
            int ans = 0;
            int cur_r = 0, next_r = 0;
            for (int i = 0; i < max_jump.size(); i++) {
                next_r = max(next_r, i + max_jump[i]);
                if (i == cur_r) {
                    if (i == next_r) return -1;
                    // 新的桥
                    cur_r = next_r;
                    ans++;
                }
            }
            return ans;
        };
        return jump();
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["abc","aaaaa","bcdef"]\n"aabcdabc"\n
// @lcpr case=end

// @lcpr case=start
// ["abababab","ab"]\n"ababaababa"\n
// @lcpr case=end

// @lcpr case=start
// ["abcdef"]\n"xyz"\n
// @lcpr case=end

 */
