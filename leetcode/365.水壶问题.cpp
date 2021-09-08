/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution {
 public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x = gcd(jug1Capacity, jug2Capacity);
        if (targetCapacity % x != 0 || targetCapacity > jug1Capacity + jug2Capacity) {
            return false;
        }
        return true;
    }
};
// @lc code=end

