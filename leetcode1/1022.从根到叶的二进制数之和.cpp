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
			// 保证栈中节点必定不为空
			while (cur) {
				st.push(cur);

				// 需要知道每一个节点的先前值
				// val 为当前值
				int val = pre_map[cur] * 2 + cur->val;
				
				// 遇到根节点计算值
				if (!cur->left && !cur->right) {
					total += val;
					break;
				}	

				cur = cur->left;

				// 存下当前节点的pre值
				if (cur) {
					pre_map[cur] = val;
				}
			}
			auto node = st.top();
			st.pop();

			cur = node->right;
			// cur 变成未录入节点， 需要知道其pre
			if (cur) {
				pre_map[cur] = pre_map[node] * 2 + node->val;
			}	
		}
		return total;
	}
};
// @lc code=end

