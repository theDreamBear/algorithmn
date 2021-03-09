/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
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
    const char* ball = "ablloon";
    int maxNumberOfBalloons1(string text) {
        vector<int> hash(26);
        for (auto c : text) {
            hash[c - 'a']++;
        }
        int ct = 0;
        bool ok = true;
        while (ok) {
            for (int i = 0; i < 7 && ok; ++i) {
                if (--hash[ball[i] - 'a'] < 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ++ct;
            }
        }
        return ct;
    }


    /*
        min(initializer_list) min 参数可以是initializer_list
    */
    int maxNumberOfBalloons(string text) {
        vector<int> hash(26);
        for (auto c : text) {
            hash[c - 'a']++;
        }
        return min({hash['a' - 'a'], hash['b' - 'a'], hash['l' - 'a'] / 2, hash['o' - 'a'] / 2, hash['n' - 'a']});
    }
};
// @lc code=end

