/*
 * @lc app=leetcode.cn id=3507 lang=cpp
 * @lcpr version=30204
 *
 * [3507] 移除最小数对使数组有序 I
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
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        for(;;) {
            bool sorted = true;
            for (int i = 0; i + 1 < nums.size(); i++) {
                if (nums[i] > nums[i + 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted or nums.size() == 1) {
                break;
            }
            // 查找最小的
            int x = 0, sum = nums[0] + nums[1];
            for (int j = 1; j + 1 < nums.size(); j++) {
                if (nums[j] + nums[j + 1] < sum) {
                    x = j;
                    sum = nums[j] + nums[j + 1];
                }
            }
            nums[x] = sum;
            // 全部右移
            for (int j = x + 2; j < nums.size(); j++) {
                nums[j - 1] = nums[j];
            }
            nums.pop_back();
            ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */

