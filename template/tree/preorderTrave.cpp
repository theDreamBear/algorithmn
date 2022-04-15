#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(TreeNode* left = NULL, TreeNode* right = NULL) {
        this->left = left;
        this->right = right;
    }

    TreeNode(int val, TreeNode* left = NULL, TreeNode* right = NULL) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};


// 递归


typedef void(*DoSome)(int val);

// 特例化
struct DoMethod {
    // 数据

    void operator()(int val) {
        cout << val << endl;
    }
};

void preorderTravelRecursion(TreeNode* root, DoMethod ds) {
    if (root == NULL) {
        return;
    }
    // do something
    ds(root->val);
    preorderTravelRecursion(root->left, ds);
    preorderTravelRecursion(root->right, ds);
}

#include<stack>
#include<vector>

void preorderTravel(TreeNode* root, DoMethod ds) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        TreeNode* cur = nodeStack.top(); nodeStack.pop();
        ds(cur->val);
        if (cur->right) {
            nodeStack.push(cur->right);
        }
        if (cur->left) {
            nodeStack.push(cur->left);
        }
    }
}

void preorderTravel3(TreeNode* root, DoMethod ds) {
    if (root == NULL) {
        return;
    }
    // 准备工具
    stack<TreeNode*> nodeStack;
    TreeNode* cur;
    
    // 加入栈的时候访问
    // 入栈时候访问才行
    #define VISIT_WHILE_PUSH

    #ifdef VISIT_WHILE_PUSH
    cur = root;
    while(cur != NULL || !nodeStack.empty()) {
        while (cur) {
            ds(cur->val);
            nodeStack.push(cur);
            cur = cur->left;
        }
        cur = nodeStack.top();
        nodeStack.pop();
        cur = cur->right;
    }
    #endif
}


#include<unordered_set>
/*
状态: 
1. 左边未加入节点
2. 左边已加入节点 包括 NULL
3. 右边未加入节点
4 右边已加入节点

new 状态:
1. 已加入节点
2. 未加入节点
3. 已访问节点
4. 未访问节点

什么时候加入栈
1. 当前节点为左边未加入节点

什么时候出栈

*/

struct Helper {
    unordered_set<TreeNode*> addedSet;

    void add(TreeNode* node) {
        addedSet.insert(node);
    }

    bool notAdd(TreeNode* node) {
        return addedSet.find(node) == addedSet.end();
    }
};


#include<unordered_set>
void postTravel(TreeNode* root, DoMethod ds) {
    if (NULL == root) {
        return;
    }
    TreeNode* preVisit = NULL;
    
    stack<TreeNode*> nodeStack;
    Helper h;
    // 何时访问节点
    // 出栈的时候访问
    TreeNode* cur = root;
    while (cur || !nodeStack.empty()) {
        while (cur && h.notAdd(cur)) {
            h.add(cur);
            nodeStack.push(cur);
            cur = cur->left;
        }
        cur = nodeStack.top();
        // 右节点为空或者访问过 才访问当前节点
        if (cur->right == NULL || !h.notAdd(cur->right)) {
            ds(cur->val);
            cur = NULL;
            nodeStack.pop();
            continue;
        }
        cur = cur->right;
    }
}

vector<int> preorderTraversal2(TreeNode * root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        TreeNode* cur = nodeStack.top(); nodeStack.pop();
        ans.push_back(cur->val);
        if (cur->right) {
            nodeStack.push(cur->right);
        }
        if (cur->left) {
            nodeStack.push(cur->left);
        }
    }
    return ans;
}


vector<int> preorderTraversal1(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    stack<TreeNode*> st;
    TreeNode* cur = root;

    // 第一次遇到时添加访问并入栈
    ans.push_back(cur->val);
    st.push(root);

    while (!st.empty()) {
        if (cur) {
            cur = cur->left;
            if (cur) {
                // 第一次遇到
                ans.push_back(cur->val);
                st.push(cur);
            }
        } else {
            cur = st.top();
            st.pop();
            cur = cur->right;
            if (cur) {
                // 第一次遇到
                ans.push_back(cur->val);
                st.push(cur);
            }
        }
    }
    return ans;
}

vector<int> preorderTraversal3(TreeNode* root) {
    vector<int> ans;
    if (NULL == root) {
        return ans;
    }
    stack<TreeNode*> st;
    TreeNode* cur = root;
    // 第一次遇到添加进栈
    ans.push_back(cur->val);
    st.push(root);
    while (!st.empty()) {
        while (cur && cur->left) {
            cur = cur->left;
            // 第一次遇到
            st.push(cur);
            ans.push_back(cur->val);
        }
        // cur 为最左以访问节点  或者 其他
        // cur 为最左
        if (cur) {
            cur = cur->right;
            if (cur) {
                // 第一次遇到
                st.push(cur);
                ans.push_back(cur->val);
            }
        } else {
            cur = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }
            cur = st.top();
            st.pop();

            cur = cur->right;
            if (cur) {
                // 第一次遇到
                st.push(cur);
                ans.push_back(cur->val);
            }
        }
    }
    return ans;
}


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while(cur || !st.empty()) {
         while (cur) {
            ans.push_back(cur->val);
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        cur = cur->right;
    }
    return ans;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (NULL == root) {
        return ans;
    }
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur =  cur->left;
        }
        cur = st.top();
        ans.push_back(cur->val);
        st.pop();
        cur = cur->right; 
    }
    return ans;
}


 vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (NULL == root) {
        return ans;
    }
    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* pre = NULL;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        if (NULL == cur->right || cur->right == pre) {
            ans.push_back(cur->val);
            pre = cur;
            st.pop();
            cur = NULL;
        } else {
            cur = cur->right;
        }
    }
    return ans;
}

/*
1. 别的思路破坏二叉树
*/

/**
int main() {
    TreeNode* root = new TreeNode(12);
    preorderTravel(root, DoMethod{});
}
*/


int main() {
    TreeNode* root = new TreeNode(2);
    TreeNode* cur = root;
    TreeNode* a = new TreeNode(1);
    cur->left = a;

    TreeNode* b = new TreeNode(3);
    cur->right = b;

    TreeNode* d = new TreeNode(4);
    cur->left->left = d;
    postTravel(root, DoMethod{});
}


