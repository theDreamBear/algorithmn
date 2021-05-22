/*
 * @lc app=leetcode.cn id=810 lang=cpp
 *
 * [810] 黑板异或游戏
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    // 返回当前选手是否能赢
    // 超时
    bool opponentWin(vector<int> &nums, vector<bool> &removed, int left, int xx) {
        if (xx == 0) {
            return true;
        }
        if (left == 1) {
            return false;
        }
        if (left == 2) {
            return true;
        }
        unordered_set<int> visited;
        for (int i = 0; i < nums.size(); ++i) {
            if (removed[i] || visited.count(nums[i]) > 0) {
                continue;
            }
            if ((xx ^ nums[i]) != 0) {
                removed[i] = true;
                visited.insert(nums[i]);
                if (!opponentWin(nums, removed, left - 1, xx ^ nums[i])) {
                    // 返回前要重置
                    removed[i] = false;
                    return true;
                }
                removed[i] = false;
            }
        }
        return false;
    }

    bool xorGame1(vector<int> &nums) {
        int xx = 0;
        for (auto val : nums) {
            xx ^= val;
        }
        vector<bool> removed(nums.size());
        sort(nums.begin(), nums.end());
        return opponentWin(nums, removed, nums.size(), xx);
    }

    /*
        找规律发现, 如果 xx 不为 0
        那么 left 为偶数结果必赢
    */
    bool xorGame(vector<int> &nums) {
        int xx = 0;
        for (auto val : nums) {
            xx ^= val;
        }
        if (xx == 0) {
            return true;
        }
        return nums.size() % 2 == 0;
    }
};
// @lc code=end

int main() {
    vector<int> ans = {1, 1, 2, 3, 4};
    cout << Solution{}.xorGame(ans);
}