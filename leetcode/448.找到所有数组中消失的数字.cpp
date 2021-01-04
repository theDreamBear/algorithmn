/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
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
    vector<int> findDisappearedNumbers_hash(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            hashMap[nums[i]] = 1;
        }
        for (int i = 1; i <= nums.size(); ++i) {
            if (hashMap.count(i) == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    vector<int> findDisappearedNumbers_sort(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int v = 1;
        for (int i  = 0; i < nums.size(); ) {
            if (nums[i] > v) {
                ans.push_back(v);
                ++v;
            } else {
                // skip 相同的
                while (i < nums.size() - 1 && nums[i + 1] == nums[i]) {
                    ++i;
                }
                ++i;
                ++v;
            }
        }
        for (int i = v; i <= nums.size(); ++i) {
            ans.push_back(i);
        }
        return ans;
    }

    /*
        遍历输入数组的每个元素一次。
        我们将把 |nums[i]|-1 索引位置的元素标记为负数。即
        nums[∣nums[i]∣−1]×−1 。
        然后遍历数组，若当前数组元素 nums[i] 为负数，说明我们在数组中存在数字 i+1。
        可以通过以下图片示例来帮助理解。
    */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] *= -1;
            }
        }
        for (int i = 1; i <= nums.size(); ++i) {
            if (nums[i - 1] > 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1, 1, 2, 2};
    Solution{}.findDisappearedNumbers(nums);
}

