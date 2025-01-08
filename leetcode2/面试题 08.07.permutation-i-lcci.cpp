/*
 * @lc app=leetcode.cn id=面试题 08.07 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 08.07] 无重复字符串的排列组合
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
    vector<string> permutation1(string S) {
        vector<string> ans;
        ranges:sort(S.begin(), S.end());
        do {
            ans.push_back(S);
        } while (next_permutation(S.begin(), S.end()));
        return ans;
    }

    vector<string> permutation2(string S) {
        vector<string> ans;
        int n = S.size();
        vector<int> vis(n);
        string tmp;
        auto dfs = [&](auto&& dfs) {
            if (tmp.size() >= n) {
                ans.push_back(tmp);
                return;
            }
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    vis[i] = 1;
                    tmp.push_back(S[i]);
                    dfs(dfs);
                    tmp.pop_back();
                    vis[i] = 0;
                }
            }
        };
        dfs(dfs);
        return ans;
    }

    // pick
    vector<string> permutation(string S) {
        vector<string> ans;
        int n = S.size();
        // pos 左边的都是已经选择过的
        auto dfs = [&](auto&& dfs, int pos) {
            if (pos >= n) {
                ans.push_back(S);
                return;
            }
            for (int i = pos; i < n; i++) {
                swap(S[i], S[pos]);
                dfs(dfs, pos + 1);
                swap(S[i], S[pos]);
            }
        };
        
        dfs(dfs, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "qwe"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n
// @lcpr case=end

 */

