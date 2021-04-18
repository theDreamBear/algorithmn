// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */
#include <ranges.h>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
    int kthSmallestHelper(TreeNode *root, int k, int &th) {
        if (!root) {
            return -1;
        }
        int left = kthSmallestHelper(root->left, k, th);
        if (left > 0) {
            return left;
        }
        // 中序遍历实际逻辑
        ++th;
        if (th > k) {
            return left;
        }
        if (th == k) {
            return root->val;
        }
        //
        return kthSmallestHelper(root->right, k, th);
    }

    TreeNode *makeTree(const vector<string> &nums) {
        if (nums.empty()) {
            return nullptr;
        }
        vector<TreeNode *> nodes;
        int i = 0;
        TreeNode *root = new TreeNode(stoi(nums[i++]));
        nodes.push_back(root);
        while (i < nums.size()) {
            vector<TreeNode *> temp;
            for (int j = 0; i < nums.size() && j < nodes.size(); ++j) {
                if (i < nums.size()) {
                    if (nums[i] != "null") {
                        TreeNode *node = new TreeNode(stoi(nums[i]));
                        nodes[j]->left = node;
                        temp.push_back(node);
                    } else {
                        temp.push_back(nullptr);
                    }
                }
                ++i;
                if (i < nums.size()) {
                    if (nums[i] != "null") {
                        TreeNode *node = new TreeNode(stoi(nums[i]));
                        nodes[j]->right = node;
                        temp.push_back(node);
                    } else {
                        temp.push_back(nullptr);
                    }
                }
                i++;
            }
            nodes = temp;
        }
        return root;
    }

    int kthSmallest1(TreeNode *root, int k) {
        int th = 0;
        return kthSmallestHelper(root, k, th);
    }

    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (k > 0 && (cur || !st.empty())) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            if (--k == 0) {
                break;
            }
            st.pop();
            cur = cur->right;
        }
        return cur->val;
    }

    // 进阶问题
        https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/solution/er-cha-sou-suo-shu-zhong-di-kxiao-de-yuan-su-jin-j/
    /*
    struct BstMemoNode{
        int val;
        BstNode* left;
        BstNode* right;
        int leftchinds;
        int rightchilds;
        BstMemoNode(int x):val(x),left(NULL),right(NULL),leftchilds(0),rightchilds(0){}
    };
    */
};
// @lc code=end

int main() {
    vector<string> data = {"3", "1", "4", "null", "2"};
    TreeNode *root = Solution{}.makeTree(data);
    cout << Solution{}.kthSmallest(root, 1);
}