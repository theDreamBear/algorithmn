/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        TreeNode* cur = root;
        q.push(cur);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if (!ans.empty()) {
                    ans.push_back('_');
                }
                if (node) {
                    ans += to_string(node->val);
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    ans.push_back('N');
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;
        if (!getline(ss, s, '_')) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(atoi(s.c_str()));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto fa = q.front();
                q.pop();
                if (getline(ss, s, '_')) {
                    TreeNode *node = nullptr;
                    if (s != "N") {
                        node = new TreeNode(atoi(s.c_str()));
                    }
                    fa->left = node;
                    if (node) {
                        q.push(node);
                    }
                }
                if (getline(ss, s, '_')) {
                    TreeNode *node = nullptr;
                    if (s != "N") {
                        node = new TreeNode(atoi(s.c_str()));
                    }
                    fa->right = node;
                    if (node) {
                        q.push(node);
                    }
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

