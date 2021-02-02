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
            if (th->children[index] == nullptr) {
                return false;
            }
            th = th->children[index];
        }
        return th->end;
    }

    Trie() { init(); }

    ~Trie() {
        if (this == nullptr) {
            return;
        }
        Trie::freeTrie(this);
    }

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