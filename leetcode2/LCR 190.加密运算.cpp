/*
 * @lc app=leetcode.cn id=LCR 190 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 190] 加密运算
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
    /*
        不能使用+ - * /
    */
    int encryptionCalculate(int dataA, int dataB) {
        while (dataB) {
            int tmp = dataA ^ dataB;
            dataB = (dataB & dataA) << 1;
            dataA = tmp;
        }
        return dataA;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n-1\n
// @lcpr case=end

 */

