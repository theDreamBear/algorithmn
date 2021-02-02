/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
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
    /*
        通过空间换时间
    */
    string longestWord1(vector<string>& words) {
        set<string> hashset;
        for (auto& str : words) {
            hashset.insert(str);
        }
        int sz = 0;
        vector<string> ans;
        // 时间复杂度高的地方
        for (auto& str : words) {
            int i = 1;
            for (; i < str.size(); ++i) {
                string temp = str.substr(0, i);
                if (hashset.find(temp) == hashset.end()) {
                    break;
                }
            }
            // 找到每一个符合要求的
            if (i == str.size()) {
                ans.push_back(str);
            }
        }

        if (!ans.empty()) {
            int sz = 0;
            string s = "";
            for (auto& str : ans) {
                if (str.size() > sz) {
                    s = str;
                    sz = str.size();
                } else if (str.size() == sz && str < s) {
                    s = str;
                }
            }
            return s;
        }
        return "";
    }

    /*
        枚举
    */
    string longestWord2(vector<string>& words) {
        set<string> dict;
        queue<string> q;
        for (auto& str : words) {
            if (str.size() == 1) {
                q.push(str);
            }
            dict.insert(str);
        }
        string result = "";
        while (!q.empty()) {
            auto w = q.front();
            q.pop();
            if (w.size() > result.size() || w < result) {
                result = w;
            }
            w.push_back('0');
            // 枚举各种
            for (char c = 'a'; c <= 'z'; ++c) {
                w.back() = c;
                if (dict.count(w) > 0) {
                    q.push(w);
                    dict.erase(w);
                }
            }
        }
        return result;
    }

    /*
        trie树
    */

    struct Trie {
        Trie** children;
        bool end;
        void init() {
            end = false;
            children = new Trie*[26];
            fill(children, children + 26, nullptr);
        }

        /*
            待优化
        */
        void add(const string& str) {
            Trie* th = this;
            for (int i = 0; i < str.size(); ++i) {
                int index = str[i] - 'a';
                if (th->children[index] == nullptr) {
                    th->children[index] = new Trie();
                }
                th = th->children[index];
            }
            th->end = true;
        }

        bool search(const string& str) {
            Trie* th = this;
            for (auto c : str) {
                int index = c - 'a';
                if (th->children[index] == nullptr || !th->children[index]->end) {
                    return false;
                }
                th = th->children[index];
            }
            return th->end;
        }

        Trie() { init(); }

        static void freeTrie(Trie* root) {
            if (root == nullptr) {
                return;
            }
            stack<Trie*> st;
            vector<Trie*> nums;
            st.push(root);
            while (!st.empty()) {
                Trie* cur = st.top();
                st.pop();
                nums.push_back(cur);
                for (int i = 25; i >= 0; --i) {
                    if (cur->children[i] != nullptr) {
                        st.push(cur->children[i]);
                        cur->children[i] = nullptr;
                    }
                }
            }
            reverse(nums.begin(), nums.end());
            for (auto& node : nums) {
                delete node;
                node = nullptr;
            }
        }
    };

    string longestWord(vector<string>& words) {
        Trie* root = new Trie();
        for (auto& str : words) {
            root->add(str);
        }
        string result;
        for (auto& str : words) {
            if (root->search(str)) {
                if (str.size() > result.size()) {
                    result = str;
                } else if (str.size() == result.size() && str < result) {
                    result = str;
                }
            }
        }
        Trie::freeTrie(root);
        return result;
    }
};
// @lc code=end
