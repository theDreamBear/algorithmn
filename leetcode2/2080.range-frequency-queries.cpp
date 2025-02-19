/*
 * @lc app=leetcode.cn id=2080 lang=cpp
 * @lcpr version=30204
 *
 * [2080] 区间内查询数字的频率
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
class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> pos;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            pos[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if (!pos.contains(value)) {
            return 0;
        }
        auto& arr = pos[value];
        auto le = lower_bound(arr.begin(), arr.end(), left);
        auto ri = upper_bound(arr.begin(), arr.end(), right);
        return ri - le;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end



/*
// @lcpr case=start
// ["RangeFreqQuery", "query", "query"][[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]\n
// @lcpr case=end

 */

