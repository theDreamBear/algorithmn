/*
 * @lc app=leetcode.cn id=LCR 063 lang=cpp
 * @lcpr version=30121
 *
 * [LCR 063] 单词替换
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
#include <sstream>
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
    struct TrieNode {
        string word;
        TrieNode* children[26];

        TrieNode() {
            bzero(children, sizeof(children));
        }
    };

    class Trie {
     public:
        TrieNode root;

        void add(const string& word) {
            TrieNode* node = &root;
            for (auto ch : word) {
                if (!node->children[ch - 'a']) {
                    node->children[ch - 'a'] = new TrieNode;
                }
                node = node->children[ch - 'a'];
            }
            node->word = word;
        }

        string search(const string& word) {
            TrieNode* node = &root;
            for (auto ch : word) {
                if (!node->children[ch - 'a']) {
                    return "";
                }
                node = node->children[ch - 'a'];
                if (!node->word.empty()) {
                    break;
                }
            }
            return node->word;
        }
    };


    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        Trie root;
        for (auto& word : dictionary) {
            root.add(word);
        }
        istringstream is(sentence);
        string word;
        while (is >> word) {
            auto res = root.search(word);
            if (res.empty()) {
                ans +=  ans.empty() ? word : " " + word;
            } else {
                ans += ans.empty() ? res : " " + res;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["cat","bat","rat"]\n"the cattle was rattled by the battery"\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","c"]\n"aadsfasf absbs bbab cadsfafs"\n
// @lcpr case=end

// @lcpr case=start
// ["a", "aa", "aaa", "aaaa"]\n"a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"\n
// @lcpr case=end

// @lcpr case=start
// ["catt","cat","bat","rat"]\n"the cattle was rattled by the battery"\n
// @lcpr case=end

// @lcpr case=start
// ["ac","ab"]\n"it is abnormal that this solution is accepted"\n
// @lcpr case=end

 */

