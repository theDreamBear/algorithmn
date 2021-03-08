/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
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

    /*
        直接排序, 找到期望顺序,作比较即可
    */
    int heightChecker1(vector<int>& heights) {
        int ct = 0;
        vector<int> temp = heights;
        sort(temp.begin(), temp.end());
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != temp[i]) {
                ++ct;
            }
        }
        return ct;
    }

    /*
        计数排序
    */
    void CountSort(vector<int>& temp) {
        vector<int> bucket(101);
        for (auto v : temp) {
            bucket[v]++;
        }
        int i = 0, j = 0;
        while (j < temp.size()) {
            while (bucket[i] == 0) {
                ++i;
            }
            while (bucket[i] > 0) {
                temp[j++] = i;
                --bucket[i];
            }
        }
    }

    int heightChecker2(vector<int>& heights) {
        int ct = 0;
        vector<int> temp = heights;
        CountSort(temp);
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != temp[i]) {
                ++ct;
            }
        }
        return ct;
    }


    int heightChecker(vector<int>& heights) {
        int ct = 0;
        vector<int> bucket(101);
        for (auto v : heights) {
            bucket[v]++;
        }
        for (int i = 0, j = 0; i < bucket.size(); ++i) {
            while (bucket[i]-- > 0) {
                if (heights[j++] != i) {
                    ++ct;
                }
            }
        }
        return ct;
    }
};
// @lc code=end

