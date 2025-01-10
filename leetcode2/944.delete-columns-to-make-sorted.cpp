/*
 * @lc app=leetcode.cn id=944 lang=cpp
 * @lcpr version=30204
 *
 * [944] 删列造序
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
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int m = strs.size(), n = strs[0].size();
        for (int j = 0; j < n; j++) {
            int pre = 0;
            for (int i = 0; i < m; i++) {
                if (strs[i][j] < pre) {
                    ans++;
                    break;
                } else {
                    pre = strs[i][j];
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["cba","daf","ghi"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","b"]\n
// @lcpr case=end

// @lcpr case=start
// ["zyx","wvu","tsr"]\n
// @lcpr case=end

 */

