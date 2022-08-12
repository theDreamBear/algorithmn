/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
// 题目看三遍
class Solution {
public:
    int countArrangement(int n) {
        vector<int> data(n + 1);
        for (int i = 1; i < n + 1; i++) {
            data[i] = i;
        }
        int ans = 0;
        function<void(int)> backtrack = [&](int pos) {
            if (pos > n) {
                ++ans;
                return;
            }
            for (int i = pos; i < n + 1; i++) {
                if (data[i] % pos == 0 || pos % data[i] == 0) {
                    swap(data[i], data[pos]);
                    backtrack(pos + 1);
                    swap(data[i], data[pos]);
                }
            }
        };
        backtrack(1);
        return ans;
    }
};
// @lc code=end

