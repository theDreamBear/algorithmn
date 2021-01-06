/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
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

using namespace std;

// @lc code=start
class Solution {
public:
    int findComplement_1(int num) {
        bool start = false;
        for (int i = 31; i >= 0; --i) {
            if (start) {
                num ^= (0x1 << i);
            } else {
                if ((num >> i) &0x1) {
                    start = true;
                    num ^= (0x1 << i);
                }
            }
        }
        return num;
    }

    /*
        补数 + 源数 + 1 = ****
    */
    int findComplement(int num) {
        long long temp = num;
        while (temp & (temp -1)) {
            temp &= (temp - 1);
        }
        return ((temp << 1) - 1) ^ num;
    }
};
// @lc code=end

int main() {
    cout << Solution{}.findComplement(5);
}

