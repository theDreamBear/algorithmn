/*
 * @lc app=leetcode.cn id=LCR 191 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 191] 按规则计算统计结果
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
#include <numeric>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> statisticalResult(vector<int>& arrayA) {
        int zero = count(arrayA.begin(), arrayA.end(), 0);
        int mulitySum = accumulate(arrayA.begin(), arrayA.end(), 1, [&](int init, int value) {
            if (value != 0) {
                init *= value;
            }
            return init;
        });
        vector<int> ans(arrayA.size(), 0);
        if (zero >= 2) {
            return ans;
        }
        for (int i = 0; i < arrayA.size(); i++) {
            if (zero == 0) {
                ans[i] = mulitySum / arrayA[i];
            } else if (zero == 1) {
                if (arrayA[i] == 0) {
                    ans[i] = mulitySum;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2, 4, 6, 8, 10]\n
// @lcpr case=end

 */

