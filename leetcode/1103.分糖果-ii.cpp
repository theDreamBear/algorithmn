/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
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
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int i = 0, j = 1;
        while (candies > 0) {
            if (candies >= j) {
                ans[i] += j;
                candies -= j;
            } else {
                ans[i] += candies;
                break;
            }
            ++i;
            ++j;
            if (i == num_people) {
                i = 0;
            }
        }
        return ans;
    }
};
// @lc code=end

