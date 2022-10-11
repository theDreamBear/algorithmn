/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 *
 * [2103] 环和杆
 */

// @lc code=start
class Solution {
public:
    int countPoints2(string rings) {
        unordered_map<int, unordered_set<char>> bs;
        for (int i = 0; i < rings.size(); i += 2) {
            char c = rings[i];
            int t = rings[i + 1] - '0';
            bs[t].insert(c);
        }
        int ans = 0;
        for (auto& ss : bs) {
            if (ss.second.size() == 3) {
                ++ans;
            }
        }
        return ans;
    }

    int countPoints3(string rings) {
        vector<vector<int>> bs(9 ,vector<int>(26));
        for (int i = 0; i < rings.size(); i += 2) {
            char c = rings[i];
            int t = rings[i + 1] - '0';
            bs[t][c] = 1;
        }
        int ans = 0;
        for (auto& ss : bs) {
            if (ss['R' - 'A'] + ss['G' - 'A'] + ss['B' - 'A'] == 3) {
                ++ans;
            }
        }
        return ans;
    }

    int countPoints(string rings) {
        int mask = 0;
        for (int i = 0; i < rings.size(); i += 2) {
            char c = rings[i];
            int p = 0;
            if (c == 'R') {
                p = 1;
            } else if (c == 'G') {
                p = 2;
            }
            int t = rings[i + 1] - '0';
            mask |=  1 << (t * 3 + p);
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            if (((mask >> (i * 3)) & 0b111) == 0b111) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

