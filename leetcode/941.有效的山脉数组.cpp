/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
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

using namespace std;

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }

        int i = 0, j = arr.size() - 1;
        while (i < j && arr[i] < arr[i + 1]) {
            ++i;
        }

        while (i < j && arr[j] < arr[j - 1]) {
            --j;
        }

        return i == j && i != 0 && i != arr.size() - 1;
    }
};
// @lc code=end

