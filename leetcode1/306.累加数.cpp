/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

// @lc code=start
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) {
            return false;
        }
        function<bool(int, long long, long long, int)> backtrack = [&](int pos, long long pre, long long prepre,
                                                                        int count) -> int {
            if (pos >= num.size()) {
                return count > 2;
            }
            for (int i = pos; i < num.size() && i - pos <= 17; i++) {
                // 前导0
                if (i > pos && num[pos] == '0') {
                    return false;
                }
                string sub = num.substr(pos, i - pos + 1);
                auto now = stoll(sub.c_str(), NULL, 10);
                if (count >= 2) {
                    if (pre + prepre < now) {
                        return false;
                    }
                    if (pre + prepre > now) {
                        continue;
                    }
                }
                if (backtrack(i + 1, now, pre, count + 1)) {
                    return true;
                }

            }
            return false;
        };
        return backtrack(0, -1, -1, 0);
    }
};

// @lc code=end

