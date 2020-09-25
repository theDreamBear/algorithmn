/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:

    int numTrees(int n) {
        if (n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        int G[n + 1];
        memset(G, 0, sizeof(int) * (n + 1));
        G[0] = 1;
        G[1] = 1;
        G[2] = 2;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j]; 
            }
        }
        return G[n];
    }
};
// @lc code=end

