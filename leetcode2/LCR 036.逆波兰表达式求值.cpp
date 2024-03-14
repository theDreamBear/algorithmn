/*
 * @lc app=leetcode.cn id=LCR 036 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 036] 逆波兰表达式求值
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
    int evalRPN(vector<string>& tokens) {
        stack<int> num_st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*") {
                int right = num_st.top();
                num_st.pop();
                int left = num_st.top();
                num_st.pop();
                int res = 0;
                if (tokens[i] == "+") {
                    res = left + right;
                } else if (tokens[i] == "-") {
                    res = left - right;
                } else if (tokens[i] == "/") {
                    res = left / right;
                } else {
                    res = left * right;
                }
                num_st.push(res);
            } else {
                num_st.push(atoi(tokens[i].c_str()));
            }
        }
        return num_st.top();
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */

