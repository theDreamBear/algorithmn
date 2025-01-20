/*
 * @lc app=leetcode.cn id=2126 lang=cpp
 * @lcpr version=30204
 *
 * [2126] 摧毁小行星
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool asteroidsDestroyed1(int mass, vector<int>& asteroids) {
        ranges::sort(asteroids);
        long long left = mass;
        for (auto v: asteroids) {
            if (v > left) return false;
            left += v;
        }
        return true;
    }

    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        vector<int> rg(20, -1);
        vector<long long> sum(20);
        for (auto& v: asteroids) {
            // 位宽
            int idx = 32 - __builtin_clz(v);
            if (rg[idx] == -1 or rg[idx] > v) rg[idx] = v;
            sum[idx] += v;
        }
        long long cur = mass;
        for (int i = 0; i < rg.size(); i++) {
            if (cur < rg[i]) return false;
            cur += sum[i];
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n[3,9,19,5,21]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[4,9,23,4]\n
// @lcpr case=end

 */

