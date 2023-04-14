/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
class Solution1 {
public:
    vector<int> helper( vector<int> &matchsticks, int target) {
        vector<int> ans;
        for (int i = 0; i < (1 << matchsticks.size()); i++) {
            int k = i;
            int sum = 0;
            while (k > 0) {
                int p = __builtin_ffs(k) - 1;
                if (sum + matchsticks[p] > target) {
                    break;
                }
                sum += matchsticks[p];
                k ^= (1 << p);
            }
            if (sum == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    bool makesquare(vector<int> &matchsticks) {
        long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }
        int target = sum / 4;
        auto data = helper(matchsticks, target);
        for (int i = 0; i < data.size(); i++) {
            for (int j = i + 1; j < data.size(); j++) {
                for (int k = j + 1; k < data.size(); k++) {
                    if ((data[i] & data[j]) == 0 && (data[j] & data[k]) == 0 && (data[i] & data[k]) == 0) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool dfs(int index, vector<int>& matchsticks, vector<int> &sums, int target) {
        if (index >= matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            if (sums[i] + matchsticks[index] > target) {
                continue;
            }
            sums[i] += matchsticks[index];
            if (dfs(index + 1, matchsticks, sums, target)) {
                return true;
            }
            sums[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks) {
        long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }
        int target = sum / 4;
        vector<int> sums(4);
        return dfs(0, matchsticks, sums, target);
    }
};
// @lc code=end

