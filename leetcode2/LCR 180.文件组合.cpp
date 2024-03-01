/*
 * @lc app=leetcode.cn id=LCR 180 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 180] 文件组合
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> fileCombination1(int target) {
        vector<vector<int>> ans;
        // [left, next) 当前窗口
        int left = 1, next = 1, sum = 0;
        while (next < target) {
            // 扩容
            while (next < target and sum < target) {
                sum += next;
                ++next;
            }
            if (sum == target) {
                int sz = next - left;
                vector<int> tmp(sz);
                std::iota(tmp.begin(), tmp.end(), left);
                ans.push_back(tmp);
                sum -= left;
                ++left;
            }
            while (left + 1 < next and sum > target) {
                sum -= left;
                ++left;
            }
            if (sum == target) {
                int sz = next - left;
                vector<int> tmp(sz);
                std::iota(tmp.begin(), tmp.end(), left);
                ans.push_back(tmp);
                sum -= left;
                ++left;
            }
        }
        return ans;
    }

    vector<vector<int>> fileCombination2(int target) {
        vector<vector<int>> ans;
        // [left, next) 当前窗口
        int left = 1, next = 1, sum = 0;
        while (next < target) {
            // 缩容
            while (left + 1 < next and sum > target) {
                sum -= left;
                ++left;
            }
            if (sum == target) {
                int sz = next - left;
                vector<int> tmp(sz);
                std::iota(tmp.begin(), tmp.end(), left);
                ans.push_back(tmp);
                sum -= left;
                ++left;
            }
            // 扩容
            while (next < target and sum < target) {
                sum += next;
                ++next;
            }
        }
        return ans;
    }

    vector<vector<int>> fileCombination(int target) {
        vector<vector<int>> ans;
        // [left, next) 当前窗口
        int left = 1, next = 2, sum = left;
        while (left < next and left <= target >> 1) {
            if (sum < target) {
                sum += next;
                ++next;
            } else if (sum > target) {
                sum -= left;
                ++left;
            } else {
                int sz = next - left;
                vector<int> tmp(sz);
                iota(tmp.begin(), tmp.end(), left);
                ans.push_back(tmp);
                sum -= left;
                ++left;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 18\n
// @lcpr case=end

 */

