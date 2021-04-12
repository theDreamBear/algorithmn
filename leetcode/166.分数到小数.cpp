/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
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
     *  注意负数以及越界问题
     * */
    string fractionToDecimal(int numerator, int denominator) {
        // 可以整除
        if ((long long)numerator % denominator == 0) {
            return to_string((long long)(numerator) / denominator);
        }
        string sign = "";
        if ((numerator >> 31) != (denominator >> 31)) {
            sign = "-";
        }
        long long num = abs(numerator);
        long long denom = abs(denominator);
        string intPart = to_string(num / denom) + ".";
        long long left = num % denom;
        int i = 0;
        string fractionalPart;
        map<pair<int, int>, int> hash;
        while (left) {
            if (hash.count({left, denom}) > 0) {
                break;
            }
            hash[{left, denom}] = i;
            left *= 10;
            while (left < denom) {
                ++i;
                fractionalPart += "0";
                left *= 10;
            }
            int temp = left / denom;
            left = left % denom;
            fractionalPart += to_string(temp);
            ++i;
        }
        if (left) {
            fractionalPart.insert(fractionalPart.begin() + hash[{left, denom}], '(');
            fractionalPart.push_back(')');
        }
        return sign + intPart + fractionalPart;
    }
};
// @lc code=end


int main() {
    cout << Solution{}.fractionToDecimal(-2147483648, 1);
}