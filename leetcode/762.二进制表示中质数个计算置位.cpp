/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    int oneNumber(int val) {
        if (val == 0) {
            return 0;
        }
        int times = 0;
        while (val) {
            ++times;
            val &= (val - 1);
        }
        return times;
    }

    void prime(unordered_set<int>& hashset) {
        vector<int> h(21, 1);
        for (int i = 2; i < 21; ++i) {
            if (h[i]) {
                hashset.insert(i);
                int j = 2 * i;
                while (j < 21) {
                    h[j] = 0;
                    j += i;
                }
            }
        }
    }

    int countPrimeSetBits1(int L, int R) {
        unordered_set<int> hashset;
        prime(hashset);
        int ans = 0;
        for (int i = L; i <= R; ++i) {
            if (hashset.count(oneNumber(i)) > 0) {
                ++ans;
            }
        }
        return ans;
    }

    /*
        直接枚举
    */
    char hashmap[20];
    int countPrimeSetBits(int L, int R) {
        fill(hashmap, hashmap + 20, 0);
        hashmap[2] = 1;
        hashmap[3] = 1;
        hashmap[5] = 1;
        hashmap[7] = 1;
        hashmap[11] = 1;
        hashmap[13] = 1;
        hashmap[17] = 1;
        hashmap[19] = 1;
        int ans = 0;
        for (int i = L; i <= R; ++i) {
            if (hashmap[oneNumber(i)] == 1) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end
