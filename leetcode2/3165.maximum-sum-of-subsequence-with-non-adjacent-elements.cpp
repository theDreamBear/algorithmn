// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3165 lang=cpp
 * @lcpr version=30204
 *
 * [3165] 不包含相邻元素的子序列的最大和
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
using ull = unsigned long long;
using ll  = long long;
using db  = long double;  // or double, if TL is tight
using str = string;       // yay python!

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
using vi  = V<int>;
using vb  = V<bool>;
using vl  = V<ll>;
using vd  = V<db>;
using vs  = V<str>;
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

using lll                              = __int128_t;
using ulll                             = __uint128_t;
using pii                              = pair<int32_t, int32_t>;
using pll                              = pair<ll, ll>;
using vll                              = vector<ll>;
template <class... Ts> using vo        = vector<Ts...>;
template <class... Ts> using min_queue = priority_queue<Ts..., vo<Ts...>, greater<>>;
template <class... Ts> using max_queue = priority_queue<Ts...>;
template <class... Ts> using umap      = map<Ts...>;
template <class... Ts> using uset      = unordered_set<Ts...>;

// loops
#define each(a, x) for (auto& a : x)
#define irep(n) for (int i = 0; i < (n); ++i)
#define irepf1(n) for (int i = 1; i <= (n); ++i)
#define jrep(n) for (int j = 0; j < (n); ++j)
#define jrepf1(n) for (int j = 1; j <= (n); ++j)
#define krep(n) for (int k = 0; k < (n); ++k)
#define krepf1(n) for (int k = 1; k <= (n); ++k)
#define rep(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define per(i, s, e) for (int(i) = (s); (i) >= (e); (i)--)
#define INF 1000000000000000000
#define Banpei 1000000000  // 問題毎に設定
#define Max_V 100000
#define mod7 1000000007
#define mod9 998244353
#define eps 0.00000001

#define lb lower_bound
#define ub upper_bound

tcT > int lwb(const V<T>& a, const T& b) {
    return int(lb(all(a), b) - bg(a));
}
tcT > int upb(const V<T>& a, const T& b) {
    return int(ub(all(a), b) - bg(a));
}
tcT > int eqb(const V<T>& a, const T& b) {
    return upb(a, b) - lwb(a, b);
}
}  // namespace my_using

using namespace my_using;

class Solution {
  public:
    int maximumSumSubsequenc1(vector<int>& nums, vector<vector<int>>& queries) {
        int  n = sz(nums);
        vl   dp(n, INT_MIN);
        auto rebuild = [&](int p) {
            // 如果修改影响结束就停止
            int lastP = p - 1;
            for (int i = p; i < n; i++) {
                ll old = dp[i];
                if (i == 0) {
                    dp[i] = max(0, nums[i]);
                } else if (i == 1) {
                    dp[i] = max(dp[i - 1], max(0ll, (ll)nums[i]));
                } else {
                    dp[i] = max(dp[i - 1], max(0ll, dp[i - 2]) + nums[i]);
                }
                if (old == dp[i]) {
                    if (i - lastP >= 2) {
                        break;
                    }
                } else {
                    lastP = i;
                }
            }
            return dp[n - 1];
        };
        rebuild(0);
        ll ans = 0;
        for (auto& vec : queries) {
            int p = vec[0], x = vec[1];
            nums[p] = x;
            ans     = (ans + rebuild(p)) % (int)(1e9 + 7);
        }
        return ans;
    }

    struct Node {
            //unsigned int dp[4]{};
            array<unsigned int, 4> dp{};
            // 正确的写法
            friend Node operator+(const Node& lhs, const Node& rhs) {
                Node nn;
                /*
                0, 无首无尾
                1, 无手有尾
                2, 有首无尾
                3, 有首有尾
                */
                nn.dp[0] = max({lhs.dp[0] + rhs.dp[2], lhs.dp[1] + rhs.dp[0]});
                nn.dp[1] = max({lhs.dp[0] + rhs.dp[3], lhs.dp[1] + rhs.dp[1]});
                nn.dp[2] = max({lhs.dp[2] + rhs.dp[2], lhs.dp[3] + rhs.dp[0]});
                nn.dp[3] = max({lhs.dp[2] + rhs.dp[3], lhs.dp[3] + rhs.dp[1]});
                return nn;
            }
        };

    // 线段树
    // typing too slow
    int maximumSumSubsequence2(vector<int>& nums, vector<vector<int>>& queries) {
        int n = sz(nums);
        vector<Node> tree(n << 2);
        auto update = [&](auto&& update, int o, int l, int r, int L) {
            if (l == r) {
                tree[o].dp[3] = max(0, nums[l - 1]);
                return;
            }
            int m = (l + r) / 2;
            if (L <= m) update(update, o << 1, l, m, L);
            else {
                update(update, o << 1 | 1, m + 1, r, L);

            }
            tree[o] = tree[o << 1] + tree[o << 1 | 1];
        };
        auto build = [&](auto&& build, int o, int l, int r) {
            if (l == r) {
                tree[o].dp[3] = max(0, nums[l - 1]);
                return;
            }
            int m = (l + r) / 2;
            build(build, o << 1, l, m);
            build(build, o << 1 | 1, m + 1, r);
            tree[o] = tree[o << 1] + tree[o << 1 | 1];
        };

        auto getmax = [&]() {
            return tree[1].dp[3];
        };

        build(build, 1, 1, n);
        long long ans = 0;
        for (auto& vec: queries) {
            nums[vec[0]] = vec[1];
            update(update, 1, 1, n, vec[0] + 1);
            ans += getmax();
        }
        return ans % (int)(1e9 + 7);
    }

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

        void update(int i, value_type& val) {
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

    template<typename T>
    struct MAX_FUNC {
    public:
        using value_type = T;
        const value_type default_value = T{};

        T operator()(T a, T b) {
            return a + b;
        }
    };

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = sz(nums);
        vector<Node> data;
        for (int i = 0; i < nums.size(); i++) {
            Node nn;
            nn.dp[3] = max(0, nums[i]);
            data.push_back(nn);
        }
        ZKW<MAX_FUNC<Node>> zkw(data);
        long long ans = 0;
        for (auto& vec: queries) {
            Node nn;
            nn.dp[3] = max(0, vec[1]);
            zkw.update(vec[0], nn);
            ans += zkw.tree[1].dp[3];
        }
        return ans % (int)(1e9 + 7);
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maximumSumSubsequence
// paramTypes= ["number[]","number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [3,5,9]\n[[1,-2],[0,-3]]\n
// @lcpr case=end

// @lcpr case=start
// [0,-1]\n[[0,-5]]\n
// @lcpr case=end

 */
