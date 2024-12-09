/*
 * @lc app=leetcode.cn id=3036 lang=cpp
 * @lcpr version=30204
 *
 * [3036] 匹配模式数组的子数组数目 II
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
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
using namespace std;

namespace my_using {
    using ull = unsigned long long;
    using ll = long long;
    using db = long double;  // or double, if TL is tight
    using str = string;      // yay python!

// pairs
    using pi = pair<int, int>;
    using pl = pair<ll, ll>;
    using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
    tcT > using V = vector<T>;
    tcT, size_t SZ > using AR = array<T, SZ>;
    using vi = V<int>;
    using vb = V<bool>;
    using vl = V<ll>;
    using vd = V<db>;
    using vs = V<str>;
    using vpi = V<pi>;
    using vpl = V<pl>;
    using vpd = V<pd>;

// vectors
#define sz(x) int(size(x))
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

    using lll=__int128_t;
    using ulll=__uint128_t;
    using pii = pair<int32_t, int32_t>;
    using pll = pair<ll, ll>;
    using vll = vector<ll>;
    template<class... Ts> using vo = vector<Ts...>;
    template<class... Ts> using min_queue = priority_queue<Ts..., vo<Ts...>, greater<>>;
    template<class... Ts> using max_queue = priority_queue<Ts...>;
    template<class... Ts> using umap = map<Ts...>;
    template<class... Ts> using uset = unordered_set<Ts...>;

// loops
#define FaR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR(i, a) FaR(i, 0, a)
#define RaF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i, a) RaF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

#define lb lower_bound
#define ub upper_bound

    tcT > int lwb(const V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
    tcT > int upb(const V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }
    tcT > int eqb(const V<T> &a, const T &b) { return upb(a, b) - lwb(a, b); }
}

using namespace my_using;

namespace my_numeric {
    const int MOD = 1e9+7;
    const int MX = (int)2e5 + 5;
    const ll BIG = 1e18;  // not too close to LLONG_MAX
    const db PI = acos((db)-1);
    const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!

    mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
    template<class T> T rand(T a, T b) { return uniform_int_distribution<T>(a, b)(rng); }
}
using namespace my_numeric;


template <class T> using pqs = priority_queue<T, vector<T>, greater<T>>;
template <class T> using pqg = priority_queue<T, vector<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); }  // # of bits set
// 位宽
constexpr int bits(int x) {  // assert(x >= 0); // make C++11 compatible until
    return x == 0 ? 0 : 31 - __builtin_clz(x);
}  // floor(log2(x))
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
// 除法向上取整
ll cdiv(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
// 除法向下取整
ll fdiv(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

tcT > bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}  // set a = min(a,b)
tcT > bool ckmax(T &a, const T &b) {
    return a < b ? a = b, 1 : 0;
}  // set a = max(a,b)

tcT > void remDup(vector<T> &v) {  // sort and remove duplicates
    sort(all(v));
    v.erase(unique(all(v)), end(v));
}
tcTU > void safeErase(T &t, const U &u) {
    auto it = t.find(u);
    assert(it != end(t));
    t.erase(it);
}

// pbds
#include<bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
using bigpHeap = __gnu_pbds::priority_queue<T>;
template<typename T>
using smallHeap = __gnu_pbds::priority_queue<T, std::greater<>>;
template<typename T>
using b_heap_iterator = bigpHeap<T>::point_iterator;
template<typename T>
using s_heap_iterator = smallHeap<T>::point_iterator;


template <typename T>
using sortedSet =   __gnu_pbds ::tree<T, __gnu_pbds::null_type, less<T>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;

template <typename T>
using _sorted_list = tree<pair<T, ll>, null_type, less<pair<T, ll>>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
class SortedList {
public:
    _sorted_list<T> _list;
    unordered_map<T, ll> idx;
    void insert(T x) {
        _list.insert({x, ++idx[x]});
    }
    void erase(T x) {
        _list.erase({x, idx[x]--});
    }
    T find_by_order(ll k) {
        return _list.find_by_order(k)->first;
    }
    auto lower_bound(T x) {
        return _list.lower_bound({x, 0});
    }
    auto upper_bound(T x) {
        return _list.upper_bound({x, 0});
    }
    // 前闭后开
    auto equal_range(T x) {
        auto lower = lower_bound(x);
        auto upper = upper_bound(x);
        return make_pair(lower, upper);
    }
    size_t size() {
        return _list.size();
    }
};


inline namespace IO {
#define SFINAE(x, ...)                                                         \
	template <class, class = void> struct x : std::false_type {};              \
	template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}

    SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>()));
    SFINAE(DefaultO, decltype(std::cout << std::declval<T &>()));
    SFINAE(IsTuple, typename std::tuple_size<T>::type);
    SFINAE(Iterable, decltype(std::begin(std::declval<T>())));

    template <auto &is> struct Reader {
        template <class T> void Impl(T &t) {
            if constexpr (DefaultI<T>::value) is >> t;
            else if constexpr (Iterable<T>::value) {
                for (auto &x : t) Impl(x);
            } else if constexpr (IsTuple<T>::value) {
                std::apply([this](auto &...args) { (Impl(args), ...); }, t);
            } else static_assert(IsTuple<T>::value, "No matching type for read");
        }
        template <class... Ts> void read(Ts &...ts) { ((Impl(ts)), ...); }
    };

    template <class... Ts> void re(Ts &...ts) { Reader<cin>{}.read(ts...); }
#define def(t, args...)                                                        \
	t args;                                                                    \
	re(args);

    template <auto &os, bool debug, bool print_nd> struct Writer {
        string comma() const { return debug ? "," : ""; }
        template <class T> constexpr char Space(const T &) const {
            return print_nd && (Iterable<T>::value or IsTuple<T>::value) ? '\n'
                                                                         : ' ';
        }
        template <class T> void Impl(T const &t) const {
            if constexpr (DefaultO<T>::value) os << t;
            else if constexpr (Iterable<T>::value) {
                if (debug) os << '{';
                int i = 0;
                for (auto &&x : t)
                    ((i++) ? (os << comma() << Space(x), Impl(x)) : Impl(x));
                if (debug) os << '}';
            } else if constexpr (IsTuple<T>::value) {
                if (debug) os << '(';
                std::apply(
                        [this](auto const &...args) {
                            int i = 0;
                            (((i++) ? (os << comma() << " ", Impl(args)) : Impl(args)),
                                    ...);
                        },
                        t);
                if (debug) os << ')';
            } else static_assert(IsTuple<T>::value, "No matching type for print");
        }
        template <class T> void ImplWrapper(T const &t) const {
            if (debug) os << "\033[0;31m";
            Impl(t);
            if (debug) os << "\033[0m";
        }
        template <class... Ts> void print(Ts const &...ts) const {
            ((Impl(ts)), ...);
        }
        template <class F, class... Ts>
        void print_with_sep(const std::string &sep, F const &f,
                            Ts const &...ts) const {
            ImplWrapper(f), ((os << sep, ImplWrapper(ts)), ...), os << '\n';
        }
        void print_with_sep(const std::string &) const { os << '\n'; }
    };

    template <class... Ts> void pr(Ts const &...ts) {
        Writer<cout, false, true>{}.print(ts...);
    }
    template <class... Ts> void ps(Ts const &...ts) {
        Writer<cout, false, true>{}.print_with_sep(" ", ts...);
    }
}  // namespace IO

inline namespace Debug {
    template <typename... Args> void err(Args... args) {
        Writer<cerr, true, false>{}.print_with_sep(" | ", args...);
    }
    template <typename... Args> void errn(Args... args) {
        Writer<cerr, true, true>{}.print_with_sep(" | ", args...);
    }

    void err_prefix(str func, int line, string args) {
        cerr << "\033[0;31m\u001b[1mDEBUG\033[0m"
             << " | "
             << "\u001b[34m" << func << "\033[0m"
             << ":"
             << "\u001b[34m" << line << "\033[0m"
             << " - "
             << "[" << args << "] = ";
    }

#ifdef LOCAL
    #define dbg(args...) err_prefix(__FUNCTION__, __LINE__, #args), err(args)
#define dbgn(args...) err_prefix(__FUNCTION__, __LINE__, #args), errn(args)
#else
#define dbg(...)
#define dbgn(args...)
#endif

    const auto beg_time = std::chrono::high_resolution_clock::now();
// https://stackoverflow.com/questions/47980498/accurate-c-c-clock-on-a-multi-core-processor-with-auto-overclock?noredirect=1&lq=1
    double time_elapsed() {
        return chrono::duration<double>(std::chrono::high_resolution_clock::now() -
                                        beg_time)
                .count();
    }
}  // namespace Debug

inline namespace FileIO {
    void setIn(str s) { freopen(s.c_str(), "r", stdin); }
    void setOut(str s) { freopen(s.c_str(), "w", stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0);  // unsync C / C++ I/O streams
        cout << fixed << setprecision(12);
        // cin.exceptions(cin.failbit);
        // throws exception when do smth illegal
        // ex. try to read letter into int
        if (sz(s)) setIn(s + ".in"), setOut(s + ".out");  // for old USACO
    }
}  // namespace FileIO

// radix_sort 函数
template<class It,class F,bool DoUnsafeStackAlloc=false>void radix_sort_impl(It begin,It end,F f){const auto n=std::distance(begin,end);using T=std::remove_const_t<std::remove_reference_t<decltype(*std::declval<It>())>>;using SortType=std::invoke_result_t<F,T>;std::unique_ptr<T[]>up=DoUnsafeStackAlloc?nullptr:std::make_unique<T[]>(n);T stack_arr[DoUnsafeStackAlloc?n:1];T*second=DoUnsafeStackAlloc?&stack_arr[0]:up.get();std::array<std::size_t,256>count{};std::uint8_t or_of_all_bytes[sizeof(SortType)]{};std::uint8_t and_of_all_bytes[sizeof(SortType)]{};for(std::size_t i=0;i<sizeof(SortType);++i){or_of_all_bytes[i]=0;and_of_all_bytes[i]=-1;}for(std::ptrdiff_t i=0;i<n;++i){auto tmp=f(begin[i]);for(std::size_t which_byte=0;which_byte<sizeof(SortType);++which_byte){std::uint8_t byte=((std::uint8_t const*)&tmp)[which_byte];or_of_all_bytes[which_byte]|=byte;and_of_all_bytes[which_byte]&=byte;}}bool needs_swap=false;for(std::size_t which_byte=0;which_byte<sizeof(SortType);++which_byte){auto do_iter=[&](auto a,auto b){count.fill(0);for(std::ptrdiff_t i=0;i<n;++i){auto tmp=f(a[i]);if constexpr(std::is_signed_v<SortType>&&std::is_integral_v<SortType>){tmp^=SortType{1}<<(8*sizeof(SortType)-1);}std::uint8_t sort_byte=((std::uint8_t const*)&tmp)[which_byte];++count[sort_byte];}for(std::ptrdiff_t i=1;i<256;++i){count[i]+=count[i-1];}for(std::ptrdiff_t i=n;i-->0;){auto tmp=f(a[i]);if constexpr(std::is_signed_v<SortType>&&std::is_integral_v<SortType>){tmp^=SortType{1}<<(8*sizeof(SortType)-1);}std::uint8_t sort_byte=((std::uint8_t const*)&tmp)[which_byte];b[--count[sort_byte]]=std::move(a[i]);}};if(or_of_all_bytes[which_byte]!=and_of_all_bytes[which_byte]){if(needs_swap){do_iter(second,begin);}else{do_iter(begin,second);}needs_swap=!needs_swap;}}if(needs_swap)std::copy(second,second+n,begin);}template<class It,class F>auto radix_sort(It begin,It end,F&&sort_by,bool do_unsafe_stack_alloc=false){if(do_unsafe_stack_alloc)radix_sort_impl<It,F,true>(begin,end,sort_by);else radix_sort_impl<It,F,false>(begin,end,sort_by);}template<class It>auto radix_sort(It begin,It end,bool do_unsafe_stack_alloc=false){const auto identity_fn=[](auto&&x){return x;};radix_sort(begin,end,identity_fn,do_unsafe_stack_alloc);}


// c(n, m, mod)
namespace my_math {
    ull quickMi(ull base, ull n, ull mod) {
        ull ans = 1;
        while (n) {
            if (n & 0x1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            n >>= 1;
        }
        //cout << "x" << endl;
        return ans;
    }

    const int MAXN = 2e5 + 100;  // 根据需要调整最大值
    long long fac[MAXN + 1], invfac[MAXN + 1];

    void CNM_Preprocess(ll n, ll mod) {
        fac[0] = invfac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
        }
        invfac[n] = quickMi(fac[n], mod - 2, mod);
        for (int i = n - 1; i >= 1; i--) {
            invfac[i] = invfac[i + 1] * (i + 1) % mod;
        }
    }

    // c(n, m, mod)
    ll C(ll n, ll m, ll mod) {
        if (n < m || m < 0) return 0;
        return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
    }

    // 得到所有除数
    vector<ll> getAllDivisors(ll x) {
        vector<ll> ans;
        for (ll i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                ans.push_back(i);
                if (i != x / i) {
                    ans.push_back(x / i);
                }
            }
        }
        return ans;
    }
};

using namespace my_math;

namespace my_template {
    // 辅助模板，检测 T 是否具有 begin 和 end 成员函数
    template <typename T, typename = void>
    struct is_container : std::false_type {};

// 如果 T 具有 value_type、begin 和 end 成员，则匹配这个偏特化版本
    template <typename T>
    struct is_container<T, std::void_t<
            typename T::value_type,  // 检查是否有 value_type
            decltype(std::declval<T>().begin()),  // 检查是否有 begin()
            decltype(std::declval<T>().end())     // 检查是否有 end()
    >> : std::true_type {};

// 检查模板参数是否是容器
    template <typename T>
    constexpr bool is_container_v = is_container<T>::value;
}

namespace bisec {
    using namespace my_template;

    /*
     *  从前往后找到第一个不满足func的位置
     *
     * */
    template<typename Func>
    ll bisect_left(ll lo, ll hi, const Func& func) {
        assert(lo <= hi and lo >= 0);
        while (lo + 1 < hi) {  // find first index such that f is true
            ll mid = lo + (hi - lo) / 2;
            !func(mid) ? hi = mid : lo = mid;
        }
        if (!func(lo)) return lo;
        if (!func(hi)) return hi;
        return hi + 1;
    }

    template<typename T, typename Func>
    ll bisect_left(ll lo, ll hi, T v, const Func& func) {
        assert(lo <= hi and lo >= 0);
        while (lo + 1 < hi) {  // find first index such that f is true
            ll mid = lo + (hi - lo) / 2;
            !func(mid, v) ? hi = mid : lo = mid;
        }
        if (!func(lo, v)) return lo;
        if (!func(hi, v)) return hi;
        return hi + 1;
    }

    template<typename Container, typename Func, typename std::enable_if<is_container_v<Container>, int>::type = 0>
    ll bisect_left(const Container& v, const Func& func) {
        return bisect_left((ll)0, (ll)v.size() - 1, func);
    }

    template<typename Container, typename T, typename Func, typename std::enable_if<is_container_v<Container>, int>::type = 0>
    ll bisect_left(const Container& v, T x, const Func& func) {
        return bisect_left((ll)0, (ll)v.size() - 1, x, func);
    }

    // 从前往后找到第一个满足func的位置, 位置对了才为true
    template<typename Func>
    ll bisect_right(ll lo, ll hi, const Func& func) {
        assert(lo <= hi and lo >= 0);
        while (lo + 1 < hi) {  // find first index such that f is true
            ll mid = lo + (hi - lo) / 2;
            func(mid) ? hi = mid : lo = mid;
        }
        if (func(lo)) return lo;
        if (func(hi)) return hi;
        return hi + 1;
    }

    template<typename T, typename Func, typename std::enable_if<is_integral_v<T>, int>::type = 0>
    ll bisect_right(ll lo, ll hi, T v, const Func& func) {
        assert(lo <= hi and lo >= 0);
        while (lo + 1 < hi) {  // find first index such that f is true
            ll mid = lo + (hi - lo) / 2;
            func(v, mid) ? hi = mid : lo = mid;
        }
        if (func(v, lo)) return lo;
        if (func(v, hi)) return hi;
        return hi + 1;
    }

    template<typename Container, typename T, typename Func, typename std::enable_if<is_container_v<Container>, int>::type = 0>
    int bisect_right(const Container& v, T x, const Func& func) {
        return bisect_right((ll)0, (ll)v.size() - 1, x, func);
    }

    template<typename T, typename U, typename std::enable_if<is_integral_v<U>, int>::type = 0>
    ll bisect_left(const vector<T>& v, U x) {
        return bisect_left((ll)0, (ll)v.size() - 1, x, [&](ll mid, U t) { return v[mid] < t;});
    }

    template<typename T, typename U, typename std::enable_if<is_integral_v<U>, int>::type = 0>
    ll bisect_right(const vector<T>& v, U x) {
        return bisect_right((ll)0, (ll)v.size() - 1, x, [&](T t, ll mid) { return t < v[mid]; });
    }
};

