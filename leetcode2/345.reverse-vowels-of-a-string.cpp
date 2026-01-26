/*
 * @lc app=leetcode.cn id=345 lang=cpp
 * @lcpr version=30204
 *
 * [345] 反转字符串中的元音字母
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
    string reverseVowels(string s) {
        // 两个指针
        string t = "aeiouAEIOU";
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j and t.find(s[i]) == string::npos) i++;
            while (i < j and t.find(s[j]) == string::npos) j--;
            if (i < j) swap(s[i], s[j]);
        }
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "IceCreAm"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */

