/*
 * @lc app=leetcode.cn id=922 lang=cpp
 * @lcpr version=30204
 *
 * [922] 按奇偶排序数组 II
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII1(vector<int>& nums) {
        queue<int> odd, even;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                even.push(nums[i]);
            } else {
                odd.push(nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = even.front();
                even.pop();
            } else {
                nums[i] = odd.front();
                odd.pop();
            }
        }
        return nums;
    }

    vector<int> sortArrayByParityII(vector<int>& nums) {
        // i 奇数的下标
        // j 偶数的下标
        int i = 0, j = 0;
        for (int x = 0; x < nums.size(); x++) {
            if (nums[x] % 2 != x % 2) {
                // 需要偶数
                if (x % 2 == 0) {
                    while (j < x or (j < nums.size() and nums[j] % 2)) j++;
                    swap(nums[x], nums[j]);
                } else {
                    while (i < x or (i < nums.size() and nums[i] % 2 == 0)) i++;
                    swap(nums[x], nums[i]);
                }
            }
        }
        return nums;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n
// @lcpr case=end

 */

