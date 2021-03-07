/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    /*
        极蠢的解法
    */
    string removeDuplicates1(string S) {
        int i = 0, sz = S.size();
        while (i < sz) {
            int ct = 1;
            while (i + 1 < sz && S[i + 1] == S[i]) {
                ++i;
                ++ct;
            }
            if (ct > 1) {
                if (ct % 2 != 0) {
                    --ct;
                }
                int pos = i - ct + 1;
                int j = i + 1;
                for (; j < sz; ++j) {
                    S[pos++] = S[j];
                }
                sz -= ct;
                i = 0;
            } else {
                ++i;
            }
        }
        return S.substr(0, sz);
    }

    /*
        栈
        或者 字符串模拟栈
    */ 
    string removeDuplicates2(string S) {
        string ans;
        for (auto c : S) {
            if (ans.empty() || ans.back() != c) {
                ans.push_back(c);
            } else {
                ans.pop_back();
            }
        }
        return ans;
    }

    /*
        [0, idx] 非重复区
        【idx + 1, i) 无效区
        【i, sz) 待处理区

        有点意思
    */
    string removeDuplicates(string S) {
        int idx = -1;
        for (int i = 0; i < S.size(); ++i) {
            if (idx == -1 || S[idx] != S[i]) {
                S[++idx] = S[i];
            } else if (S[idx] == S[i]) {
                --idx;
            }
        }
        return S.substr(0, idx + 1);
    }
};
// @lc code=end

int main() {
    cout << Solution{}.removeDuplicates("abbaca");
}