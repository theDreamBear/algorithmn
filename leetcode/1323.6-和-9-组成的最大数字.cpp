/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 *
 * [1323] 6 和 9 组成的最大数字
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
        翻转从左到右第一个6
    */
    int maximum69Number1 (int num) {
        string str = to_string(num);
        for (auto& c : str) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return atoi(str.c_str());
    }


    int maximum69Number2 (int num) {
        int last = -1;
        int n = num;
        int i = -1;
        while (n) {
            ++i;
            int val = n % 10;
            if (val == 6) {
                last = i;
            }
            n /= 10;
        }
        if (last == -1) {
            return num;
        }
        return num + 3 * pow(10, last);
    }

    int maximum69Number (int num) {
        stack<int> st;
        while (num) {
            int val = num % 10;
            st.push(val);
            num /= 10;
        }
        int ans = 0;
        bool found = false;
        while (!st.empty()) {
            int val = st.top();
            if (!found && val == 6) {
                val = 9;
                found = true;
            }
            ans =  ans * 10 + val;
            st.pop();
        }
        return ans;
    }
};
// @lc code=end
