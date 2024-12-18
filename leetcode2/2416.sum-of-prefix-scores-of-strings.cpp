/*
 * @lc app=leetcode.cn id=2416 lang=cpp
 * @lcpr version=30204
 *
 * [2416] 字符串的前缀分数和
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
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int     rnd(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

long long MOD = 1e18 + rnd(0, 1e9), BASE = 233 + rnd(0, 1e3);

struct HashObj {
    vector<__int128> P, H;

    template <typename Container> HashObj(Container& s) {
        int n = s.size();
        P.resize(n + 1);
        P[0] = 1;
        for (int i = 1; i <= n; i++)
            P[i] = P[i - 1] * BASE % MOD;
        H.resize(n + 1);
        H[0] = 0;
        for (int i = 1; i <= n; i++)
            H[i] = (H[i - 1] * BASE + s[i - 1]) % MOD;
    }
    // [l, r]
    long long query(int l, int r) {
        if (l > r)
            return 0;
        return (H[r + 1] - H[l] * P[r - l + 1] % MOD + MOD) % MOD;
    }
};

class Solution {
  public:
    // mle
    vector<int> sumPrefixScores_mle(vector<string>& words) {
        unordered_map<string, int>         cnt;
        unordered_map<string, set<string>> sub;
        for (auto& word : words) {
            string str;
            for (int i = 0; i < word.size(); i++) {
                str += word[i];
                cnt[str]++;
                sub[word].insert(str);
            }
        }
        vector<int> ans(words.size());
        for (int i = 0; i < words.size(); i++) {
            auto vec = sub[words[i]];
            for (auto& str : vec) {
                ans[i] += cnt[str];
            }
        }
        return ans;
    }

    // tle
    vector<int> sumPrefixScores_tle(vector<string>& words) {
        unordered_map<long long, int>            cnt;
        unordered_map<long long, set<long long>> sub;
        for (auto& word : words) {
            string  str;
            HashObj obj(word);
            auto    hsc = obj.query(0, word.size() - 1);
            for (int i = 0; i < word.size(); i++) {
                auto code = obj.query(0, i);
                cnt[code]++;
                sub[hsc].insert(code);
            }
        }
        vector<int> ans(words.size());
        for (int i = 0; i < words.size(); i++) {
            HashObj obj(words[i]);
            auto    hsc = obj.query(0, words[i].size() - 1);
            auto    vec = sub[hsc];
            for (auto& str : vec) {
                ans[i] += cnt[str];
            }
        }
        return ans;
    }

    struct Node {
        Node* child[26]{};
        int cnt = 0;

        Node() {}
    };

    Node root;

    void insert(string& s) {
        Node* node = &root;
        for (auto ch: s) {
            if (node->child[ch - 'a'] == nullptr) {
                node->child[ch - 'a'] = new Node;
            }
            node = node->child[ch - 'a'];
            ++node->cnt;
        } 
    }

    void insert(vector<string>& words) {
        for (auto& s: words) {
            insert(s);
        }
    }

    int search(string& s) {
        Node* node = &root;
        int ans = 0;
        for (auto ch: s) {
            node = node->child[ch - 'a'];
            ans += node->cnt;
        }
        return ans;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        insert(words);
        int n = words.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = search(words[i]);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["abc","ab","bc","b"]\n
// @lcpr case=end

// @lcpr case=start
// ["abcd"]\n
// @lcpr case=end

 */
