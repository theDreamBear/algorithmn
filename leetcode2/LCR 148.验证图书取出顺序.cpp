/*
 * @lc app=leetcode.cn id=LCR 148 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 148] 验证图书取出顺序
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
    bool validateBookSequences(vector<int>& putIn, vector<int>& takeOut) {
        stack<int> st;
        int j = 0;
        for (int i = 0; i < putIn.size(); i++) {
            st.push(putIn[i]);
            if (putIn[i] != takeOut[j]) {
                continue;
            }
            while (!st.empty() and st.top() == takeOut[j]) {
                st.pop();
                j++;
            }
        }
        return j == takeOut.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,7,8,9,10,11]\n[9,11,10,8,7,6]\n
// @lcpr case=end

// @lcpr case=start
// [6,7,8,9,10,11]\n[11,9,8,10,6,7]\n
// @lcpr case=end

 */

