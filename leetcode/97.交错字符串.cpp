/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;


// @lc code=start
class Solution {
public:
    bool partCompare(const string& left, const string& right, int i, int j) {
        for (; i < left.size() && j < right.size(); ++i, ++j) {
            if (left[i] != right[j]) {
                return false;
            }
        }
        return i == left.size() && j == right.size();
    }

    vector<vector<int>> dp;
    bool dfs(const string& s1, const string& s2, const string& s3, int i, int j, int k) {
        if (i == s1.size() && j == s2.size()) {
            dp[i][j] = 1;
            return true;
        }
        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }
        if(i == s1.size()) {
            return dp[i][j] = partCompare(s2, s3, j, k);
        }
        if (j == s2.size()) {
            return dp[i][j] = partCompare(s1, s3, i, k);
        }
        if (s1[i] == s3[k] && dfs(s1, s2, s3, i + 1, j, k + 1)) {
            dp[i][j] = 1;
            return true;
        }
        if (s2[j] == s3[k] && dfs(s1, s2, s3, i, j + 1, k + 1)) {
            dp[i][j] = 1;
            return true;
        }
        dp[i][j] = 0;
        return false;
    }

    /*
        备忘录
    */
    bool isInterleave1(string s1, string s2, string s3) {
        // 边界
        // 长度必须相等
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, INT_MAX));

        return dfs(s1, s2, s3, 0, 0, 0);
    }

    /*
        循环记忆化搜索
        dp[i][j] 前 i, j
    */
    bool isInterleave(string s1, string s2, string s3) {
        // 边界
        // 长度必须相等
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<vector<bool>> dp2(s1.size() + 1, vector<bool>(s2.size() + 1));
        dp2[0][0] = 1;
        // 前 i 项
        for (int i = 0; i <= s1.size(); ++i) {
            // 前 j 项
            for (int j = 0; j <= s2.size(); ++j) {
                if (i > 0) {
                    dp2[i][j] = dp2[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                }
                if (j > 0) {
                    dp2[i][j] = dp2[i][j] | (dp2[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp2[s1.size()][s2.size()];
    }

    /*
        滚动数组
    */
    bool isInterleave2(string s1, string s2, string s3) {
        // 边界
        // 长度必须相等
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        int m = s1.size();
        int n = s2.size();
        const string* left = &s1;
        const string* right = &s2;
        if (m > n) {
            left = &s2;
            right = &s1;
        }
        vector<bool> dp2(left->size() + 1);
        dp2[0] = true;
        for (int i = 1; i <= left->size(); ++i) {
            dp2[i] = dp2[i - 1] && left->at(i - 1) == s3[i - 1];
        }
        bool update = true;
        for (int i = 1; i <= right->size(); ++i) {
            update = false;
            dp2[0] = dp2[0] && right->at(i - 1) == s3[i - 1];
            if (!update) {
                update = dp2[0];
            }
            for (int j = 1; j <= left->size(); ++j) {
                bool l = dp2[j - 1] && left->at(j - 1) == s3[i + j - 1];
                bool r = dp2[j] && right->at(i - 1) == s3[i + j - 1];
                dp2[j] = l || r;
                if (!update) {
                    update = dp2[j];
                }
            }
            if (!update) {
                break;
            }
        }
        return dp2.back();
    }
};
// @lc code=end

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";
    cout << Solution{}.isInterleave(s1, s2, s3);
}
