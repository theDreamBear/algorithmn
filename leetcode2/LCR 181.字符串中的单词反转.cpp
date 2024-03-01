/*
 * @lc app=leetcode.cn id=LCR 181 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 181] 字符串中的单词反转
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
    string reverseMessage1(string message) {
        for (int i = 0, j = message.size() - 1; i < j; i++, j--) {
            swap(message[i], message[j]);
        }
        // [0, r] 已经处理完的位置
        // 【left, r] 当前的区间
        // 【r + 1, i) 有问题的区间
        //  [i, n) 待处理区间
        int left = 0, r = -1;
        int space_cnt = 0;
        int alpha_cnt = 0;
        for (int i = 0; i < message.size(); i++) {
            if (alpha_cnt != 0 and space_cnt == 0 and message[i] == ' ' or message[i] != ' ') {
                if (message[i] == ' ') {
                    for (int m = left, n = r; m < n; m++, n--) {
                        swap(message[m], message[n]);
                    }
                    ++space_cnt;
                    left = r + 2;
                } else {
                    space_cnt = 0;
                    alpha_cnt = 1;
                }
                ++r;
                if (i != r) {
                    swap(message[i], message[r]);
                }
            }
        }
        while (r >= 0 and message[r] == ' ') {
            --r;
        }
        for (int m = left, n = r; m < n; m++, n--) {
            swap(message[m], message[n]);
        }
        message[r + 1] = '\0';
        return message.c_str();
    }

    string reverseMessage(string message) {
        int n = message.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world!  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */

