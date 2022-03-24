/*
 * @lc app=leetcode.cn id=2011 lang=cpp
 *
 * [2011] 执行操作后的变量值
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
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto& str : operations) {
             if (str.find('+') != string::npos) {
                 ++ans;
             } else {
                 --ans;
             }
        }
        return ans;
    }
};
// @lc code=end

