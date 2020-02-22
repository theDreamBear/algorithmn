/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (39.62%)
 * Likes:    317
 * Dislikes: 0
 * Total Accepted:    37.9K
 * Total Submissions: 93.2K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 * 
 */
#include <vector>
#include <string>
using namespace std;  // NOLINT

// @lc code=start
class Solution {
 public:
    bool travelHelper(vector<vector<char>>& board, const string& word, int x, int y, int pos) {
        if (board[x][y] != word[pos]) {
            return false;
        }
        if (pos == word.size() - 1) {
            return true;
        }
        char c = board[x][y];
        board[x][y] = '.';
        for (int i = 0; i < 4; ++i) {
            int dx = x + directX[i];
            int dy = y + directY[i];
            if (dx < 0 || dx >= board.size() || dy < 0 || dy >= board[dx].size()) {
                continue;
            }
            if (board[dx][dy] != '.') {
                if (travelHelper(board, word, dx, dy, pos + 1)) {
                    return true;
                }
            }
        }
        board[x][y] = c;
        return false;
    }

    /**
     * 
     * 
     * **/
    bool existHelper(vector<vector<char>>& board, const string& word) {
        if (word.size() == 0) {
            return false;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (travelHelper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        return existHelper(board, word);
    }
    vector<int> directX{0, -1, 0, 1};
    vector<int> directY{-1, 0, 1, 0};
};
// @lc code=end

