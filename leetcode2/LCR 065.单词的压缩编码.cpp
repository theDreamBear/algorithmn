/*
 * @lc app=leetcode.cn id=LCR 065 lang=cpp
 * @lcpr version=30120
 *
 * [LCR 065] 单词的压缩编码
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
    int minimumLengthEncoding1(vector<string>& words) {
        vector<string> tmp = words;
        sort(tmp.begin(), tmp.end(), [](const string& lhs, const string& rhs) {
            return lhs.size() > rhs.size();
        });
        std::string now;
        unordered_map<string, int> ct;
        for (auto& str: tmp) {
            auto x = str + "#";
            if (now.find(x) == string::npos) {
                now += x;
            }
            ct[x] = now.find(x);
        }
        return now.size();
    }

    static bool check(const string& lhs, const string& rhs) {
        return strcmp(lhs.c_str() + (lhs.size() - rhs.size()), rhs.c_str()) == 0;
    }

    class UF {
     public:
        const vector<string>& words;
        vector<int> parent;

        UF(const vector<string>& words): words(words), parent(words.size()) {
            for (int i = 0; i < words.size(); i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        void merge(int i, int j) {
            int pi = find(i);
            int pj = find(j);
            if (words[pi].size() >= words[pj].size()) {
                if (check(words[pi], words[pj])) {
                    parent[pj] = pi;
                }
                return;
            } else {
                if (check(words[pj], words[pi])) {
                    parent[pi] = pj;
                }
                return;
            }
        }

        int findp(int i) {
            return parent[i];
        }
    };
    int minimumLengthEncoding_UF(vector<string>& words) {
        UF uf(words);
        // 这个地方的复杂度高了
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                uf.merge(i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            if (uf.findp(i) == i) {
                ans += words[i].size() + 1;
            }
        }
        return ans;
    }

    struct TrieNode {
        int sz;
        vector<TrieNode*> children;

        TrieNode(): sz(0), children(26) {}
    };

    class Trie {
     public:
        TrieNode root;
        int ans = 0;

        void add(const string& str) {
            TrieNode* node = &root;
            for (int i = str.size() - 1; i >= 0; i--) {
                bool flag = false;
                int idx = str[i] - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode;
                    flag = true;
                }
                node = node->children[idx];
                // 遇到非叶节点
                if (i != 0 and node->sz > 0) {
                    ans -= node->sz;
                    // 非叶节点sz为0
                    node->sz = 0;
                }
                // 叶节点
                if (i == 0 && flag) {
                    node->sz = str.size() + 1;
                    ans += node->sz;
                }
            }
        }
    };

    int minimumLengthEncoding(vector<string>& words) {
        Trie tree;
        for (auto& word : words) {
            tree.add(word);
        }
        return tree.ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["time", "me", "bell"]\n
// @lcpr case=end

// @lcpr case=start
// ["t"]\n
// @lcpr case=end

 */

