/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
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
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> times(2001);
        vector<int> exist(1001);
        for (auto v : arr) {
            ++times[v + 1000];
        }
        for (auto v : times) {
            if (v != 0){
                if (exist[v] != 0) {
                    return false;
                }
                exist[v] = 1;
            }
        }
        return true;
    }
};
// @lc code=end

