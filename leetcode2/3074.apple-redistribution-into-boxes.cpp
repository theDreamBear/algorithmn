/*
 * @lc app=leetcode.cn id=3074 lang=cpp
 * @lcpr version=30204
 *
 * [3074] 重新分装苹果
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
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        ranges::sort(capacity, greater<>{});
        int j = 0, left = 0;
        for (int i = 0; i < apple.size() and j < capacity.size(); i++) {
            while (j < capacity.size() and left < apple[i]) {
                left += capacity[j++];
            }
            if (left >= apple[i]) left -= apple[i];
        }
        return j;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2]\n[4,3,1,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5]\n[2,4,2,7]\n
// @lcpr case=end

 */

