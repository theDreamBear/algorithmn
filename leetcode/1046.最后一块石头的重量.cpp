/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */
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
    int lastStoneWeight_heap(vector<int>& stones) {
        if (stones.size() == 1) {
            return stones[0];
        }
        priority_queue<int> maxHeap;
        for (auto& x : stones) {
            maxHeap.push(x);
        }
        while (maxHeap.size() >= 2) {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if (y > x) {
                maxHeap.push(y - x);
            }
        }
        if (maxHeap.size() == 0) {
            return 0;
        }
        return maxHeap.top();
    }

    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) {
            return stones[0];
        }
        priority_queue<int> maxHeap;
        for (auto& x : stones) {
            maxHeap.push(x);
        }
        while (maxHeap.size() >= 2) {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if (y > x) {
                maxHeap.push(y - x);
            }
        }
        if (maxHeap.size() == 0) {
            return 0;
        }
        return maxHeap.top();
    }
};
// @lc code=end
