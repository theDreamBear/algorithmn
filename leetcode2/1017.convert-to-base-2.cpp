// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 * @lcpr version=30122
 *
 * [1017] 负二进制转换
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
    string baseNeg2_1(int n) {
        if (n == 0) {
            return "0";
        }
        string ans;
        while (n != 0) {
            if (n % -2 == 0) {
                ans.push_back('0');
            } else {
                ans.push_back('1');
                n -= 1;
            }
            n /= -2;
        }
        ranges::reverse(ans);
        return ans;
    }

    string baseNeg2(int n) {
        
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

