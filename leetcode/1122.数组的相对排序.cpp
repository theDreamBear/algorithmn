/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
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
    /*
        官方很多解法都很有趣
        pair 方法很好
        i - n的方法也不错
        计数排序也不错
    */
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> hash(1001, -1);
        for (int i = 0; i < arr2.size(); ++i) {
            hash[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int last, int before) {
            if (hash[last] != -1 && hash[before] != -1) {
                return hash[last] < hash[before];
            }
            if (hash[last] != -1) {
                return true;
            }
            if (hash[before] != -1) {
                return false;
            }
            return last < before;
        });
        return arr1;
    }
};
// @lc code=end

