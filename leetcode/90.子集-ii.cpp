/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
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
#include<climits>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    void subsetsWithDupHelper1(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int pos, int last) {
        if (pos >= nums.size()) {
            ans.emplace_back(temp);
            return;
        }
        temp.push_back(nums[pos]);
        subsetsWithDupHelper1(ans, temp, nums, pos + 1, nums[pos]);
        temp.pop_back();
        /**
         *      5 5
         *      5 *  跳过这种情况
         *      * 5
        */
        if (last != nums[pos]) {
            subsetsWithDupHelper1(ans, temp, nums, pos + 1, last);
        }

    }

    vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        subsetsWithDupHelper1(ans, temp, nums, 0, INT_MAX);
        return ans;
    }

    void subsetsWithDupHelper(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int pos) {
        ans.emplace_back(temp);
        if (pos >= nums.size()) {
            return;
        }
        /**
         *   忽略当前
        */
        // 下面是错误的处理
        //subsetsWithDupHelper(ans, temp, nums, pos + 1);
        for (int i = pos; i < nums.size(); ++i) {
            if (i != pos && nums[i] == nums[i- 1]) {
                continue;
            }
            temp.push_back(nums[i]);
            // 选择
            subsetsWithDupHelper(ans, temp, nums, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        subsetsWithDupHelper(ans, temp, nums, 0);
        return ans;
    }
};

// @lc code=end

int main() {
    vector<int> data = {1, 2, 2};
    Solution{}.subsetsWithDup(data);
}
