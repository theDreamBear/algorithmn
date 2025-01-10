/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 * @lcpr version=30204
 *
 * [1078] Bigram 分词
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
    vector<string> findOcurrences1(string text, string first, string second) {
        vector<string> ans;
        stringstream is(text);
        string name;
        int id = 0;
        while(is >> name) {
            if (id == 2) {
                ans.push_back(name);
                id = 0;
                // 一样的
                if (first == second) {
                    id = 1;
                    if (name == second) {
                        id++;
                    }
                }
                else if (name == first) id = 1;
            } else if (id == 1 and name == second) id++;
            else if (name == first) id = 1;
            else id = 0;
        }
        return ans;
    }

    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        stringstream is(text);
        string name;
        int id = 0;
        string prepre, pre;
        while(is >> name) {
            if (prepre == "") prepre = name;
            else if (pre == "") pre = name;
            else {
                if (prepre == first and pre == second) {
                    ans.push_back(name);
                }
                prepre = pre;
                pre = name;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "alice is a good girl she is a good student"\n"a"\n"good"\n
// @lcpr case=end

// @lcpr case=start
// "we will we will rock you"\n"we"\n"will"\n
// @lcpr case=end

 */

