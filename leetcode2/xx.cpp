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
//#define f first
//#define s second

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

    using lll = __int128_t;
    using ulll = __uint128_t;
    using pii = pair<int32_t, int32_t>;
    using pll = pair<ll, ll>;
    using vll = vector<ll>;
    template<class... Ts> using vo = vector<Ts...>;
    template<class... Ts> using min_queue = priority_queue<Ts..., vo<Ts...>, greater<>>;
    template<class... Ts> using max_queue = priority_queue<Ts...>;
    template<class... Ts> using umap = map<Ts...>;
    template<class... Ts> using uset = unordered_set<Ts...>;

// loops
#define each(a, x) for (auto &a : x)
#define irep(n) for (int i = 0; i < (n); ++i)
#define irepf1(n) for (int i = 1; i <= (n); ++i)
#define jrep(n) for (int j = 0; j < (n); ++j)
#define jrepf1(n) for (int j = 1; j <= (n); ++j)
#define krep(n) for (int k = 0; k < (n); ++k)
#define krepf1(n) for (int k = 1; k <= (n); ++k)
#define rep(i, s, e) for (int (i) = (s); (i) < (e); (i)++)
#define per(i, s, e) for (int (i) = (s); (i) >= (e); (i)--)
#define INF 1000000000000000000
#define Banpei 1000000000 // 問題毎に設定
#define Max_V 100000
#define mod7 1000000007
#define mod9 998244353
#define eps 0.00000001


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
using b_heap_iterator = typename bigpHeap<T>::point_iterator;
template<typename T>
using s_heap_iterator = typename smallHeap<T>::point_iterator;


template <typename T>
using sortedSet =   __gnu_pbds ::tree<T, __gnu_pbds::null_type, less<T>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;

template <typename T>
using _sorted_list = tree<pair<T, ll>, null_type, less<pair<T, ll>>, rb_tree_tag, tree_order_statistics_node_update>;

// rank从0开始的
template <typename T>
class SortedList {
public:
    _sorted_list<T> _list;
    unordered_map<T, ll> idx;
    void insert(T x) {
        _list.insert({x, idx[x]++});
    }
    void erase(T x) {
        if (idx.count(x) and idx[x] > 0) {
            _list.erase({x, --idx[x]});
            if (idx[x] == 0) {
                idx.erase(x);
            }
        }
    }
    T find_by_order(ll k) {
        return _list.find_by_order(k)->first;
    }

    // 第一个的位置
    ll order_of_key(T x) {
        return _list.order_of_key({x, 0});
    }

    auto prev(T x) {
        auto rk = order_of_key(x);
        return find_by_order(rk - 1);
    }

    auto nxt(T x) {
        auto rk = order_of_key(x + 1);
        return find_by_order(rk);
    }

