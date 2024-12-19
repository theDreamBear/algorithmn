/*
 * @lc app=leetcode.cn id=1854 lang=cpp
 * @lcpr version=30204
 *
 * [1854] 人口最多的年份
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> data(2500);
        for (auto& vec: logs) {
            int b = vec[0], d = vec[1];
            data[b]++, data[d]--;
        }
        int idx = 0, cnt = 0;
        int res = 0;
        for (int i = 0; i < data.size(); i++) {
            res += data[i];
            if (res > cnt) {
                cnt = res;
                idx = i;
            }
        }
        return idx;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1993,1999],[2000,2010]]\n
// @lcpr case=end

// @lcpr case=start
// [[1950,1961],[1960,1971],[1970,1981]]\n
// @lcpr case=end

 */

