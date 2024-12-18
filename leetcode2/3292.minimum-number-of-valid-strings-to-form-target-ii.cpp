/*
 * @lc app=leetcode.cn id=3292 lang=cpp
 * @lcpr version=30204
 *
 * [3292] 形成目标字符串需要的最少字符串数 II
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
class Ac {
public:
    struct Node {
        vector<Node*> child;
        Node* fail = nullptr;
        int depth = 0;
        Node():child(26){}
    };
    Node* root = new Node;

    #define idx (ch - 'a')
    void insert(string& word) {
        Node* node = root;
        int d = 0;
        for (auto ch: word) {
            if (!node->child[idx]) {
                node->child[idx] = new Node;
            }
            node = node->child[idx];
            node->depth = ++d;
        }
    }

    void insert(vector<string>& words) {
        for (auto& word: words) {
            insert(word);
        }
    }

    void build_fail() {
        root->fail = root;
        queue<Node*> q;
        for (int i = 0; i < 26; i++) {
            if (!root->child[i]) {
                // 虚拟节点
                root->child[i] = root;
            } else {
                root->child[i]->fail = root;
                q.push(root->child[i]);
            }
        }
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            for (int i = 0; i < 26; i++) {
                auto& son = node->child[i];
                if (!son) {
                    // 一步到位
                    son = node->fail->child[i];
                    continue;
                }
                son->fail = node->fail->child[i];
                q.push(son);
            }
        }
    }

    Ac(vector<string>& words) {
        insert(words);
        build_fail();
    }
};

class Solution {
public:
    int minValidStrings_ac(vector<string>& words, string target) {
        Ac ac(words);
        int n = target.size();
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        auto node = ac.root;
        for (int i = 1; i <= n; i++) {
            char ch = target[i - 1];
            node = node->child[idx];
            if (node == ac.root) {
                return -1;
            }
            dp[i] = min(dp[i], dp[i - node->depth] + 1);
        }        
        return dp[n] == INT_MAX / 2 ? -1 : dp[n];
    }

    int minValidStrings(vector<string>& words, string target) {
        // kmp
        int n = target.size();
        vector<int> back(n);
        auto back_fun = [&](const string& s) {
            int n = s.size();
            vector<int> next(n);
            int k = 0;
            for (int i = 1; i < n; i++) {
                while (k and s[k] != s[i]) {
                    k = next[k - 1];
                }
                if (s[k] == s[i]) k++;
                next[i] = k;
            }
            return next;
        };
        for (auto& word: words) {
            auto dp = back_fun(word + "#" + target);
            int m = word.size() + 1;
            for (int i = 0; i < n; i++) {
                back[i] = max(back[i], dp[i + m]);
            }
        }
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = min(dp[i], dp[i - back[i - 1]] + 1);
            if (dp[i] > n) {
                return -1;
            }
        }
        return dp[n];
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

