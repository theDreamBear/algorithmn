/*
 * @lc app=leetcode.cn id=3136 lang=cpp
 * @lcpr version=30204
 *
 * [3136] 有效单词
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
    bool isValid(string word) {
        if (word.size() < 3) return false;
        int f[2]{};
        for (auto ch: word) {
            char low = tolower(ch);
            if (isalpha(low)) {
                f[low == 'a' or low == 'e' or low == 'i' or low == 'o' or low == 'u'] = 1;
            } else if (!isdigit(low)) return false;
        }
        return f[0] and f[1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "234Adas"\n
// @lcpr case=end

// @lcpr case=start
// "b3"\n
// @lcpr case=end

// @lcpr case=start
// "a3$e"\n
// @lcpr case=end

 */

