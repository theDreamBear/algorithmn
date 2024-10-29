/*
 * @lc app=leetcode.cn id=188 lang=cpp
 * @lcpr version=30204
 *
 * [188] 买卖股票的最佳时机 IV
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
namespace my_cache {

    template <typename Sig, class F> class memoize_helper;

    template <typename R, typename... Args, class F> class memoize_helper<R(Args...), F> {
    public:
        using Boundary_func = function<pair<bool, R>(const Args&...)>;
        using function_type   = F;
        using args_tuple_type = tuple<Args...>;

        function_type                   f;
        mutable map<args_tuple_type, R> cache;
        Boundary_func handler = nullptr;



    public:
        template <class Function> memoize_helper(Function&& f, Boundary_func handler = nullptr) : f(std::forward<Function>(f)), handler(handler) {}

        memoize_helper(const memoize_helper& other) : f(other.f) {}

        R operator()(const Args&... args) const {
            if (handler) {
                if (auto res = handler(args...); res.first) {
                    return res.second;
                }
            }
            auto args_tuple = make_tuple(args...);
            auto it         = cache.find(args_tuple);
            if (it != cache.end()) {
                return it->second;
            }
            auto result = f(*this, args...);
            cache.emplace(args_tuple, result);
            return result;
        }
    };


    template<size_t Dim, typename R>
    class cache_vec_helper : public cache_vec_helper<Dim - 1, R> {
    public:
        using type = vector<typename cache_vec_helper<Dim - 1, R>::type>;
    };

    template<typename R>
    class cache_vec_helper<0, R> {
    public:
        using type = R;
    };

    template<size_t Dim, typename R, class F>
    class memoize_nvec_helper;

    template<size_t Dim, typename R, typename ...Args, class F>
    class memoize_nvec_helper<Dim, R(Args...), F> {
    public:
        using function_type = F;
        function_type f;
        mutable typename cache_vec_helper<Dim, R>::type cache;
        array<size_t, Dim> szs;
        R dv;
        using Boundary_func = function<pair<bool, R>(const Args&...)>;
        Boundary_func handler = nullptr;

        template<class Function>
        memoize_nvec_helper(Function &&f, vector<int>& vec_sz, R r, Boundary_func handler = nullptr) : f(std::forward<Function>(f)), dv(r), handler(handler) {
            for (int i = 0; i < Dim; ++i) {
                szs[i] = vec_sz[i];
            }
            initialize_cache(cache, szs);
        }

        template<class ...InnerArgs>
        R operator()(InnerArgs &&... args) {
            static_assert(sizeof...(args) == Dim, "Number of arguments must match the dimension.");
            std::array<int, Dim> indices = {std::forward<InnerArgs>(args)...};
            if (handler) {
                if (auto res = handler(args...); res.first) {
                    return res.second;
                }
            } else {
                // 检查是否越界
                for (int i = 0; i < Dim; ++i) {
                    if (indices[i] < 0 || indices[i] >= static_cast<int>(szs[i])) {
                        return dv;
                        //throw std::out_of_range("Index out of bounds");
                    }
                }
            }
            // 访问或修改缓存
            return access_cache(cache, indices, std::make_index_sequence<Dim>{}, std::forward<InnerArgs>(args)...);
        }

    private:
        // 辅助函数用于递归地初始化 cache
        template<typename T, size_t D>
        void initialize_cache(std::vector<T> &vec, const std::array<size_t, D> &sizes, size_t current_dim = 0) {
            vec.resize(sizes[current_dim]);
            if (current_dim + 1 < D) {
                for (auto &sub_vec: vec) {
                    initialize_cache(sub_vec, sizes, current_dim + 1);
                }
            }
        }

        // 特化用于处理最后一个维度
        void initialize_cache(std::vector<R> &vec, const std::array<size_t, Dim> &sizes, size_t current_dim = 0) {
            vec.resize(sizes[current_dim], dv);
        }

        // 辅助函数用于递归地访问或修改缓存
        template<size_t... Is, class ...InnerArgs>
        R access_cache(typename cache_vec_helper<Dim, R>::type &cache, const std::array<int, Dim> &indices,
                       std::index_sequence<Is...>, InnerArgs &&... args) {
            return access_cache_impl(cache, indices, std::make_index_sequence<Dim>{}, std::forward<InnerArgs>(args)...);
        }

        // 实际递归访问缓存的实现
        template<size_t... Is, class ...InnerArgs>
        R access_cache_impl(typename cache_vec_helper<sizeof ...(Is), R>::type &cache, const std::array<int, Dim> &indices,
                            std::index_sequence<Is...>, InnerArgs &&... args) {
            return access_cache_impl(cache, indices, std::index_sequence<Is...>{}, std::forward<InnerArgs>(args)...);
        }

        template<size_t First, size_t... Rest, class ...InnerArgs>
        R access_cache_impl(typename cache_vec_helper<sizeof ...(Rest) + 1, R>::type &cache,
                            const std::array<int, Dim> &indices, std::index_sequence<First, Rest...>,
                            InnerArgs &&... args) {
            return access_cache_impl(cache[indices[First]], indices, std::index_sequence<Rest...>{},
                                     std::forward<InnerArgs>(args)...);
        }

        // 递归访问缓存的辅助函数
        template<size_t Last, class ...InnerArgs>
        R access_cache_impl(typename cache_vec_helper<1, R>::type &cache, const std::array<int, Dim> &indices,
                            std::index_sequence<Last>, InnerArgs &&... args) {
            auto &elem = cache[indices[Last]];
            if (elem != dv) {
                return elem;
            }
            // 获取每一参数
            // 获取indices 的每一个成员
            // 递归调用
            return elem = f(*this, std::forward<InnerArgs>(args)...);
        }
    };


    template<int Dim, typename R, class F>
    class memoize_vec_helper;

    // 一维数组的特化
    template<typename R, typename ...Args, class F>
    class memoize_vec_helper<1, R(Args...), F> {
    public:
        using function_type = F;
        function_type f;
        mutable vector<R> cache;
        R dv;
        using Boundary_func = function<pair<bool, R>(const Args&...)>;
        Boundary_func handler = nullptr;

    public:
        template<class Function>
        memoize_vec_helper(Function &&f, int sz, R r, Boundary_func handler = nullptr) : f(std::forward<Function>(f)), cache(sz, r), dv(r), handler(handler) {}

        template<class InnerArgs>
        R operator()(InnerArgs &&arg) const {
            if (handler) {
                if (auto res = handler(arg); res.first) {
                    return res.second;
                }
            } else if (arg < 0 || arg >= cache.size()) {
                return dv;
            }
            if (cache[arg] != dv) {
                return cache[arg];
            }
            return cache[arg] = f(*this, std::forward<InnerArgs>(arg));
        }
    };

    // 二维数组的特化
    template<typename R, typename ...Args, class F>
    class memoize_vec_helper<2, R(Args...), F> {
    public:
        using function_type = F;
        function_type f;
        mutable vector<vector<R>> cache;
        R dv;
        using Boundary_func = function<pair<bool, R>(const Args&...)>;
        Boundary_func handler = nullptr;

    public:
        template<class Function>
        memoize_vec_helper(Function &&f, int fs, int ss, R r, Boundary_func handler = nullptr) : f(std::forward<Function>(f)), cache(fs, vector<R>(ss, r)),
                                                                                                 dv(r), handler(handler) {}

        template<typename IndexType>
        R operator()(IndexType first, IndexType second) const {
            if (handler) {
                if (auto res = handler(first, second); res.first) {
                    return res.second;
                }
            } else if (first < 0 || first >= cache.size() || second < 0 || second >= cache[first].size()) {
                return dv;
            }
            if (cache[first][second] != dv) {
                return cache[first][second];
            }
            return cache[first][second] = f(*this, first, second);
        }
    };

    // 三维数组的特化
    template<typename R, typename ...Args, class F>
    class memoize_vec_helper<3, R(Args...), F> {
    public:
        using function_type = F;
        function_type f;
        mutable vector<vector<vector<int>>> cache;
        R dv;
        using Boundary_func = function<pair<bool, R>(const Args&...)>;
        Boundary_func handler = nullptr;

    public:
        template<class Function>
        memoize_vec_helper(Function &&f, int fs, int ss, int ts, R r, Boundary_func handler = nullptr) : f(std::forward<Function>(f)),
                                                                                                         cache(fs,vector<vector<int>>(ss,vector<int>(ts,r))), dv(r), handler(handler) {}

        template<typename IndexType>
        R operator()(IndexType first, IndexType second, IndexType third) const {
            if (handler) {
                if (auto res = handler(first, second, third); res.first) {
                    return res.second;
                }
            } else if (first < 0 || first >= cache.size() || second < 0 || second >= cache[first].size() || third < 0 || third >= cache[first][second].size()) {
                return dv;
            }
            // 这里需要修改，因为arg现在是一个pair或者tuple
            if (cache[first][second][third] != dv) {
                return cache[first][second][third];
            }
            return cache[first][second][third] = f(*this, first, second, third);
        }
    };


    /**
     * @brief  cache使用map
     */
    template<class Sig, class F>
    memoize_helper<Sig, std::decay_t<F>> cache(F &&f, typename memoize_helper<Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {
        return memoize_helper<Sig, std::decay_t<F>>(std::forward<F>(f), handler);
    }

    /*
     * n纬度数组
     *
     * */
    template<size_t Dim, class Sig, class F>
    memoize_nvec_helper<Dim, Sig, std::decay_t<F>> cache_nvec(F &&f, vector<int> sz, int default_value, typename memoize_nvec_helper<Dim, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {
        return memoize_nvec_helper<Dim, Sig, std::decay_t<F>>(std::forward<F>(f), sz, default_value, handler);
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
    memoize_vec_helper<1, Sig, std::decay_t<F>> cache_vec(F &&f, int sz, int default_value, typename memoize_vec_helper<1, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {
        return memoize_vec_helper<1, Sig, std::decay_t<F>>(std::forward<F>(f), sz, default_value, handler);
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
    memoize_vec_helper<2, Sig, std::decay_t<F>> cache_vec2(F &&f, int sz, int sz2, int default_value, typename memoize_vec_helper<2, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {
        return memoize_vec_helper<2, Sig, std::decay_t<F>>(std::forward<F>(f), sz, sz2, default_value, handler);
    }


    // 创建三维数组的函数
    /***
     * @brief
     * @param f 函数
     * @param sz 第一维数组大小
     * @param sz2 第二维数组大小
     * @param sz3 第三维数组大小
     * @param default_value 默认值
     * @return
     */
    template<class Sig, class F>
    memoize_vec_helper<3, Sig, std::decay_t<F>> cache_vec3(F &&f, int sz, int sz2, int sz3, int default_value, typename memoize_vec_helper<3, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {
        return memoize_vec_helper<3, Sig, std::decay_t<F>>(std::forward<F>(f), sz, sz2, sz3, default_value, handler);
    }

    // 计算数组总大小的辅助函数
template<typename T>
constexpr std::size_t total_size(T value) {
    return static_cast<std::size_t>(value);
}

template<typename T, typename... Args>
constexpr std::size_t total_size(T first, Args... args) {
    return static_cast<std::size_t>(first) * total_size(args...);
}

// 填充函数
template<typename T, typename... Args>
void fill_array(T* arr, T value, Args... dims) {
    static_assert(sizeof...(dims) > 0, "At least one dimension required");
    static_assert((std::is_integral_v<Args> && ...), "All dimensions must be integral");
    std::fill_n(arr, total_size(dims...), value);
}
}

using namespace my_cache;

class Solution {
public:
    int maxProfit1(int k, vector<int>& prices) {
          // dp[i][0]
        auto hander = [&](int i, int k, int hold)->pair<bool, int> {
            if (k < 0) {
                return {true, INT_MIN / 2}; 
            }
            if (i < 0) {
                if (hold == 0) return {true, 0};
                return {true, INT_MIN / 2};
            }
            return {false, 0};
        };

        auto memo = [&](auto&& dfs, int i, int k, int hold) {
            // 不这么写会得到边界默认值
            // 持有
            if (hold) {
                return max(dfs(i - 1, k, hold), dfs(i - 1, k - 1, !hold) - prices[i]);
            }
            return max(dfs(i - 1, k, hold), dfs(i - 1, k, !hold) + prices[i]);
        };
        return cache_nvec<3, int(int, int, int)>(memo, {(int)prices.size(), k + 1, 2}, -1, hander)((int)prices.size() - 1, k, 0);
    }

    // k == 1 dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - 1][0] - prices[i])
    // k == 0 dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j][1] + prices[i])
    // 整体往前+1
    int maxProfit2(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[n + 1][k + 2][2];
        fill_array(&dp[0][0][0], INT_MIN / 2, n + 1, k + 2, 2);
        // j = 0 是非法的
        for (int j = 1; j < k + 2; j++) {
            dp[0][j][0] = 0;
        }
        // f[0, j, 0] = 0
        // 其他
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k + 1; j++) {
                dp[i + 1][j + 1][1] = max(dp[i][j + 1][1], dp[i][j][0] - prices[i]);
                dp[i + 1][j + 1][0] = max(dp[i][j + 1][0], dp[i][j + 1][1] + prices[i]);
            }
        }
        return dp[n][k + 1][0];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[k + 2][2];
        fill_array(&dp[0][0], INT_MIN / 2, k + 2, 2);
        // j = 0 是非法的
        for (int j = 1; j < k + 2; j++) {
            dp[j][0] = 0;
        }
        // f[0, j, 0] = 0
        // 其他
        for (int i = 0; i < n; i++) {
            for (int j = k; j >= 0; j--) {
                dp[j + 1][1] = max(dp[j + 1][1], dp[j][0] - prices[i]);
                dp[j + 1][0] = max(dp[j + 1][0], dp[j + 1][1] + prices[i]);
            }
        }
        return dp[k + 1][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[2,4,1]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[3,2,6,5,0,3]\n
// @lcpr case=end

 */

