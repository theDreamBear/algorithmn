// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2523 lang=cpp
 * @lcpr version=30204
 *
 * [2523] 范围内最接近的两个质数
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
const int maxn = 1e6 + 100;
int       isprime[maxn];
int       n = 0;
int       prime[maxn];

// 哎式筛选
auto aishai = []() {
    n = 0;
    for (long long i = 2; i < maxn; i++) {
        if (!isprime[i]) {
            prime[n++] = i;
            for (long long j = i * i; j < maxn; j += i) {
                isprime[j] = 1;
            }
        }
    }
    return nullptr;
};

// 欧拉筛
auto EulerShai = []() {
    n = 0;
    for (long long i = 2; i < maxn; i++) {
        if (!isprime[i]) {
            prime[n++] = i;
        }
        for (long long j = 0; j < n; j++) {
            if (i * prime[j] >= maxn)
                break;
            isprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return nullptr;
}();

class Solution {
  public:
    vector<int> closestPrimes(int left, int right) {
        // nums1, nums2 一定是相邻的, 筛选就行了
        auto low  = lower_bound(prime, prime + n, left) - prime;
        auto high = upper_bound(prime, prime + n, right) - prime - 1;
        if (low + 1 > high) {
            return {-1, -1};
        }
        vector<int> ans;
        int         minDiff = INT_MAX;
        for (int i = low + 1; i <= high; i++) {
            if (prime[i] - prime[i - 1] < minDiff) {
                minDiff = prime[i] - prime[i - 1];
                ans     = {prime[i - 1], prime[i]};
            }
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=closestPrimes
// paramTypes= ["number","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 10\n19\n
// @lcpr case=end

// @lcpr case=start
// 4\n6\n
// @lcpr case=end

 */
