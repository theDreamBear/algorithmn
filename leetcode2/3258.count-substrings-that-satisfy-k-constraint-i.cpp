/*
 * @lc app=leetcode.cn id=3258 lang=cpp
 * @lcpr version=30204
 *
 * [3258] 统计满足 K 约束的子字符串数量 I
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
    int countKConstraintSubstrings(string s, int k) {
        int cnt[2]{};
        int ans = 0;
        for (int left = 0, right = 0; right < s.size(); right++) {
            cnt[s[right] - '0']++;
            while (cnt[0] > k and cnt[1] > k) {
                cnt[s[left++] - '0']--;
            }
            ans += (right - left + 1);
        } 
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "10101"\n1\n
// @lcpr case=end

// @lcpr case=start
// "1010101"\n2\n
// @lcpr case=end

// @lcpr case=start
// "11111"\n1\n
// @lcpr case=end

 */

