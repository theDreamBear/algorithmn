/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30204
 *
 * [42] 接雨水
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
    int trap1(vector<int>& h) {
        // 单调递减栈
        // 左右第一个比自己大的
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() and h[st.top()] <= h[i]) {
                int j = st.top();
                st.pop();
                if (!st.empty()) {
                    int w = i - st.top() - 1;
                    ans += w * (min(h[st.top()], h[i]) - h[j]);
                }
            }
            st.push(i);
        }
        return ans;
    }

      // 错误
            // if (h[i] < rm) {
            //     ans += min(lm, rm) - h[i];
            //     i++;
            //     continue;
            // }
            // if (h[j] < lm) {
            //     ans += min(lm, rm) - h[j];
            //     j--;
            // }
    int trap(vector<int>& h) {
        int ans = 0;
        int lm = 0, rm = 0, n = h.size();
        for (int i = 0, j = n - 1; i <= j;) {
            lm = max(lm, h[i]);
            rm = max(rm, h[j]);
            if (lm <= rm) {
                ans += lm - h[i];
                i++;
            } else {
                ans += rm - h[j];
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */

