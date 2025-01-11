/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 * @lcpr version=30204
 *
 * [1299] 将每个元素替换为右侧最大元素
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
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        ans[n - 1] = -1;
        int ma = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = ma;
            ma = max(ma, arr[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [17,18,5,4,6,1]\n
// @lcpr case=end

// @lcpr case=start
// [400]\n
// @lcpr case=end

 */

