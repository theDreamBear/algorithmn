/*
 * @lc app=leetcode.cn id=907 lang=cpp
 * @lcpr version=30204
 *
 * [907] 子数组的最小值之和
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
    int sumSubarrayMins(vector<int>& arr) {
        // 找到第一个比自己<
        //单调递增栈
        vector<long long> st, cnt;
        long long ans = 0;
        int mod = 1e9 + 7;
        auto cal = [&]() {
            for (long long i = 0; i < arr.size(); i++) {
                while (!st.empty() and arr[st.back()] > arr[i]) {
                    ans = (ans +  (i - st.back()) * arr[st.back()] * cnt.back()) % mod;
                    st.pop_back();
                    cnt.pop_back();
                }
                int len = i + 1;
                if (!st.empty()) {
                    len = i - st.back();
                }
                cnt.push_back(len);
                st.push_back(i);
            }
            while(!st.empty()) {
                ans = (ans + arr[st.back()] * (arr.size() - st.back()) * cnt.back()) % mod;
                st.pop_back();
                cnt.pop_back();
            }
        };
        cal();
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [11,81,94,43,3]\n
// @lcpr case=end

 */

