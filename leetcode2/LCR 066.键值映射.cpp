/*
 * @lc app=leetcode.cn id=LCR 066 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 066]  键值映射
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
class MapSum {
public:
    struct TrieNode {
        int sum;
        int val;
        vector<TrieNode*> children;

        TrieNode(int sum = 0): sum(sum), val(0), children(26) {}
    };

    class Trie {
     public:
        TrieNode root;

        int get_old(const string& key) {
            TrieNode* node = &root;
            for (auto ch : key) {
                if (!node->children[ch - 'a']) {
                    return 0;
                }
                node = node->children[ch - 'a'];
            }
            if (node->val) {
                return node->val;
            }
            return 0;
        }

        void insert(string key, int val) {
            int old = get_old(key);
            TrieNode* node = &root;
            for (auto ch : key) {
                if (!node->children[ch - 'a']) {
                    node->children[ch - 'a'] = new TrieNode;
                }
                node->children[ch - 'a']->sum += (val - old);
                node = node->children[ch - 'a'];
            }
            node->val = val;
        }

        int sum(const string& prefix) {
            //int ans = 0;
            TrieNode* node = &root;
            for (auto ch : prefix) {
                if (!node->children[ch - 'a']) {
                    return 0;
                }
                node = node->children[ch - 'a'];
            }
            return node->sum;
        }
    };

    Trie root;

    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        root.insert(key, val);
    }

    int sum(string prefix) {
        return root.sum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MapSum", "insert", "sum", "insert"\n[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]\n
// @lcpr case=end

 */

