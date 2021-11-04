/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
 public:
    struct TriesNode {
        vector<TriesNode *> children;
        int strIndex;

        TriesNode() : children(26, nullptr), strIndex(-1) {}
    };

#define Index(name) \
        (name - 'a')

    struct TriesTree {
        TriesNode root;

        void add(const string &str, int index) {
            TriesNode *th = &root;
            for (auto ch : str) {
                if (!th->children[Index(ch)]) {
                    th->children[Index(ch)] = new TriesNode;
                }
                th = th->children[Index(ch)];
            }
            th->strIndex = index;
        }

        bool search(const string &s, int& i, int &index) {
            if (i >= s.size() || nullptr == root.children[Index(s[i])]) {
                return false;
            }
            TriesNode *th = root.children[Index(s[i++])];
            while (th->strIndex == -1) {
                if (!th->children[Index(s[i])]) {
                    return false;
                }
                th = th->children[Index(s[i])];
                i++;
            }
            index = th->strIndex;
            return true;
        }
    };

    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> ans;
        TriesTree tree;
        unordered_map<string, int> word_counter;
        for (int i = 0; i < words.size(); i++) {
            tree.add(words[i], i);
            word_counter[words[i]]++;
        }
        int word_count = words.size();
        int step = words[0].size();
        int min_len = word_count * step;
        int left = word_counter.size();

        unordered_map<string, int> word_left = word_counter;
        //deque<string> exist;

        for (int i = 0; i + min_len <= s.size(); i++) {
            int j = i;
            word_left = word_counter;
            //exist.clear();
            left = word_counter.size();
            int index = -1;
            while (j < s.size()) {
                if (tree.search(s, j, index)) {
                    if (word_left[words[index]] <= 0) {
                        break;
                    }
                    if (--word_left[words[index]] == 0) {
                        --left;
                    }
                   // exist.push_back(words[index]);
                    if (left == 0) {
                        ans.push_back(i);
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