    auto lower_bound(T x) {
        return _list.lower_bound({x, 0})->first;
    }
    auto upper_bound(T x) {
        return _list.lower_bound({x + 1, 0})->first;
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

    template<typename Func>
    ll mod_op(ll a, ll b, ll mod, Func f) {
        return f(a, b) % mod;
    }

    ll mod_add(ll a, ll b, ll mod) {
        return (a + b) % mod;
    }

    ll mod_sub(ll a, ll b, ll mod) {
        return (a - b + mod) % mod;
    }

    ll mod_mulipliy(ll a, ll b, ll mod) {
        return a * b % mod;
    }

    template<typename Func>
    ll mod_div(ll a, ll b, ll mod) {
        return a * quickMi(b, mod - 2, mod);
    }

    template <ll MD> struct ModInt {
        static constexpr ll md = MD;
        using M = ModInt;
        const static M G;
        ll v;
        ModInt(ll _v = 0) { set_v(_v % MD + MD); }
        M& set_v(ll _v) {
            v = (_v < MD) ? _v : _v - MD;
            return *this;
        }
        explicit operator bool() const { return v != 0; }
        M operator-() const { return M() - *this; }
        M operator+(const M& r) const { return M().set_v(v + r.v); }
        M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
        M operator*(const M& r) const { return M().set_v(ll(v) * r.v % MD); }
        M operator/(const M& r) const { return *this * r.inv(); }
        M& operator+=(const M& r) { return *this = *this + r; }
        M& operator-=(const M& r) { return *this = *this - r; }
        M& operator*=(const M& r) { return *this = *this * r; }
        M& operator/=(const M& r) { return *this = *this / r; }
        bool operator==(const M& r) const { return v == r.v; }
        M pow(ll n) const {
            M x = *this, r = 1;
            while (n) {
                if (n & 1) r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        M inv() const { return pow(MD - 2); }
        friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
    };
//    using Mint = ModInt<998244353>;
//
//    Mint mod_pow (Mint l, ll r) {
//        if (r == 0) return 1;
//
//        return mod_pow((l * l), r/2) * ((r%2) ? l : 1);
//    }
//    Mint mod_inv (Mint x) {
//        return mod_pow(x, Mint::md - 2);
//    }
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

    template<typename ...T>
    struct Range;


    struct intIterator {
        typedef long VALUE_TYPE;
        explicit intIterator(VALUE_TYPE value) {
            _value = value;
        }

        bool operator != (intIterator& rhs) {
            return getValue() != rhs.getValue();
        }

        VALUE_TYPE operator*() const {
            return getValue();
        }

        const intIterator&  operator ++() {
            ++_value;
            return *this;
        }
    private:
        [[nodiscard]] VALUE_TYPE getValue() const{
            return _value;
        }
        VALUE_TYPE _value;


    };

    template<>
    struct Range<int> {
        int left,right;

        Range(int left, int right) {
            this->left = left;
            this->right = right;
        }

        explicit Range(int right) {
            left = 0;
            this->right = right;
        }

        [[nodiscard]] intIterator begin() const {
            return intIterator(left);
        }

        [[nodiscard]] intIterator end() const {
            return intIterator(right);
        }
    };

    template<typename T>
    struct vecIterator {
        explicit vecIterator(const vector<T>& values):_index(0), _values(values){}

        vecIterator(int index, const vector<T>& values):_index(index), _values(values){}

        bool operator!=(const vecIterator& rhs) {
            return getIndex() != rhs.getIndex();
        }

        pair<int, T> operator* () const{
            int index = getIndex();
            return {index, ref(_values[index])};
        }

        const vecIterator& operator++() {
            ++_index;
            return *this;
        }

    private:
        [[nodiscard]] int getIndex() const{
            return _index;
        }

        int _index;
        const vector<T>& _values;
    };

    template<typename T>
    struct Range<vecIterator<T>> {
        //typedef long T;
        const vector<T>& values;

        explicit Range(const vector<T>& values):values(values) {}

        [[nodiscard]] vecIterator<T> begin() const {
            return vecIterator<T>(0, values);
        }

        [[nodiscard]] vecIterator<T> end() const {
            return vecIterator<T>(values.size(), values);
        }
    };

    Range<int> range(int left, int right) {
        return Range<int>(left, right);
    }

    Range<int> range(int right) {
        return Range<int>(0, right);
    }

    template<typename T>
    Range<vecIterator<T>> range(const vector<T>& data) {
        return Range<vecIterator<T>>(data);
    }
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

    long long MOD = 1e18 + rnd(0, 1e9), BASE = 233 + rnd(0, 1e3);

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
        ll n = source.size(), m = needle.size();
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

        bool isMatch(string& s) {
            ACNode* cur = &root;
            for (int i = s.size() - 1; i >= 0; i--) {
                int id = s[i] - 'a';
                if (cur->children[id]) {
                    cur = cur->children[id];
                } else {
                    break;
                }
                if (!cur->exsit.empty()) {
                    for (auto& len : cur->exsit) {
                        if (i + len >= s.size()) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    };
};

using namespace my_string;

namespace my_bit {
    template<typename T>
    string intToBinary(T n) {
        if (n == 0) {
            return "0";
        }
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

    template<typename T>
    int is_set(T x, int pos) {
        assert(pos >= 0);
        return (x >> pos) & 1;
    }

#if __cplusplus < 202002L
    template<typename T>      bool has_single_bit(T n) { return n > 0 && (n & (n - 1)) == 0; }      template<typename T>      int bit_width(T n) {          if (n == 0) return 0;          return sizeof(n) - __builtin_clz(n);      }      template<typename T>      T bit_ceil(T n) {          if (n <= 1) return 1;          if (has_single_bit(n)) return n;          return (T)1 << bit_width(n);      }      template<typename T>      T bit_floor(T n) {          if (n == 0) return 0;          if (has_single_bit(n)) return n;          return (T)1 << (bit_width(n) - 1);      }      // 循环左移      template<typename T>      T rotl(T n, unsigned int shift) {          const unsigned int mask = sizeof(T) * 8 - 1;          shift &= mask;          return (n << shift) | (n >> ((-shift) & mask));      }      // 循环右移      template<typename T>      T rotr(T n, unsigned int shift) {          const unsigned int mask = sizeof(T) * 8 - 1;          shift &= mask;          return (n >> shift) | (n << ((-shift) & mask));      }      //      template<typename T>      int countl_zero(T n) {          if (n == 0) return sizeof(T) * 8;          return __builtin_clz(n);      }      template<typename T>      int countl_one(T n) {          if (n == 0) {              return 0;          }          int high = bit_width(n);          int cnt = 0;          for (int i = high - 1; i >= 0; i--) {              if ((n >> i) & 1) cnt++;              else {                  break;              }          }          return cnt;      }      template<typename T>      int countr_zero(T n) {          if (n == 0) return sizeof(T) * 8;          return __builtin_ctz(n);      }      template<typename T>      int countr_one(T n) {          int count = 0;          while (n & 1) {              n >>= 1;              ++count;          }          return count;      }      template<typename T>      int popcount(T n) {          int count = 0;          while (n) {              count += n & 1;              n >>= 1;          }          return count;      }
#endif
};

using namespace my_bit;

namespace my_segment {
    template<typename T>
    struct MAX_FUNC {
    public:
        using value_type = T;
        const value_type default_value = numeric_limits<T>::min();

        T operator()(T a, T b) {
            return max(a, b);
        }
    };

    template<typename T>
    struct MIN_FUNC {
    public:
        using value_type = T;
        const value_type default_value = numeric_limits<T>::max();

        T operator()(T a, T b) {
            return min(a, b);
        }
    };

    template<typename T>
    struct SUM_FUNC {
    public:
        using value_type = T;
        const value_type default_value = 0;

        T operator()(T a, T b) {
            return a + b;
        }
    };

    template<typename FUNC>
    class ST{
    public:
        using value_type = typename FUNC::value_type;
        FUNC func;
        //
        vector<vector<value_type>> st;
        ST(const vector<value_type>& arr) {
            int n = arr.size();
            int k = log2(arr.size()) + 1;
            st.resize(arr.size(), vector<ll>(k, func.default_val));
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

        value_type query(int L, int R) {
            int d = log2(R - L + 1);
            return func(st[L][d], st[R - (1 << d) + 1][d]);
        }

        ll  bisect_right(int L, int R, value_type target) {
            return ::bisect_right(L, R, [&](ll idx) {
                return query(idx, R) < target;
            });
        }

        ll bisect_left(int L, int R, value_type target) {
            return ::bisect_left(L, R, [&](ll idx) {
                return query(L, idx) > target;
            });
        }
    };

    template<typename Func>
    class ZKW {
    public:
        using value_type = typename Func::value_type;
        Func func;
        int n;
        vector<value_type> tree;

        ZKW(int sz) {
            n = 1;
            while (n < sz + 2) n <<= 1;
            tree.resize(n * 2, func.default_value);
            n++;
        }

        ZKW(vector<value_type>& data) {
            n = 1;
            while (n < data.size() + 2) n <<= 1;
            tree.resize(n * 2, func.default_value);
            n++;
            for (int i = 0; i < data.size(); i++) {
                tree[i + n] = data[i];
            }
            for (int i = n - 2; i > 0; i--) {
                tree[i] = func(tree[i << 1], tree[i << 1 | 1]);
            }
        }

        void update(int i, value_type val) {
            for (tree[i += n] = val, i >>= 1; i; i >>= 1) {
                tree[i] = func(tree[i << 1], tree[i << 1 | 1]);
            }
        }
        value_type query(int L, int R) {
            value_type ans = func.default_value;
            for (L+= n - 1, R += n + 1; L ^ R ^ 1; L >>= 1, R >>= 1) {
                if (~L & 1) ans = func(ans, tree[L ^ 1]);
                if (R & 1) ans = func(ans, tree[R ^ 1]);
            }
            return ans;
        }
    };

    using ST_MAX = ST<MAX_FUNC<ll>>;
    using ST_MIN = ST<MIN_FUNC<ll>>;

    using ZKW_MAX = ZKW<MAX_FUNC<ll>>;
    using ZKW_MIN = ZKW<MIN_FUNC<ll>>;
    using ZKW_SUM = ZKW<SUM_FUNC<ll>>;

    class ZKW_Differential {
    private:
        int n;
        vector<int> tr;

    public:
        ZKW_Differential() =default;

        ZKW_Differential(vector<int> & arr) {
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

    // 支持区间修改， 区间查询的区间和线段树
    class ZKW_SegmentTree_SUM {
    public:
        ZKW_Differential zkw_differential;
        ZKW_Differential zkw_n_differential;

        explicit ZKW_SegmentTree_SUM(vector<int> & arr) {
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
            zkw_n_differential.update(L, R, (L + 1) *value, (R + 2) * value);
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
}

using namespace my_segment;

namespace my_uf {

    template<typename T>
    class UF {
    public:
        vector<T> fa;
        int groupCnt;

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

        // 左边合并到右边
        void merge(T u, T v) {
            T pu = find(u), pv = find(v);
            if (pu == pv) return;
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

    template<typename T>
    class UFR {
    public:
        vector<T> fa, rank;
        int groupCnt;

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
            if (pu == pv) return;
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

};
using namespace my_uf;

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




namespace my_randome_test {
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

    ll getRandomInt(ll low, ll high) {
        std::uniform_int_distribution<ll> dist(low, high);
        return dist(rng);
    }

    std::vector<ll> generateRandomArray(int size, ll min_val, ll max_val) {
        std::vector<ll> arr(size);
        for (auto &x : arr) {
            x = getRandomInt(min_val, max_val);
        }
        return arr;
    }
};

namespace my_testing {
    ostream& operator << (ostream& os, vector<ll>& arr) {
        for (auto v: arr) {
            os << v << "\t";
        }
        return os;
    }

    // 定义颜色的终端控制序列
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";        // 红色
    const std::string GREEN = "\033[32m";      // 绿色
    const std::string YELLOW = "\033[33m";     // 黄色

    void pass_print(const string& s) {
        // 使用GREEN定义的控制序列来输出绿色文本到stderr
        std::cerr << GREEN << s << RESET << std::endl;
    }

    void wa_print(const string& s) {
        // 使用RED定义的控制序列来输出红色文本到stderr
        std::cerr << RED << s << RESET << std::endl;
    }

    void info_print(const string& s) {
        // 使用YELLOW定义的控制序列来输出黄色文本到stderr
        std::cerr << YELLOW << s << RESET << std::endl;
    }

    struct my_timer {
        chrono::time_point<chrono::steady_clock> start, end;
        chrono::duration<double> duration;
        my_timer() {
            start = chrono::steady_clock::now();
        }
        ~my_timer() {
            end = chrono::steady_clock::now();
            duration = end - start;
            info_print("time: " + to_string(duration.count() * 1000) + "ms");
        }
    };

    string emptyStr = "nullptr";
    string inputFile = "in.dat";
    string outputFile = "out.dat";
    string expectFile = "exp.dat";

    ifstream in(inputFile);
    ofstream out(outputFile);

    ifstream output(outputFile);
    ifstream expect(expectFile);

    class Prepare {
    public:
        Prepare() {
            prepare();
        }

        static void prepare() {
            if (!in.is_open()) {
                info_print("in empty input file");
                exit(-1);
            }
            if (!expect.is_open()) {
                info_print("exp empty input file");
                exit(-1);
            }
        };
    };
    class Check {
    public:
        ~Check() {
            // compare
#ifndef ONLINE_JUDGE
            for (int i = 1; !output.eof(); ++i) {
                if (output.eof()) {
                    break;
                }
                string l, r;
                getline(output, l);
                getline(expect, r);
                while (!l.empty() && l.back() == ' ') {
                    l.pop_back();
                }
                while (!r.empty() && r.back() == ' ') {
                    r.pop_back();
                }
                if (l.empty() && r.empty()) {
                    break;
                }
                if (l == emptyStr) {
                    break;
                }
                if (l == r) {
                    pass_print("case: " + to_string(i) + " pass");
                } else if (l != r) {
                    wa_print("case: " + to_string(i) + " wa" + " output: " + l + " expect: " + r);
                    continue;
                }
            }
#endif
        }
    };
};


// #define MY_DEBUG
//#define MY_LEETCODE

#ifdef MY_LEETCODE
#undef MY_CFF
#else
#define MY_CFF
#endif

#ifdef MY_DEBUG
#undef MY_RELEASE
#define MY_Check
#else
#define MY_RELEASE
#endif

#ifdef MY_Check
void test() {
    // 随机生成数据
    // #define GEN_RNADONE_TEST
    #ifdef GEN_RNADONE_TEST
    using namespace my_testing;
    using namespace my_randome_test;
    ofstream inn(inputFile);
        ofstream expe(expectFile);
        auto brute = [&expe](vector<ll>& a, vector<ll>& b) {
            // 数量最多的找价格最便宜的
            int cur = 0;
            ll ans = 0;
            while (true) {
                int mmi = 0;
                for (int i = 0; i < a.size(); i++) {
                    if (b[i] < b[mmi] || (b[i] == b[mmi] and a[i] > a[mmi])) {
                        mmi = i;
                    }
                }
                int li = 0;
                //int lp = INT_MAX;
                for (int i = 0; i < a.size(); i++) {
                    if (a[i] > a[li] || (a[i] == a[li] and b[i] < b[li])) {
                        li = i;
                    }
                }
                if (mmi == li) {
                    cur++;
                    ans += b[mmi];
                    a[mmi]--;
                } else {
                    if (b[mmi] < b[li] * 2) {
                        cur++;
                        ans += b[mmi];
                        a[mmi]--;
                    } else {
                        cur ++;
                        ans += b[li];
                        a[li]--;
                    }
                }
                bool flag = true;
                for (int i = 0; i < a.size(); i++) {
                    if (a[i] >= cur) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            expe << ans << endl;
        };
        int low = 0;
        int high = 20;
        int sz = 5;
        int times = 100;
        inn << times << endl;
        for (int i = 0; i < times; i++) {
            auto a = generateRandomArray(sz, low, high);
            auto b = generateRandomArray(sz, 1, 6);
            inn << sz << endl;
            inn << a << endl;
            inn << b << endl;
            // 对比输出到文件
            brute(a, b);
        }
#endif
}

void init() {
#ifndef ONLINE_JUDGE
    using namespace my_testing;
    static Prepare pre;
    static Check check;

    using namespace my_testing;
    using namespace  my_randome_test;
    my_timer timer;
    freopen("in.dat", "r", stdin);
    freopen("out.dat", "w", stdout);

    test();
#endif
}

// my_testing::wa_print( "Array access out of bounds at line " + to_string(__LINE__)  +  ": "  + e.what());

#define Trace_Bein try {
#define Trace_End } catch (exception& e) { \
        cout << -((444444440000000) + __LINE__) << endl; \
    }
#else
    void init(){}
    #define Trace_Bein
    #define Trace_End
#endif




void solve(vector<ll>& a, vector<ll>& b) {
    // 价格
    vector<ll> idx(a.size());
    iota(all(idx), 0);
    // 按照b的大小排序
    ranges::sort(idx, [&](int i, int j) {
        return b[i] < b[j];
    });
    // 数量
    vector<ll> cntidx(a.size());
    iota(all(cntidx), 0);
    // 按照b的大小排序
    ranges::sort(cntidx, [&](int i, int j) {
        return a[i] > a[j];
    });

    vector<ll> c(a.size());
    int mt = ranges::max(a);
    int n = a.size();
    ll ans = LLONG_MAX;
    // 单调性是前不够一定不能成为第一
    ll low = 0, high = 36;
    auto check = [&](ll mm) {
       // 计算最多能买多少个
       auto get_max = [&](ll left) {
           ll res = 0;
           for (int i = 0 ; left and i < idx.size(); i++) {
                if (b[idx[i]] <= left) {
                     int cnt = min({left, a[idx[i]], left / b[idx[i]]});
                     res += cnt;
                     left -= cnt * b[idx[i]];
                }
           }
           return res;
       };
        // 二分枚举用这么多钱买的话， 成功的时候的糖果数量
        int lt = 0, rt = get_max(mm);
       // 返回第一个不符合的位置， true, true, ... false
       auto res = bisect_left(lt, rt, [&](ll target) {
           // 我是mm, 我还要是第一
           c = a;
           ll need = target;
           ll leftmm = mm;
           for (int i = 0; i < c.size(); i++) {
               if (c[cntidx[i]] >= target) {
                   int cnt = min(need, c[cntidx[i]] - target + 1);
                   need -= cnt;
                   leftmm -= cnt * b[cntidx[i]];
                   c[cntidx[i]] -= cnt;
                   if (need <= 0 and leftmm <= 0) {
                       break;
                   }
               } else {
                   break;
               }
           }
           if (need >= 0 and leftmm <= 0) return true;
           for (int i = 0; i < c.size() and need; i++) {
               if (c[idx[i]]) {
                   int cnt = min(need, c[idx[i]]);
                   need -= cnt;
                   leftmm -= cnt * b[idx[i]];
                   if (need <= 0 || leftmm <= 0) {
                       break;
                   }
               }
           }
           if(!(need == 0 and leftmm >= 0)) {
               return true;
           }
           for (int i = 0; i < c.size(); i++) {
               if (c[i] >= target) {
                   return true;
               }
           }
           return false;
       });
       return res != rt + 1;
    };
    while (low + 1 < high) {
        ll mid = (high - low) / 2 + low;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    if (check(low)) {
        cout << low << endl;
    } else {
        cout << high << endl;
    }
}


#ifdef MY_CFF
void solveA() {
    def(ll, k);
    if (k % 2 == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


int main() {
    Trace_Bein

    init();
    setIO();
    def(ll, tc);
    while (tc--) solveA();

    Trace_End
}
#endif
