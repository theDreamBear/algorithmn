/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
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

using namespace std;

// @lc code=start
class Solution {
public:
    string t3 = "Fizz";
    string t5 = "Buzz";
    string t15 = "FizzBuzz";

    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                ans.push_back(t15);
                continue;
            }
            if (i % 3 == 0) {
                ans.push_back(t3);
                continue;
            }
            if (i % 5 == 0) {
                ans.push_back(t5);
                continue;
            }
            ans.push_back(to_string(i));
        }
        return ans;
    }
};
// @lc code=end

