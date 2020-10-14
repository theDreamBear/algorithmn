/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <string>
using namespace std;

// @lc code=start
class Trie {
 public:
    constexpr static int TOTAL = 27;
    struct trieNode {
        trieNode** children;

        bool terminal() { return NULL != children[TOTAL - 1]; }

        int getIndex(char c) {
            if (c == '\n') {
                return TOTAL - 1;
            }
            return c - 'a';
        }

        bool contain(char c) { return NULL != children[getIndex(c)]; }

        trieNode* addChild(char c) { 
            if (NULL == children[getIndex(c)]) {
                children[getIndex(c)] = new trieNode;
            }
            return children[getIndex(c)];
        }
        
        trieNode* getChild(char c) {
            return children[getIndex(c)];
        }

        void addTerminal() { 
            children[TOTAL - 1] = new trieNode(true);
        }

        trieNode(bool dummy = false) {
            if (!dummy) {
                children = new trieNode*[TOTAL];
                for (int i = 0; i < TOTAL; ++i) {
                    children[i] = NULL;
                }
            }
        }
    };
    trieNode* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new trieNode;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            cur = cur->addChild(word[i]);
        }
        cur->addTerminal();
    }

    /** Returns if the word is in the trie. */
    trieNode* _startWith(string prefix) {
        trieNode* cur = root;
        for (int i = 0; i < prefix.size(); ++i) {
            cur = cur->getChild(prefix[i]);
            if (NULL == cur) {
                return NULL;
            }
        }
        return cur;
    }

    bool search(string word) {
        trieNode* cur = _startWith(word);
        if (NULL == cur) {
            return false;
        }
        return cur->terminal();
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        if (_startWith(prefix)) {
            return true;
        }
        return false;
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
