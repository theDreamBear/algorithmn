/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
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
class WordDictionary {
 public:
    struct Node {
        vector<Node*> children;
        int childNum;
        bool end;
        Node() : children(26), childNum(0),end(false) {}
    };
    Node* root;
    /** Initialize your data structure here. */
    WordDictionary() { root = new Node;}

    void addWord(string word) {
        Node* th = root;
        for (auto c : word) {
            if (!th->children[c - 'a']) {
                th->children[c - 'a'] = new Node;
                ++th->childNum;
            }
            th = th->children[c - 'a'];
        }
        th->end = true;
    }

    bool dfs(int pos, const string& word, Node* node) {
        // 终止条件
        if (pos == word.size()) {
            if (!node) {
                return false;
            }
            return node->end;
        }
        if (!node || 0 == node->childNum) {
            return false;
        }
        if (word[pos] != '.') {
            for (; pos < word.size() && word[pos] != '.'; ++pos) {
                if (!(node->children[word[pos] - 'a'])) {
                    return false;
                }
                node = node->children[word[pos] - 'a'];
            }
            return dfs(pos, word, node);
        }
        int num = node->childNum;
        for (int i = 0; i < 26 && num > 0; ++i) {
            if (node->children[i]) {
                --num;
                if (dfs(pos + 1, word, node->children[i])) {
                    return true;
                }
            }
        }
        return false;
    }

    bool search(string word) {
        return dfs(0, word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
