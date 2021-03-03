/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
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
#include <sstream>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        stringstream ss(A);
        vector<string> ans;
        unordered_map<string, int> word_times;
        string temp;
        while (ss >> temp) {
            ++word_times[temp];
        }
        // ss.clear();
        // ss.str("");

        stringstream s(B);
        while (s >> temp) {
            ++word_times[temp];
        }
        for (auto& kv : word_times) {
            if (kv.second == 1) {
                ans.push_back(kv.first);
            }
        }
        return ans;
    }
};
// @lc code=end

