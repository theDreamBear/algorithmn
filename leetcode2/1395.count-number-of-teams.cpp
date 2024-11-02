// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1395 lang=cpp
 * @lcpr version=30204
 *
 * [1395] 统计作战单位数
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

class Bits{
 public:
    vector<int> bits;

    Bits(int n): bits(n + 1) {}

    void add(int i) {
        while (i < bits.size()) {
            bits[i] += 1;
            i += (i & -i);
        }
    }

    int sum(int i) {
        int ans = 0;
        while (i > 0) {
            ans += bits[i];
            i &= (i - 1);
        }
        return ans;
    }
};

class Solution {
public:
    // 枚举中间, 然后找左小右大, 左大右小
    int numTeams1(vector<int>& rating) {
        auto data = rating;
        ranges::sort(data);
        int ans = 0;
        int maxn = ranges::max(rating);
        Bits bit(maxn + 1);
        for (int i = 0; i < rating.size(); i++) {
            // less
            int less = bit.sum(rating[i] - 1);
            int greater = data.end() -  upper_bound(data.begin(), data.end(), rating[i]) - (i - less);
            ans += (less * greater);

            ans += (i - less) * (upper_bound(data.begin(), data.end(), rating[i] - 1) - data.begin() - less);
            bit.add(rating[i]);
        }
        return ans;
    }

    int numTeams(vector<int>& rating) {
        // f(i, j) i是下标, j = 0当前选择了几个, 的作战单元的方案数
        // f(i, 0) = 1, 选择了1个的方案数为1
        // f(i, 1) = // 找i (0, i - 1)且小于rating(i - 1) j = 0的方案和 因为独一无二所以可以用前缀和
        int n = rating.size();
        int dp[n][3];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            dp[i][1] = 0;
            dp[i][2] = 0;
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) {
                    dp[i][0] = 1;
                    dp[i][1] += dp[j][0];
                    dp[i][2] += dp[j][1];
                }
            }
            ans += dp[i][2];
        }

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            dp[i][1] = 0;
            dp[i][2] = 0;
            for (int j = 0; j < i; j++) {
                if (rating[j] > rating[i]) {
                    dp[i][0] = 1;
                    dp[i][1] += dp[j][0];
                    dp[i][2] += dp[j][1];
                }
            }
            ans += dp[i][2];
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=numTeams
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2,5,3,4,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

