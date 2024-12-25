/*
 * @lc app=leetcode.cn id=2843 lang=cpp
 * @lcpr version=30204
 *
 * [2843] 统计对称整数的数目
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
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int v = low; v <= high; v++) {
            auto s = to_string(v);
            if (s.size() % 2 != 0) {
                continue;
            }
            int diff = 0;
            for (int i = 0, j = s.size() / 2, mid = j; i < mid; i++, j++) {
                diff += (s[i] - s[j]);
            }
            if (diff == 0) ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n100\n
// @lcpr case=end

// @lcpr case=start
// 1200\n1230\n
// @lcpr case=end

 */

