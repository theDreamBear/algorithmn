/*
 * @lc app=leetcode.cn id=2829 lang=cpp
 * @lcpr version=30204
 *
 * [2829] k-avoiding 数组的最小总和
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
    int minimumSum(int n, int k) {
        int val = 1, sum = 0;
        unordered_set<int> vals;
        auto get_one = [&]() {
            bool ok = false;
            while (!ok) {
                ok = true;
                for (auto x: vals) {
                    if (x + val == k) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    vals.insert(val);
                    sum += val;
                }
                val++;
            }
        };
        while (n--) {
            get_one();
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n4\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n
// @lcpr case=end

 */

