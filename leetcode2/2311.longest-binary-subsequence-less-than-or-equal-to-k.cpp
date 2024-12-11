/*
 * @lc app=leetcode.cn id=2311 lang=cpp
 * @lcpr version=30204
 *
 * [2311] 小于等于 K 的最长二进制子序列
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
    // 子序列, 所以错了
    int longestSubsequence1(string s, int k) {
        // 连续区间, 滑动窗口
        int ans = 0;
        int v = 0;
        double pow = 1;
        for (int left = 0, right = 0; right < s.size(); right++) {
            v = v * 2 + (s[right] - '0');
            pow *= 2;
            while (v > k) {
                pow /= 2;
                v -= (s[left++] - '0') * pow;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1001010"\n5\n
// @lcpr case=end

// @lcpr case=start
// "00101001"\n1\n
// @lcpr case=end

 */

