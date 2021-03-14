/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
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
    int calculate(string s) {
        stack<char> op;
        stack<int> num;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            if (!isdigit(s[i])) {
                op.push(s[i]);
                continue;
            }
            int val = s[i] - '0';
            int j = i + 1;
            while (j < s.size() && isdigit(s[j])) {
                val = 10 * val + (s[j] - '0');
                ++j;
            }
            num.push(val);
            i = j - 1;
        }
        if (op.empty()) {
            return num.top();
        }
        while (!num.empty()) {
            int right = num.top();
            num.pop();
            int left = num.top();
            num.pop();
            char opt = op.top();
            op.pop();
            int ans = 0;
            switch(opt) {
                case '+' : {
                    ans = left + right;
                    break;
                }
                case '-' : {
                    ans = left - right;
                    break;
                }
                case '*' : {
                    ans = left * right;
                    break;
                }
                case '/' : {
                    ans = left / right;
                    break;
                }
            }
            if (num.empty()) {
                return ans;
            }
            num.push(ans);
        }
        return -1;
    }
};
// @lc code=end

int main() {
    string s = "1-1+1";
    cout << Solution{}.calculate(s);
}
