/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
class Solution {
public:
    vector<string> getAllHour(int hct) {
        vector<string> ans;
        for (int i = 0; i < 12; i++) {
            if (__builtin_popcount(i) == hct) {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }

    vector<string> getAllMinute(int mct) {
        vector<string> ans;
        for (int i = 0; i < 60; i++) {
            if (__builtin_popcount(i) == mct) {
                if (i < 10) {
                    ans.push_back(move("0" + to_string(i)));
                } else {
                    ans.push_back(move(to_string(i)));
                }
            }
        }
        return ans;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int hct = 0; hct <= 4; hct++) {
            int mct = turnedOn - hct;
            auto hvec = getAllHour(hct);
            auto mvec = getAllMinute(mct);
            if (hvec.empty() || mvec.empty()) {
                continue;
            }
            for (auto& h : hvec) {
                for (auto& m: mvec) {
                    ans.push_back(move(h + ":" + m));
                }
            }
        }
        return ans;
    }
};
// @lc code=end

