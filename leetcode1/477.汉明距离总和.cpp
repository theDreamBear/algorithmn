/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */

// @lc code=start
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int cz = 0;
            int co = 0;
            for (auto v : nums) {
                if ((v >> i) & 0x1) {
                    co++;
                } else {
                    cz++;
                }
            }
            ans += (co * cz);
        }
        return ans;
    }
};
// @lc code=end

