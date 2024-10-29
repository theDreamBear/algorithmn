namespace my_uf {

template <typename T> class UF {
  public:
    vector<T> fa;
    int       groupCnt;

    UF(int n) : fa(n) {
        iota(fa.begin(), fa.end(), 0);
        groupCnt = n;
    }

    T find(T u) {
        if (fa[u] == u) {
            return u;
        }
        return fa[u] = find(fa[u]);
    }

    void merge(T u, T v) {
        T pu = find(u), pv = find(v);
        if (pu == pv)
            return;
        --groupCnt;
        if (pu == fa.size() - 1) {
            fa[pv] = pu;
        } else {
            fa[pu] = pv;
        }
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    int cnt() {
        return groupCnt;
    }
};

template <typename T> class UFR {
  public:
    vector<T> fa, rank;
    int       groupCnt;

    UFR(int n) : fa(n), rank(n) {
        iota(fa.begin(), fa.end(), 0);
        fill(rank.begin(), rank.end(), 1);
        groupCnt = n;
    }

    T find(T u) {
        if (fa[u] == u) {
            return u;
        }
        return fa[u] = find(fa[u]);
    }

    void merge(T u, T v) {
        T pu = find(u), pv = find(v);
        if (pu == pv)
            return;
        --groupCnt;
        if (rank[pu] >= rank[pv]) {
            fa[pv] = pu;
            rank[pu] += rank[pv];
        } else {
            fa[pu] = pv;
            rank[pv] += rank[pu];
        }
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    int cnt() {
        return groupCnt;
    }
};

};  // namespace my_uf
using namespace my_uf;

namespace my_cache {

template <typename Sig, class F> class memoize_helper;

template <typename R, typename... Args, class F> class memoize_helper<R(Args...), F> {
  public:
    using Boundary_func   = function<pair<bool, R>(const Args&...)>;
    using function_type   = F;
    using args_tuple_type = tuple<Args...>;

    function_type                   f;
    mutable map<args_tuple_type, R> cache;
    Boundary_func                   handler = nullptr;

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

template <size_t Dim, typename R> class cache_vec_helper : public cache_vec_helper<Dim - 1, R> {
  public:
    using type = vector<typename cache_vec_helper<Dim - 1, R>::type>;
};

template <typename R> class cache_vec_helper<0, R> {
  public:
    using type = R;
};

template <size_t Dim, typename R, class F> class memoize_nvec_helper;

template <size_t Dim, typename R, typename... Args, class F> class memoize_nvec_helper<Dim, R(Args...), F> {
  public:
    using function_type = F;
    function_type                                   f;
    mutable typename cache_vec_helper<Dim, R>::type cache;
    array<size_t, Dim>                              szs;
    R                                               dv;
    using Boundary_func   = function<pair<bool, R>(const Args&...)>;
    Boundary_func handler = nullptr;

    template <class Function> memoize_nvec_helper(Function&& f, vector<int>& vec_sz, R r, Boundary_func handler = nullptr) : f(std::forward<Function>(f)), dv(r), handler(handler) {
        for (int i = 0; i < Dim; ++i) {
            szs[i] = vec_sz[i];
        }
        initialize_cache(cache, szs);
    }

    template <class... InnerArgs> R operator()(InnerArgs&&... args) {
        static_assert(sizeof...(args) == Dim, "Number of arguments must match the dimension.");
        std::array<int, Dim> indices = {std::forward<InnerArgs>(args)...};
        if (handler) {
            if (auto res = handler(args...); res.first) {
                return res.second;
            }
        } else {
            for (int i = 0; i < Dim; ++i) {
                if (indices[i] < 0 || indices[i] >= static_cast<int>(szs[i])) {
                    return dv;
                }
            }
        }
        return access_cache(cache, indices, std::make_index_sequence<Dim>{}, std::forward<InnerArgs>(args)...);
    }

  private:
    template <typename T, size_t D> void initialize_cache(std::vector<T>& vec, const std::array<size_t, D>& sizes, size_t current_dim = 0) {
        vec.resize(sizes[current_dim]);
        if (current_dim + 1 < D) {
            for (auto& sub_vec : vec) {
                initialize_cache(sub_vec, sizes, current_dim + 1);
            }
        }
    }

    void initialize_cache(std::vector<R>& vec, const std::array<size_t, Dim>& sizes, size_t current_dim = 0) {
        vec.resize(sizes[current_dim], dv);
    }

    template <size_t... Is, class... InnerArgs>
    R access_cache(typename cache_vec_helper<Dim, R>::type& cache, const std::array<int, Dim>& indices, std::index_sequence<Is...>, InnerArgs&&... args) {
        return access_cache_impl(cache, indices, std::make_index_sequence<Dim>{}, std::forward<InnerArgs>(args)...);
    }

    template <size_t... Is, class... InnerArgs>
    R access_cache_impl(typename cache_vec_helper<sizeof...(Is), R>::type& cache, const std::array<int, Dim>& indices, std::index_sequence<Is...>, InnerArgs&&... args) {
        return access_cache_impl(cache, indices, std::index_sequence<Is...>{}, std::forward<InnerArgs>(args)...);
    }

    template <size_t First, size_t... Rest, class... InnerArgs>
    R access_cache_impl(typename cache_vec_helper<sizeof...(Rest) + 1, R>::type& cache,
                        const std::array<int, Dim>&                              indices,
                        std::index_sequence<First, Rest...>,
                        InnerArgs&&... args) {
        return access_cache_impl(cache[indices[First]], indices, std::index_sequence<Rest...>{}, std::forward<InnerArgs>(args)...);
    }

    template <size_t Last, class... InnerArgs>
    R access_cache_impl(typename cache_vec_helper<1, R>::type& cache, const std::array<int, Dim>& indices, std::index_sequence<Last>, InnerArgs&&... args) {
        auto& elem = cache[indices[Last]];
        if (elem != dv) {
            return elem;
        }
        return elem = f(*this, std::forward<InnerArgs>(args)...);
    }
};

template <int Dim, typename R, class F> class memoize_vec_helper;

template <typename R, typename... Args, class F> class memoize_vec_helper<1, R(Args...), F> {
  public:
    using function_type = F;
    function_type     f;
    mutable vector<R> cache;
    R                 dv;
    using Boundary_func   = function<pair<bool, R>(const Args&...)>;
    Boundary_func handler = nullptr;

  public:
    template <class Function>
    memoize_vec_helper(Function&& f, int sz, R r, Boundary_func handler = nullptr) : f(std::forward<Function>(f)), cache(sz, r), dv(r), handler(handler) {}

    template <class InnerArgs> R operator()(InnerArgs&& arg) const {
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

template <typename R, typename... Args, class F> class memoize_vec_helper<2, R(Args...), F> {
  public:
    using function_type = F;
    function_type             f;
    mutable vector<vector<R>> cache;
    R                         dv;
    using Boundary_func   = function<pair<bool, R>(const Args&...)>;
    Boundary_func handler = nullptr;

  public:
    template <class Function>
    memoize_vec_helper(Function&& f, int fs, int ss, R r, Boundary_func handler = nullptr) : f(std::forward<Function>(f)), cache(fs, vector<R>(ss, r)), dv(r), handler(handler) {}

    template <typename IndexType> R operator()(IndexType first, IndexType second) const {
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
template <typename R, typename... Args, class F> class memoize_vec_helper<3, R(Args...), F> {
  public:
    using function_type = F;
    function_type                       f;
    mutable vector<vector<vector<int>>> cache;
    R                                   dv;
    using Boundary_func   = function<pair<bool, R>(const Args&...)>;
    Boundary_func handler = nullptr;

  public:
    template <class Function>
    memoize_vec_helper(Function&& f, int fs, int ss, int ts, R r, Boundary_func handler = nullptr)
        : f(std::forward<Function>(f)), cache(fs, vector<vector<int>>(ss, vector<int>(ts, r))), dv(r), handler(handler) {}

    template <typename IndexType> R operator()(IndexType first, IndexType second, IndexType third) const {
        if (handler) {
            if (auto res = handler(first, second, third); res.first) {
                return res.second;
            }
        } else if (first < 0 || first >= cache.size() || second < 0 || second >= cache[first].size() || third < 0 || third >= cache[first][second].size()) {
            return dv;
        }
        if (cache[first][second][third] != dv) {
            return cache[first][second][third];
        }
        return cache[first][second][third] = f(*this, first, second, third);
    }
};

template <class Sig, class F> memoize_helper<Sig, std::decay_t<F>> cache(F&& f, typename memoize_helper<Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {
    return memoize_helper<Sig, std::decay_t<F>>(std::forward<F>(f), handler);
}

template <size_t Dim, class Sig, class F>
memoize_nvec_helper<Dim, Sig, std::decay_t<F>>
cache_nvec(F&& f, vector<int> sz, int default_value, typename memoize_nvec_helper<Dim, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {
    return memoize_nvec_helper<Dim, Sig, std::decay_t<F>>(std::forward<F>(f), sz, default_value, handler);
}

template <class Sig, class F>
memoize_vec_helper<1, Sig, std::decay_t<F>> cache_vec(F&& f, int sz, int default_value, typename memoize_vec_helper<1, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {
    return memoize_vec_helper<1, Sig, std::decay_t<F>>(std::forward<F>(f), sz, default_value, handler);
}

template <class Sig, class F>
memoize_vec_helper<2, Sig, std::decay_t<F>>
cache_vec2(F&& f, int sz, int sz2, int default_value, typename memoize_vec_helper<2, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {
    return memoize_vec_helper<2, Sig, std::decay_t<F>>(std::forward<F>(f), sz, sz2, default_value, handler);
}

template <class Sig, class F>
memoize_vec_helper<3, Sig, std::decay_t<F>>
cache_vec3(F&& f, int sz, int sz2, int sz3, int default_value, typename memoize_vec_helper<3, Sig, std::decay_t<F>>::Boundary_func handler = nullptr) {
    return memoize_vec_helper<3, Sig, std::decay_t<F>>(std::forward<F>(f), sz, sz2, sz3, default_value, handler);
}

template <typename T> constexpr std::size_t total_size(T value) {
    return static_cast<std::size_t>(value);
}

template <typename T, typename... Args> constexpr std::size_t total_size(T first, Args... args) {
    return static_cast<std::size_t>(first) * total_size(args...);
}

template <typename T, typename... Args> void fill_array(T* arr, T value, Args... dims) {
    static_assert(sizeof...(dims) > 0, "At least one dimension required");
    static_assert((std::is_integral_v<Args> && ...), "All dimensions must be integral");
    std::fill_n(arr, total_size(dims...), value);
}
}  // namespace my_cache

using namespace my_cache;