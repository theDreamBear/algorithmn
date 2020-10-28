/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */
#include <iostream>
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

    int listNodeLen(ListNode* head) {
        int len = 0;
        ListNode* cur = head;
        for (; cur != nullptr; cur = cur->next, ++len)
            ;
        return len;
    }

    TreeNode* dfs_new(ListNode*& head, int i, int n) {
        if (i > n) {
            return NULL;
        }
        TreeNode* root = new TreeNode;
        root->left = dfs_new(head, 2 * i, n);
        if (head == NULL) {
            return NULL;
        }
        root->val = head->val;
        //cout << head->val << endl;
        head = head->next;
        root->right = dfs_new(head, 2 * i + 1, n);
        return root;
    }

    /*
        build
    */
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        int len = listNodeLen(head);
        cout << len << endl;
        return dfs_new(head, 1, len);
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

void preorderTraversal(TreeNode* root) {
    if (NULL == root) {
        return;
    }
    preorderTraversal(root->left);
     cout << root->val << endl;
    preorderTraversal(root->right);
}

int main() {
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7};
    auto list = makeList(vec);
    TreeNode* root =  Solution{}.sortedListToBST(list);
    preorderTraversal(root);
}