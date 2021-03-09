/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */
 #include <iostream>
 #include <utility>
 #include <string>
 #include <string.h>
 #include <vector>
 #include <map>
 #include <set>
 #include <stack>
 #include <queue>
 #include <unordered_map>
 #include <unordered_set>
 #include <algorithm>
 #include <numeric>

 using namespace std;

// @lc code=start
class Solution {
public:
    int balancedStringSplit1(string s) {
        int cl = 0, cr = 0, i = 0, ans = 0;
        do {
            if (s[i] == 'L') {
                ++cl;
            } else {
                ++cr;
            }
            if (cl == cr) {
                cl = 0;
                cr = 0;
                ++ans;
            }
            ++i;
        } while (i < s.size());
        return ans;
    }

    /*
        L和R的中间字符O,即L-O=-3;R-O=3,
        原串就可以转化为3和-3的序列,这么看思路就很清晰了
    */
    int balancedStringSplit(string s) {
        int sum = 0, num = 0;
        for (auto c : s) {
            sum += ((num += (c - 'O')) == 0);
        }
        return sum;
    }
};
// @lc code=end

