/*
 * @lc app=leetcode.cn id=2545 lang=cpp
 * @lcpr version=30204
 *
 * [2545] 根据第 K 场考试的分数排序
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
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        ranges::sort(score, {}, [&](auto& vec){
            return -vec[k];
        });
        return score;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[10,6,9,1],[7,5,11,2],[4,8,3,15]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[3,4],[5,6]]\n0\n
// @lcpr case=end

 */

