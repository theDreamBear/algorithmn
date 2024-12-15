/*
 * @lc app=leetcode.cn id=1338 lang=cpp
 * @lcpr version=30204
 *
 * [1338] 数组大小减半
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
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto v: arr) {
            cnt[v]++;
        }
        vector<int> idx;
        for (auto& [k, v]: cnt) {
            idx.push_back(v);
        }
        ranges::sort(idx, greater<>{});
        int ans = 0, hald = (arr.size() + 1) / 2;
        for (auto v: idx) {
            hald -= v;
            ans++;
            if (hald <= 0) {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,3,3,3,5,5,5,2,2,7]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7]\n
// @lcpr case=end

 */

