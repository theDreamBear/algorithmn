/*
 * @lc app=leetcode.cn id=3285 lang=cpp
 * @lcpr version=30204
 *
 * [3285] 找到稳定山的下标
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
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for (int i = 1; i < height.size(); i++) {
            if (height[i - 1] > threshold) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [10,1,10,1,10]\n3\n
// @lcpr case=end

// @lcpr case=start
// [10,1,10,1,10]\n10\n
// @lcpr case=end

 */

