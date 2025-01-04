/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 * @lcpr version=30204
 *
 * [1261] 在受污染的二叉树中查找元素
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
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
class FindElements1 {
public:
TreeNode* root;
unordered_set<int> hash;

    FindElements1(TreeNode* root) {
        this->root = root;
        auto set = [&](auto&& set, TreeNode* node, int val = 0) {
            if (!node) return;
            node->val = val;
            hash.insert(val);
            set(set, node->left, val * 2 + 1);
            set(set, node->right, val * 2 + 2);
        };
        set(set, root, 0);
    }
    
    bool find(int target) {
        return hash.count(target);
    }
};

class FindElements {
public:
TreeNode* root;

    FindElements(TreeNode* root) {
        this->root = root;
    }
    
    bool find(int target) {
        target++;
        auto cur = root;
        for (int i = 30 - __builtin_clz(target); i >= 0 and cur; i--) {
            int bit = target >> i & 1;
            cur = bit ? cur->right: cur->left;
        }
        return cur != nullptr;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end



/*
// @lcpr case=start
// ["FindElements","find","find"][[[-1,null,-1]],[1],[2]]\n
// @lcpr case=end

// @lcpr case=start
// ["FindElements","find","find","find"][[[-1,-1,-1,-1,-1]],[1],[3],[5]]\n
// @lcpr case=end

// @lcpr case=start
// ["FindElements","find","find","find","find"][[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]\n
// @lcpr case=end

 */

