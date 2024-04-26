/*
 * @lc app=leetcode.cn id=931 lang=cpp
 * @lcpr version=30122
 *
 * [931] 下降路径最小和
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        auto memo = [&](auto& dfs, int i, int j)->int {
            if (i >= m || j >= n || i < 0 || j < 0) {
                return INT_MAX;
            }
            if (i == m - 1) {
                return matrix[i][j];
            }
            return min({dfs(i + 1, j), dfs(i + 1, j - 1), dfs(i + 1, j + 1)}) + matrix[i][j];
        };
        int ans = INT_MAX;
        auto dfs = cache<int(int, int)>(memo);
        for (int j = 0; j < n; j++) {
            ans = min(ans, dfs(0, j));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,3],[6,5,4],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[-19,57],[-40,-5]]\n
// @lcpr case=end

 */

