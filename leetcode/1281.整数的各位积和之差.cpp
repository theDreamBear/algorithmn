/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
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
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while (n) {
            int val = n % 10;
            n /= 10;
            product *= val;
            sum += val;
        }
        return product - sum;
    }
};
// @lc code=end

