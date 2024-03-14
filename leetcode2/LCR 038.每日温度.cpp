/*
 * @lc app=leetcode.cn id=LCR 038 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 038] 每日温度
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 寻找每个第一个大于的下标差
        int n = temperatures.size();

        vector<int> ans(n);
        stack<int> st;
        // [pos, n) 有序且单调递增区间

        st.push(n - 1);
        for (int i = n  - 2; i >= 0; i--) {
            while (!st.empty() and temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top() - i;
            } else {
                ans[i] = 0;
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */

