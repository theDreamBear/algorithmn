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
        最大连续和
    */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
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
        if (max_sum >= g_max_sum) {
            g_pos = pos;
            pos = -1;
        }
        if (total < 0) {
            return -1;
        }
        return g_pos;
    }
};
// @lc code=end

int main() {
    vector<int> gas = {5, 8, 2, 8};
    vector<int> cost = {6, 5, 6, 6};
    cout << Solution{}.canCompleteCircuit(gas, cost);
}