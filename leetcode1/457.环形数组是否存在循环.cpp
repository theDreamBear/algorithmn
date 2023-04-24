/*
 * @lc app=leetcode.cn id=457 lang=cpp
 *
 * [457] 环形数组是否存在循环
 */

// @lc code=start
class Solution1 {
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

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto next = [&](int cur) {
            return ((cur + nums[cur]) % n + n) % n; // 保证返回值在 [0,n) 中
        };
        for (int i = 0; i < n; i++) {
            if (!nums[i]) {
                continue;
            }
            // 快慢指针
            int slow = i, fast = next(i);
            // 判断非零且方向相同
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    } else {
                        break;
                    }
                }
                slow = next(slow);
                fast = next(next(fast));
            }
            int add = i;
            while (nums[add] * nums[next(add)] > 0) {
                int tmp = add;
                add = next(add);
                nums[tmp] = 0;
            }
            nums[add] = 0;
        }
        return false;
    }
};
// @lc code=end

