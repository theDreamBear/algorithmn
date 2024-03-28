/*
 * @lc app=leetcode.cn id=LCR 064 lang=cpp
 * @lcpr version=30121
 *
 * [LCR 064] 实现一个魔法字典
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
class MagicDictionary_bad {
public:
    class Item {
     public:
        vector<int> ct;
        int size;

        Item(const string& word):ct(26) {
            size = word.size();
            for (auto ch : word) {
                ++ct[ch - 'a'];
            }
        }

        Item() {}

        bool can(const string& other) const{
            if (other.size() != size) {
                return false;
            }
            Item item(other);
            int one_ct = 0, minus_ct = 0;
            for (int i = 0; i < 26; i++) {
                int left = item.ct[i] - ct[i];
                if (left < -1 || left > 1) {
                    return false;
                }
                if (left == 1) {
                    if (one_ct > 0) {
                        return false;
                    }
                    one_ct++;
                    continue;
                }
                if (left == -1) {
                    if (minus_ct > 0) {
                        return false;
                    }
                    minus_ct++;
                }
            }
            return one_ct == 1 and minus_ct == 1;
        }

    };

    vector<Item> vec;

    /** Initialize your data structure here. */
    MagicDictionary_bad() {

    }

    void buildDict(vector<string> dictionary) {
        for (auto& word: dictionary) {
            vec.emplace_back(word);
        }
    }

    // 理解有问题， 字母的位置也需要一样
    bool search_bad(string searchWord) {
        for (auto& item : vec) {
            if (item.can(searchWord)) {
                return true;
            }
        }
        return false;
    }
};

class MagicDictionary2 {
public:
    vector<string> vec;

    /** Initialize your data structure here. */
    MagicDictionary2() {}

    void buildDict(vector<string> dictionary) {
        vec = std::move(dictionary);
    }

    static bool can(const string& lhs, const string& rhs) {
        if (lhs.size() != rhs.size()) {
            return false;
        }
        int diff_cnt = 0;
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] != rhs[i]) {
                if (diff_cnt > 0) {
                    return false;
                }
                ++diff_cnt;
            }
        }
        return diff_cnt == 1;
    }

    bool search(string searchWord) {
        for (auto& item : vec) {
            if (can(item, searchWord)) {
                return true;
            }
        }
        return false;
    }
};

class MagicDictionary {
public:
    vector<string> vec;
    vector<int> codes;

    /** Initialize your data structure here. */
    MagicDictionary() {}

    int get_code(const string& word) {
        int code = 0;
        for (auto ch : word) {
            code += (ch - 'a');
        }
        return code;
    }

    void buildDict(vector<string> dictionary) {
        vec = std::move(dictionary);
        for (auto& word : vec) {
            codes.push_back(get_code(word));
        }
    }

    static bool can(const string& lhs, const string& rhs) {
        if (lhs.size() != rhs.size()) {
            return false;
        }
        int diff_cnt = 0;
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] != rhs[i]) {
                if (diff_cnt > 0) {
                    return false;
                }
                ++diff_cnt;
            }
        }
        return diff_cnt == 1;
    }

    bool search(string searchWord) {
        int code = get_code(searchWord);
        for (int i = 0; i < vec.size(); i++) {
            if (abs(code - codes[i]) <= 26) {
                if (can(vec[i], searchWord)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// 前缀树 + 容忍度

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end



