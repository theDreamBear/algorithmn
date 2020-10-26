/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* dfs(int low, int high, vector<ListNode*> vec) {
        if (low > high) {
            return NULL;
        }
        if (low == high) {
            return new TreeNode(vec[low]->val);
        }
        int mid = (low + high) / 2;
        TreeNode* root = new TreeNode(vec[mid]->val);
        root->left = dfs(low, mid - 1, vec);
        root->right = dfs(mid + 1, high, vec);
        return root;
    }

    TreeNode* sortedListToBST_dfs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        vector<ListNode*> vec;
        ListNode* cur = head;
        while (cur) {
            vec.push_back(cur);
            cur = cur->next;
        }
        return dfs(0, vec.size() - 1, vec);
    }

    ListNode* findmid(ListNode* head) {
        if (head->next == NULL) {
            return head;
        }
        ListNode* cur = head;
        ListNode* quick = head->next->next;
        while (quick && quick->next) {
            cur = cur->next;
            quick = quick->next->next;
        }
        return cur;
    }

    TreeNode* buildTreeDFS(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return new TreeNode(head->val);
        }
        ListNode* cur = findmid(head);
        ListNode* next = cur->next;
        int val = next->val;
        TreeNode* root = new TreeNode(val);
        next = next->next;
        cur->next = NULL;
        root->left = buildTreeDFS(head);
        root->right = buildTreeDFS(next);
        return root;
    }

    TreeNode* buildTree(ListNode* head) {
        stack<ListNode*> st;
        stack<TreeNode*> nodes;
        st.push(head);
        while (!st.empty()) {
            ListNode* cur = st.top();
            st.pop();
            if (cur == NULL) {
                nodes.push(NULL);
                continue;
            }
            if (cur->next == NULL) {
                TreeNode* node = new TreeNode(cur->val);
                nodes.push(NULL);
                nodes.push(NULL);
                nodes.push(node);
                continue;
            }

            ListNode* c = findmid(cur);
            ListNode* next = c->next;
            if (next == NULL) {
                st.push(NULL);
                continue;
            }
            int val = next->val;
            TreeNode* root = new TreeNode(val);
            nodes.push(root);
            next = next->next;
            c->next = NULL;

            st.push(cur);
            st.push(next);
        }
        TreeNode dummy;
        TreeNode* pleft = &dummy;
        TreeNode* pright = &dummy;
        TreeNode* pp = &dummy;

        TreeNode* left = &dummy;
        TreeNode* right = &dummy;
        TreeNode* p = &dummy;
        while (!nodes.empty()) {
            TreeNode* cur = nodes.top();
            nodes.pop();
            if (pleft != &dummy && pright != &dummy) {
                pp = cur;
                pp->left = pleft;
                pp->right = pright;
                pleft = pp;

                pp = &dummy;
                pright = &dummy;
                continue;
            } else {
                if (left == &dummy) {
                    left = cur;
                } else if (right == &dummy) {
                    right = cur;
                } else if (p == &dummy) {
                    p = cur;
                    p->left = left;
                    p->right = right;
                    if (pleft == &dummy) {
                        pleft = p;
                    } else {
                        pright = p;
                    }
                    p = &dummy;
                    left = &dummy;
                    right = &dummy;
                }
            }
        }
        if (right != &dummy) {
            pp = right;
            pp->left = pleft;
            pp->right= left; 
            pleft = pp;
        } else if (left != &dummy) {
            pleft = left;
        }
        return pleft;
    }

    /*
        build
    */
    TreeNode* sortedListToBST(ListNode* head) { 
        if (head == NULL) {
            return NULL;
        }
        return buildTree(head); 
    }
};
// @lc code=end

ListNode* makeList(vector<int>& vec) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int i = 0; i < vec.size(); ++i) {
        ListNode* cur = new ListNode(vec[i]);
        tail->next = cur;
        tail = cur;
    }
    return dummy.next;
}

int main() {
    vector<int> vec{0,1,2,3,4,5,6,7};
    auto list = makeList(vec);
    Solution{}.sortedListToBST(list);
}