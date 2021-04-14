/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
        暴力法, 最后一个用例超时
    */
    int rangeBitwiseAnd1(int left, int right) {
        int ans = 0x7fffffff;
        for (int i = left; i <= right; ++i) {
            ans &= i;
            if (ans == 0 || i == right) {
                break;
            }
        }
        return ans;
    }

    /*
        每一位处理, 对于高位可能会循环好久
        同样最后一个测试用例超时
    */
    int rangeBitwiseAnd2(int left, int right) {
        int ans = 0x7fffffff;
        int temp = 0;
        for (int i = 0; i <= 31; ++i) {
            if (i > 0) {
                temp |= (0x1 << (i - 1));
            }
            // ++j越界的问题
            for (int j = left; j <= right; ++j) {
                if ((j & (0x1 << i)) == 0) {
                    ans &= ~(0x1 << i);
                    break;
                } else if ((left | temp ) >= right) {
                    break;
                }
                if (j == right) {
                    break;
                }
            }
        }
        return ans;
    }

    /*
        寻找公共前缀
    */
    int rangeBitwiseAnd3(int left, int right) {
        while (left < right) {
            right &= (right - 1);
        }
        return right;
    }

    /*
        逐个消除右边非前缀
    */
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left << shift;
    }
};
// @lc code=end

int main() {
    cout << Solution{}.rangeBitwiseAnd(8, 15);
}
