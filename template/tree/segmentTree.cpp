#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;

struct segmentNode {
    int left;
    int right;
    int minVal;

    segmentNode* lchild, * rchild;

    segmentNode(int l, int r, int mval) : left(l), right(r), minVal(mval), lchild(NULL), rchild(NULL) {}

    segmentNode() = default;
};


class segmentTree {
 private:
    vector<int> _nums;
    segmentNode* root;

    segmentNode* makeTree(int low, int high) {
        if (low > high) {
            return NULL;
        }
        if (low == high) {
            return new segmentNode(low, high, _nums[low]);
        }
        int mid = (low + high) / 2;
        segmentNode* left = makeTree(low, mid);
        segmentNode* right = makeTree(mid + 1, high);
        segmentNode* r = new segmentNode(low, high, min(left->minVal, right->minVal));
        r->lchild = left;
        r->rchild = right;
        return r;
    }

    int _query(segmentNode* node, int left, int right) {
        if (left > node->right || right < node->left) {
            return INT_MIN;
        }
        if (node->left == left && node->right == right) {
            return node->minVal;
        }
        if (node->lchild->right >= right) {
            return _query(node->lchild, left, right);
        }
        if (node->rchild->left <= left) {
            return _query(node->rchild, left, right);
        }
        int lval = _query(node->lchild, left, node->lchild->right);
        int rval = _query(node->rchild, node->rchild->left, right);
        return min(lval, rval);
    }

    void _update(segmentNode* node, int index, int val) {
        if (node == NULL) {
            return;
        }
        if (node->left > index || node->right < index) {
            return;
        }
        _update(node->lchild, index, val);
        _update(node->rchild, index, val);

        if (node->left == index && node->right == index) {
            node->minVal = val;
        } else {
            node->minVal = min(node->lchild->minVal, node->rchild->minVal);
        }
    }

 public:
    segmentTree(const vector<int>& nums) : _nums(nums), root(NULL){
        root = makeTree(0, _nums.size() - 1);
    }

    int queryMin(int left, int right) {
        if (left < root->left) {
            left = root->left;
        }
        if (right > root->right) {
            right = root->right;
        }
        return _query(root, left, right);
    }

    void update(int index, int val) {
        _update(root, index, val);
        _nums[index] = val;
    }
};

int main() {
    vector<int> nums{2, 4, 1, 5, 3, 7};
    segmentTree s(nums);
    cout << s.queryMin(3, 5) << endl;
    s.update(4, -1);
    cout << s.queryMin(0, 5) << endl;
}