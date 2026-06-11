/*
 * @lc app=leetcode.cn id=3691 lang=cpp
 * @lcpr version=30204
 *
 * [3691] 最大子数组总值 II
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
struct MinOp {
    int operator()(int a, int b) const { return a < b ? a : b; }
};

struct MaxOp {
    int operator()(int a, int b) const { return a > b ? a : b; }
};

    template<typename OP>
    class ST{
     public:
        vector<int>& nums;
        vector<vector<int>> arr;
        ST(vector<int>& data): nums(data), arr(nums.size(), vector<int>(bit_width(nums.size()))) {
            for (int i = 0; i < nums.size(); i++) {
                arr[i][0] = nums[i];
            }
            for (int j = 1; j < arr[0].size(); j++) {
                for (int i = 0; i + (1 << (j - 1)) < nums.size(); i++) {
                    // i, i + (1 << j) - 1;
                    // (i, i + (1 << (j - 1)) - 1)  (i << (j - 1))
                    arr[i][j] = OP{}(arr[i][j - 1], arr[i + (1 << (j - 1))][j - 1]);
                }
            }
        }

        int query(int low, int high) {
            int d = log2(high - low + 1);
            // low, low + (1 << d) - 1
            // high - (1 << d) + 1, high
            // low + (1 << d) - 1 >= high - (1 << d) + 1
            // 1 << d >= (high - low + 2) / 2;
            return OP{}(arr[low][d], arr[high - (1 << d) + 1][d]);
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        ST<MinOp> Mm(nums);
        ST<MaxOp> Mx(nums);
        auto query = [&](int low, int high) {
            return Mx.query(low, high) - Mm.query(low, high);
        };

        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(query(0, nums.size() - 1), 0, nums.size() - 1);
        long long ans = 0;
        while (k-- > 0) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if (l < r) {
                pq.emplace(query(l, r - 1), l, r - 1);
            }
            if (r + 1 == nums.size() and l < r) {
                pq.emplace(query(l + 1, r), l + 1, nums.size() - 1);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,5,1]\n3\n
// @lcpr case=end

 */

