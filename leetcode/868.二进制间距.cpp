/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
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
    int binaryGap1(int n) {
        int left = -1;
        int max_width = 0;
        for (int i = 0; i < 32; ++i) {
            int v = (n >> i) & 0x1;
            if (v) {
                if (left == -1) {
                    left = i;
                } else {
                    int width = i - left;
                    if (width > max_width) {
                        max_width = width;
                    }
                    left = i;
                }
            }
        }
        return max_width;
    }

    /*
        log 以 e 为底
    */
    int binaryGap(int n) {
        int max_width = 0;
        int last = n & (-n);
        n -= last;
        while (n) {
            int t = n & (-n);
            max_width = max(max_width, int(log10(t / last) / log10(2)));
            last = t;
            n -= t;
        }
        return max_width;
    }
};
// @lc code=end

