// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2929 lang=cpp
 * @lcpr version=30204
 *
 * [2929] 给小朋友们分糖果 II
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
    // 真容斥
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        auto cal = [&](long long n) {
            return n > 1 ? 
        }
        return ans;
    }

    // 直接枚举
    long long distributeCandies2(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i > 2 * limit) {
                continue;
            }
            // 减去c会超过limit的情况            
            ans += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return ans;
    }

    // 我滴神, 纯傻
    long long distributeCandies1(int n, int limit) {
        // 每个孩子得到最多limit个, 然后容斥
        // 第一个孩子得到 i 课糖的方案是 (n - i + 1) * (n - i + 1) or 0;
        // 0 0 0 都不符合
        // 0 0 1  只有一个符合
        // 0 1 0
        // 1 0 0

        // 0 1 1 两个符合
        // 1 0 1
        // 1 1 0
        // 1 1 1 都符合
        // 怎么分都超了
        if ((n - 3 * limit) > 0) {
            return 0;
        }
        int ans = 0;
        long long f[3]{};
//        auto cal = [&](int m) {
//            if (m < 0) return 0;
//            // m个苹果分成3份的方案数, 可以为0
//            return (m + 1) * (m + 2) / 2;
//        };
//        // 1个符合
//        for (int i = 0; i <= min(n, limit); i++) {
//            f[0] += (n - i + 1) * (n - i + 1);
//        }
        // 2个符合
        for (int i = 0; i <= min(n, limit); i++) {
            f[1] += (min(n - i, limit) + 1);
        }
        // 2个符合第三个不符合
        if (n - (limit +1) >= 0) {
            int left = n - (limit + 1);
            for (int i = 0; i <= min(left, limit); i++) {
                f[2] += min(left - i, limit) +1;
            }
        }
        return f[1] - f[2];
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=distributeCandies
// paramTypes= ["number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 5\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */

