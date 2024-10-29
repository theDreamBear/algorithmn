// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=122 lang=cpp
 * @lcpr version=30204
 *
 * [122] 买卖股票的最佳时机 II
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
#include <string.h>
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

}

using namespace my_cache;


namespace my_tools {
#ifndef MY_REVERSE
#define AT(arr, ...) arr.at(__VA_ARGS__)
#else
#define AT(arr, ...) arr[__VA_ARGS__]
#endif

    template <typename T, T default_value, size_t first, size_t... rest>
    struct multi_array_helper {
        using type = std::array<typename multi_array_helper<T, default_value, rest...>::type, first>;
    };

    template <typename T, T default_value, size_t first>
    struct multi_array_helper<T, default_value, first> {
        using type = std::array<T, first>;
    };

    template <typename T, T default_value, size_t... dimensions>
    struct multi_array {
        using array_type = typename multi_array_helper<T, default_value, dimensions...>::type;
        array_type data;

        multi_array() : data{} {
            fill(data);
        }

        template <typename... Indices>
        auto operator()(Indices... indices) -> decltype(access(data, indices...)) {
            return access(data, indices...);
        }

        template <typename... Indices>
        auto operator()(Indices... indices) const -> decltype(access(data, indices...)) {
            return access(data, indices...);
        }

        auto& operator[](size_t index) {
            return AT(data, index);
        }

        const auto& operator[](size_t index) const {
            return AT(data, index);
        }

    private:
        template <typename U>
        typename std::enable_if<!std::is_array<U>::value>::type
        fill(U& arr) {
            arr.fill(default_value);
        }

        template <typename U>
        typename std::enable_if<std::is_array<U>::value>::type
        fill(U& arr) {
            for (auto& sub_arr : arr) {
                fill(sub_arr);
            }
        }

        template <typename U, typename... Indices>
        auto access(U& arr, size_t index, Indices... rest) -> decltype(access(arr[index], rest...)) {
            return access(arr[index], rest...);
        }

        template <typename U>
        auto access(U& arr, size_t index) -> decltype(arr[index]) {
            return arr[index];
        }
    };

    template<typename T, size_t N>
    class multi_vector;

// 特化版本用于递归终止（一维）
    template<typename T>
    class multi_vector<T, 1> {
        std::vector<T> data;
        T default_value;
    public:
        using container_type = std::vector<T>;

        multi_vector(T def_val, size_t size) : default_value(def_val), data(size, def_val) {}

        // 从vector构造
        multi_vector(T def_val, const container_type& vec)
                : default_value(def_val), data(vec) {}

        T& operator[](size_t i) { return AT(data, i); }
        const T& operator[](size_t i) const { return AT(data, i); }

        void resize(size_t new_size) {
            data.resize(new_size, default_value);
        }

        size_t size() const { return data.size(); }

        // 隐式转换
        operator container_type&() { return data; }
        operator const container_type&() const { return data; }

        // 显式获取
        container_type& vec() { return data; }
        const container_type& vec() const { return data; }

        // 赋值运算符
        multi_vector& operator=(const container_type& vec) {
            data = vec;
            return *this;
        }

        auto begin() { return data.begin(); }
        auto end() { return data.end(); }
        auto begin() const { return data.begin(); }
        auto end() const { return data.end(); }
        auto cbegin() const { return data.cbegin(); }
        auto cend() const { return data.cend(); }
    };

// 通用版本
    template<typename T, size_t N>
    class multi_vector {
        std::vector<multi_vector<T, N-1>> data;
        T default_value;

    public:
        using container_type = std::vector<multi_vector<T, N-1>>;
        using nested_container_type = std::vector<typename multi_vector<T, N-1>::container_type>;

        // 构造函数
        multi_vector(T def_val, const std::vector<size_t>& dims) : default_value(def_val) {
            if (dims.size() != N) {
                throw std::invalid_argument("Wrong number of dimensions");
            }
            data.reserve(dims[0]);
            std::vector<size_t> remaining_dims(dims.begin() + 1, dims.end());
            for (size_t i = 0; i < dims[0]; ++i) {
                data.emplace_back(default_value, remaining_dims);
            }
        }

        template<typename... Sizes>
        multi_vector(T def_val, size_t first, Sizes... rest) : default_value(def_val) {
            static_assert(sizeof...(rest) == N-1, "Wrong number of dimensions");
            data.reserve(first);
            for (size_t i = 0; i < first; ++i) {
                data.emplace_back(default_value, rest...);
            }
        }

        multi_vector(T def_val, std::initializer_list<size_t> dims) : default_value(def_val) {
            std::vector<size_t> vec_dims(dims.begin(), dims.end());
            if (vec_dims.size() != N) {
                throw std::invalid_argument("Wrong number of dimensions");
            }
            data.reserve(vec_dims[0]);
            std::vector<size_t> remaining_dims(vec_dims.begin() + 1, vec_dims.end());
            for (size_t i = 0; i < vec_dims[0]; ++i) {
                data.emplace_back(default_value, remaining_dims);
            }
        }

        // 从嵌套vector构造
        multi_vector(T def_val, const nested_container_type& nested_vec)
                : default_value(def_val) {
            data.reserve(nested_vec.size());
            for (const auto& vec : nested_vec) {
                data.emplace_back(default_value, vec);
            }
        }

        auto& operator[](size_t i) { return AT(data, i); }
        const auto& operator[](size_t i) const { return AT(data, i); }

        template<typename... Indices>
        auto& operator()(size_t first, Indices... rest) {
            static_assert(sizeof...(rest) == N-1, "Wrong number of indices");
            return data[first](rest...);
        }

        template<typename... Indices>
        const auto& operator()(size_t first, Indices... rest) const {
            static_assert(sizeof...(rest) == N-1, "Wrong number of indices");
            return data[first](rest...);
        }

        void resize(const std::vector<size_t>& new_sizes) {
            if (new_sizes.size() != N) {
                throw std::invalid_argument("Wrong number of dimensions");
            }
            data.resize(new_sizes[0],
                        multi_vector<T, N-1>(default_value,
                                             std::vector<size_t>(new_sizes.begin() + 1, new_sizes.end())));
        }

        size_t size() const { return data.size(); }

        // 隐式转换到直接容器
        operator container_type&() { return data; }
        operator const container_type&() const { return data; }

        // 显式获取容器
        container_type& vec() { return data; }
        const container_type& vec() const { return data; }

        // 获取嵌套容器
        nested_container_type to_nested_vector() const {
            nested_container_type result;
            result.reserve(data.size());
            for (const auto& v : data) {
                result.push_back(v.vec());
            }
            return result;
        }

        auto begin() { return data.begin(); }
        auto end() { return data.end(); }
        auto begin() const { return data.begin(); }
        auto end() const { return data.end(); }
        auto cbegin() const { return data.cbegin(); }
        auto cend() const { return data.cend(); }
    };

// 基本的make_vector函数 - 正确处理可变参数模板
    template<typename T, size_t N, typename... Args>
    auto make_vector(T def_val, size_t first, Args... dims) {
        static_assert(sizeof...(dims) == N-1, "Wrong number of dimensions");
        return multi_vector<T, N>(def_val, first, dims...);
    }

// 从vector构造的版本
    template<typename T, size_t N>
    auto make_vector(T def_val, const std::vector<size_t>& dims) {
        if (dims.size() != N) {
            throw std::invalid_argument("Wrong number of dimensions");
        }
        return multi_vector<T, N>(def_val, dims);
    }

// 从初始化列表构造的版本
    template<typename T, size_t N>
    auto make_vector(T def_val, std::initializer_list<size_t> dims) {
        if (dims.size() != N) {
            throw std::invalid_argument("Wrong number of dimensions");
        }
        return multi_vector<T, N>(def_val, dims);
    }

// 辅助函数：自动推导维度的版本
    template<typename T>
    auto make_vector(T def_val, std::initializer_list<size_t> dims) {
        return make_vector<T, dims.size()>(def_val, dims);
    }

}
using namespace my_tools;

class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        for (int i = 0; i < n; ) {
            int start = i++;
            while (i < n and prices[i] >= prices[i - 1]) i++;
            ans += (prices[i - 1] - prices[start]);
        }
        return ans;
    }

    int maxProfit2(vector<int>& prices) {
        // dp[i][0]
        auto hander = [&](int i, int j)->pair<bool, int> {
            if (i < 0) {
                if (j == 0) return {true, 0};
                return {true, INT_MIN / 2};
            }
            return {false, 0};
        };

        auto memo = [&](auto&& dfs, int i, int mask) {
            // 不这么写会得到边界默认值
            // 持有
            if (mask) {
                return max(dfs(i - 1, 1), dfs(i - 1, 0) - prices[i]);
            }
            return max(dfs(i - 1, 0), dfs(i - 1, 1) + prices[i]);
        };
        return cache_nvec<2, int(int, int)>(memo, {(int)prices.size(), 2}, -1, hander)((int)prices.size() - 1, 0);
    }

    int maxProfit3(vector<int>& prices) {
        // dp[i][0]
        auto hander = [&](int i, int j)->pair<bool, int> {
            if (i < 0) {
                if (j == 0) return {true, 0};
                return {true, INT_MIN / 2};
            }
            return {false, 0};
        };

        auto memo = [&](auto&& dfs, int i, int mask) {
            // 不这么写会得到边界默认值
            // 持有
            if (mask) {
                return max(dfs(i - 1, 1), dfs(i - 1, 0) - prices[i]);
            }
            return max(dfs(i - 1, 0), dfs(i - 1, 1) + prices[i]);
        };
        return cache<int(int, int)>(memo, hander)(prices.size() - 1, 0);
    }

    int maxProfit4(vector<int>& prices) {

        
        auto memo = [&](auto&& dfs, int i, int mask)->int {
            if (i < 0) {
                return mask == 0 ? 0 : INT_MIN / 2;
            }
            // 不这么写会得到边界默认值
            // 持有
            if (mask) {
                return max(dfs(i - 1, 1), dfs(i - 1, 0) - prices[i]);
            }
            return max(dfs(i - 1, 0), dfs(i - 1, 1) + prices[i]);
        };
        return cache<int(int, int)>(memo)(prices.size() - 1, 0);
    }

    int maxProfit5(vector<int>& prices) {
        int n = prices.size();
        int dp[n + 1][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0, dp[0][1] = INT_MIN / 2;
        for (int i = 0; i < n; i++) {
            dp[i + 1][0] = max(dp[i][1] + prices[i], dp[i][0]);
            dp[i + 1][1] = max(dp[i][0] - prices[i], dp[i][1]);
        }
        return max(dp[n][0], dp[n][1]);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int p0 = 0, p1 = INT_MIN / 2;
        for (int i = 0; i < n; i++) {
            int newp = max(p1 + prices[i], p0);
            p1 = max(p0 - prices[i], p1);
            p0 = newp;
        }
        return max(p0, p1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

