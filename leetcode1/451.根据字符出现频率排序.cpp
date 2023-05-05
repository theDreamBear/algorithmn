/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnt(300);
        for (auto ch : s) {
            cnt[ch]++;
        }
        auto cmp = [&](char lhs, char rhs) {
            if (cnt[lhs] != cnt[rhs]) {
                return cnt[lhs] > cnt[rhs];
            }
            return lhs > rhs;
        };
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
// @lc code=end

