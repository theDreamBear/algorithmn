/*
 * @lc app=leetcode.cn id=1791 lang=cpp
 * @lcpr version=30114
 *
 * [1791] 找出星型图的中心节点
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
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> degree(n + 2);
        for (auto& vec : edges) {
            int v = vec[0];
            int w = vec[1];
            if (++degree[v] > 1) {
                return v;
            }
            if (++degree[w] > 1) {
                return w;
            }
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,3],[4,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[5,1],[1,3],[1,4]]\n
// @lcpr case=end

 */

