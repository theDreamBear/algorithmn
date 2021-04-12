/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
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
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> pq;
        for (auto val : nums) {
            pq.push_back(to_string(val));
        }
        sort(pq.begin(), pq.end(), [&](const string& back, const string& before) {
            return back + before > before + back;
        });
        if (!pq.empty() && pq[0] == "0") {
            return "0";
        }
        for(auto& str: pq) {
            ans += str;
        }
        return ans;
    }
};
// @lc code=end

