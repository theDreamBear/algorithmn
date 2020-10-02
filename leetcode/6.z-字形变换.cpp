// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
    string convert_bad(string s, int numRows) {
        if (numRows <= 1 || s.size() <= 1) {
            return s;
        }
        vector<vector<char>> temp(numRows, vector<char>(s.size(), 0));
        int idx = 0;
        int i = 0;
        int j = 0;
        temp[i][j] = s[idx++];
        ++i;
        while (idx < s.size()) {
            while (idx < s.size() && i < numRows) {
                temp[i++][j] = s[idx++];
            }
            --i;
            while (idx < s.size() && i >= 1) {
                temp[--i][++j] = s[idx++];
            }
            ++i;
        }
        string res;
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < s.size(); ++col) {
                if (temp[row][col] != 0) {
                    res.push_back(temp[row][col]);
                }
            }
        }
        return res;
    }

    string convert_2(string s, int numRows) {
        if (numRows <= 1 || s.size() <= 1) {
            return s;
        }
        string res = s;
        int total = 2 * numRows - 2;

        int idx = -1;
        for (int i = 0; i < numRows; ++i) {
            res[++idx] = s[i];
            int left = total - 2 * i;
            int right = 2 * i;
            for (int j = i; j < s.size();) {
                if (left > 0 && j + left < s.size()) {
                    res[++idx] = s[j + left];
                }
                j += left;

                if (right > 0 && j + right < s.size()) {
                    res[++idx] = s[j + right];
                }
                j += right;
            }
        }
        return res;
    }

    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};
// @lc code=end

int main() {
    string s = "PAYPALISHIRING";
    Solution{}.convert(s, 3);
}