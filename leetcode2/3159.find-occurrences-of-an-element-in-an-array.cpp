/*
 * @lc app=leetcode.cn id=3159 lang=cpp
 * @lcpr version=30204
 *
 * [3159] 查询数组中元素的出现位置
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
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                pos.push_back(i);
            }
        }
        vector<int> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i] <= pos.size()) {
                ans[i] = pos[queries[i] - 1];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,1,7]\n[1,3,2,4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[10]\n5\n
// @lcpr case=end

 */

