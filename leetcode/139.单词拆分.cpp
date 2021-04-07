/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
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
    struct Node {
        vector<Node*> children;
        int children_num;
        bool end;

        Node() : children(26), end(false) {}
    };

    struct Tries {
        Node* root;

        void add(const string& s) {
            Node* th = root;
            for (auto c : s) {
                if (th->children[c - 'a'] == nullptr) {
                    ++th->children_num;
                    th->children[c - 'a'] = new Node();
                }
                th = th->children[c - 'a'];
            }
            th->end = true;
        }

        Tries(){
            root = new Node;
        }
    };

    Tries tree;

    Node* search(const string& s, int& index, Node* node) {
        Node* th = node;
        for (; index < s.size(); ++index) {
            if (th->children_num == 0 ||
                th->children[s[index] - 'a'] == nullptr) {
                return nullptr;
            }
            th = th->children[s[index] - 'a'];
            if (th->end) {
                ++index;
                return th;
            }
        }
        return nullptr;
    }

    struct pair_hash {
        inline size_t operator()(const pair<int, Node*> & p) const {
            if (p.second) {
                return size_t(p.second) + p.first;
            }
            return p.first;
        }
    };

    unordered_set<pair<int, Node*>, pair_hash> hash;

    bool wordBreakHelper(const string& s, int pos, Node* node) {
        if (node == nullptr) {
            return false;
        }
        if (pos > s.size()) {
            return false;
        }
        if (pos == s.size()) {
            return true;
        }
        if (hash.count({pos, node}) > 0) {
            return false;
        }
        int p = pos;
        Node* newNode = search(s, pos, node);
        if (!newNode) {
            hash.insert({pos, node});
            return false;
        }
        // 从新节点继续 // 或者从头开始
        if (wordBreakHelper(s, pos, newNode) || wordBreakHelper(s, pos, tree.root)) {
            return true;
        }
        hash.insert({p, node});
        return false;
    }

    /*
        字典树, 不记录超时
        1. 若s, 存在字典不存在字符, 则直接返回 false

        记录状态, pos + node 完美通过
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<char> exist(26);
        for (auto& str : wordDict) {
            tree.add(str);
            for (auto c : str) {
                ++exist[c - 'a'];
            }
        }
        for (auto c : s) {
            if (!exist[c - 'a']) {
                return false;
            }
        }
        return wordBreakHelper(s, 0, tree.root);
    }
};
// @lc code=end
