/*
 * @lc app=leetcode.cn id=2611 lang=cpp
 * @lcpr version=30204
 *
 * [2611] 老鼠和奶酪
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
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        ranges::sort(idx, [&](int l, int r) {
            return reward1[l] - reward2[l] > reward1[r] - reward2[r];
        });
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += (reward1[idx[i]] - reward2[idx[i]]);
        }
        return ans + reduce(reward2.begin(), reward2.end(), 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,3,4]\n[4,4,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n[1,1]\n2\n
// @lcpr case=end

 */

