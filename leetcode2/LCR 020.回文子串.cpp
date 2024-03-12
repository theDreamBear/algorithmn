/*
 * @lc app=leetcode.cn id=LCR 020 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 020] 回文子串
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
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int low = i, high = i;
            while (low >= 0 and high < s.size() and s[low] == s[high]) {
                ++ans;
                low--;
                high++;
            }
            low = i - 1, high = i;
            while (low >= 0 and high < s.size() and s[low] == s[high]) {
                ++ans;
                low--;
                high++;
            }
        }
        return ans;
    }

    // 还有一个更统一的写法， 参照官网解法
    // 马拉车算法更快
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n
// @lcpr case=end

 */

