/*
 * @lc app=leetcode.cn id=2275 lang=cpp
 * @lcpr version=30204
 *
 * [2275] 按位与结果大于零的最长组合
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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // 看错题目了
    int largestCombination_bad(vector<int>& candidates) {
        int cnt[32]{};
        int ans = 0;
        int val = 0;
        auto opt  = [&](int v, int x) {
            for (int i = 0; i < 32; i++) {
                if (v >> i & 1) {
                    cnt[i] += x;
                }
            }
        };
        auto get = [&](int len) {
            val = 0;
            for (int i = 0; i < 32; i++) {
                if (cnt[i] == len) {
                    val |= (1 << i);
                }
            }
            return val;
        };
        for (int left = 0, right = 0; right < candidates.size(); right++) {
            opt(candidates[right], 1);
            while (get(right - left + 1) == 0) {
                opt(candidates[left++], -1);
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }

    int largestCombination(vector<int>& candidates) {
        int cnt[32]{};
        int ans = 0;
        int val = 0;
        auto opt  = [&](int v, int x) {
            for (int i = 0; i < 32; i++) {
                if (v >> i & 1) {
                    cnt[i] += x;
                }
            }
        };
        for (auto v: candidates) opt(v, 1);
        return ranges::max(cnt);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [16,17,71,62,12,24,14]\n
// @lcpr case=end

// @lcpr case=start
// [8,8]\n
// @lcpr case=end

 */

