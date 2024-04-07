/*
 * @lc app=leetcode.cn id=LCR 056 lang=cpp
 * @lcpr version=30121
 *
 * [LCR 056] 两数之和 IV - 输入二叉搜索树
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget_vec_二分(TreeNode* root, int k) {
        if (!root) {
            return false;
        }
        vector<int> data;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            inorder(node->left);
            data.emplace_back(node->val);
            inorder(node->right);
        };
        inorder(root);
        for (int i = 0; i < data.size() and data[i] <= k >> 1; i++) {
            auto it = lower_bound(data.begin() + i + 1, data.end(), k - data[i]);
            if (it != data.end() and *it == k - data[i]) {
                return true;
            }
        }
        return false;
    }

    bool findTarget_two_pointer(TreeNode* root, int k) {
        if (!root) {
            return false;
        }
        vector<int> data;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            inorder(node->left);
            data.emplace_back(node->val);
            inorder(node->right);
        };
        inorder(root);
        int j = data.size() - 1;
        for (int i = 0; i < data.size() and i < j; i++) {
            while (i < j and data[i] + data[j] > k) {
                --j;
            }
            if (i < j and data[i] + data[j] == k) {
                return true;
            }
        }
        return false;
    }

    class InTraversal {
     public:
        stack<TreeNode*> st;
        TreeNode* cur = NULL;

        InTraversal(TreeNode* node):cur(node) {}

        bool hasNext() {
            return cur || !st.empty();
        }

        virtual TreeNode* next() {
            while (hasNext()) {
                while (cur) {
                    st.push(cur);
                    cur = cur->left;
                }
                cur = st.top();
                auto ans = cur;
                st.pop();
                cur = cur->right;
                return ans;
            }
            return nullptr;
        }
    };

    class ReverseInTraversal: public InTraversal {
     public:

        ReverseInTraversal(TreeNode* node):InTraversal(node){}

        virtual TreeNode* next() {
            while (hasNext()) {
                while (cur) {
                    st.push(cur);
                    cur = cur->right;
                }
                cur = st.top();
                auto ans = cur;
                st.pop();
                cur = cur->left;
                return ans;
            }
            return nullptr;
        }
    };

    bool findTarget_traversal(TreeNode* root, int k) {
        if (!root) {
            return false;
        }
        // 迭代法
        InTraversal in(root);
        ReverseInTraversal rin(root);
        auto right = rin.next();
        auto left = in.next();
        while (left != right) {
            while (left != right and left->val + right->val > k) {
                right = rin.next();
            }
            if (left != right and left->val + right->val == k) {
                return true;
            }
            if (left == right) {
                break;
            }
            left = in.next();
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) {
            return false;
        }
        unordered_set<int> ms;
        vector<int> data;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            inorder(node->left);
            data.emplace_back(node->val);
            inorder(node->right);
        };
        inorder(root);
        for (auto v : data) {
            if (ms.count(k - v)) {
                return true;
            }
            ms.insert(v);
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,6,10,5,7,9,11]\n12\n
// @lcpr case=end

// @lcpr case=start
// [8,6,10,5,7,9,11]\n22\n
// @lcpr case=end

 */

