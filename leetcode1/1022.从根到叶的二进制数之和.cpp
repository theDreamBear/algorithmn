/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
 */

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
	void sumRootToLeafHelper(TreeNode *root, int pre, int &total) {
		if (nullptr == root) {
			return;
		}
		int v = pre * 2 + root->val;
		if (nullptr == root->left && nullptr == root->right) {
			total += v;
			return;
		}
		if (nullptr != root->left) {
			sumRootToLeafHelper(root->left, v, total);
		}
		if (nullptr != root->right) {
			sumRootToLeafHelper(root->right, v, total);
		}

	}
	int sumRootToLeaf1(TreeNode *root) {
		int total = 0;
		sumRootToLeafHelper(root, 0, total);
		return total;
	}

	int sumRootToLeaf(TreeNode *root) {
		if (!root) {
			return 0;
		}
		// 
		unordered_map<TreeNode*, int> pre_map;
		pre_map[root] = 0;

		int total = 0;
		stack<TreeNode*> st;
		TreeNode* cur = root;

		while(cur || !st.empty()) {
			while (cur) {
				st.push(cur);
				int pre = pre_map[cur];
				int val = pre * 2 + cur->val;
				if (!cur->left && !cur->right) {
					total += val;
					break;
				}	
				cur = cur->left;
				if (cur) {
					pre_map[cur] = val;
				}
			}
			auto node = st.top();
			st.pop();
			cur = node->right;
			if (cur) {
				pre_map[cur] = pre_map[node] * 2 + node->val;
			}	
		}
		return total;
	}
};
// @lc code=end

