/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */

#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
    /*
        算法设计:
        边界
        1. 右不空, 左空 需要添加左空括号
        2. 左不空,右空, 省略右空括号
        3. 左右不空, 递归
        4. 左右皆空, 忽略左右
        5. 为空, 直接返回

    */
    void tree2strHelper(TreeNode *t, string &result) {
        if (t == NULL) {
            return;
        }
        bool df = (result != "");
        if (t->left == NULL && t->right == NULL) {
            if (df) {
                result.push_back('(');
            }
            result += to_string(t->val);
            if (df) {
                result.push_back(')');
            }
            return;
        }
        if (t->left == NULL) {
            if (df) {
                result.push_back('(');
            }
            result += to_string(t->val);
            result += "()";
            tree2strHelper(t->right, result);
            if (df) {
                result.push_back(')');
            }
            return;
        }

        if (t->right == NULL) {
            if (df) {
                result.push_back('(');
            }
            result += to_string(t->val);
            tree2strHelper(t->left, result);
            if (df) {
                result.push_back(')');
            }
            return;
        }
        // 左右皆不空
        if (df) {
            result.push_back('(');
        }
        result += to_string(t->val);
        tree2strHelper(t->left, result);
        tree2strHelper(t->right, result);
        if (df) {
            result.push_back(')');
        }
        return;
    }

    string tree2str(TreeNode *t) {
        string result;
        tree2strHelper(t, result);
        return result;
    }
};
// @lc code=end
