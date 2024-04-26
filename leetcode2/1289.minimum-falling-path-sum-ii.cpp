/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 * @lcpr version=30122
 *
 * [1289] 下降路径最小和  II
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
#include <set>
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
    int minFallingPathSum2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int t = 0;
        auto memo = [&](auto& dfs, int i , int j)->int {
            if (i >= m || j >= n) {
                return INT_MAX;
            }
            if (i == m - 1) {
                return grid[i][j];
            }
            int ans = INT_MAX;
            for (int k = 0; k < n; k++) {
                if (j == k){
                    continue;
                }
                t++;
                ans = min(ans, dfs(i + 1, k) + grid[i][j]);
            }
            cout << t << endl;
            return ans;
        };
        int ans = INT_MAX;
        auto f = cache_vec2<int(int, int)>(memo, 200, 200, -100000);
        for (int j = 0; j < n; j++) {
            ans = min(ans, f(0, j));
        }
        return ans;
    }

    int minFallingPathSum1(vector<vector<int>>& grid) {
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int res = INT_MAX;
                for (int k = 0; k < grid[0].size(); k++) {
                    if (k == j) {
                        continue;
                    }
                    res = min(res, grid[i - 1][k]);
                }
                grid[i][j] += res;
            }
        }
        return ranges::min(grid.back());
    }

    int minFallingPathSum3(vector<vector<int>>& grid) {
        map<int, int> mm;
        for (auto v : grid[0]) {
            mm[v]++;
        } 
        for (int i = 1; i < grid.size(); i++) {
            map<int, int> next;
            for (int j = 0; j < grid[0].size(); j++) {
                int v = grid[i - 1][j];
                int res;
                auto it = mm.begin();
                if (it->first != v || it->second > 1) {
                    res = it->first;
                } else {
                    res = (++it)->first;
                }
                grid[i][j] += res;
                next[grid[i][j]]++;
            }
            mm = next;
        }
        return ranges::min(grid.back());
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int mm = INT_MAX, nmm = INT_MAX;
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[0][j] < mm) {
                swap(mm, nmm);
                mm = grid[0][j];
            } else if (grid[0][j] < nmm) {
                nmm = grid[0][j];
            }
        }
        for (int i = 1; i < grid.size(); i++) {
            int xmm = INT_MAX, xnmm = INT_MAX;
            for (int j = 0; j < grid[0].size(); j++) {
                grid[i][j] += grid[i - 1][j] == mm ? nmm : mm;
                if (grid[i][j] < xmm) {
                    swap(xmm, xnmm);
                    xmm = grid[i][j];
                } else if (grid[i][j] < xnmm) {
                    xnmm = grid[i][j];
                }
            }
            mm = xmm;
            nmm = xnmm;
        }
        return ranges::min(grid.back());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[7]]\n
// @lcpr case=end

 */