using namespace bisec;

namespace my_string {
    ull base1 = rand((ull)8e8, (ull)9e8);
    ull base2 = rand((ull)8e8, (ull)9e8);
    ull mod1 =  1'070'777'777, mod2 = 1'000'000'007;
    ull P1, P2;

    void initP(int n) {
        P1 = quickMi(base1, n, mod1);
        P2 = quickMi(base2, n, mod2);
    }

    ull get_hash1(const std::string &s) {
        int len = s.size();
        ull ans = 0;
        for (int i = 0; i < len; i++) ans = (ans * base1 + (ull) s[i]) % mod1;
        return ans;
    }

    ull get_hash2(const std::string &s) {
        int len = s.size();
        ull ans = 0;
        for (int i = 0; i < len; i++) ans = (ans * base2 + (ull) s[i]) % mod2;
        return ans;
    }

    pair<ull, ull> get_hash_pair(const std::string &s) {
        return {get_hash1(s), get_hash2(s)};
    }

    ull get_hash(const std::string &s) {
        return get_hash1(s) << 32 | get_hash2(s);
    }

    ull roll_hash1(ull hash, int len, ull pre, char nxt) {
        return (hash * base1 % mod1 + nxt - pre * P1 % mod1 + mod1) % mod1;
    }

    ull roll_hash2(ull hash, int len, ull pre, char nxt) {
        return (hash * base2 % mod2 + nxt - pre * P2 % mod2 + mod2) % mod2;
    }

