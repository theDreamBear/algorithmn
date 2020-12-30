/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
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

    string push(int leftVal, int rightVal) {
        string l = to_string(leftVal);
        if (leftVal == rightVal) {
            return l;
        }
        string r = to_string(rightVal);
        l += ("->" + r);
        return l;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) {
            return ans;
        }
        int left = 0, right = 0;
        while (right + 1 < nums.size()) {
            if (nums[right] + 1 == nums[right + 1]) {
                ++right;
            } else {
                ans.push_back(push(nums[left], nums[right]));
                ++right;
                left = right;
            }
        }
        if (left < nums.size()) {
            ans.push_back(push(nums[left], nums[right]));
        }
        return ans;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {0,2,3,4,6,8,9};
    auto ans = Solution{}.summaryRanges(nums);
    for (auto x : ans) {
        cout << x << endl;
    }
}

