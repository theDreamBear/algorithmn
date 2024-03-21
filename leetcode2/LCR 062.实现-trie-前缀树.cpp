/*
 * @lc app=leetcode.cn id=LCR 062 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 062] 实现 Trie (前缀树)
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
class Trie {
public:
    struct TrieNode {
        bool end = false;
        vector<TrieNode*> children;

        TrieNode(bool end = false):end(end), children(26){}
    };

    TrieNode root;

    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = &root;
        for (auto ch : word) {
            if (!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new TrieNode;
            }
            node = node->children[ch - 'a'];
        }
        node->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = &root;
        for (auto ch : word) {
            if (!node->children[ch - 'a']) {
                return false;
            }
            node = node->children[ch - 'a'];
        }
        return node->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = &root;
        for (auto ch : prefix) {
            if (!node->children[ch - 'a']) {
                return false;
            }
            node = node->children[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end



