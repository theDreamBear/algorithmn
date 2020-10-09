#include <iostream>
#include <queue>
#include <sstream>

#include "../sort/randomInput.h"

using namespace std;

enum Color {
    RED = 0,
    BLACK = 1,
};

struct redBlackNode {
    Color c;
    redBlackNode* left;
    redBlackNode* right;
    redBlackNode* p;
    int val;

    redBlackNode(int val = 0, Color c = RED) {
        this->c = c;
        left = NULL;
        right = NULL;
        p = NULL;
        this->val = val;
    }
};

static redBlackNode* nil = new redBlackNode(-1, BLACK);

string redBlackNodeToString(redBlackNode* root) {
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<redBlackNode*> q;
    q.push(root);
    while (!q.empty()) {
        redBlackNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }
        string c = "red";
        if (node->c == BLACK) {
            c = "black";
        }
        output += to_string(node->val) + "[" + c + "]" + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
}

redBlackNode* stringToredBlackNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    redBlackNode* root = new redBlackNode(stoi(item));
    queue<redBlackNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        redBlackNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new redBlackNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new redBlackNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void prettyPrintTree(redBlackNode* node, string prefix = "",
                     bool isLeft = true) {
    if (!node) {
        cout << "Empty tree";
        return;
    }

    if (node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "),
                        false);
    }
    string c = "R";
    if (node->c == BLACK) {
        c = "B";
    }
    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "[" +
                c + "]" + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

struct redBlackTree {
    redBlackNode* root;

    redBlackTree() { root = nil; }
};

bool isNULL(redBlackNode* x) {
    if (NULL == x || nil == x) {
        return true;
    }
    return false;
}

void leftRotate(redBlackTree* tree, redBlackNode* x) {
    if (isNULL(x) || isNULL(x->right) || NULL == tree || isNULL(tree->root)) {
        return;
    }
    // check x in tree
    //
    redBlackNode* y = x->right;
    x->right = y->left;
    if (!isNULL(x->right)) {
        x->right->p = x;
    }
    y->p = x->p;
    if (isNULL(x->p)) {
        tree->root = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }
    y->left = x;
    x->p = y;
}

void rightRotate(redBlackTree* tree, redBlackNode* x) {
    if (isNULL(x) || isNULL(x->left) || NULL == tree || isNULL(tree->root)) {
        return;
    }
    redBlackNode* y = x->left;
    x->left = y->right;
    if (!isNULL(x->left)) {
        x->left->p = x;
    }
    y->p = x->p;
    if (isNULL(x->p)) {
        tree->root = y;
    } else if (x->p->left == x) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }
    y->right = x;
    x->p = y;
}

void insertFixup(redBlackTree* tree, redBlackNode* z) {
    while (RED == z->c) {
        if (z == tree->root) {
            z->c = BLACK;
            return;
        }
        if (BLACK == z->p->c) {
            return;
        }
        if (z->p == z->p->p->left) {
            redBlackNode* y = z->p->p->right;
            if (BLACK == y->c) {
                if (z == z->p->right) {
                    z = z->p;
                    leftRotate(tree, z);
                }
                z->p->c = BLACK;
                z->p->p->c = RED;
                rightRotate(tree, z->p->p);
            } else {
                y->c = BLACK;
                z->p->c = BLACK;
                z = z->p->p;
                z->c = RED;
            }
        } else {
            redBlackNode* y = z->p->p->left;
            if (BLACK == y->c) {
                if (z == z->p->left) {
                    z = z->p;
                    rightRotate(tree, z);
                }
                z->p->c = BLACK;
                z->p->p->c = RED;
                leftRotate(tree, z->p->p);
            } else {
                y->c = BLACK;
                z->p->c = BLACK;
                z = z->p->p;
                z->c = RED;
            }
        }
    }
    tree->root->c = BLACK;
}

