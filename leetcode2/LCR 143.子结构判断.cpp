/*
 * @lc app=leetcode.cn id=LCR 143 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 143] 子结构判断
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructurePre(TreeNode* A, TreeNode* B) {
        if (NULL == B) {
            return true;
        }
        if (NULL == A or A->val != B->val) {
            return false;
        }
        return isSubStructurePre(A->left, B->left) and isSubStructurePre(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (NULL == A || NULL == B) {
            return false;
        }
        // 先序遍历
        if (A->val == B->val) {
            if (isSubStructurePre(A->left, B->left) and isSubStructurePre(A->right, B->right)) {
                return true;
            }
        }
        return isSubStructure(A->left, B) or isSubStructure(A->right, B);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,5]\n[6,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,6,7,1,8]\n[6,1]\n
// @lcpr case=end

 */

