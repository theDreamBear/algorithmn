// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3233 lang=cpp
 * @lcpr version=30204
 *
 * [3233] 统计不是特殊数字的数字数量
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
    int nonSpecialCount(int l, int r) {
        int ans = r - l + 1;
        // 偶数只有4可以, 奇数只能为质数的平方  => 质数的个数
        auto isprim = [&](int v) {
            if (v == 1) return false;
            if (v == 2) return true;
            for (int i = 2; i * i <= v; i++) {
                if (v % i == 0) {
                    return false;
                }
            }
            return true;
        };
        int i = 1;
        while (i * i < l) i++;
        for (; i * i <= r; i++) {
            if (isprim(i)) {
                ans--;
            }
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=nonSpecialCount
// paramTypes= ["number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 5\n7\n
// @lcpr case=end

// @lcpr case=start
// 4\n16\n
// @lcpr case=end

 */

