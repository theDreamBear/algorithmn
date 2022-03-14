/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    class BinaryTreeInorderTraversal {
     private:
        TreeNode* root;
        virtual void  change(TreeNode* cur) = 0;
     public:
        BinaryTreeInorderTraversal(TreeNode* node) : root(node){}

        void Traversal() {
            if (!root) {
                return;
            }
            TreeNode* cur = root;
            stack<TreeNode*> st;
            while (!st.empty() || cur) {
                while (cur) {
                    st.push(cur);
                    cur = cur->left;
                }
                cur = st.top();
                st.pop();
                // 变化
                change(cur);
                //
                cur = cur->right;
            }
        }
    };

    class TotalSumAnalysis : public BinaryTreeInorderTraversal {
     private:
        int sum = 0;

     public:
        TotalSumAnalysis(TreeNode* node): BinaryTreeInorderTraversal(node) {}

        int getSum() {
            return sum;
        }
        void change(TreeNode* cur) override {
            if (cur) {
                sum += cur->val;
            }
        }
    };

    class ParialSum : public BinaryTreeInorderTraversal {
     public:
        int pre;
        int sum;
        ParialSum(TreeNode* node, int sum): BinaryTreeInorderTraversal(node)  ,sum(sum) {
            pre = 0;
        }

        void change(TreeNode *cur) override {
            if (cur) {
                int val = cur->val;
                cur->val = sum - pre;
                pre += val;
            }
        }
    };

    TreeNode* convertBST(TreeNode* root) {
        TotalSumAnalysis ts(root);
        ts.Traversal();
        int sum = ts.getSum();

        ParialSum ps(root, sum);
        ps.Traversal();
        return root;
    }

    TreeNode* convertBST0(TreeNode* root) {
        if (!root) {
            return root;
        }
        int sum = 0;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();

            // 变化
            sum += cur->val;
            //

            cur = cur->right;
        }

        int pre = 0;
        // cur 需要重置
        cur = root;
        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();

            // 变化
            // 源值
            int val = cur->val;
            // sum - pre
            cur->val = sum - pre;
            pre += val;

            //
            cur = cur->right;
        }
        return root;
    }
};


// @lc code=end