    bool cmp(const std::string &s, const std::string &t) {
        bool f1 = get_hash1(s) != get_hash1(t);
        bool f2 = get_hash2(s) != get_hash2(t);
        return f1 || f2;
    }

    // 字符串哈希模板开始

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int rnd(int x, int y) {
        return uniform_int_distribution<int>(x, y)(rng);
    }

    long long MOD = 1e18 + rnd(0, 1e9);
    long long BASE = 233 + rnd(0, 1e3);
    
    /** HashOBj 替代
    struct HashString {
        vector<__int128> P, H;

        HashString(string &s) {
            int n = s.size();
            P.resize(n + 1);
            P[0] = 1;
            for (int i = 1; i <= n; i++) P[i] = P[i - 1] * BASE % MOD;
            H.resize(n + 1);
            H[0] = 0;
            for (int i = 1; i <= n; i++) H[i] = (H[i - 1] * BASE + s[i - 1]) % MOD;
        }
        // [l, r]
        long long query(int l, int r) {
            if (l > r) return 0;
            return (H[r + 1] - H[l] * P[r - l + 1] % MOD + MOD) % MOD;
        }
    };
     **/

    struct HashObj {
        vector<__int128> P, H;
        
        template<typename Container, typename std::enable_if<is_container_v<Container>, int>::type = 0>
        HashObj(Container &s) {
            int n = s.size();
            P.resize(n + 1);
            P[0] = 1;
            for (int i = 1; i <= n; i++) P[i] = P[i - 1] * BASE % MOD;
            H.resize(n + 1);
            H[0] = 0;
            for (int i = 1; i <= n; i++) H[i] = (H[i - 1] * BASE + s[i - 1]) % MOD;
        }
        // [l, r]
        long long query(int l, int r) {
            if (l > r) return 0;
            return (H[r + 1] - H[l] * P[r - l + 1] % MOD + MOD) % MOD;
        }
    };
    
