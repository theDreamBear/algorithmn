/*
 * @lc app=leetcode.cn id=LCR 002 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 002] 二进制求和
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
    string addBinary(string a, string b) {
        int len = max(a.size(), b.size()) + 2;
        char buf[len];
        buf[len - 1] = '\0';
        int m = a.size(), n = b.size();
        int i = a.size() - 1, j = b.size() - 1, idx = len - 2;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int left = i >= 0 ? a[i] - '0' : 0;
            int right = j >= 0 ? b[j] - '0' : 0;
            buf[idx] = (left + right + carry) % 2 + '0';
            carry = (left + right + carry) >> 1;
            idx--;
            i--;
            j--;
        }
        buf[idx] = carry + '0';
        if (buf[0] == '0') {
            return buf + 1;
        }
        return buf;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "11"\n"10"\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n"1011"\n
// @lcpr case=end

 */

