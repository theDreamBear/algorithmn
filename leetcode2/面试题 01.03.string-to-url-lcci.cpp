/*
 * @lc app=leetcode.cn id=面试题 01.03 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 01.03] URL化
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
    string replaceSpaces1(string S, int length) {
        string ans;
        for (int i = 0; i < length; i++) {
            char ch = S[i];
            if (isspace(ch)) {
                ans += "%20";
            } else {
                ans.push_back(ch);
            }
        }
        return ans;
    }

    string replaceSpaces(string S, int length) {
        int n = S.size();
        int j = n - 1;
        for (int i = length - 1; i >= 0; i--) {
            if (isspace(S[i])) {
                S[j - 2] = '%';
                S[j - 1] = '2';
                S[j] = '0';
                j -= 3;
            } else {
                S[j--] = S[i];
            }
        }
        if (j < 0) {
            return S;
        }
        return S.c_str() + j + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "Mr John Smith    ", 13\n
// @lcpr case=end

// @lcpr case=start
// "               ", 5\n
// @lcpr case=end

 */

