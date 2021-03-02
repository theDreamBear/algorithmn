/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
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
    bool inRec(const vector<pair<int, int>>& rec1, const vector<int>& rec2) {
        for (auto& p : rec1) {
            if (p.first > rec2[0] && p.first < rec2[2] && p.second > rec2[1] && p.second < rec2[3]) {
                return true;
            }
        }
        return false;
    }

    /*
        再做一便
    */
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            return false;
        }
        int x1 = max(rec1[0], rec2[0]);
        int y1 = max(rec1[1], rec2[1]);

        int x2 = min(rec1[2], rec2[2]);
        int y2 = min(rec1[3], rec2[3]);
        
        if (x1 < x2 && y1 < y2) {
            return true;
        }
        return false;
    }
};
// @lc code=end

