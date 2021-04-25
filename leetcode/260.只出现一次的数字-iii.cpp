/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
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
    vector<int> singleNumber(vector<int>& nums) {
        long long sum = 0;
        for (auto val : nums) {
            sum ^= val;
        }
        // int 的话 sum - 1 可能会越界
        sum = sum & ~(sum - 1);
        int left = 0, right = 0;
        for (auto val : nums) {
            if (val & sum) {
                left ^= val;
            } else {
                right ^= val;
            }
        }
        return {left, right};
    }
};
// @lc code=end

int main () {
    vector<int> data = {1,2,1,3,2,5};
    Solution{}.singleNumber(data);
}