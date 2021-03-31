/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
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
#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    bool canCompleteCircuitHelper(vector<int>& gas, vector<int>& cost, int start) {
        int n = cost.size();
        int end = start;
        int left = 0;
        do {
            left = left + gas[start] - cost[start];
            if (left < 0) {
                return false;
            }
            start = (start + 1) % n;
        } while (start != end);
        return true;
    }

    int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < cost.size(); ++i) {
            if (gas[i] >= cost[i] && canCompleteCircuitHelper(gas, cost, i)) {
                return i;
            }
        }
        return -1;
    }

    /*
        最大连续和, 要算两次（从尾到头）
    */
    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        int g_pos = -1;
        int g_max_sum = INT_MIN;

        int pos = -1;
        int max_sum = INT_MIN;
        
        int sum = 0;
        int total = 0;
        for (int i = 0; i < cost.size(); ++i) {
            if (sum == 0) {
                pos = i;
            }
            int diff = gas[i] - cost[i];
            sum += diff;
            total += diff;
            if (sum <= 0) {
                if (max_sum >= g_max_sum) {
                    g_max_sum = max_sum;
                    g_pos = pos;
                    pos = -1;
                }
                sum = 0;
                max_sum = 0;
            } else if (sum > max_sum) {
                max_sum = sum;
            }
        }
        for (int i = 0; i < cost.size(); ++i) {
            if (sum == 0) {
                pos = i;
            }
            int diff = gas[i] - cost[i];
            sum += diff;
            total += diff;
            if (sum <= 0) {
                if (max_sum >= g_max_sum) {
                    g_max_sum = max_sum;
                    g_pos = pos;
                    pos = -1;
                }
                sum = 0;
                max_sum = 0;
            } else if (sum > max_sum) {
                max_sum = sum;
            }
        }
        if (max_sum > g_max_sum) {
            g_pos = pos;
            pos = -1;
        }
        if (total < 0) {
            return -1;
        }
        return g_pos;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 整体最大和
        int max_sum = INT_MIN;
        // 整体最大起点
        int start = -1;
        
        // 当前区间起点
        int pos = -1;
        // 当前区间和
        int sum = 0;
        // 当前区间最大和
        int range_sum = 0;

        // 整体和
        int total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            if (sum == 0) {
                pos = i;
            }
            int diff = gas[i] - cost[i];
            total += diff;
            sum += diff;
            if (sum < 0) {
                if (range_sum > max_sum) {
                    max_sum = range_sum;
                    start = pos;
                }
                range_sum = 0;
                sum = 0;
            } else if (sum > range_sum) {
                range_sum = sum;
            }
        }

        for (int i = 0; i < gas.size(); ++i) {
            if (sum == 0) {
                pos = i;
            }
            int diff = gas[i] - cost[i];
            total += diff;
            sum += diff;
            if (sum < 0) {
                if (range_sum > max_sum) {
                    max_sum = range_sum;
                    start = pos;
                }
                range_sum = 0;
                sum = 0;
            } else if (sum > range_sum) {
                range_sum = sum;
            }
        }

        if (range_sum > max_sum) {
            start = pos;
        }
        if (total < 0) {
            return -1;
        }
        return start;
    }
};
// @lc code=end

int main() {
    vector<int> gas = {2};
    vector<int> cost = {2};
    cout << Solution{}.canCompleteCircuit(gas, cost);
}