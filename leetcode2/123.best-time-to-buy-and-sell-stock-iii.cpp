/*
 * @lc app=leetcode.cn id=123 lang=cpp
 * @lcpr version=30204
 *
 * [123] 买卖股票的最佳时机 III
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
namespace my_cache {       template <typename Sig, class F> class memoize_helper;       template <typename R, typename... Args, class F> class memoize_helper<R(Args...), F> {       public:           using Boundary_func = function<pair<bool, R>(const Args&...)>;           using function_type   = F;           using args_tuple_type = tuple<Args...>;           function_type                   f;           mutable map<args_tuple_type, R> cache;           Boundary_func handler = nullptr;       public:           template <class Function> memoize_helper(Function&& f, Boundary_func handler = nullptr) : f(std::forward<Function>(f)), handler(handler) {}           memoize_helper(const memoize_helper& other) : f(other.f) {}           R operator()(const Args&... args) const {               if (handler) {                   if (auto res = handler(args...); res.first) {                       return res.second;                   }               }               auto args_tuple = make_tuple(args...);               auto it         = cache.find(args_tuple);               if (it != cache.end()) {                   return it->second;               }               auto result = f(*this, args...);               cache.emplace(args_tuple, result);               return result;           }       };       template<size_t Dim, typename R>       class cache_vec_helper : public cache_vec_helper<Dim - 1, R> {       public:           using type = vector<typename cache_vec_helper<Dim - 1, R>::type>;       };       template<typename R>       class cache_vec_helper<0, R> {       public:           using type = R;       };       template<size_t Dim, typename R, class F>       class memoize_nvec_helper;       template<size_t Dim, typename R, typename ...Args, class F>       class memoize_nvec_helper<Dim, R(Args...), F> {       public:           using function_type = F;           function_type f;           mutable typename cache_vec_helper<Dim, R>::type cache;           array<size_t, Dim> szs;           R dv;           using Boundary_func = function<pair<bool, R>(const Args&...)>;           Boundary_func handler = nullptr;           template<class Function>           memoize_nvec_helper(Function &&f, vector<int>& vec_sz, R r, Boundary_func handler = nullptr) : f(std::forward<Function>(f)), dv(r), handler(handler) {               for (int i = 0; i < Dim; ++i) {                   szs[i] = vec_sz[i];               }               initialize_cache(cache, szs);           }           template<class ...InnerArgs>           R operator()(InnerArgs &&... args) {               static_assert(sizeof...(args) == Dim, "Number of arguments must match the dimension.");               std::array<int, Dim> indices = {std::forward<InnerArgs>(args)...};               if (handler) {                   if (auto res = handler(args...); res.first) {                       return res.second;                   }               } else {                   for (int i = 0; i < Dim; ++i) {                       if (indices[i] < 0 || indices[i] >= static_cast<int>(szs[i])) {                           return dv;                       }                   }               }               return access_cache(cache, indices, std::make_index_sequence<Dim>{}, std::forward<InnerArgs>(args)...);           }       private:           template<typename T, size_t D>           void initialize_cache(std::vector<T> &vec, const std::array<size_t, D> &sizes, size_t current_dim = 0) {               vec.resize(sizes[current_dim]);               if (current_dim + 1 < D) {                   for (auto &sub_vec: vec) {                       initialize_cache(sub_vec, sizes, current_dim + 1);                   }               }           }           void initialize_cache(std::vector<R> &vec, const std::array<size_t, Dim> &sizes, size_t current_dim = 0) {               vec.resize(sizes[current_dim], dv);           }           template<size_t... Is, class ...InnerArgs>           R access_cache(typename cache_vec_helper<Dim, R>::type &cache, const std::array<int, Dim> &indices,                          std::index_sequence<Is...>, InnerArgs &&... args) {               return access_cache_impl(cache, indices, std::make_index_sequence<Dim>{}, std::forward<InnerArgs>(args)...);           }           template<size_t... Is, class ...InnerArgs>           R access_cache_impl(typename cache_vec_helper<sizeof ...(Is), R>::type &cache, const std::array<int, Dim> &indices,                               std::index_sequence<Is...>, InnerArgs &&... args) {               return access_cache_impl(cache, indices, std::index_sequence<Is...>{}, std::forward<InnerArgs>(args)...);           }           template<size_t First, size_t... Rest, class ...InnerArgs>           R access_cache_impl(typename cache_vec_helper<sizeof ...(Rest) + 1, R>::type &cache,                               const std::array<int, Dim> &indices, std::index_sequence<First, Rest...>,                               InnerArgs &&... args) {               return access_cache_impl(cache[indices[First]], indices, std::index_sequence<Rest...>{},                                        std::forward<InnerArgs>(args)...);           }           template<size_t Last, class ...InnerArgs>           R access_cache_impl(typename cache_vec_helper<1, R>::type &cache, const std::array<int, Dim> &indices,                               std::index_sequence<Last>, InnerArgs &&... args) {               auto &elem = cache[indices[Last]];               if (elem != dv) {                   return elem;               }               return elem = f(*this, std::forward<InnerArgs>(args)...);           }       };       template<int Dim, typename R, class F>       class memoize_vec_helper;       template<typename R, typename ...Args, class F>       class memoize_vec_helper<1, R(Args...), F> {       public:           using function_type = F;           function_type f;           mutable vector<R> cache;           R dv;           using Boundary_func = function<pair<bool, R>(const Args&...)>;           Boundary_func handler = nullptr;       public:           template<class Function>           memoize_vec_helper(Function &&f, int sz, R r, Boundary_func handler = nullptr) : f(std::forward<Function>(f)), cache(sz, r), dv(r), handler(handler) {}           template<class InnerArgs>           R operator()(InnerArgs &&arg) const {               if (handler) {                   if (auto res = handler(arg); res.first) {                       return res.second;                   }               } else if (arg < 0 || arg >= cache.size()) {                   return dv;               }               if (cache[arg] != dv) {                   return cache[arg];               }               return cache[arg] = f(*this, std::forward<InnerArgs>(arg));           }       };       template<typename R, typename ...Args, class F>       class memoize_vec_helper<2, R(Args...), F> {       public:           using function_type = F;           function_type f;           mutable vector<vector<R>> cache;           R dv;           using Boundary_func = function<pair<bool, R>(const Args&...)>;           Boundary_func handler = nullptr;       public:           template<class Function>           memoize_vec_helper(Function &&f, int fs, int ss, R r, Boundary_func handler = nullptr) : f(std::forward<Function>(f)), cache(fs, vector<R>(ss, r)),                                                                                                    dv(r), handler(handler) {}           template<typename IndexType>           R operator()(IndexType first, IndexType second) const {               if (handler) {                   if (auto res = handler(first, second); res.first) {                       return res.second;                   }               } else if (first < 0 || first >= cache.size() || second < 0 || second >= cache[first].size()) {                   return dv;               }               if (cache[first][second] != dv) {                   return cache[first][second];               }               return cache[first][second] = f(*this, first, second);           }       };       template<typename R, typename ...Args, class F>       class memoize_vec_helper<3, R(Args...), F> {       public:           using function_type = F;           function_type f;           mutable vector<vector<vector<int>>> cache;           R dv;           using Boundary_func = function<pair<bool, R>(const Args&...)>;           Boundary_func handler = nullptr;       public:           template<class Function>           memoize_vec_helper(Function &&f, int fs, int ss, int ts, R r, Boundary_func handler = nullptr) : f(std::forward<Function>(f)),                                                                                                            cache(fs,vector<vector<int>>(ss,vector<int>(ts,r))), dv(r), handler(handler) {}           template<typename IndexType>           R operator()(IndexType first, IndexType second, IndexType third) const {               if (handler) {                   if (auto res = handler(first, second, third); res.first) {                       return res.second;                   }               } else if (first < 0 || first >= cache.size() || second < 0 || second >= cache[first].size() || third < 0 || third >= cache[first][second].size()) {                   return dv;               }               if (cache[first][second][third] != dv) {                   return cache[first][second][third];               }               return cache[first][second][third] = f(*this, first, second, third);           }       };       template<class Sig, class F>       memoize_helper<Sig, std::decay_t<F>> cache(F &&f, typename memoize_helper<Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {           return memoize_helper<Sig, std::decay_t<F>>(std::forward<F>(f), handler);       }       template<size_t Dim, class Sig, class F>       memoize_nvec_helper<Dim, Sig, std::decay_t<F>> cache_nvec(F &&f, vector<int> sz, int default_value, typename memoize_nvec_helper<Dim, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {           return memoize_nvec_helper<Dim, Sig, std::decay_t<F>>(std::forward<F>(f), sz, default_value, handler);       }       template<class Sig, class F>       memoize_vec_helper<1, Sig, std::decay_t<F>> cache_vec(F &&f, int sz, int default_value, typename memoize_vec_helper<1, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {           return memoize_vec_helper<1, Sig, std::decay_t<F>>(std::forward<F>(f), sz, default_value, handler);       }       template<class Sig, class F>       memoize_vec_helper<2, Sig, std::decay_t<F>> cache_vec2(F &&f, int sz, int sz2, int default_value, typename memoize_vec_helper<2, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {           return memoize_vec_helper<2, Sig, std::decay_t<F>>(std::forward<F>(f), sz, sz2, default_value, handler);       }       template<class Sig, class F>       memoize_vec_helper<3, Sig, std::decay_t<F>> cache_vec3(F &&f, int sz, int sz2, int sz3, int default_value, typename memoize_vec_helper<3, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {           return memoize_vec_helper<3, Sig, std::decay_t<F>>(std::forward<F>(f), sz, sz2, sz3, default_value, handler);       }   };   using namespace my_cache;

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


class Solution {
public:
    int maxProfit_bad(vector<int>& prices) {
        // 进行一次
        auto one = [&]()->int {
            int mm = prices[0];
            int ans = 0;
            for (auto v : prices) {
                mm = min(mm, v);
                ans = max(ans, v - mm);
            }
            return ans;
        };
        //进行两次, 有问题因为++++ -- +++++ 这种对这种算法需要进行区间合并
        auto two = [&]()->int {
            int prepre = 0, pre = 0;
            int mm = prices[0];
            int ans = 0;
            for (int i = 0; i < prices.size(); ) {
                int start = i++;
                while (i < prices.size() and prices[i] >= prices[i - 1]) i++;
                int diff = prices[i - 1] - prices[start];
                if (diff > prepre) {
                    pre = prepre;
                    prepre = diff;
                } else if (diff > pre) {
                    pre = diff;
                }
            }
            return prepre + pre;
        };
        return max(one(), two());
    }

    int maxProfit1(vector<int>& prices) {
        auto memo = [&](auto&& dfs, int i, int j, int h) {
            if (j < 0) return INT_MIN / 2;
            if (i < 0) return h == 0 ? 0 : INT_MIN / 2;
            if (h) {
                return max(dfs(i - 1, j, h), dfs(i - 1, j - 1, 0) - prices[i]);
            }
            return max(dfs(i - 1, j, 0), dfs(i - 1, j, 1) + prices[i]);
        };
        return cache<int(int, int, int)>(memo)((int)prices.size() - 1, 2, 0);
    }

    int maxProfit2(vector<int>& prices) {
        auto handler = [&](int i, int j, int h)-> pair<bool, int> {
            if (j < 0) return {true, INT_MIN / 2};
            if (i < 0) return {true, h == 0 ? 0 : INT_MIN / 2};
            return {false, 0};
        };
        auto memo = [&](auto&& dfs, int i, int j, int h) {
            if (h) {
                return max(dfs(i - 1, j, h), dfs(i - 1, j - 1, 0) - prices[i]);
            }
            return max(dfs(i - 1, j, 0), dfs(i - 1, j, 1) + prices[i]);
        };
        return cache<int(int, int, int)>(memo, handler)((int)prices.size() - 1, 2, 0);
    }

    int maxProfit3(vector<int>& prices) {
        auto handler = [&](int i, int j, int h)-> pair<bool, int> {
            if (j < 0) return {true, INT_MIN / 2};
            if (i < 0) return {true, h == 0 ? 0 : INT_MIN / 2};
            return {false, 0};
        };
        auto memo = [&](auto&& dfs, int i, int j, int h) {
            if (h) {
                return max(dfs(i - 1, j, h), dfs(i - 1, j - 1, 0) - prices[i]);
            }
            return max(dfs(i - 1, j, 0), dfs(i - 1, j, 1) + prices[i]);
        };
        return cache_vec3<int(int, int, int)>(memo, (int)prices.size(), 3, 2, INT_MIN / 2, handler)((int)prices.size() -1, 2, 0);
    }

    int maxProfit4(vector<int>& prices) {
        auto handler = [&](int i, int j, int h)-> pair<bool, int> {
            if (j < 0) return {true, INT_MIN / 2};
            if (i < 0) return {true, h == 0 ? 0 : INT_MIN / 2};
            return {false, 0};
        };
        int n = prices.size();
        int dp[n][3][2];
        fill_array(&dp[0][0][0], INT_MIN / 2, n, 3, 2);
        auto get_v = [&](int i, int j, int h) {
            if (auto res = handler(i, j, h); res.first) {
                return res.second;
            }
            return dp[i][j][h];
        };
        // 这么写就可以少考虑越界问题了
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j][1] = max(get_v(i - 1, j ,1), get_v(i - 1, j - 1, 0) - prices[i]);
                dp[i][j][0] = max(get_v(i - 1, j, 0), get_v(i - 1, j, 1) + prices[i]);
            }
        }
        return dp[n - 1][2][0];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[3][2];
        fill_array(&dp[0][0], INT_MIN / 2, 3, 2);
        auto handler = [&](int i, int j, int h)-> pair<bool, int> {
            if (j < 0) return {true, INT_MIN / 2};
            if (i < 0) return {true, h == 0 ? 0 : INT_MIN / 2};
            return {false, 0};
        };
        auto get_v = [&](int i, int j, int h) {
            if (auto res = handler(i, j, h); res.first) {
                return res.second;
            }
            return dp[j][h];
        };
        for (int i = 0; i < n; i++) {
            for (int j = 2; j >= 0; j--) {
                dp[j][1] = max(get_v(i - 1, j, 1), get_v(i - 1, j - 1, 0) - prices[i]);
                dp[j][0] = max(get_v(i - 1, j, 0), get_v(i - 1, j, 1) + prices[i]);
            }
        }
        return dp[2][0];
    }

    int maxProfit5(vector<int>& prices) {
        // auto handler = [&](int i, int j, int h)-> pair<bool, int> {
        //     if (j < 0) return {true, INT_MIN / 2};
        //     if (i < 0) return {true, h == 0 ? 0 : INT_MIN / 2};
        //     return {false, 0};
        // };
        // dp[i][j][1] = dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i];
        // dp[i][j][0] = dp[i - 1][j][0], dp[i - 1][j][1] + price[i];
        int n = prices.size();
        int dp[4][2];
        fill_array(&dp[0][0], INT_MIN / 2, 4, 2);
        for (int j = 1; j < 4; j++) {
            dp[j][0] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 2; j >= 0; j--) {
                dp[j + 1][1] = max(dp[j + 1][1], dp[j][0] - prices[i]);
                dp[j + 1][0] = max(dp[j + 1][0], dp[j + 1][1] + prices[i]);
            }
        }
        return dp[3][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,3,5,0,0,3,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

