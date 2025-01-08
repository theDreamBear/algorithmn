/*
 * @lc app=leetcode.cn id=2274 lang=cpp
 * @lcpr version=30204
 *
 * [2274] 不含特殊楼层的最大连续楼层数
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
    // ttl
    int maxConsecutive1(int bottom, int top, vector<int>& special) {
        int ans = 0;
        unordered_set<int> sp;
        for (auto v: special) {
            sp.insert(v);
        }
        for (int i = bottom, sz = 0; i <= top; i++) {
            if (sp.contains(i)) {
                sz = 0;
            } else {
                sz++;
            }
            ans = max(ans, sz);
        }
        return ans;
    }

    int maxConsecutive2(int bottom, int top, vector<int>& special) {
        int ans = 0;
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        ranges::sort(special);
        int left = special[0];
        for (int i = 0; i < special.size();) {
            int start = i++;
            while (i < special.size() and special[i] == special[i - 1] + 1) i++;
            // [start, i - 1] 是连续区间
            ans = max(ans, special[start] - left - 1);
            left = special[i - 1];
        }
        return ans;
    }

    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0;
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        ranges::sort(special);
        for (int i = 1; i < special.size(); i++) {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n9\n[4,6]\n
// @lcpr case=end

// @lcpr case=start
// 6\n8\n[7,6,8]\n
// @lcpr case=end

 */

