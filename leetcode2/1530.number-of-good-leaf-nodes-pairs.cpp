/*
 * @lc app=leetcode.cn id=1530 lang=cpp
 * @lcpr version=30204
 *
 * [1530] 好叶子节点对的数量
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
#include <map>
#include <set>
#include <string>
#include <string.h>
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
class Solution {
public:
    #define SIZE 10
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        auto post = [&](this auto&& dfs, TreeNode* node)->array<int, 10> {
            if (!node) {
                return {};
            }
            if (!node->left and !node->right) {
                return array<int, 10>{1};
            }
            auto l = dfs(node->left);
            auto r = dfs(node->right);
            for (int i = 0; i <= distance - 2; i++) {
                if (l[i] != 0) {
                    for (int j = 0; j <= distance - 2 - i; j++) {
                        ans += l[i] * r[j];
                    }
                }
            }
            for (int i = SIZE - 1; i > 0; i--) {
                l[i] = l[i - 1] + r[i - 1];
            }
            l[0] = 0;
            return l;
        };
        post(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [7,1,4,6,null,5,3,null,null,null,null,null,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [100]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

 */

