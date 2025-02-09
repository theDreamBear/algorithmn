/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30204
 *
 * [80] 删除有序数组中的重复项 II
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int removeDuplicates1(vector<int>& nums) {
        // [0, l) 之前的位置
        int l = 0;
        for (int i = 0; i < nums.size(); ) {
            int start = i++;
            while (i < nums.size() and nums[i] == nums[i - 1]) i++;
            nums[l++] = nums[start];
            if (start + 1 < i) {
                nums[l++] = nums[start];
            }
        }
        return l;
    }

    int removeDuplicates(vector<int>& nums) {
        // [0, l) 之前的位置
        int sz = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[sz - 2]) {
                nums[sz++] = nums[i];
            }
        }
        return min(sz, (int)nums.size());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */

