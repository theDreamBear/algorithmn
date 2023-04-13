/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

// @lc code=start
class Solution {
public:
    bool canCover(int r, vector<int>& houses, vector<int>& heaters) {
        int l = 0;
        for (int i = 0; i < heaters.size(); i++) {
            if (heaters[i] + r < houses[l]) {
                continue;
            }
            if (heaters[i] - r > houses[l]) {
                break;
            }
            //l = heaters[i] + r + 1;
            while (l < houses.size() && heaters[i] + r >= houses[l]) {
                l++;
            }
            if (l >= houses.size()) {
                break;
            }
        }
        return l >= houses.size();
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        // 二分枚举
        int low = 0, high = 1e9;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (canCover(mid, houses, heaters)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (canCover(low, houses, heaters)) {
            return low;
        }
        return high;
    }
};
// @lc code=end

