/*
 * @lc app=leetcode.cn id=845 lang=cpp
 * @lcpr version=30204
 *
 * [845] 数组中的最长山脉
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
    int longestMountain1(vector<int>& arr) {
        // i结尾的递增长度
        // j开头的递减长度
        int n = arr.size();
        vector<int> pre(n, 1), suf(n, 1);
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) pre[i] = pre[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) suf[i] = suf[i + 1] + 1;
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (pre[i] > 1 and suf[i] > 1) {
                ans = max(ans, pre[i] + suf[i] - 1);
            }
        }
        return ans;
    }

    int longestMountain(vector<int>& arr) {
        // i结尾的递增长度
        // j开头的递减长度
        int n = arr.size();
        vector<int> suf(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) suf[i] = suf[i + 1] + 1;
        }
        int ans = 0;
        int pp = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                pp++;
            } else {
                pp = 0;
            }
            if (pp > 0 and suf[i] > 1) {
                ans = max(ans, pp + suf[i]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,4,7,3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n
// @lcpr case=end

 */

