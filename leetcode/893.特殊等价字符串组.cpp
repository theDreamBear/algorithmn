/*
 * @lc app=leetcode.cn id=893 lang=cpp
 *
 * [893] 特殊等价字符串组
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    string weirdSortKey(const string& str) {
        string odd, even;
        for (int i = 0; i < str.size(); ++i) {
            if (i % 2 != 0) {
                odd.push_back(str[i]);
            } else {
                even.push_back(str[i]);
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        return odd + even;
    }

    int numSpecialEquivGroups(vector<string>& A) {
        unordered_map<string, int> hash;
        for (auto& str: A) {
            ++hash[move(weirdSortKey(str))];
        }

        return hash.size();
    }

    // 如果只是比较两个字符串是否能够特殊等价, 可以如下面的方法

    bool specialEqual(const string& lhs, const string& rhs) {
        vector<int> h(52);
        for (int i = 0; i < lhs.size(); ++i) {
            ++h[lhs[i] + ((i % 2 == 0) ? 1 : 0)];
        }

        for (int i = 0; i < rhs.size(); ++i) {
            --h[lhs[i] + ((i % 2 == 0) ? 1 : 0)];
        }

        for (auto v : h) {
            if (v != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
