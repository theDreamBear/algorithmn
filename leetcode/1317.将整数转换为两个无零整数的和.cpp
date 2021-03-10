/*
 * @lc app=leetcode.cn id=1317 lang=cpp
 *
 * [1317] 将整数转换为两个无零整数的和
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
    bool isNonZeroNumber(int val) {
        string str = to_string(val);
        for (char c : str) {
            if (c == '0') {
                return false;
            }
        }
        return true;
    }

    vector<int> getNoZeroIntegers1(int n) {
        for (int i = 1; i < n; ++i) {
            if ((to_string(i) + to_string(n - i)).find('0') == string::npos) {
                return {i, n - i};
            }
        }
        return {};
    }

    bool isNonZeroNumber2(int val) {
        while(val > 1) {
            int v = val % 10;
            if (v == 0) {
                return false;
            }
            val /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers2(int n) {
        for (int i = 1; i < n; ++i) {
            if (isNonZeroNumber2(i) && isNonZeroNumber2(n - i)) {
                return {i, n - i};
            }
        }
        return {};
    }

    /*
        若10 进制某一位不为 1 ,则随意1 , 若为 1 则取 2( 3其它也可以)
    */
    vector<int> getNoZeroIntegers(int n) {
        int x = n;
        int base = 1;
        int a = (n < 10) ? 1 : 0;
        while (x >= 0) {
            if (x < 10) {
                break;
            }
            int delta = (x % 10 == 1) ? 2 : 1;
            a += base * delta;
            x -= delta;
            x /= 10;
            base *= 10;
        }
        return {a, n - a};
    }
};
// @lc code=end

