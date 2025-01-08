/*
 * @lc app=leetcode.cn id=面试题 08.04 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 08.04] 幂集
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> tmp;
            //bool ok = true;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    // if (tmp.contains(nums[j])) {
                    //     ok = false;
                    //     goto end;
                    // } else {
                        tmp.push_back(nums[j]);
                    // }
                } 
            }
            // end:
            // if (ok) {
            //    vector<int> res(tmp.begin(), tmp.end());
                ans.push_back(tmp);
            //}
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

