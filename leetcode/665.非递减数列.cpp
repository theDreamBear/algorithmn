/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
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
    bool checkPossibility(vector<int>& nums) {
        int bt = 0;
        for (int i = 1; i< nums.size() - 1; ++i) {
            // 递减
            if (nums[i] > nums[i + 1]) {
                ++bt;
                
                if (bt > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {4, 2, 1};

}
