/*
 * @lc app=leetcode.cn id=824 lang=cpp
 * @lcpr version=30204
 *
 * [824] 山羊拉丁文
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string toGoatLatin1(string sentence) {
        string ans;
        // a e i o u 下标
        // 0 5 
        int cnt[300]{};
        cnt['a'] = cnt['e'] = cnt['i'] = cnt['o'] = cnt['u'] = 1;
        cnt['A'] = cnt['E'] = cnt['I'] = cnt['O'] = cnt['U'] = 1;
        auto p = strtok((char*)sentence.c_str(), " ");
        int idx = 1;
        while (p) {
            string tmp(p);
            if (cnt[tmp[0]]) {
                tmp += "ma" + string(idx, 'a');
            } else {
                char ch = tmp[0];
                tmp = tmp.substr(1);
                tmp += string(1, ch) + "ma" + string(idx, 'a');
            }
            ans += tmp;
            idx++;
            p = strtok(NULL, " ");
            if (p) {
                ans += ' ';
            }
        }
        return ans;
    }

    string toGoatLatin(string sentence) {
        string ans;
        // a e i o u 下标
        // 0 5 
        int cnt[300]{};
        cnt['a'] = cnt['e'] = cnt['i'] = cnt['o'] = cnt['u'] = 1;
        cnt['A'] = cnt['E'] = cnt['I'] = cnt['O'] = cnt['U'] = 1;
        stringstream ss(sentence);
        string tmp;
        int idx = 1;
        while (getline(ss, tmp, ' ')) {
            if (cnt[tmp[0]]) {
                tmp += "ma" + string(idx, 'a');
            } else {
                char ch = tmp[0];
                tmp = tmp.substr(1);
                tmp += string(1, ch) + "ma" + string(idx, 'a');
            }
            ans += tmp;
            idx++;
            ans += ' ';
        }
        if (!ans.empty()) ans.pop_back();
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "I speak Goat Latin"\n
// @lcpr case=end

// @lcpr case=start
// "The quick brown fox jumped over the lazy dog"\n
// @lcpr case=end

 */

