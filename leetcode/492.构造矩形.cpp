/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
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
    逆序找更快
    */
   int getWidth(int n) {
        int i = sqrt(n);
        for (; i >= 1; --i) {
            if (n % i == 0) {
                return i;
            }
        }
        return 1;
    }

    vector<int> constructRectangle(int area) {
        int w = getWidth(area);
        int l = area / w;
        return {l, w};
    }
};
// @lc code=end

