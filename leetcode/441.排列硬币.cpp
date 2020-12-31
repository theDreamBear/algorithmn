/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
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
    int arrangeCoins(int n) {
        if (n <= 1) {
            return n;
        }
        long long low = 1, high = sqrt(INT64_MAX);
        while (low  + 1 < high) {
            long long mid = (low + high) / 2;
            if ((mid * mid + mid) / 2 < n) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if ((high * high + high) / 2 <= n) {
            return high;
        }
        return low;
    }
};
// @lc code=end

int main() {
    int n = 5;
    cout << Solution{}.arrangeCoins(n);
}
