/*
 * @lc app=leetcode.cn id=2375 lang=cpp
 * @lcpr version=30204
 *
 * [2375] 根据模式串构造最小数字
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
    string smallestNumber1(string pattern) {
        int n = pattern.size() + 1;
        string s;
        for (int i = 1; i <= n; i++) {
            s.push_back(i + '0');
        }
        do {
            bool ok = true;
            for (int i = 0; i + 1 < n; i++) {
                if (pattern[i] == 'I') {
                    if (s[i] > s[i + 1]) {
                        ok = false;
                        break;
                    }
                } else {
                    if (s[i] < s[i + 1]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                break;
            }
        } while (next_permutation(s.begin(), s.end()));
        return s;
    }

    string smallestNumber(string pattern) {
        int n = pattern.size();
        string s(n + 1, '0');
        char cur = '1';
        for (int i = 0; i < n; ) {
            if (i and pattern[i] == 'I') i++;
            while (i < n and pattern[i] == 'I') {
                s[i++] = cur++;
            }
            int start = i;
            while (i < n and pattern[i] == 'D') i++;
            for (int j = i; j >= start; j--) s[j] = cur++;
        }
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "IIIDIDDD"\n
// @lcpr case=end

// @lcpr case=start
// "DDD"\n
// @lcpr case=end

 */

