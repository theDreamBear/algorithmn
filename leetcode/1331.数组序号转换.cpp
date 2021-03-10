/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
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
    vector<int> arrayRankTransform1(vector<int>& arr) {
        vector<int> ans(arr.size());
        if (arr.empty()) {
            ans;
        }
        auto temp = arr;
        sort (temp.begin(), temp.end());
        unordered_map<int, int> hash;
        int rank = 1;
        int pos = 0;
        for (int i = 0; i < temp.size(); ++i) {
            if (hash.count(temp[i]) == 0) {
                hash[temp[i]] = rank++;
            }
        }
        int i = 0;
        for (auto val : arr) {
            ans[i++] = hash[val];
        }
        return ans;
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans(arr.size());
        if (arr.empty()) {
            ans;
        }
        set<int> arrSet(arr.begin(), arr.end());
        unordered_map<int, int> hash;
        int rank = 1;
        for (auto val: arrSet) {
            hash[val] = rank++;
        }
        int i = 0;
        for (auto val : arr) {
            ans[i++] = hash[val];
        }
        return ans;
    }
};
// @lc code=end

