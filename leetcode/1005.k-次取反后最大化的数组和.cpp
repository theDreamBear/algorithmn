/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include <ranges.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
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

    */
    int largestSumAfterKNegations1(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int zero_ct = 0;
        int absmin = 100;
        int pre_sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (abs(A[i]) < absmin) {
                absmin = abs(A[i]);
            }
            if (A[i] < 0) {
                ++zero_ct;
            }
            pre_sum += A[i];
        }
        int m = min(K, zero_ct);
        for (int i = 0; i < m; ++i) {
            pre_sum += 2 * abs(A[i]);
            --K;
            --zero_ct;
        }
        if (K <= zero_ct || absmin == 0 || K % 2 == 0) {
            return pre_sum;
        } else {
            return pre_sum - 2 * absmin;
        }
    }

    /*
        优先队列
    */
    int largestSumAfterKNegations2(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int>> pr;
        for (auto v : A) {
            pr.push(v);
        }
        for (int i = 0; i < K; ++i) {
            auto v = pr.top();
            pr.pop();
            pr.push(-1 * v);
        }
        int sum = 0;
        while (!pr.empty()) {
            sum += pr.top();
            pr.pop();
        }
        return sum;
    }

    static bool cmp(int left, int right) {
        return abs(left) > abs(right);
    }

    /*
        两次贪心
    */
    int largestSumAfterKNegations3(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);
        for (int i = 0; i < A.size() && K > 0; ++i) {
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                --K;
            }
        }
        if (K % 2 == 1) {
            A.back() *= -1;
        }
        int sum = 0;
        for (auto v : A) {
            sum += v;
        }
        return sum;
    }

    /*
        有点意思的解法
    */
    int largestSumAfterKNegations(vector<int>& A, int K) {
        vector<int> number(201);
        for (auto v : A) {
            ++number[v + 100];
        }
        int minIndex = 0;
        while (K > 0) {
            while (number[minIndex] == 0) {
                ++minIndex;
            }
            --number[minIndex];
            ++number[200 - minIndex];
            if (minIndex > 100) {
                minIndex = 200 - minIndex;
            }
            --K;
        }
        int sum = 0;
        for (int i = 0; i < number.size(); ++i) {
            if (number[i] != 0) {
                sum += ((i - 100) * number[i]);
            }
        }
        return sum;
    }
};
// @lc code=end
