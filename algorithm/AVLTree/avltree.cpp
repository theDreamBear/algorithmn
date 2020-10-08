#include <iostream>

#include "../sort/randomInput.h"
using namespace std;

struct AVLTreeNode {
    AVLTreeNode* left;
    AVLTreeNode* right;
    AVLTreeNode* p;
    int val;
    int h;
    AVLTreeNode(int val = 0)
        : left(NULL), right(NULL), p(NULL), val(val), h(0) {}
};

struct AVLTree {
    AVLTreeNode* root;

    AVLTree() { root = NULL; }
};

void traverse(AVLTreeNode* root) {
    if (NULL == root) {
        return;
    }
    traverse(root->left);
    cout << root->val << " " << root->h << endl;
    traverse(root->right);
}

AVLTreeNode* search(AVLTreeNode* root, int val) {
    AVLTreeNode* r = root;
    while (r) {
        if (r->val > val) {
            r = r->left;
        } else if (r->val < val) {
            r = r->right;
        } else {
            return r;
        }
    }
    return NULL;
}

AVLTreeNode* find(AVLTreeNode* root, int val) {
    if (NULL == root) {
        return NULL;
    }
    AVLTreeNode* r = root;
    while (NULL != r) {
        if (r->val < val) {
            r = r->right;
        } else if (r->val > val) {
            r = r->left;
        } else {
            return r;
        }
    }
    return NULL;
}

AVLTreeNode* minmum(AVLTreeNode* root) {
    AVLTreeNode* r = root;
    while (r->left) {
        r = r->left;
    }
    return r;
}

AVLTreeNode* maxmum(AVLTreeNode* root) {
    AVLTreeNode* r = root;
    while (r->right) {
        r = r->right;
    }
    return r;
}

AVLTreeNode* _firstBiggerAncestor(AVLTreeNode* root) {
    if (NULL == root || NULL == root->p) {
        return NULL;
    }
    AVLTreeNode* x = root;
    AVLTreeNode* p = x->p;
    while (NULL != p && x == p->right) {
        x = p;
        p = p->p;
    }
    return p;
}

AVLTreeNode* successor(AVLTreeNode* root) {
    if (root->right) {
        return minmum(root->right);
    }
    return _firstBiggerAncestor(root);
}

AVLTreeNode* _firstLesserAncestor(AVLTreeNode* root) {
    if (NULL == root || NULL == root->p) {
        return NULL;
    }
    AVLTreeNode* x = root;
    AVLTreeNode* p = root->p;
    while (NULL != p && x == p->left) {
        x = p;
        p = p->p;
    }
    return p;
}

AVLTreeNode* predecessor(AVLTreeNode* root) {
    if (root->left) {
        return maxmum(root->left);
    }
    return _firstLesserAncestor(root);
}

void insert(AVLTree* tree, AVLTreeNode* z) {
    if (NULL == tree->root) {
        tree->root = z;
        // cout << "dddd" << endl;
        return;
    }
    AVLTreeNode* x = tree->root;
    AVLTreeNode* y = NULL;
    while (NULL != x) {
        y = x;
        if (x->val > z->val) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->p = y;
    if (z->val < y->val) {
        y->left = z;
    } else {
        y->right = z;
    }
    // cout << "y: " << y->val << " " << y->h << endl;
    z->h = y->h + 1;
    return;
}

/*
    u 待删除节点
    v 替代节点
*/
void transPlant(AVLTree* tree, AVLTreeNode* u, AVLTreeNode* v) {
    if (NULL == u) {
        return;
    }
    AVLTreeNode* p = u->p;
    if (NULL == p) {
        tree->root = v;
        return;
    }
    if (p->left == u) {
        p->left = v;
    } else {
        p->right = v;
    }
    if (NULL != v) {
        v->p = p;
        v->h = p->h + 1;
    }
}

void _delete(AVLTreeNode* z) {
    z->p = NULL;
    z->left = NULL;
    z->right = NULL;
    delete z;
}

/*
删除节点z
1.
*/
void deleteNode(AVLTree* tree, AVLTreeNode* z) {
    if (NULL == z->left) {
        transPlant(tree, z, z->right);
    }
    if (NULL == z->right) {
        transPlant(tree, z, z->left);
    }
    // 左右均不为空
    AVLTreeNode* su = minmum(z->right);
    if (su != z->right) {
        transPlant(tree, su, su->right);
        su->right = z->right;
        su->right->p = su;
    }
    transPlant(tree, z, su);
    su->left = z->left;
    su->left->p = su;
    _delete(z);
}

void makeTree(AVLTree* tree, vector<int> nums) {
    for (int i = 0; i < nums.size(); ++i) {
        AVLTreeNode* z = new AVLTreeNode(nums[i]);
        insert(tree, z);
    }
}

int main() {
    vector<int> ans = {86, 93, 9, 48, 19, 7};  // randomInput(5, 100);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    AVLTree* tree = new AVLTree;
    makeTree(tree, ans);
    // traverse(tree->root);
    AVLTreeNode* z = find(tree->root, 9);
    deleteNode(tree, z);
    traverse(tree->root);
}