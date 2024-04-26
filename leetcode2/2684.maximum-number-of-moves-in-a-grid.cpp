/*
 * @lc app=leetcode.cn id=2684 lang=cpp
 * @lcpr version=30122
 *
 * [2684] 矩阵中移动的最大次数
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
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto memo = [&](auto& dfs, int i, int j) {
            if (i < 0 || j < 0 || i >= m || j >= n) {
                return -1;
            }
            int res = 0;
            if (i - 1 >= 0 and j + 1 < n and grid[i - 1][j + 1] > grid[i][j]) {
                res = max(res, dfs(i - 1, j + 1) + 1);
            }
            if (j + 1 < n and grid[i][j + 1] > grid[i][j]) {
                res = max(res, dfs(i, j + 1) + 1);
            }
            if (i + 1 < m and j + 1 < n and grid[i + 1][j + 1] > grid[i][j]) {
                res = max(res, dfs(i + 1, j + 1) + 1);
            }
            return res;
        };
        auto f = cache<int(int, int)>(memo);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, f(i, 0));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2,4],[2,1,9],[1,1,7]]\n
// @lcpr case=end

 */

