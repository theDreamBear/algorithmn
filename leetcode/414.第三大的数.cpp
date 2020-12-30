/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
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

    int thirdMax(vector<int>& nums) {
        int s = INT_MIN;
        int m = s, b = s;
        bool ok = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == INT_MIN) {
                ok = true;
            }
            if (nums[i] > b) {
                swap(b, nums[i]);
            }
            if (nums[i] != b && nums[i] > m) {
                swap(m, nums[i]);
            }
            if (nums[i] != b && nums[i] != m && nums[i] > s) {
                swap(nums[i], s);
            }
        }
        if (s == INT_MIN) {
            return b;
        }
        return s;
    }

};
// @lc code=end

int main() {
    vector<int> x = {2,2,3};
    cout << Solution{}.thirdMax(x);
}