/*
 * @lc app=leetcode.cn id=457 lang=cpp
 *
 * [457] 环形数组是否存在循环
 */

// @lc code=start
class Solution {
public:
    bool sameSign(int sign, int other) {
        return ((sign >> 31) & 0x1) == ((other >> 31) & 0x1);
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return false;
        }
        int root[n];
        for (int i = 0; i < nums.size(); i++) {
            memset(root, 0, sizeof(int) * n);
            int p = i;
            bool found = true;
            int sign = nums[p];
            int sz = 0;
            while (!root[p]) {
                sz++;
                root[p] = i + 1;
                if (!sameSign(sign, nums[p])) {
                    found = false;
                    break;
                }
                p += nums[p];
                while (p < 0 || p >= n) {
                    p = (p + n) % n;
                }
            }
            if (root[p] != p + 1) {
                continue;
            }
            if (found && sz > 1) {
                return true;
            }
        }
        return false;
    }
};

// 快慢指针
// @lc code=end

