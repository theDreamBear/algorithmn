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
    ull mod1 =  1070777777, mod2 = 1000000007;
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
            t += "#";
            t.push_back(c);
        }
        t += "#$";
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

    using ST_MAX = ST<MAX_FUNC<int>>;
    using ST_MIN = ST<MIN_FUNC<int>>;

    using ZKW_MAX = ZKW<MAX_FUNC<int>>;
    using ZKW_MIN = ZKW<MIN_FUNC<int>>;
    using ZKW_SUM = ZKW<SUM_FUNC<int>>;

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