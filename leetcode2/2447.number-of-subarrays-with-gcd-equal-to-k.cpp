/*
 * @lc app=leetcode.cn id=2447 lang=cpp
 * @lcpr version=30204
 *
 * [2447] 最大公因数等于 K 的子数组数目
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
namespace my_using {
    using ui = unsigned int;
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

    template<typename T>
    struct GCD_FUNC {
    public:
        using value_type = T;
        const value_type default_val = 0;

        T operator()(T a, T b) {
            return gcd(a, b);
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
            st.resize(arr.size(), vector<value_type>(k, func.default_val));
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

        ll binary_search_right(int L, int R, auto&& op) {
            int low = L, high = R;
            while (low + 1 < high) {
                int mid = (low + high) >> 1;
                if (op(query(L, mid))) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            if (op(query(L, high))) {
                return high;
            }
            if (op(query(L, low))) {
                return low;
            }
            return low - 1;
        }
    };



class Solution {
public:
    // 哎, 模拟
    int subarrayGCD_1(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        // 枚举每一个
        for (int i = 0; i < n; i++) {
            int g  = 0;
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g % k != 0) break;
                if (g == k) ans++;
            }
        }
        return ans;
    }


    // 最右 ()>= k) - ()> k)
    // 最左 < k - <= k
    int subarrayGCD(vector<int>& nums, int k) {
        ST<GCD_FUNC<int>> st(nums);
        int ans = 0, n = nums.size();
        // 枚举每一个
        for (int i = 0; i < n; i++) {
            // <= k, < k
            auto l = st.binary_search_right(i, n - 1, [&](int val) {
                return val > k;
            });
            auto r = st.binary_search_right(i, n - 1, [&](int val) {
                return val >= k;
            });
            ans += (r - l);
        }
        return ans;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [9,3,1,2,6,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [4]\n7\n
// @lcpr case=end

 */

