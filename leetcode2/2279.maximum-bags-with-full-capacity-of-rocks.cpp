/*
 * @lc app=leetcode.cn id=2279 lang=cpp
 * @lcpr version=30204
 *
 * [2279] 装满石头的背包的最大数量
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumBags1(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> idx(n);
        ranges::iota(idx, 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return capacity[a] - rocks[a] < capacity[b] - rocks[b];
        });
        int i = 0;
        for (; i < n; i++) {
            int x = idx[i];
            if (additionalRocks >= capacity[x] - rocks[x]) {
                additionalRocks -= (capacity[x] - rocks[x]);
            } else {
                break;
            }
        }
        return i;
    }

    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        for (int i = 0;i < n; i++) {
            capacity[i] -= rocks[i];
        }
        ranges::sort(capacity);
        int i = 0;
        for (; i < capacity.size(); i++) {
            additionalRocks -= capacity[i];
            if (additionalRocks < 0) {
                break;
            }
        }
        return i;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,4,5]\n[1,2,4,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [10,2,2]\n[2,2,0]\n100\n
// @lcpr case=end

 */

