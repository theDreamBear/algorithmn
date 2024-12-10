/*
 * @lc app=leetcode.cn id=3043 lang=cpp
 * @lcpr version=30204
 *
 * [3043] 最长公共前缀的长度
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
class Solution {
public:
    class Trie{
    public:
        struct Node {
            vector<Node*> children;
            Node():children(10){};
        };

        Node root;

        void add(int v) {
            Node* node = &root;
            string sv = to_string(v);
            for (int i = 0; i < sv.size(); i++) {
                if (!node->children[sv[i] - '0']) {
                    node->children[sv[i] - '0'] = new Node();
                }
                node = node->children[sv[i] - '0'];
            }
        }

        int search(int v) {
            Node* node = &root;
            string sv = to_string(v);
            int ans = 0;
            for (int i = 0; i < sv.size(); i++) {
                if (!node->children[sv[i] - '0']) {
                    break;
                }
                ans++;
                node = node->children[sv[i] - '0'];
            }
            return ans;
        }
    };

    // 多模匹配
    int longestCommonPrefix1(vector<int>& arr1, vector<int>& arr2) {
        // 字典树
        Trie trie;
        for (auto v: arr1) {
            trie.add(v);
        }
        int ans = 0;
        for (auto v: arr2) {
            ans = max(ans, trie.search(v));
        }
        return ans;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for (auto v : arr1) {
            for (; v ; v /= 10) {
                st.insert(v);
            }
        }
        int mx = 0;
        for (auto v : arr2) {
            for (; v and !st.contains(v); v /= 10);
            mx = max(mx, v);
        }
        return mx ? to_string(mx).size() : 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,10,100]\n[1000]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[4,4,4]\n
// @lcpr case=end

 */

