/*
 * @lc app=leetcode.cn id=3154 lang=cpp
 * @lcpr version=30204
 *
 * [3154] 到达第 K 级台阶的方案数
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

    template<class Function>
    memoize_nvec_helper(Function &&f, vector<int> vec_sz, R r) : f(std::forward<Function>(f)), dv(r) {
        for (int i = 0; i < Dim; ++i) {
            szs[i] = vec_sz[i];
        }
        initialize_cache(cache, szs);
    }

    template<class ...InnerArgs>
    R operator()(InnerArgs &&... args) {
        static_assert(sizeof...(args) == Dim, "Number of arguments must match the dimension.");
        std::array<int, Dim> indices = {std::forward<InnerArgs>(args)...};

        // 检查是否越界
        for (int i = 0; i < Dim; ++i) {
            if (indices[i] < 0 || indices[i] >= static_cast<int>(szs[i])) {
                return dv;
                //throw std::out_of_range("Index out of bounds");
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
    void initialize_cache(std::vector<R> &vec, const std::array<size_t, Dim> &sizes, size_t current_dim) {
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
private:
    using function_type = F;
    function_type f;
    mutable vector<R> cache;
    R dv;

public:
    template<class Function>
    memoize_vec_helper(Function &&f, int sz, R r, R bad) : f(std::forward<Function>(f)), cache(sz, r), dv(r) {}

    template<class InnerArgs>
    R operator()(InnerArgs &&arg) const {
        if (arg < 0 || arg >= cache.size()) {
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
private:
    using function_type = F;
    function_type f;
    mutable vector<vector<R>> cache;
    R dv;

public:
    template<class Function>
    memoize_vec_helper(Function &&f, int fs, int ss, R r) : f(std::forward<Function>(f)), cache(fs, vector<R>(ss, r)),
                                                            dv(r) {}

    template<typename IndexType>
    R operator()(IndexType first, IndexType second) const {
        // 这里需要修改，因为arg现在是一个pair或者tuple
        if (first < 0 || first >= cache.size() || second < 0 || second >= cache[first].size()) {
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
private:
    using function_type = F;
    function_type f;
    mutable vector<vector<vector<int>>> cache;
    R dv;

public:
    template<class Function>
    memoize_vec_helper(Function &&f, int fs, int ss, int ts, R r) : f(std::forward<Function>(f)),
                cache(fs,vector<vector<int>>(ss,vector<int>(ts,r))), dv(r) {}

    template<typename IndexType>
    R operator()(IndexType first, IndexType second, IndexType third) const {
        // 这里需要修改，因为arg现在是一个pair或者tuple
        if (first < 0 || first >= cache.size() || second < 0 || second >= cache[first].size() || third < 0 || third >= cache[first][second].size()) {
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
memoize_helper<Sig, std::decay_t<F>> cache(F &&f) {
    return memoize_helper<Sig, std::decay_t<F>>(std::forward<F>(f), null_param{});
}

/*
 * n纬度数组
 *
 * */
template<size_t Dim, class Sig, class F>
memoize_nvec_helper<Dim, Sig, std::decay_t<F>> cache_nvec(F &&f, vector<int> sz, int default_value) {
    return memoize_nvec_helper<Dim, Sig, std::decay_t<F>>(std::forward<F>(f), sz, default_value);
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
memoize_vec_helper<3, Sig, std::decay_t<F>> cache_vec3(F &&f, int sz, int sz2, int sz3, int default_value) {
    return memoize_vec_helper<3, Sig, std::decay_t<F>>(std::forward<F>(f), sz, sz2, sz3, default_value);
}

auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution1 {
public:
    int fast(int e) {
        int ans = 1;
        int base = 2;
        while (e) {
            if (e & 1) ans *= base;
            e >>= 1;
            if (e) {
                base *= base;
            }
        }
        return ans;
    }

    int waysToReachStair(int k) {
        struct Node {
            int pos, jump;
            bool isDow;

            bool operator < (const Node& other) const {
                if (pos != other.pos) return pos < other.pos;
                if (jump != other.jump) return jump < other.jump;
                return isDow < other.isDow;
            }
        };
        // pos, jump
        map<Node, int> dp;
        auto dfs = [&](auto&& dfs, Node x) {
            if (dp.contains(x)) {
                return dp[x];
            }
            int pos = x.pos, jump = x.jump, isDown = x.isDow;
            if (pos >= k + 2) {
                return 0;
            }
            int ans = 0;
            if (pos == k) ans++;
            if (!isDown and pos != 0) {
                ans += dfs(dfs, Node{.pos = pos - 1, .jump = jump, .isDow = 1});
            }
            // 往上
            ans += dfs(dfs, Node{.pos = pos + fast(jump), .jump = jump + 1, .isDow = 0});
            return dp[x] = ans;
        };
        return dfs(dfs, Node{.pos = 1, .jump = 0, .isDow = 0});
    }
};

int c[31][31];
auto init = []() {
    for (int i = 1; i < 31; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    return nullptr;
}();

class Solution {
public:
    int waysToReachStair1(int k) {
        auto memo = [&](auto&& dfs, int i, int f, int p)->int {
            if (i > k + 1 || i < 0) {
                return 0;
            }
            int ans = 0;
            if (i == k) {
                ans++;
            }
            if (f or i == 0) {
                ans += dfs(i + (1 << p), 0, p + 1);
            } else {
                ans += dfs(i - 1, 1, p);
                ans += dfs(i + (1 << p), 0, p + 1);
            }
            return ans;
        };
        return cache<int(int, int, int)>(memo)(1, 0, 0); // 120ms
    }

    // 89ms
    int waysToReachStair2(int k) {
        auto memo = [&](auto&& dfs, long long state)->int {
            long long i = state >> 32;
            long long p = (state & 0xfffffffe) >> 1;
            long long f = state & 1;
            if (i > k + 1 || i < 0) {
                return 0;
            }
            int ans = 0;
            if (i == k) {
                ans++;
            }
            if (f or i == 0) {
                // i + (1 << p), 0, p + 1
                ans += dfs(((i + (1 << p)) << 32) | ((p + 1) << 1));
            } else {
                // i - 1, 1, p
                ans += dfs(((i - 1) << 32) | (p << 1) | 1);
                ans += dfs(((i + (1 << p)) << 32) | ((p + 1) << 1));
            }
            return ans;
        };
        return cache<int(long long)>(memo)(1LL << 32);
    }

    int waysToReachStair(int k) {
        // m = 2^j - k;
        int ans = 0;
        for (int j = 0; j < 30; j++) {
            int m = (1 << j) - k;
            if (0 <= m and m <= j + 1) {
                ans += c[j + 1][m];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

