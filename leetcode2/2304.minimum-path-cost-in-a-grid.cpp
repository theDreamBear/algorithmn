/*
 * @lc app=leetcode.cn id=2304 lang=cpp
 * @lcpr version=30122
 *
 * [2304] 网格中的最小路径代价
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
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class null_param {
};
template<typename Sig, class F>
class memoize_helper;

template<typename R, typename... Args, class F>
class memoize_helper<R(Args...), F> {
private:
    using function_type = F;
    using args_tuple_type = tuple<Args...>;

    function_type f;
    mutable map<args_tuple_type, R> cache;

public:
    template<class Function>
    memoize_helper(Function &&f, null_param) : f(std::forward<Function>(f)) {}

    memoize_helper(const memoize_helper &other) : f(other.f) {}

    template<class ...InnerArgs>
    R operator()(InnerArgs &&... args) const {
        auto args_tuple = make_tuple(std::forward<InnerArgs>(args)...);
        auto it = cache.find(args_tuple);
        if (it != cache.end()) {
            return it->second;
        }
        return cache[args_tuple] = f(*this, std::forward<InnerArgs>(args)...);
    }
};

template<class Sig, class F>
memoize_helper<Sig, std::decay_t<F>> cache(F &&f) {
    return memoize_helper<Sig, std::decay_t<F>>(std::forward<F>(f), null_param{});
}

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        auto memo = [&](auto& dfs, int i, int j)->int {
            if (i < 0 || j < 0 | i >= m || j >= n) {
                return INT_MAX;
            }
            if (i == m - 1) {
                return grid[i][j];
            }
            int v = grid[i][j];
            int res = INT_MAX;
            for (int k = 0; k < n; k++) {
                res = min(res, dfs(i + 1, k) + v + moveCost[v][k]);
            }
            return res;
        };
        int ans = INT_MAX;
        auto f = cache<int(int, int)>(memo);
        for (int j = 0; j < n; j++) {
            ans = min(ans, f(0, j));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[5,3],[4,0],[2,1]]\n[[9,8],[1,5],[10,12],[18,6],[2,4],[14,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,2],[4,0,3]]\n[[12,10,15],[20,23,8],[21,7,1],[8,1,13],[9,10,25],[5,3,2]]\n
// @lcpr case=end

 */

