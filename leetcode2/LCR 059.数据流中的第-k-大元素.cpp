/*
 * @lc app=leetcode.cn id=LCR 059 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 059] 数据流中的第 K 大元素
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
// @lcpr-template-en
// @lc code=start
class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums): k(k) {
        for (auto v : nums) {
            if (pq.size() >= k) {
                if (pq.top() >= v) {
                    continue;
                }
                pq.pop();
            }
            pq.push(v);
        }
    }

    int add(int val) {
        if (pq.size() >= k) {
            if (pq.top() >= val) {
                return pq.top();
            }
            pq.pop();
        }
        pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end



/*
// @lcpr case=start
// ["KthLargest", "add", "add", "add", "add", "add"][[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]\n
// @lcpr case=end

 */

