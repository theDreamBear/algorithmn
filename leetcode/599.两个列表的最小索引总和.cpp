/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string, int> hash;
        for (int i = 0; i < list1.size(); ++i) {
            hash[list1[i]] += (i + 100000);
        }
        for (int i = 0; i < list2.size(); ++i) {
            if (hash.count(list2[i]) > 0) {
                hash[list2[i]] += (i - 100000);
            }
        }

        int min_index = INT_MAX;
        for (auto& kv : hash) {
            if (kv.second < min_index) {
                min_index = kv.second;
            }
        }
        for (auto& kv : hash) {
            if (kv.second == min_index) {
                ans.push_back(kv.first);
            }
        }
        return ans;
    }
};
// @lc code=end
