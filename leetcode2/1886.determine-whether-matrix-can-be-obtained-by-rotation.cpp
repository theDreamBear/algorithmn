/*
 * @lc app=leetcode.cn id=1886 lang=cpp
 * @lcpr version=30204
 *
 * [1886] 判断矩阵经轮转后是否一致
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
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        auto rotate = [&]() {
            int m = mat.size(), n = mat[0].size();
            vector<vector<int>> tmp = mat;
            for (int j = 0; j < n; j++) {
                for (int i = m - 1; i >= 0; i--) {
                    mat[j][m - i - 1] = tmp[i][j];
                }
            }
        };
        for (int i = 0; i < 4; i++) {
            if (mat == target) return true;
            rotate();
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[1,0]]\n[[1,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,1]]\n[[1,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,1,0],[1,1,1]]\n[[1,1,1],[0,1,0],[0,0,0]]\n
// @lcpr case=end

 */

