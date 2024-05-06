/*
 * @lc app=leetcode.cn id=741 lang=cpp
 * @lcpr version=30122
 *
 * [741] 摘樱桃
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

template<int Dim, typename R, class F>
class memoize_vec_helper;

// 一维数组的特化
template<typename R, typename ...Args, class F>
class memoize_vec_helper<1, R(Args...), F> {
private:
    using function_type = F;
    function_type f;
    mutable vector<R> cache;
    R dv;

public:
    template<class Function>
    memoize_vec_helper(Function &&f, int sz, R r, R bad) : f(std::forward<Function>(f)), cache(sz, r), dv(r) {}

    template<class InnerArgs>
    R operator()(InnerArgs && arg) const {
        if (cache[arg] != dv) {
            return cache[arg];
        }
        return cache[arg] = f(*this, std::forward<InnerArgs>(arg));
    }
};

// 二维数组的特化
template<typename R, typename ...Args, class F>
class memoize_vec_helper<2, R(Args...), F> {
private:
    using function_type = F;
    function_type f;
    mutable vector<vector<R>> cache;
    R dv;

public:
    template<class Function>
    memoize_vec_helper(Function &&f, int fs, int ss, R r) : f(std::forward<Function>(f)), cache(fs, vector<R>(ss, r)), dv(r){}

    template<typename IndexType>
    R operator()(IndexType first, IndexType second) const {
        // 这里需要修改，因为arg现在是一个pair或者tuple
        if (cache[first][second] != dv) {
            return cache[first][second];
        }
        return cache[first][second] = f(*this, first, second);
    }
};

/**
 * @brief  cache使用map
 *
 * @tparam Sig
 * @tparam F
 * @param f
 * @return memoize_helper<Sig, std::decay_t<F>>
 */
template<class Sig, class F>
memoize_helper<Sig, std::decay_t<F>> cache(F &&f) {
    return memoize_helper<Sig, std::decay_t<F>>(std::forward<F>(f), null_param{});
}

// 创建一维数组的函数
/***
 * @brief  chache 使用一维数组
 * @param f 函数
 * @param sz 数组大小
 * @param default_value 默认值
 * @return
 */
template<class Sig, class F>
memoize_vec_helper<1, Sig, std::decay_t<F>> cache_vec(F &&f, int sz, int default_value) {
    return memoize_vec_helper<1, Sig, std::decay_t<F>>(std::forward<F>(f), sz, default_value);
}

// 创建二维数组的函数
/***
 * @brief cache 使用二维数组
 * @param f 函数
 * @param sz 第一维数组大小
 * @param sz2 第二维数组大小
 * @param default_value 默认值
 * @return
 */
template<class Sig, class F>
memoize_vec_helper<2, Sig, std::decay_t<F>> cache_vec2(F &&f, int sz, int sz2, int default_value) {
    return memoize_vec_helper<2, Sig, std::decay_t<F>>(std::forward<F>(f), sz, sz2, default_value);
}
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        auto memo = [&](auto& dfs, int t, int j, int k) {
            if (t < j || t < k || j < 0 || k < 0 || grid[t - j][j] < 0 || grid[t - k][k] < 0) {
                return INT_MIN;
            }
            if (t == 0) {
                return grid[0][0];
            }
            return max({dfs(t - 1, j - 1, k - 1), dfs(t - 1, j, k), dfs(t - 1, j, k - 1), dfs(t - 1, j - 1, k)}) +
                grid[t - j][j] + ((j != k) ? grid[t - k][k] : 0);
        };
        auto ans = cache<int(int, int, int)>(memo)(2 * n - 2, n - 1, n - 1);
        return max(0, ans);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,-1],[1,0,-1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,-1],[1,-1,1],[-1,1,1]]\n
// @lcpr case=end

 */

