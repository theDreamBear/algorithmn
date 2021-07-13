/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * [1838] 最高频元素的频数
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
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
    bool valid(vector<long long> &suffix, vector<int> &data, int low, int high,
               int k) {
        long long diff = suffix[high + 1] - suffix[low];
        return (long long)(high - low + 1) * data[high] - diff <= k;
    }

    /*
        方案一
    */
    int maxFrequency1(vector<int> &data, int k) {
        sort(data.begin(), data.end());
        vector<long long> suffix(data.size() + 1);
        suffix[0] = 0;
        suffix[1] = data[0];
        for (int i = 1; i < (int)data.size(); ++i) {
            suffix[i + 1] = (suffix[i] + data[i]);
        }
        int low = 0, high = 0, ans = 0;
        while (high < (int)data.size()) {
            while (high < (int)data.size() &&
                   valid(suffix, data, low, high, k)) {
                if (high - low + 1 > ans) {
                    ans = high - low + 1;
                }
                ++high;
            }
            while (high < (int)data.size() && low < high &&
                   !valid(suffix, data, low, high, k)) {
                ++low;
            }
        }
        return ans;
    }

    int maxFrequency(vector<int> &data, int k) {
        sort(data.begin(), data.end());

        int low = 0, high = 0, ans = 0;
        return ans;
    }

};
// @lc code=end
