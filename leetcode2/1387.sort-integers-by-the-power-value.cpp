/*
 * @lc app=leetcode.cn id=1387 lang=cpp
 * @lcpr version=30204
 *
 * [1387] 将整数按权重排序
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
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> w;
        auto get = [&](auto&& get, int val) {
            if (val == 1) {
                return 0;
            }
            if (w.contains(val)) {
                return w[val];
            }
            if (val % 2 == 0) {
                return w[val] = get(get, val / 2) + 1;
            } else {
                return w[val] = get(get, val * 3 + 1) + 1;
            }
        };
        vector<int> ids(hi - lo + 1);
        std::iota(ids.begin(), ids.end(), lo);
        ranges::sort(ids, [&](int i, int j) {
            return get(get, i) < get(get, j) or ( get(get, i) == get(get, j) and i < j);
        });
        return ids[k - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n15\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n11\n4\n
// @lcpr case=end

 */

