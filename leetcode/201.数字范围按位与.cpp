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
    */
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0x7fffffff;
        for (int i = 31; i >= 0; --i) {
            // ++j越界的问题
            for (int j = left; j <= right; ++j) {
                if ((j & (0x1 << i)) == 0) {
                    ans &= ~(0x1 << i);
                    break;
                }
                if (j == right) {
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    cout << Solution{}.rangeBitwiseAnd(2147483646, 0x7fffffff);
}
