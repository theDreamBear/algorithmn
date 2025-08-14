/*
 * @lc app=leetcode.cn id=1780 lang=cpp
 * @lcpr version=30204
 *
 * [1780] 判断一个数字是否可以表示成三的幂的和
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
class Solution1 {
public:
    using ll = long long;
    bool checkPowersOfThree(int n) {
        vector<ll> can;
        ll i = 1;
        while (i <= n) {
            can.emplace_back(i);
            i *= 3;
        }
        int size = can.size();
        while (n and size > 0) {
            auto idx = upper_bound(can.begin(), can.begin() + size, n) - can.begin() - 1;
            n -= can[idx];
            size = idx;
        }
        return n == 0;
    }
};

class Solution2 {
public:
    using ll = long long;
    bool checkPowersOfThree(int n) {
        ll i = 1;
        while (i <= n) {
            i *= 3;
        }
        i /= 3;
        while(i and n) {
            if (i <= n) {
                n -= i;
            }
            // 换一个更小的
            i /= 3;
            while (i and i > n) i /= 3;
        }
        return n == 0;
    }
};

class Solution {
public:
    using ll = long long;
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 91\n
// @lcpr case=end

// @lcpr case=start
// 21\n
// @lcpr case=end

 */

