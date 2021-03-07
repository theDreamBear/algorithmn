/*
 * @lc app=leetcode.cn id=1033 lang=cpp
 *
 * [1033] 移动石子直到连续
 */
#include <ranges.h>
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
    vector<int> numMovesStones(int a, int b, int c) {
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
        if (a > b) {
            swap(a, b);
        }
        int ldiff = b - a - 1;
        int rdiff = c - b - 1;

        int ma = ldiff + rdiff;
        int mm = 0;
        if (ldiff > 0 && rdiff > 0) {
            if (min(ldiff, rdiff) == 1) {
                mm = 1;
            } else {
                mm = 2;
            }
        } else {
            if (ldiff > 0 || rdiff > 0) {
                mm = 1;
            } else {
                mm = 0;
            }
        }
        return {mm, ma};
    }
};
// @lc code=end

int main() {
    vector<int> arr = Solution{}.numMovesStones(4, 3, 2);
    for (auto c : arr) {
        cout << c << endl;
    }
}
