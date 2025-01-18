/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 * @lcpr version=30204
 *
 * [1710] 卡车上的最大单元数
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        ranges::sort(boxTypes, {}, [&](auto box) {
            return - box[1];
        });
        int ans = 0;
        for (int i = 0; i < boxTypes.size() and truckSize; i++) {
            auto cnt = boxTypes[i][0], us = boxTypes[i][1];
            int cb = min(cnt, truckSize);
            ans += cb * us;
            truckSize -= cb;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,2],[3,1]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[5,10],[2,5],[4,7],[3,9]]\n10\n
// @lcpr case=end

 */

