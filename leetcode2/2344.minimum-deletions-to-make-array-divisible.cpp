/*
 * @lc app=leetcode.cn id=2344 lang=cpp
 * @lcpr version=30204
 *
 * [2344] 使数组可以被整除的最少删除次数
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int, int> group;
        for (auto v: nums) {
            group[v]++;
        }
        int g = 0;
        for (auto v: numsDivide) {
            g = gcd(g, v);
        }
        auto getdivs = [&](int val) {
            vector<int> ans;
            for (int i = 1; i * i <= val; i++) {
                if (val % i == 0) {
                    ans.push_back(i);
                    if (i * i != val) {
                        ans.push_back(val / i);
                    }
                }
            }
            ranges::sort(ans);
            return ans;
        };
        auto divs = getdivs(g);
        for (auto v: divs) {
            if (group.contains(v)) {
                int ans = 0;
                for (auto& [k, cnt]: group) {
                    if (k == v) {
                        break;
                    }
                    ans += cnt;
                }
                return ans;
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2,4,3]\n[9,6,9,3,15]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,6]\n[8,2,6,10]\n
// @lcpr case=end

 */

