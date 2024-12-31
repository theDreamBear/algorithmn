/*
 * @lc app=leetcode.cn id=面试题 01.06 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 01.06] 字符串压缩
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
    string compressString(string S) {
       string res;
       // 分组循环
       for (int i = 0; i < S.size(); ) {
            int start = i++;
            while (i < S.size() and S[start] == S[i]) i++;
            res += S[start];
            res += to_string(i - start);
       }
       if (res.size() < S.size()) return res;
       return S;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aabcccccaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abbccd"\n
// @lcpr case=end

 */

