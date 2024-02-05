/*
 * @lc app=leetcode.cn id=LCR 073 lang=cpp
 * @lcpr version=30115
 *
 * [LCR 073] 爱吃香蕉的狒狒
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
    bool can(vector<int>& piles, int k, int h) {
        int t = 0;
        for (auto n : piles) {
            t += ceil(n * 1.0 / k);
            if (t > h) {
                return false;
            }
        }
        return t <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9;
        while (low + 1 < high) {
            int mid = (high - low) / 2 + low;
            if (can(piles, mid, h)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (can(piles, low, h)) {
            return low;
        }
        return high;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */

