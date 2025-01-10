/*
 * @lc app=leetcode.cn id=832 lang=cpp
 * @lcpr version=30204
 *
 * [832] 翻转图像
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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& vec: image) {
            ranges::reverse(vec);
            for (auto& ch: vec) {
                ch ^= 1;
            }
        }
        return image;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,0],[1,0,1],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]\n
// @lcpr case=end

 */