    using HashString = HashObj;

    struct HashReverseString {
        vector<__int128> P, H;

        HashReverseString(string &s) {
            int n = s.size();
            P.resize(n + 1);
            P[0] = 1;
            for (int i = 1; i <= n; i++) P[i] = P[i - 1] * BASE % MOD;
            H.resize(n + 1);
            H[n] = 0;
            for (int i = n - 1; i >= 0; i--) H[i] = (H[i + 1] * BASE + s[i]) % MOD;
        }

        // [l, r]
        long long query(int l, int r) {
            if (l > r) return 0;
            return (H[l] - H[r + 1] * P[r - l + 1] % MOD + MOD) % MOD;
        }
    };

    // pair 奇轴 偶轴, 偶数的下标是右边那个
    vector<pair<ll, ll>> manacher(const string& s) {
        string t="^";
        for(auto c:s){
            t.push_back('#');
            t.push_back(c);
        }
        t.push_back('#');
        t.push_back('$');
        int n = t.size();
        vector<ll> dp(n);
        int center=0,right=0;
        for (ll i = 1; i < n - 1; i++) {
            if (i <= right) {
                dp[i] = min(right - i, dp[2 * center - i]);
            }
            while (t[i - dp[i] - 1] == t[i + dp[i] + 1]) {
                dp[i]++;
            }
            if (i + dp[i] > right) {
                center = i;
                right = i + dp[i];
            }
        }
        int m = s.size();
        vector<pll> ans(m);
        int j = 0;
        for (int i = 2; i < n - 1; i += 2) {
            ans[j].first = dp[i];
            ans[j].second = dp[i + 1];
            j++;
        }
        return ans;
    }

    pll getMaxIdxAndLen(vector<pll>& dp) {
        pll ans;
        for (int i = 0; i < dp.size(); i++) {
            ll maxLen = max(dp[i].first, dp[i].second);
            if (maxLen > ans.second) {
                ans.second = maxLen;
                ans.first = i - (maxLen - 1) / 2;
            }
        }
        return ans;
    }

