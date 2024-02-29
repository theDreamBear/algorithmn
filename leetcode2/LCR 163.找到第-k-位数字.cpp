/*
 * @lc app=leetcode.cn id=LCR 163 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 163] 找到第 k 位数字
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
    int findKthNumber1(int k) {
        /*
        1. 10
        2. 9 * 10 * 2;
        3. 9 * 100 * 3;
        4. 9 * 1000 * 4;
        5. 9 * 10000 * 5;
        */
        if (k < 10) {
            return k;
        }
        int now = 10;
        long long preth = 9;
        int len = 2;
        long long len_max_cnt = 90;
        while (preth + len_max_cnt * len < k) {
            preth += len_max_cnt * len;
            len++;
            len_max_cnt *= 10;
            now *= 10;
        }
        int left = k - preth;

        // 👍这个地方的写法不错， 我真棒
        int cnt = (left - 1) / len;
        left = (left - 1) % len;
        return to_string(now + cnt)[left] - '0';
    }

    /*
        二分
    */
    int findKthNumber(int k) {
        /*
        1. 10
        2. 9 * 10 * 2;
        3. 9 * 100 * 3;
        4. 9 * 1000 * 4;
        5. 9 * 10000 * 5;
        */
        if (k < 10) {
            return k;
        }
        vector<long long> data = {10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
        vector<long long> preth = {10,190,2890,38890,488890,5888890,68888890,788888890,8888888890};
        auto pos = upper_bound(preth.begin(), preth.end(), k) - preth.begin() - 1;
        int value = data[pos];
        int pre = preth[pos] - 1;
        int len = pos + 2;
        int left = k - pre;
        int cnt = (left - 1) / len;
        left = (left - 1) % len;
        return to_string(value + cnt)[left] - '0';
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 12\n
// @lcpr case=end

 */

