/*
 * @lc app=leetcode.cn id=119 lang=cpp
 * @lcpr version=30204
 *
 * [119] 杨辉三角 II
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
    vector<int> getRow1(int r) {
        vector<vector<int>> f(2, vector<int>(r + 1));
        int ft = 0, st = 1;
        f[ft][0] = 1;
        for (int i = 1; i <= r; i++) {
            f[st][0] = f[st][i] = 1;
            for (int j = 1; j < i; j++) {
                f[st][j] = f[ft][j - 1] + f[ft][j];
            }
            swap(ft, st);
        }
        return f[ft];
    }

    vector<int> getRow(int r) {
        vector<int> f(r + 1, 0);
        f[0]=1;
        for (int i = 1; i <= r; i++) {
            for (int j = i; j > 0; j--) {
                f[j] += f[j-1];
            }
        }
        return f;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

