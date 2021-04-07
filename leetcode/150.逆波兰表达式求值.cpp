/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        for (auto& str : tokens) {
            if (isdigit(str[0]) || (str.size() > 1 && str[0] == '-')) {
                nums.push_back(stod(str));
            } else {
                char c = str[0];
                int right = nums.back();
                nums.pop_back();
                int left = nums.back();
                nums.pop_back();
                switch(c) {
                    case '+' : {
                        nums.push_back(left + right);
                        break;
                    }
                    case '-' : {
                        nums.push_back(left - right);
                        break;
                    }
                    case '*' : {
                        nums.push_back(left * right);
                        break;
                    }
                    case '/' : {
                        nums.push_back(left / right);
                        break;
                    }
                }
            }
        }
        return nums.back();
    }
};
// @lc code=end

