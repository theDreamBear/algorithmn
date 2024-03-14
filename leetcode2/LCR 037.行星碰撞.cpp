/*
 * @lc app=leetcode.cn id=LCR 037 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 037] 行星碰撞
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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++) {
            if (ans.empty() || ans.back() < 0 and asteroids[i] > 0 || ans.back() * asteroids[i] > 0) {
                ans.push_back(asteroids[i]);
                continue;
            }
            bool flag = true;
            while (!ans.empty() and ans.back() > 0 and asteroids[i] < 0) {
                if (ans.back() > abs(asteroids[i])) {
                    // 直接销毁i
                    flag = false;
                    break;
                }
                if (ans.back() == abs(asteroids[i])) {
                    // 两败俱伤
                    flag = false;
                    ans.pop_back();
                    break;
                }
                ans.pop_back();
            }
            if (flag) {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,10,-5]\n
// @lcpr case=end

// @lcpr case=start
// [8,-8]\n
// @lcpr case=end

// @lcpr case=start
// [10,2,-5]\n
// @lcpr case=end

// @lcpr case=start
// [-2,-1,1,2]\n
// @lcpr case=end

 */

