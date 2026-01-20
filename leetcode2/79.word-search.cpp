/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30204
 *
 * [79] 单词搜索
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
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        auto find = [&](int x, int y) {
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            auto dfs = [&](auto&& dfs, int i, int j, int z) {
                if (z >= word.size()) {
                    return true;
                }
                if (board[i][j] != word[z]) {
                    return false;
                }
                // 最后一个也匹配成功了
                if (z + 1 == word.size()) {
                    return true;
                }
                // 标记并存储
                char tmp = board[i][j];
                board[i][j] = '.';
                // 递归查找
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 and ni < board.size() and nj >= 0 and nj < board[ni].size() and board[ni][nj] == word[z + 1] and dfs(dfs, ni, nj, z + 1)) {
                        return true;
                    }
                }
                board[i][j] = tmp;
                return false;
            };
            return dfs(dfs, x, y, 0);
        };
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0] and find(i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCB"\n
// @lcpr case=end

 */