    vector<ll> Z(const string& s) {
        ll n = s.size();
        vector<ll> z(n);
        z[0] = n;
        ll l = 0, r = 0;
        for (ll i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    vector<ll> makeNext(const string& s) {
        int n = s.size();
        vector<ll> next(n);
        //
        ll r = 0;
        for (ll i = 1; i < n; i++) {
            // 不符合条件
            while (r and s[r] != s[i]) {
                r = next[r - 1];
            }
            if (s[r] == s[i]) {
                r++;
            }
            next[i] = r;
        }
        return next;
    }

    int kmp(const string& source, const string& needle) {
        auto next = makeNext(needle);
        int n = source.size(), m = needle.size();
        ll r = 0;
        for (ll i = 0; i < n; i++) {
            // 不符合
            while (r and source[i] != needle[r]) {
                r = next[r - 1];
            }
            if (source[i] == needle[r]) {
                if (++r == needle.size()) {
                    return i - m + 1;
                }
            }
        }
        return -1;
    }

    class ACMachine {
    public:
        struct ACNode {
            vector<ACNode*> children;
            ACNode* fail;
            vector<int> exsit;
        };

        ACNode root;

        ACMachine() {
            root.children.resize(26, nullptr);
            root.fail = nullptr;
        }

        void _insert(const string& s) {
            ACNode* cur = &root;
            for (auto& c : s) {
                int id = c - 'a';
                if (cur->children[id] == nullptr) {
                    cur->children[id] = new ACNode();
                    cur->children[id]->children.resize(26, nullptr);
                }
                cur = cur->children[id];
            }
            cur->exsit.push_back(s.size());
        }

        void build_fail() {
            queue<ACNode*> q;
            q.push(&root);
            while (!q.empty()) {
                ACNode* cur = q.front();
                q.pop();
                for (int i = 0; i < 26; i++) {
                    if (cur->children[i] != nullptr) {
                        ACNode* y = cur->children[i], *fa_fail = cur->fail;
                        // 查找第一个
                        while (fa_fail and fa_fail->children[i] == nullptr) {
                            fa_fail = fa_fail->fail;
                        }
                        if (fa_fail == nullptr) {
                            y->fail = &root;
                        } else {
                            y->fail = fa_fail->children[i];
                        }
                        if (!y->fail->exsit.empty()) {
                            y->exsit.insert(y->exsit.end(), y->fail->exsit.begin(), y->fail->exsit.end());
                        }
                        q.push(y);
                    }
                }
            }
        }

        void make_tree(const vector<string>& words) {
            for (auto& s : words) {
                _insert(s);
            }
            build_fail();
        }

        vector<string> print(const string& s) {
            vector<string> ans;
            ACNode* cur = &root;
            for (int i = 0; i < s.size(); i++) {
                int id = s[i] - 'a';
                while (cur->children[id] == nullptr and cur->fail) {
                    cur = cur->fail;
                }
                if (cur->children[id]) {
                    cur = cur->children[id];
                } else {
                    // cur == &root;
                    continue;
                }
                for (auto& len : cur->exsit) {
                    ans.push_back(s.substr(i - len + 1, len));
                }
            }
            return ans;
        }

        unordered_map<string, vector<int>> print_pos(const string& s) {
            unordered_map<string, vector<int>> ans;
            ACNode* cur = &root;
            for (int i = 0; i < s.size(); i++) {
                int id = s[i] - 'a';
                while (cur->children[id] == nullptr and cur->fail) {
                    cur = cur->fail;
                }
                if (cur->children[id]) {
                    cur = cur->children[id];
                } else {
                    // cur == &root;
                    continue;
                }
                for (auto& len : cur->exsit) {
                    ans[s.substr(i - len + 1, len)].push_back({i - len + 1});
                }
            }
            return ans;
        }

        ACNode* query(ACNode* cur, char ch) {
            while (cur->children[ch - 'a'] == nullptr and cur->fail) {
                cur = cur->fail;
            }
            if (cur->children[ch - 'a']) {
                return cur->children[ch - 'a'];
            } else {
                return &root;
            }
        }
    };

    class ACMachineLast {
    public:
        struct ACNode {
            vector<ACNode*> children;
            ACNode* fail;
            ACNode* last;
            int len;
        };

        ACNode root;

        ACMachineLast() {
            root.children.resize(26, nullptr);
            root.fail = nullptr;
            root.last = nullptr;
        }

        void _insert(const string& s) {
            ACNode* cur = &root;
            for (auto& c : s) {
                int id = c - 'a';
                if (cur->children[id] == nullptr) {
                    cur->children[id] = new ACNode();
                    cur->children[id]->children.resize(26, nullptr);
                }
                cur = cur->children[id];
            }
            cur->len = s.size();
        }

        void build_fail() {
            queue<ACNode*> q;
            q.push(&root);
            while (!q.empty()) {
                ACNode* cur = q.front();
                q.pop();
                for (int i = 0; i < 26; i++) {
                    if (cur->children[i] != nullptr) {
                        ACNode* y = cur->children[i], *fa_fail = cur->fail;
                        // 查找第一个
                        while (fa_fail and fa_fail->children[i] == nullptr) {
                            fa_fail = fa_fail->fail;
                        }
                        if (fa_fail == nullptr) {
                            y->fail = &root;
                        } else {
                            y->fail = fa_fail->children[i];
                        }
                        if (y->fail->len) {
                            y->last = y->fail;
                        } else {
                            y->last = y->fail->last;
                        }
                        q.push(y);
                    }
                }
            }
        }

        void make_tree(const vector<string>& words) {
            for (auto& s : words) {
                _insert(s);
            }
            build_fail();
        }

        vector<string> print(const string& s) {
            vector<string> ans;
            ACNode* cur = &root;
            for (int i = 0; i < s.size(); i++) {
                int id = s[i] - 'a';
                while (cur->children[id] == nullptr and cur->fail) {
                    cur = cur->fail;
                }
                if (cur->children[id]) {
                    cur = cur->children[id];
                } else {
                    // cur == &root;
                    continue;
                }
                ACNode* tmp = cur;
                while (tmp) {
                    if (tmp->len) {
                        ans.push_back(s.substr(i - tmp->len + 1, tmp->len));
                    }
                    tmp = tmp->last;
                }
            }
            return ans;
        }

        unordered_map<string, vector<int>> print_pos(const string& s) {
            unordered_map<string, vector<int>> ans;
            ACNode* cur = &root;
            for (int i = 0; i < s.size(); i++) {
                int id = s[i] - 'a';
                while (cur->children[id] == nullptr and cur->fail) {
                    cur = cur->fail;
                }
                if (cur->children[id]) {
                    cur = cur->children[id];
                } else {
                    // cur == &root;
                    continue;
                }
                ACNode* tmp = cur;
                while (tmp) {
                    if (tmp->len) {
                        ans[s.substr(i - tmp->len + 1, tmp->len)].push_back({i - tmp->len + 1});
                    }
                    tmp = tmp->last;
                }
            }
            return ans;
        }

        ACNode* query(ACNode* cur, char ch) {
            while (cur->children[ch - 'a'] == nullptr and cur->fail) {
                cur = cur->fail;
            }
            if (cur->children[ch - 'a']) {
                return cur->children[ch - 'a'];
            } else {
                return &root;
            }
        }
    };

    struct AhoCorasick {
        struct Node {
            Node* son[26]{};
            Node* fail; // 当 cur.son[i] 不能匹配 target 中的某个字符时，cur.fail.son[i] 即为下一个待匹配节点（等于 root 则表示没有匹配）
            Node* last; // 后缀链接（suffix link），用来快速跳到一定是某个 words[k] 的最后一个字母的节点（等于 root 则表示没有）
            int len = 0;
            int cost = INT_MAX;
        };

        Node* root = new Node();

        void put(string& s, int cost) {
            auto cur = root;
            for (char b : s) {
                b -= 'a';
                if (cur->son[b] == nullptr) {
                    cur->son[b] = new Node();
                }
                cur = cur->son[b];
            }
            cur->len = s.length();
            cur->cost = min(cur->cost, cost);
        }

        void build_fail() {
            root->fail = root->last = root;
            queue<Node*> q;
            for (auto& son : root->son) {
                if (son == nullptr) {
                    son = root;
                } else {
                    son->fail = son->last = root; // 第一层的失配指针，都指向根节点 ∅
                    q.push(son);
                }
            }
            // BFS
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (int i = 0; i < 26; i++) {
                    auto& son = cur->son[i];
                    if (son == nullptr) {
                        // 虚拟子节点 cur.son[i]，和 cur.fail.son[i] 是同一个
                        // 方便失配时直接跳到下一个可能匹配的位置（但不一定是某个 words[k] 的最后一个字母）
                        son = cur->fail->son[i];
                        continue;
                    }
                    son->fail = cur->fail->son[i]; // 计算失配位置
                    // 沿着 last 往上走，可以直接跳到一定是某个 words[k] 的最后一个字母的节点（如果跳到 root 表示没有匹配）
                    son->last = son->fail->len ? son->fail : son->fail->last;
                    q.push(son);
                }
            }
        }
    };

    class AC{
    public:
        struct Node {
            Node* son[26]{};
            Node* fail = nullptr, *last = nullptr;
            int len = 0, cost = INT_MAX;
        };

        Node* root = new Node();

        void insert(const string& s, int cost) {
            Node* cur = root;
            for (auto ch: s) {
                int idx = ch - 'a';
                if (nullptr == cur->son[idx]) {
                    cur->son[idx] = new Node;
                }
                cur = cur->son[idx];
            }
            cur->len = s.size();
            cur->cost = min(cur->cost, cost);
        }

        void build_fail() {
            root->fail = root->last = root;
            queue<Node*> q;
            for (auto& son: root->son) {
                if (son == nullptr) {
                    son = root;
                } else {
                    q.push(son);
                    son->fail = son->last = root;
                }
            }
            while (!q.empty()) {
                auto node = q.front(); q.pop();
                for (int i = 0; i < 26; i++) {
                    auto& son = node->son[i];
                    if (son == nullptr) {
                        son = node->fail->son[i];
                        continue;
                    }
                    son->fail = node->fail->son[i];
                    son->last = son->fail->len ? son->fail : son->fail->last;
                    q.push(son);
                }
            }
        }


        void make(const vector<string>& words, const vector<int>& costs) {
            for (int i = 0; i < words.size(); i++) {
                insert(words[i], costs[i]);
            }
            build_fail();
        }

        map<int, vpi> scan(const string& s) {
            auto cur = root;
            map<int, vpi> ans;
            for (int i = 1; i <= s.size(); i++) {
                cur = cur->son[s[i - 1] - 'a'];
                if (cur->len) {
                    ans[i - cur->len].push_back({cur->len, cur->cost});
                }
                for (auto p = cur->last; p != root; p = p->last) {
                    ans[i - p->len].push_back({p->len, p->cost});
                }
            }
            return ans;
        }

        struct Ite {
        public:
            Node* root;
            Node* cur;
            string& s;
            int pos = 0;

            Ite(Node* root, string& s): root(root), cur(root), s(s) {}

            vector<pi> operator++() {
                if (pos > s.size()) return {};
                cur = cur->son[s[pos++] - 'a'];
                vector<pi> ans;
                if (cur->len) {
                    ans.push_back({cur->len, cur->cost});
                }
                for (auto p = cur->last; p != root; p = p->last) {
                    ans.push_back({p->len, p->cost});
                }
                return ans;
            }
        };

    };
};

using namespace my_string;

namespace my_bit {
#if __cplusplus < 202002L
    template<typename T>      bool has_single_bit(T n) { return n > 0 && (n & (n - 1)) == 0; }      template<typename T>      T bit_ceil(T n) {          if (n <= 1) return 1;          --n;          for (size_t i = 1; i < sizeof(T) * 8; i <<= 1) { n |= n >> i; }          return n + 1;      }      template<typename T>      T bit_floor(T n) {          if (n == 0) return 0;          T result = 1;          while (result <= n) { result <<= 1; }          return result >> 1;      }      template<typename T>      int bit_width(T n) {          int width = 0;          while (n > 0) {              n >>= 1;              ++width;          }          return width;      }      template<typename T>      T rotl(T n, unsigned int shift) {          const unsigned int mask = sizeof(T) * 8 - 1;          shift &= mask;          return (n << shift) | (n >> ((-shift) & mask));      }      template<typename T>      T rotr(T n, unsigned int shift) {          const unsigned int mask = sizeof(T) * 8 - 1;          shift &= mask;          return (n >> shift) | (n << ((-shift) & mask));      }      template<typename T>      int countl_zero(T n) {          if (n == 0) return sizeof(T) * 8;          int count = 0;          for (int i = sizeof(T) * 8 - 1; i >= 0; --i) {              if ((n >> i) & 1) break;              ++count;          }          return count;      }      template<typename T>      int countl_one(T n) {          int count = 0;          for (int i = sizeof(T) * 8 - 1; i >= 0; --i) {              if (!((n >> i) & 1)) break;              ++count;          }          return count;      }      template<typename T>      int countr_zero(T n) {          if (n == 0) return sizeof(T) * 8;          int count = 0;          while (!(n & 1)) {              n >>= 1;              ++count;          }          return count;      }      template<typename T>      int countr_one(T n) {          int count = 0;          while (n & 1) {              n >>= 1;              ++count;          }          return count;      }      template<typename T>      int popcount(T n) {          int count = 0;          while (n) {              count += n & 1;              n >>= 1;          }          return count;      }

#endif
    template<typename T>
    string intToBinary(T n) {
        string s;
        while (n) {
            s += to_string(n % 2);
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    ll binaryToInt(const string& s) {
        ll ans = 0;
        for (auto& c : s) {
            ans = ans * 2 + c - '0';
        }
        return ans;
    }

    // lowbit
    template<typename T>
    T lowbit(T x) {
        return x & -x;
    }
};

using namespace my_bit;

namespace my_segment {
    class ST{
    public:
        // 需要修改区间
        const ll default_val = 0;
        ll func (ll a, ll b) {
            return a | b;
        }
        //
        vector<vector<ll>> st;
        ST(const vector<int>& arr) {
            int n = arr.size();
            int k = log2(arr.size()) + 1;
            st.resize(arr.size(), vector<ll>(k, default_val));
            for (int i = 0; i < arr.size(); i++) {
                st[i][0] = arr[i];
            }
            for (int y = 1; y < k; y++) {
                for (int i = 0; i < n; i++) {
                    st[i][y] = st[i][y - 1];
                    int r = i + (1 << (y - 1));
                    if (r < n) {
                        st[i][y] = func(st[i][y], st[r][y - 1]);
                    }
                }
            }
        }

        ll query(int L, int R) {
            int d = log2(R - L + 1);
            return func(st[L][d], st[R - (1 << d) + 1][d]);
        }

        ll  bisect_right(int L, int R, ll target) {
            return ::bisect_right(L, R, [&](ll idx) {
                return query(idx, R) < target;
            });
        }

        ll bisect_left(int L, int R, ll target) {
            return ::bisect_left(L, R, [&](ll idx) {
                return query(L, idx) > target;
            });
        }
    };

    // 单点修改，区间查询
    class ZKW_Single {
    public:
        int n = 1;
        ll default_val = 0;
        vector<ll> dis;

        static ll op(ll l, ll r) {
            return l + r;
        }

        ZKW_Single(vector<int>& arr) {
            n = 1;
            while (n < (arr.size() + 2)) n <<= 1;
            dis.resize(n << 1, default_val);
            n++;
            for (int i = 0; i < arr.size(); i++) {
                dis[i + n] = arr[i];
            }
            for (int i = n - 2; i >= 1; i--) {
                dis[i] = op(dis[i << 1], dis[i << 1 | 1]);
            }
        }

        ZKW_Single(int sz) {
            n = 1;
            while (n < (sz + 2)) n <<= 1;
            dis.resize(n << 1, default_val);
            n++;
        }

        void update(int x, ll v) {
            for (dis[x += n] += v; x >>= 1; ) {
                dis[x] = op(dis[x << 1], dis[x << 1 | 1]);
            }
        }

        ll query(int L, int R) {
            ll ans = default_val;
            for (L += n - 1, R += n + 1; L ^ R ^ 1; L >>= 1, R >>= 1) {
                if (~L & 1) ans = op(ans, dis[L ^ 1]);
                if ( R & 1) ans = op(ans, dis[R ^ 1]);
            }
            return ans;
        }
    };

    // 区间修改，区间查询， 区间和
    class ZKW_Segment_SUM {
    public:
        class ZKW_Differential {
        private:
            int n;
            vector<int> tr;

        public:
            ZKW_Differential() = default;

            ZKW_Differential(vector<int> &arr) {
                n = 1;
                while (n < (arr.size() + 2)) n <<= 1;
                tr.resize(n << 1);
                n++;
                for (int i = 0; i < arr.size(); i++) {
                    tr[i + n] = arr[i];
                }
                for (int i = n - 2; i >= 1; i--) {
                    tr[i] = tr[i << 1] + tr[i << 1 | 1];
                }
            }

            void update(int L, int R, int addValue, int subValue) {
                for (tr[L += n] += addValue, L >>= 1; L; L >>= 1) {
                    tr[L] = tr[L << 1] + tr[L << 1 | 1];
                }
                for (tr[R += n + 1] -= subValue, R >>= 1; R; R >>= 1) {
                    tr[R] = tr[R << 1] + tr[R << 1 | 1];
                }
            }

            int query(int L, int R) {
                int res = 0;
                for (L += n - 1, R += n + 1; L ^ R ^ 1; L >>= 1, R >>= 1) {
                    if (~L & 1) res += tr[L ^ 1];
                    if (R & 1) res += tr[R ^ 1];
                }
                return res;
            }

        };
        ZKW_Differential zkw_differential;
        ZKW_Differential zkw_n_differential;

        explicit ZKW_Segment_SUM(vector<int> &arr) {
            vector<int> tmp = arr;
            adjacent_difference(arr.begin(), arr.end(), tmp.begin());

            zkw_differential = ZKW_Differential(tmp);
            for (int i = 0; i < arr.size(); i++) {
                tmp[i] *= (i + 1);
            }
            zkw_n_differential = ZKW_Differential(tmp);
        }

        void update(int L, int R, int value) {
            zkw_differential.update(L, R, value, value);
            zkw_n_differential.update(L, R, (L + 1) * value, (R + 2) * value);
        }

        int query(int L) {
            return ((L + 2) * zkw_differential.query(0, L) - zkw_n_differential.query(0, L));
        }

        int query(int L, int R) {
            return query(R) - query(L - 1);
        }
    };

    // 支持区间修改， 区间查询的最大值 最小值线段树， cmp = ZKW_SegmentTree_Extremum_Ext::max 参数决定
    class ZKW_SegmentTree_Extremum_Ext {
    public:
        int n;
        vector<int> tree;
        function<int(int, int)> cmp;

        static int max(int a, int b) {
            return std::max(a, b);
        }

        static int min(int a, int b) {
            return std::min(a, b);
        }

        ZKW_SegmentTree_Extremum_Ext(int sz, function<int(int, int)> cmp = ZKW_SegmentTree_Extremum_Ext::max) : cmp(cmp) {
            n = 1;
            while (n < sz + 2) n <<= 1;
            tree.resize(n * 2);
            n++;
        }

        ZKW_SegmentTree_Extremum_Ext(vector<int>& data, function<int(int, int)> cmp = ZKW_SegmentTree_Extremum_Ext::max) : cmp(cmp) {
            n = 1;
            while (n < data.size() + 2) n <<= 1;
            tree.resize(n * 2);
            n++;
            for (int i = 0; i < data.size(); i++) {
                tree[i + n] = data[i];
            }
            for (int i = n - 2; i > 0; i--) {
                int A = cmp(tree[i << 1], tree[i << 1 | 1]);
                tree[i] += A, tree[i << 1] -= A, tree[i << 1 | 1] -= A;
            }
        }

        void add(int L, int R, int val) {
            int A;
            for (L += n - 1, R += n + 1; L ^ R ^ 1; L >>= 1, R >>= 1) {
                if (~L & 1) tree[L ^ 1] += val;
                if (R & 1) tree[R ^ 1] += val;
                A = cmp(tree[L], tree[L ^ 1]), tree[L] -= A, tree[L ^ 1] -= A, tree[L >> 1] += A;
                A = cmp(tree[R], tree[R ^ 1]), tree[R] -= A, tree[R ^ 1] -= A, tree[R >> 1] += A;
            }
            for (; L != 1; L >>= 1) {
                A = cmp(tree[L], tree[L^1]);
                tree[L] -= A, tree[L^1] -= A, tree[L >> 1] += A;
            }
        }

        // 闭区间查询
        int query(int L, int R) {
            int lan = 0, ran = 0;
            for (L+= n, R += n; L != R and L ^ R ^ 1; L >>= 1, R >>= 1) {
                lan += tree[L], ran += tree[R];
                if (~L & 1) lan = cmp(lan, tree[L ^ 1]);
                if (R & 1) ran = cmp(ran, tree[R ^ 1]);
            }
            int ans = cmp(lan + tree[L], ran + tree[R]);
            while (L > 1) ans += tree[L >>= 1];
            return ans;
        }
    };

    // lazy线段树
    class lazy_segment {
    public:
        // 区间1的个数
        vector<ll> tree;
        // 区间翻转次数， 奇数翻转， 偶数不翻转
        vector<int> lazy;
        ll default_val = 0;
        ll op(ll a, ll b) {
            return a + b;
        }

        lazy_segment(vector<int>& arr) {
            int n = arr.size();
            tree.resize(n << 2);
            lazy.resize(n << 2);
            build(arr, 1, 0, n - 1);
        }

        void build(vector<int>& arr, int o, int l, int r) {
            if (l == r) {
                tree[o] = arr[l];
                return;
            }
            int m = (l + r) >> 1;
            build(arr, o << 1, l, m);
            build(arr, o << 1 | 1, m + 1, r);
            push_up(o, l, r);
        }

        void do_(int o, int l, int r) {
            tree[o] = r - l + 1 - tree[o];
            lazy[o] = 1 - lazy[o];
        }

        void push_down(int o, int l, int r) {
            int m = (l + r) >> 1;
            if (lazy[o]) {
                do_(o << 1, l, m);
                do_(o << 1 | 1, m + 1, r);
                lazy[o] = 0;
            }
        }

        void push_up(int o, int l, int r) {
            tree[o]  = op(tree[o << 1], tree[o << 1 | 1]);
        }

        void update(int o, int l, int r, int L, int R) {
            if (L <= l and r <= R) {
                do_(o, l, r);
                return;
            }
            push_down(o, l, r);
            int m = (l + r) >> 1;
            if (L <= m) update(o << 1, l, m, L, R);
            if (m < R) update(o << 1 | 1, m + 1, r, L, R);
            push_up(o, l, r);
        }

        ll query(int o, int l, int r, int L, int R) {
            if (L <= l and r <= R) {
                return tree[o];
            }
            push_down(o, l, r);
            ll ans = default_val;
            int m = (l + r) >> 1;
            if (L <= m) ans = op(ans,query(o << 1, l, m, L, R));
            if (m < R)  ans = op(ans, query(o << 1 | 1, m + 1, r, L, R));
            push_up(o, l, r);
            return ans;
        }

    };
}

using namespace my_segment;

class Solution {
public:
    vector<ll> makeNext(vector<int>& pattern) {
        int n = pattern.size();
        vector<ll> next(n);
        //
        ll r = 0;
        for (ll i = 1; i < n; i++) {
            // 不符合条件
            while (r and pattern[r] != pattern[i]) {
                r = next[r - 1];
            }
            if (pattern[r] == pattern[i]) {
                r++;
            }
            next[i] = r;
        }
        return next;
    }

    int countMatchingSubarrays2(vector<int>& nums, vector<int>& pattern) {
        int ans = 0;
        auto next = makeNext(pattern);
        int r = 0;
        for (int j = 1; j < nums.size(); j++) {
            int v = nums[j] > nums[j - 1] ? 1 : nums[j] == nums[j - 1] ? 0 : -1;
            while (r and pattern[r] != v) {
                r = next[r - 1];
            }
            if (pattern[r] == v) {
                r++;
            }
            if (r == pattern.size()) {
                ans++;
                // 取最长的前后缀
                r = next[r - 1];
            }
        }
        return ans;
    }

    int countMatchingSubarrays3(vector<int>& nums, vector<int>& pattern) {
        int ans = 0;
        int m = pattern.size();
        for (int i = 1; i < nums.size(); i++) {
            pattern.push_back((nums[i] > nums[i - 1]) - (nums[i] < nums[i - 1]));
        }
        int n = pattern.size();
        vector<int> z(n);
        int l = 0, r = 0;
        z[0] = n;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n and pattern[z[i]] == pattern[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        for (int i = m; i < n; i++) {
            ans += z[i] >= m;
        }
        return ans;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans = 0;
        HashObj hs(pattern);
        vector<int> nn;
        for (int i = 1; i < nums.size(); i++) {
            nn.push_back((nums[i] > nums[i - 1]) - (nums[i] < nums[i - 1]));
        }
        HashObj ht(nn);
        for (int i = pattern.size() - 1; i < nn.size(); i++) {
            ans += (hs.query(0, pattern.size() - 1) == ht.query(i - pattern.size() + 1, i));
        }
        return ans;
    }
};

// int main() {
//     Solution solution;
//     vector<int> nums = {1,2,3,4,5,6};
//     vector<int> pattern = {1, 1};
//     cout << solution.countMatchingSubarrays(nums, pattern) << endl;
//     return 0;
// }
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6]\n[1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,4,1,3,5,5,3]\n[1,0,-1]\n
// @lcpr case=end

 */

