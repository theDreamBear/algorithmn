// @before-stub-for-debug-begin

#include <stack>
#include <string>
#include <vector>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */
#include <limits.h>

#include <functional>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
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
    struct bigWrongNode {
        TreeNode* pre;
        bool ok;
        bigWrongNode() {
            pre = NULL;
            ok = false;
        }

        void operator()(TreeNode* node, bool& ok) {
            if (pre && node->val < pre->val) {
                ok = true;
            } else {
                pre = node;
            }
            return;
        }
    };

    struct lessWrongNode {
        TreeNode* pre;
        bool ok;
        lessWrongNode() {
            pre = NULL;
            ok = false;
        }
        void operator()(TreeNode* node, bool& ok) {
            if (!pre || (pre && pre->val > node->val)) {
                pre = node;
            }
            return;
        }
    };

    void fromNodeTreversalBig(TreeNode* root, TreeNode* startNode, bool& ok,
                              bool& start, bigWrongNode& ob) {
        // 终止条件
        if (ok || NULL == root) {
            return;
        }
        // left
        fromNodeTreversalBig(root->left, startNode, ok, start, ob);
        // 主要逻辑
        if (ok) {
            return;
        }
        if (root == startNode) {
            start = true;
        }
        if (start) {
            ob(root, ok);
        }
        //
        if (!ok) {
            fromNodeTreversalBig(root->right, startNode, ok, start, ob);
        }
    }

    void fromNodeTreversalLess(TreeNode* root, TreeNode* startNode, bool& ok,
                               bool& start, lessWrongNode& ob) {
        // 终止条件
        if (ok || NULL == root) {
            return;
        }
        // left
        fromNodeTreversalLess(root->left, startNode, ok, start, ob);
        // 主要逻辑
        if (ok) {
            return;
        }
        if (root == startNode) {
            start = true;
        }
        if (start) {
            ob(root, ok);
        }
        //
        if (!ok) {
            fromNodeTreversalLess(root->right, startNode, ok, start, ob);
        }
    }

    struct ans {
        TreeNode* bpre;
        bool ok;
        TreeNode* lpre;
        ans() {
            bpre = NULL;
            ok = false;
            lpre = NULL;
        }

        void operator()(TreeNode* node) {
            //
            if (!ok) {
                if (bpre && bpre->val > node->val) {
                    ok = true;
                } else {
                    bpre = node;
                }
            }
            if (ok) {
                if (!lpre || lpre->val > node->val) {
                    lpre = node;
                }
            }
        }
    };

    void fromNodeTreversal(TreeNode* root, ans& ob) {
        // 终止条件
        if (NULL == root) {
            return;
        }
        // left
        fromNodeTreversal(root->left, ob);
        // 主要逻辑
        ob(root);
        //
        fromNodeTreversal(root->right, ob);
    }

    void recoverTree1(TreeNode* root) {
        // bigWrongNode ob;
        // bool ok = false;
        // bool start = true;
        // fromNodeTreversalBig(root, NULL, ok, start, ob);
        // TreeNode* f = ob.pre;

        // lessWrongNode lwn;
        // ok = false;
        // start = false;
        // fromNodeTreversalLess(root, f, ok, start, lwn);

        // TreeNode* s = lwn.pre;
        ans an;
        fromNodeTreversal(root, an);
        TreeNode* f = an.bpre;
        TreeNode* s = an.lpre;
        int i = f->val;
        f->val = s->val;
        s->val = i;
        return;
    }

    // 空间方法
    void treeTraversal(TreeNode* root, vector<TreeNode*>& vec) {
        if (NULL == root) {
            return;
        }
        treeTraversal(root->left, vec);
        vec.push_back(root);
        treeTraversal(root->right, vec);
    }

    void treeFix(vector<TreeNode*>& vec) {
        TreeNode* bpre = NULL;
        TreeNode* lpre = NULL;
        bool ok = false;
        for (int i = 0; i < vec.size(); ++i) {
            if (!ok) {
                if (bpre && bpre->val > vec[i]->val) {
                    ok = true;
                } else {
                    bpre = vec[i];
                }
            }
            if (ok) {
                if (!lpre || lpre->val > vec[i]->val) {
                    lpre = vec[i];
                }
            }
        }
        int i = bpre->val;
        bpre->val = lpre->val;
        lpre->val = i;
        return;
    }

    void recoverTree2(TreeNode* root) {
        vector<TreeNode*> vec;
        treeTraversal(root, vec);
        treeFix(vec);
        return;
    }

    void recoverTree(TreeNode* root) {
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pre = nullptr;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (NULL != cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (pre && pre->val > cur->val) {
                y = cur;
                if (nullptr == x) {
                    x = pre;
                } else {
                    break;
                }
            }
            pre = cur;
            cur = cur->right;
        }
        swap(x->val, y->val);
        return;
    }
};

TreeNode* newNode(string& s) {
    if (s == "") {
        return NULL;
    }
    return new TreeNode(stoi(s));
}

TreeNode* makeTree(vector<string> nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    int index = 0;
    vector<TreeNode*> vec;
    vector<TreeNode*> vech;
    if (nums[index] == "") {
        return NULL;
    }
    TreeNode* root = new TreeNode(stoi(nums[index++]));
    vec.push_back(root);
    while (index < nums.size()) {
        int sz = vec.size();
        for (int vi = 0; vi < sz && index < nums.size(); ++vi) {
            // left;
            TreeNode* left = newNode(nums[index++]);
            vech.push_back(left);
            while (vi < sz && NULL == vec[vi]) {
                ++vi;
            }
            vec[vi]->left = left;
            // right;
            if (index < nums.size()) {
                TreeNode* right = newNode(nums[index++]);
                vec[vi]->right = right;
                vech.push_back(right);
            }
        }
        vec.clear();
        vec.assign(vech.begin(), vech.end());
        vech.clear();
    }
    return root;
}

// @lc code=end

int main() {
    vector<string> nums = {"3", "1", "4", "", "", "2"};
    TreeNode* root = makeTree(nums);
    Solution s;
    s.recoverTree(root);
}
