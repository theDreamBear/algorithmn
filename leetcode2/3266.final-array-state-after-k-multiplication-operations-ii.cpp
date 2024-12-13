/*
 * @lc app=leetcode.cn id=3266 lang=cpp
 * @lcpr version=30204
 *
 * [3266] K 次乘运算后的最终数组 II
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
class Solution1 {
    const int MOD = 1'000'000'007;

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }

public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) { // 数组不变
            return move(nums);
        }

        int n = nums.size();
        int mx = ranges::max(nums);
        vector<pair<long long, int>> h(n);
        for (int i = 0; i < n; i++) {
            h[i] = {nums[i], i};
        }
        ranges::make_heap(h, greater<>()); // 最小堆，O(n) 堆化

        // 模拟，直到堆顶是 mx
        for (; k && h[0].first < mx; k--) {
            ranges::pop_heap(h, greater<>());
            h.back().first *= multiplier;
            ranges::push_heap(h, greater<>());
        }

        // 剩余的操作可以直接用公式计算
        ranges::sort(h);
        for (int i = 0; i < n; i++) {
            auto& [x, j] = h[i];
            nums[j] = x % MOD * pow(multiplier, k / n + (i < k % n)) % MOD;
        }
        return move(nums);
    }
};

class Solution {
  public:
    // 超精度了
    using ll = __int128_t;
    vector<int> getFinalState1(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        // 1. 先逼近
        // 2. 中间循环
        // 3. 善后
        // 这样可以
        int                                                             n = nums.size();
        queue<int>                                                      q;
        vector<int>                                                     cnt(n);
        int                                                             ct = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        while (k--) {
            auto [v, idx] = pq.top();
            pq.pop();
            pq.push({v * multiplier, idx});
            if (++cnt[idx] == 1) {
                ct++;
            }
            q.push(idx);
            if (q.size() > n) {
                auto x = q.front();
                q.pop();
                if (--cnt[idx] == 0) {
                    ct--;
                }
            }
            if (ct == n) {
                // 找到了一个循环了
                break;
            }
        }
        vector<pair<ll, int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        int div = k / n;
        k %= n;
        int  mod     = 1e9 + 7;
        auto fastMul = [&](long long base, int n) {
            base %= mod;
            long long res = 1;
            while (n) {
                if (n & 1)
                    res = res * base % mod;
                n >>= 1;
                base = base * base % mod;
            }
            return res;
        };
        int base = fastMul(multiplier, div);
        for (int i = 0; i < n; i++) {
            res[i].first = (res[i].first % mod * base) % mod;
        }
        for (int i = 0; i < k; i++) {
            res[i].first = (res[i].first * multiplier) % mod;
        }
        vector<int> ans(nums.size());
        for (int i = 0; i < n; i++) {
            ans[res[i].second] = res[i].first;
        }
        return ans;
    }

    // 超精度了
    // using ll =  __int128_t;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        // 1. 先逼近
        // 2. 中间循环
        // 3. 善后
        // 这样可以
        int  ma      = ranges::max(nums);
        int  mod     = 1e9 + 7;
        auto fastMul = [&](long long base, int n) {
            base %= mod;
            long long res = 1;
            while (n) {
                if (n & 1)
                    res = res * base % mod;
                n >>= 1;
                base = base * base % mod;
            }
            return res;
        };
        int n = nums.size();
        if (n == 1) {
            nums[0] = (nums[0] * fastMul(multiplier, k)) % mod;
            return nums;
        }
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        // 尼玛 逆天优化
        if (k >= 2e5) {
            for (int i = 0; i < n and k; i++) {
                auto [v, idx] = pq.top();
                pq.pop();
                int       sub = (int)(log(ma * 1.0 / v) / log(multiplier));
                long long xx  = fastMul(multiplier, sub);
                if (xx * v < ma) {
                    sub++;
                    xx *= multiplier;
                }
                k -= sub;
                pq.push({v * xx, idx});
            }
        } else {
            queue<int>  q;
            vector<int> cnt(n);
            int         ct = 0;
            while (k--) {
                auto [v, idx] = pq.top();
                pq.pop();
                pq.push({v * multiplier, idx});
                if (v >= ma) {
                    break;
                }
                if (++cnt[idx] == 1) {
                    ct++;
                }
                q.push(idx);
                if (q.size() > n) {
                    auto x = q.front();
                    q.pop();
                    if (--cnt[idx] == 0) {
                        ct--;
                    }
                }
                if (ct == n) {
                    // 找到了一个循环了
                    break;
                }
            }
        }
        vector<pair<ll, int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        int div = k / n;
        k %= n;
        int base = fastMul(multiplier, div);
        for (int i = 0; i < n; i++) {
            res[i].first = (res[i].first % mod * base) % mod;
        }
        for (int i = 0; i < k; i++) {
            res[i].first = (res[i].first * multiplier) % mod;
        }
        vector<int> ans(nums.size());
        for (int i = 0; i < n; i++) {
            ans[res[i].second] = res[i].first;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,3,5,6]\n5\n2\n
// @lcpr case=end

// @lcpr case=start
// [100000,2000]\n2\n1000000\n
// @lcpr case=end

 */