void insert(redBlackTree* tree, redBlackNode* z) {
    if (NULL == tree || isNULL(z)) {
        return;
    }
    redBlackNode* p = nil;
    redBlackNode* cur = tree->root;
    while (!isNULL(cur)) {
        p = cur;
        if (cur->val > z->val) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    z->p = p;
    if (isNULL(p)) {
        tree->root = z;
    } else if (p->val > z->val) {
        p->left = z;
    } else {
        p->right = z;
    }
    z->left = nil;
    z->right = nil;
    z->c = RED;
    insertFixup(tree, z);
}

void traverse(redBlackNode* root) {
    if (isNULL(root)) {
        return;
    }
    traverse(root->left);
    cout << root->val << " " << root->c << endl;
    traverse(root->right);
}

bool contains(redBlackTree* tree, int val) {
    redBlackNode* cur = tree->root;
    if (isNULL(cur)) {
        return false;
    }
    while (!isNULL(cur)) {
        if (val > cur->val) {
            cur = cur->right;
        } else if (val < cur->val) {
            cur = cur->left;
        } else {
            return true;
        }
    }
    return false;
}

redBlackNode* minmum(redBlackNode* root) {
    if (isNULL(root)) {
        return nil;
    }
    redBlackNode* cur = root;
    while (!isNULL(cur->left)) {
        cur = cur->left;
    }
    return cur;
}

redBlackNode* maxmum(redBlackNode* root) {
    if (isNULL(root)) {
        return nil;
    }
    redBlackNode* cur = root;
    while (!isNULL(cur->right)) {
        cur = cur->right;
    }
    return cur;
}

redBlackNode* _firstBiggerAncestor(redBlackNode* root) {
    if (isNULL(root)) {
        return nil;
    }
    redBlackNode* cur = root;
    redBlackNode* p = cur->p;
    while (!isNULL(p) && cur == p->right) {
        cur = p;
        p = p->p;
    }
    return p;
}

redBlackNode* _firstLessorAncestor(redBlackNode* root) {
    if (isNULL(root)) {
        return nil;
    }
    redBlackNode* cur = root;
    redBlackNode* p = root->p;
    while (!isNULL(p) && cur == p->left) {
        cur = p;
        p = p->p;
    }
    return p;
}

redBlackNode* successor(redBlackNode* root) {
    if (!isNULL(root->right)) {
        return minmum(root->right);
    }
    return _firstBiggerAncestor(root);
}

redBlackNode* predesucessor(redBlackNode* root) {
    if (isNULL(root->left)) {
        return maxmum(root->left);
    }
    return _firstLessorAncestor(root);
}

void transplant(redBlackTree* tree, redBlackNode* u, redBlackNode* v) {
    if (NULL == tree || isNULL(u)) {
        return;
    }
    if (isNULL(u->p)) {
        tree->root = v;
    } else if (u->p->left == u) {
        u->p->left = v;
    } else {
        u->p->right = v;
    }
    v->p = u->p;
}

void deleteFixUp(redBlackTree* tree, redBlackNode* x) {
    if (NULL == tree) {
        return;
    }
    while (x != tree->root && BLACK == x->c) {
        if (x->p->left == x) {
            redBlackNode* w = x->p->right;
            if (RED == w->c) {
                w->c = BLACK;
                x->p->c = RED;
                leftRotate(tree, x->p);
                w = x->p->right;
            }
            if (BLACK == w->left->c && BLACK == w->right->c) {
                w->c = RED;
                x = x->p;
            } else {
                if (RED == w->left->c) {
                    w->left->c = BLACK;
                    w->c = RED;
                    rightRotate(tree, w);
                    w = x->p->right;
                }
                w->c = x->p->c;
                x->p->c = BLACK;
                w->right->c = RED;
                leftRotate(tree, x->p);
                x = tree->root;
            }
        } else {
            redBlackNode* w = x->p->left;
            if (RED == w->c) {
                w->c = BLACK;
                x->p->c = RED;
                rightRotate(tree, x->p);
                w = x->p->left;
            }
            if (BLACK == w->left->c && BLACK == w->right->c) {
                w->c = RED;
                x = x->p;
            } else {
                if (RED == w->right->c) {
                    w->c = RED;
                    w->right->c = BLACK;
                    leftRotate(tree, w);
                    w = x->p->left;
                }
                w->c = x->p->c;
                w->p->c = BLACK;
                w->left->c = RED;
                rightRotate(tree, x->p);
                x = tree->root;
            }
        }
    };
    x->c = BLACK;
}

void deleteNode(redBlackTree* tree, redBlackNode* z) {
    if (isNULL(z) || NULL == tree || isNULL(tree->root)) {
        return;
    }
    redBlackNode* y = z;
    redBlackNode* x = nil;
    Color old_c = y->c;
    // 1
    if (isNULL(z->left)) {
        x = z->right;
        transplant(tree, z, z->right);
        // 2
    } else if (isNULL(z->right)) {
        x = z->left;
        transplant(tree, z, z->left);
        // 3
    } else {
        y = successor(z);
        old_c = y->c;
        x = y->right;
        if (y->p == z) {
            // x可能为nil
            x->p = y;
        } else {
            transplant(tree, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplant(tree, z, y);
        y->left = z->left;
        y->left->p = y;
        y->c = z->c;
    }
    if (old_c == BLACK) {
        deleteFixUp(tree, x);
    }
}

void removeFixUp(redBlackTree* tree, redBlackNode* z) {
    if (NULL == tree || isNULL(tree->root)) {
        return;
    }
    while (BLACK == z->c && z != tree->root) {
        if (z == z->p->left) {
            redBlackNode* w = z->p->right;
            if (RED == w->c) {
                z->p->c = RED;
                w->c = BLACK;
                leftRotate(tree, z->p);
                w = z->p->right;
            }
            if (BLACK == w->left->c && BLACK == w->right->c) {
                w->c = RED;
                z = z->p;
            } else {
                if (RED == w->left->c) {
                    w->left->c = BLACK;
                    w->c = RED;
                    rightRotate(tree, w);
                    w = w->p;
                }
                w->c = z->p->c;
                z->p->c = BLACK;
                w->right->c = BLACK;
                leftRotate(tree, z->p);
                z = tree->root;
            }
        } else {
            redBlackNode* w = z->p->left;
            if (RED == w->c) {
                w->c = BLACK;
                z->p->c = RED;
                rightRotate(tree, z->p);
                w = z->p->left;
            }
            if (BLACK == w->left->c && BLACK == w->right->c) {
                w->c = RED;
                z = z->p;
            } else {
                if (RED == w->right->c) {
                    w->c = RED;
                    w->right->c = BLACK;
                    leftRotate(tree, w);
                    w = w->p;
                }
                w->c = z->p->c;
                z->p->c = BLACK;
                w->left->c = BLACK;
                rightRotate(tree, z->p);
                z = tree->root;
            }
        }
    }
    z->c = BLACK;
}

void remove(redBlackTree* tree, redBlackNode* z) {
    if (NULL == tree || isNULL(tree->root) || isNULL(z)) {
        return;
    }
    Color c = z->c;
    redBlackNode* x = nil;
    if (isNULL(z->left)) {
        x = z->right;
        transplant(tree, z, z->right);
    } else if (isNULL(z->right)) {
        x = z->left;
        transplant(tree, z, z->left);
    } else {
        redBlackNode* y = successor(z);
        c = y->c;
        redBlackNode* x = y->right;
        if (y->p == z) {
            x->p = y;
        } else {
            transplant(tree, y, y->right);
            y->right->p = y;
        }
        transplant(tree, z, y);
        y->left = z->left;
        y->left->p = y;
        y->c = z->c;
        if (BLACK == c) {
            removeFixUp(tree, x);
        }
    }

    void makeTree(redBlackTree * tree, vector<int> nums) {
        for (int i = 0; i < nums.size(); ++i) {
            redBlackNode* z = new redBlackNode(nums[i]);
            insert(tree, z);
            // cout << i << " " << nil->c << endl;
        }
    }

    redBlackNode* find(redBlackTree * tree, int val) {
        if (NULL == tree || isNULL(tree->root)) {
            return nil;
        }
        redBlackNode* cur = tree->root;
        while (!isNULL(cur)) {
            if (cur->val > val) {
                cur = cur->left;
            } else if (cur->val < val) {
                cur = cur->right;
            } else {
                return cur;
            }
        }
        return nil;
    }

    int main() {
        // cout << "nil c: " << nil->c << endl;
        vector<int> nums = {9,  31, 8,  71, 71, 5,  19, 4,  8,  14,
                            79, 97, 77, 24, 35, 41, 58, 66, 77, 9};
        randomInput(20, 100);
        for (auto y : nums) {
            cout << y << " ";
        }
        cout << endl << endl;
        redBlackTree* tree = new redBlackTree;
        makeTree(tree, nums);
        prettyPrintTree(tree->root);
        // cout << "root: " << tree->root->val << " " << endl;
        redBlackNode* d = find(tree, 5);
        if (!isNULL(d)) {
            deleteNode(tree, d);
        }
        prettyPrintTree(tree->root);
    }
