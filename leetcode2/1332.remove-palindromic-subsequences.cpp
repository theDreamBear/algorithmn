/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 * @lcpr version=30204
 *
 * [1332] 删除回文子序列
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
    int removePalindromeSub(string s) {
        // a b
        int ans = 0;
        while (true) {
            for (int i = 0, j = s.size() - 1; i <= j; ) {
                while (i <= j and s[i] == ' ') i++;
                if (i >= j) return ans + (j - i + 1);
                while (i <= j and s[j] != s[i]) j--;
                if ()


                
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ababa"\n
// @lcpr case=end

// @lcpr case=start
// "abb"\n
// @lcpr case=end

// @lcpr case=start
// "baabb"\n
// @lcpr case=end

 */

