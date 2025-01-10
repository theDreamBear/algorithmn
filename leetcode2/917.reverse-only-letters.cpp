/*
 * @lc app=leetcode.cn id=917 lang=cpp
 * @lcpr version=30204
 *
 * [917] 仅仅反转字母
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
    string reverseOnlyLetters(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j and !isalpha(s[i])) i++;
            while (i < j and !isalpha(s[j])) j--;
            if (i < j) swap(s[i], s[j]);
            if (i + 1 == j) break;
        }
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ab-cd"\n
// @lcpr case=end

// @lcpr case=start
// "a-bC-dEf-ghIj"\n
// @lcpr case=end

// @lcpr case=start
// code-Q!"\n
// @lcpr case=end

 */

