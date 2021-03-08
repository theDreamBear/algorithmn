/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
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
    string defangIPaddr(string address) {
        string ans;
        for (int i = 0; i < address.size(); ++i) {
            if (address[i] != '.') {
                ans.push_back(address[i]);
            } else {
                ans.push_back('[');
                ans.push_back('.');
                ans.push_back(']');
            }
        }
        return ans;
    }
};
// @lc code=end

