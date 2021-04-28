/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    /*
        想到了这种方法但是, 没想明白终止条件
    */
    int nthUglyNumber1(int n) {
        if (n == 1) {
            return 1;
        }
        priority_queue<long long, vector<long long>, greater<long long>>
            minHeap;
        unordered_set<long long> exist;
        minHeap.push(1);
        exist.insert(1);
        int ct = 0;
        while (ct <= n) {
            ++ct;
            long long v = minHeap.top();
            minHeap.pop();
            if (ct == n) {
                return v;
            }
            long long v1 = 2 * v, v2 = 3 * v, v3 = 5 * v;
            if (exist.count(v1) == 0) {
                exist.insert(v1);
                minHeap.push(v1);
            }
            if (exist.count(v2) == 0) {
                exist.insert(v2);
                minHeap.push(v2);
            }
            if (exist.count(v3) == 0) {
                exist.insert(v3);
                minHeap.push(v3);
            }
        }
        return 0;
    }

    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> dp(n);
        dp.push_back(1);
        int p2 = 0, p3 = 0, p5 = 0;
        int ct = 1;
        while (ct < n) {
            dp[ct] = min({2 * dp[p2], 3 * dp[p3]})
        }
    };
    // @lc code=end
