/*
 * @lc app=leetcode.cn id=830 lang=cpp
 * @lcpr version=30204
 *
 * [830] 较大分组的位置
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
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        for (int i = 0; i < s.size(); ) {
            int start = i++;
            while (i < s.size() and s[i] == s[start]) i++;
            if (i - start >= 3) {
                ans.push_back({start, i - 1});
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abbxxxxzzy"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcdddeeeeaabbbcd"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

 */

