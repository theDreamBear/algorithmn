/*
 * @lc app=leetcode.cn id=1433 lang=cpp
 *
 * [1433] 检查一个字符串是否可以打破另一个字符串
 */

// @lc code=start
class Solution {
public:
    bool CheckIfCanBreakHelper(const string &s1, const string &s2) {
        int state = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) {
                continue;
            }
            if (state == 0) {
                state = (s1[i] > s2[i]) ? 1 : -1;
                continue;
            }
            int cur = (s1[i] > s2[i]) ? 1 : -1;
            if (cur != state) {
                return false;
            }
        }
        return true;
    }

    void my_Sort_normal(string &s) {
        sort(s.begin(), s.end());
    }

    void my_Sort_best(string &s) {
        // 低位优先排序
        vector<int> counter(26);
        int n = s.size();
        for (auto c: s) {
            counter[c - 'a']++;
        }
        int x = 0;
        for (int i = 0; i < 26; i++) {
            while (counter[i]--) {
                s[x++] = 'a' + i;
            }
        }
    }

    bool checkIfCanBreak(string s1, string s2) {
//        my_Sort_normal(s1);
//        my_Sort_normal(s2);
        my_Sort_best(s1);
        my_Sort_best(s2);
        if (CheckIfCanBreakHelper(s1, s2)) {
            return true;
        }
        return CheckIfCanBreakHelper(s2, s1);
    }
};
// @lc code=end

