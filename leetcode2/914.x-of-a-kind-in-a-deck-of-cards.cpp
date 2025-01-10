/*
 * @lc app=leetcode.cn id=914 lang=cpp
 * @lcpr version=30204
 *
 * [914] 卡牌分组
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
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (auto v: deck) freq[v]++;
        int g = 0;
        for (auto& [_, v]: freq) {
            g = gcd(g, v);
        }
        return g > 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,2,2,3,3]\n
// @lcpr case=end

 */

