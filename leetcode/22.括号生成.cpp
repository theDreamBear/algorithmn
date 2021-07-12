/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <ranges.h>
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
    void insertRight(string& s, int pos, unordered_set<string>& exist,
                    vector<string>& ans) {
        int left = 0;
        int right = 0;
        for (int i = 0; i <= pos; ++i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
        }
        for (int j = pos + 1; j <= s.size(); ++j) {
            if (left - right == 1) {
                string temp = s;
                temp.insert(temp.begin() + j, ')');
                if (exist.find(temp) == exist.end()) {
                    exist.insert(temp);
                    ans.push_back(temp);
                }
            }
            if (s[j] == '(') {
                ++left;
            } else {
                ++right;
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        unordered_set<string> exist;
        vector<string> ans;
        if (n == 0) {
            return ans;
        }
        int i = 1;
        while (i <= n) {
            if (i != 1) {
                int sz = ans.size();
                vector<string> newCommer;
                for (int idx = 0; idx < sz; ++idx) {
                    string s = ans[idx];
                    for (int j = 0; j < s.size(); ++j) {
                        string news = s;
                        news.insert(news.begin() + j, '(');
                        insertRight(news, j, exist, newCommer);
                    }
                }
                ans = newCommer;
            } else {
                ans.emplace_back("()");
                exist.insert(move("()"));
            }
            ++i;
        }
        return ans;
    }
};

// java 实现的思路

// class Solution {
//     static List<String> allList = new ArrayList();
//     static HashSet hashSet = new HashSet();
//     public static List<String> generateParenthesis(int n) {
//         allList.clear();
//         hashSet.clear();
//         // 边界
//         if (n == 0) {
//             return allList;
//         }
//         if (n == 1) {
//             allList.add("()");
//             return allList;
//         }
//         backtrack(new StringBuilder(), n, 0, 0);
//         return allList;
//     }

//     public static void backtrack(StringBuilder builder, int n, int left, int right) {
//         hashSet.add(builder);
//         if(builder.length() >= 2 * n && left == right)
//         {
//             String str = builder.toString();
//             //if(!allList.contains(str)) {
//                 allList.add(builder.toString());
//             //}
//             return;
//         }
//         // 插入左括号
//         if (left >= right && left < n) {
//             builder.append('(');
//             if (!hashSet.contains(builder.toString())) {
//                 backtrack(builder, n, left + 1, right);
//             }
//             builder.deleteCharAt(builder.length() - 1);
//         }
//         // 插入右括号
//         if (left > right) {
//             builder.append(')');
//             if (!hashSet.contains(builder.toString())) {
//                 backtrack(builder, n, left, right + 1);
//             }
//             builder.deleteCharAt(builder.length() - 1);
//         }
//     }
// };

// @lc code=end

int main() {
    int n = 3;
    auto res = Solution{}.generateParenthesis(n);
    for (auto x : res) {
        cout << x << endl;
    }
}
