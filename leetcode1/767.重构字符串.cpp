/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
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
    string reorganizeString(string s) {
        vector<int> alphaCount(26);
        int threshold = (s.size() + 1) >> 1;
        for (auto c : s) {
            if (++alphaCount[c - 'a'] > threshold) {
               return "";
            }
        }
        priority_queue<pair<int, char>> priorityQueue;
        for (int i = 0; i < 26; ++i) {
            if (alphaCount[i] > 0) {
                priorityQueue.push({alphaCount[i], i + 'a'});
            }
        }
        string ans;
        int preCount = 0;
        char preChar = '#';
        while (!priorityQueue.empty()) {
            auto [ct, c] = priorityQueue.top();
            priorityQueue.pop();
            ans.push_back(c);
            if (preCount > 0) {
                priorityQueue.push({preCount, preChar});
            }
            --ct;
            preCount = 0;
            if (ct > 0) {
                preCount = ct;
                preChar = c;
            }
        }
        if (preCount > 0) {
            return "";
        }
        return ans;
    }
};
// @lc code=end

