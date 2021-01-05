/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
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
    int hammingDistance_1(int x, int y) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int left = (x >> i) & 0x1;
            int right = (y >> i) & 0x1;
            if (left != right) {
                ++ans;
            }
        }
        return ans;
    }

    int hammingDistance_xor(int x, int y) {
        int ans = 0;
        x  ^= y;
        while (x) {
            ++ans;
            x &= (x - 1);
        }
        return ans;
    }

     int hammingDistance(int x, int y) {
        return bitset<32>(x ^ y).count();
    }

};
// @lc code=end

