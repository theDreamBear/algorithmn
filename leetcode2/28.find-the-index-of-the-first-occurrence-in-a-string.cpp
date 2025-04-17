/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30204
 *
 * [28] 找出字符串中第一个匹配项的下标
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
class KMP {
    public:
        vector<int> makeNext(const string& target) {
            int n = target.size();
            vector<int> next(n);
            for (int k = 0, i = 1; i < n; i++) {
                while (k and target[k] != target[i]) {
                    k = next[k - 1];
                }
                if (target[k] == target[i]) {
                    ++k;
                }
                next[i] = k;
            }
            return next;
        }
    
        int strstr(const string& source, const string& target) {
            auto next = makeNext(target);
            for (int k = 0, i = 0; i < source.size(); i++) {
                while (k and source[i] != target[k]) {
                    k = next[k - 1];
                }
                if (source[i] == target[k]) {
                    if (++k == target.size()) {
                        return i - target.size() + 1;
                    }
                }
            }
            return -1;
        }
};

class Z {
    public:
        vector<int> makeZ(const string& source, const string& des) {
            string s = des + source;
            int n = s.size();
            vector<int> z(n);
            z[0] = n;
            int l = 0, r = 0;
            for (int i = 1; i < n; i++) {
                if (i <= r) z[i] = min(z[i - l], r - i + 1);
                while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
                if (i + z[i] - 1 > r) {
                    r = i + z[i] - 1;
                    l = i;
                }
            }
            return z;
        }
        
        int strstr(const string& source, const string& des) {
            auto z = makeZ(source, des);
            for (int i = des.size(); i < z.size(); i++) {
                if (z[i] >= des.size()) {
                    return i - des.size();
                }
            }
            return -1;
        }
    };

class Solution {
public:
    int strStr(string haystack, string needle) {
        //return KMP{}.strstr(haystack, needle);
        return Z{}.strstr(haystack, needle);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */

