/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30204
 *
 * [654] 最大二叉树
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
class ST {
public:
    const vector<int>& data;
    vector<vector<int>> index;

    ST(const vector<int>& data):data(data) {
        int n = data.size();
        int d = log2(n);
        index.resize(n, vector<int>(d + 1));
        for (int i = 0; i < n; i++) {
            index[i][0] = i;
        }
        for (int k = 1; k <= d; k++) {
            for (int i = 0; i < n; i++) {
                index[i][k] = index[i][k - 1];
                int t = i + (1 << (k - 1));
                if (t < n  and data[index[i][k]] < data[index[t][k - 1]]) {
                    index[i][k] = index[t][k - 1];
                }
            }
        }
    }

    int queryIndex(int l, int r) {
        int d = log2(r - l + 1);
        int li = index[l][d];
        int ri = index[r - (1 << d) + 1][d];
        return data[li] > data[ri] ? li : ri;
    }
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree1(vector<int>& nums) {
        ST st(nums);

        auto build = [&](this auto&& dfs, int l, int r)->TreeNode* {
            if (l > r) return nullptr;
            int mid = st.queryIndex(l, r);
            return new TreeNode(nums[mid], dfs(l, mid - 1), dfs(mid + 1, r));
        };
        return build(0, nums.size() - 1);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        vector<TreeNode*> nodes(n);
        // 找左, 右第一个比自己大的
        vector<int> left(n, -1), right(n, -1);
        vector<int> st;

        // left 单减栈
        for (int i = 0; i < n; i++) {
            nodes[i] = new TreeNode(nums[i]);
            while (!st.empty() and nums[st.back()] < nums[i]) {
                right[st.back()] = i;
                st.pop_back();
            }
            if (!st.empty()) {
                left[i] = st.back();
            }
            st.push_back(i);
        }
        TreeNode* root = nullptr;
        for (int i = 0; i < n; i++) {
            if (left[i] == -1 and right[i] == -1) {
                root = nodes[i];
                continue;
            }
            if (right[i] == -1 or (left[i] != -1 and nums[left[i]] < nums[right[i]])) {
                nodes[left[i]]->right = nodes[i];
            } else {
                nodes[right[i]]->left = nodes[i];
            }
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */

