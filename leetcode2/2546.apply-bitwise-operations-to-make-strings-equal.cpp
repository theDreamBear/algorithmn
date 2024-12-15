/*
 * @lc app=leetcode.cn id=2546 lang=cpp
 * @lcpr version=30204
 *
 * [2546] 执行逐位运算使字符串相等
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
    bool makeStringsEqual1(string s, string target) {
        // 1 1 => 1, 0, 0 1
        // 0 1 => 1, 1 => 1 0
        // 1 0 => 1 1

        // 0 1 <=> 1, 1 <=> 1 0
        //int ones = 0, zeros = 0;
        //  1 1 1=? 10 1 1 1 0 1 0 0
        // 
        return s == target or (ranges::count(s, '1') and ranges::count(target, '1'));
    }

    bool makeStringsEqual(string s, string target) {
        // 1 1 => 1, 0, 0 1
        // 0 1 => 1, 1 => 1 0
        // 1 0 => 1 1

        // 0 1 <=> 1, 1 <=> 1 0
        //int ones = 0, zeros = 0;
        //  1 1 1=? 10 1 1 1 0 1 0 0
        // 
        return (s.find('1') != string::npos)  == (target.find('1') != string::npos); 
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1010"\n"0110"\n
// @lcpr case=end

// @lcpr case=start
// "11"\n"00"\n
// @lcpr case=end

 */

