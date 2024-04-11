/*
 * @lc app=leetcode.cn id=1766 lang=cpp
 * @lcpr version=30122
 *
 * [1766] 互质树
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
class Solution1 {
public:
    class graph {
     public:
        int n;
        vector<pair<int, vector<int>>> g;
        vector<int> marked;
        vector<int> st;

        graph(vector<int>& nums, vector<vector<int>>& edges) : n(nums.size()), g(n), marked(n){
            for (int i = 0; i < n; i++) {
                g[i] = {nums[i], {}};
            }
            for (auto& vec : edges) {
                int from = vec[0], to = vec[1];
                g[from].second.push_back(to);
                g[to].second.push_back(from);
            }
        }

        void dfs(vector<int>& ans, int i) {
            marked[i] = 1;
            int val = g[i].first;
            for (int j = st.size() - 1; j >= 0; j--) {
                if (gcd(val, g[st[j]].first) == 1) {
                    ans[i] = st[j];
                    break;
                }
            }
            st.push_back(i);
            for (auto& adj : g[i].second) {
                if (!marked[adj]) {
                    dfs(ans, adj);
                }
            }
            st.pop_back();
        }

        void solve(vector<int>& ans) {
            dfs(ans, 0);
        }
    };

    // 超时
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        vector<int> ans(nums.size(), -1);
        graph g(nums, edges);
        g.solve(ans);
        return ans;
    }
};

class Solution {
public:
    class graph {
     public:
        int n;
        vector<pair<int, vector<int>>> g;
        vector<int> marked;
        // 每一个值出现的层级
        vector<vector<int>> pre;
        vector<vector<int>> pri;
        vector<vector<int>> hz;

        graph(vector<int>& nums, vector<vector<int>>& edges) : n(nums.size()), g(n), marked(n), pre(51), pri(51), hz(51){
            for (int i = 0; i < n; i++) {
                g[i] = {nums[i], {}};
            }
            for (auto& vec : edges) {
                int from = vec[0], to = vec[1];
                g[from].second.push_back(to);
                g[to].second.push_back(from);
            }
            for (int i = 1; i <= 50; i++) {
                for (int j = i + 1; j <= 50; j++) {
                    if (gcd(i, j) == 1) {
                        hz[i].push_back(j);
                        hz[j].push_back(i);
                    }
                }
            }
        }

        int getAns(int val) {
            int r = -1;
            int ans = -1;
            for (auto v : hz[val]) {
                if (!pre[v].empty()) {
                    if (pre[v].back() > r) {
                        ans = pri[v].back();
                        r = pre[v].back();
                    }
                }
            }
            return ans;
        }

        void dfs(vector<int>& ans, int i, int rank) {
            marked[i] = 1;
            int val = g[i].first;
            ans[i] = getAns(val);
            pre[val].push_back(rank);
            pri[val].push_back(i);
            for (auto& adj: g[i].second) {
                if (!marked[adj]) {
                    dfs(ans, adj, rank + 1);
                }
            }
            pre[val].pop_back();
            pri[val].pop_back();
        }

        void solve(vector<int>& ans) {
            dfs(ans, 0, 0);
        }
    };
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        vector<int> ans(nums.size(), -1);
        graph g(nums, edges);
        g.solve(ans);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,3,2]\n[[0,1],[1,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [5,6,10,2,3,6,15]\n[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]\n
// @lcpr case=end

 */

