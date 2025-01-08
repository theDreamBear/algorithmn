/*
 * @lc app=leetcode.cn id=2264 lang=cpp
 * @lcpr version=30204
 *
 * [2264] 字符串中最大的 3 位相同数字
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
string ans;
    string largestGoodInteger1(string num) {
        string ans;
        for (int i = 2; i < num.size(); i++) {
            if (num[i] == num[i - 1] and num[i - 1] == num[i - 2]) {
                if (ans == "" or ans[0] < num[i]) {
                    ans = string(3, num[i]);
                }
            }
        }
        return ans;
    }

    string largestGoodInteger(string num) {
        //return num.size() < 3 ? ans: (num[0] == num[1] and num[1] == num[2] ? (ans == "" or ans < string(3, num[0]) ? (ans = string(3, num[0]), ans = largestGoodInteger(num.substr(1))): ans = largestGoodInteger(num.substr(1))): ans = largestGoodInteger(num.substr(1)));
        return num.size() < 3 ? "" : (num[0] == num[1] && num[1] == num[2] ? max(string(3, num[0]), largestGoodInteger(num.substr(1))) : largestGoodInteger(num.substr(1))); 
    }
};
// @lc code=end



/*
// @lcpr case=start
// "6777133339"\n
// @lcpr case=end



// @lcpr case=start
// "2300019"\n
// @lcpr case=end

// @lcpr case=start
// "42352338"\n
// @lcpr case=end

 */



