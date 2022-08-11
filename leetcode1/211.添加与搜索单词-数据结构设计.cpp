/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool end{};
        
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode root;
    
    WordDictionary() {}
    void addWord(string word) {
        TrieNode* th = &root;
        for (auto ch : word) {
            if (!th->children[ch - 'a']) {
                th->children[ch - 'a'] = new TrieNode;
            }
            th = th->children[ch - 'a'];
        }
        th->end = true;
    }

    bool search(string word) {
        function<bool(int, TrieNode*)> backtrack = [&](int pos, TrieNode* th) {
            if (pos == word.size()) {
                return th->end;
            }
            char ch = word[pos];
            if (ch != '.') {
                if (th->children[ch - 'a']) {
                    return backtrack(pos + 1, th->children[ch - 'a']);
                }
                return false;
            }
            for (int i = 0; i < 26; i++) {
                if (th->children[i] && backtrack(pos + 1, th->children[i])) {
                    return true;
                }
            }
            return false;
        };
        return backtrack(0, &root);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

