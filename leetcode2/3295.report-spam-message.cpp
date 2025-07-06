/*
 * @lc app=leetcode.cn id=3295 lang=cpp
 * @lcpr version=30204
 *
 * [3295] 举报垃圾信息
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
#include <random>
// @lcpr-template-end
// @lc code=start
using ull = unsigned long long;

mt19937 mt(random_device{}());

template<typename T>
T rnd(T a, T b) {
    return uniform_int_distribution<T>(a, b)(mt);
}

ull mod = 1e18 + rnd(0, (int)1e9);
ull base = 233 + rnd(0, (int)1e9);

ull StringHash(string& s) {
    ull hash = 0;
    for (auto& ch: s) {
        hash = (hash * base + ch) % mod;
    }
    return hash;
}

class OBJ {
public:
    vector<__int128_t> P, H;

    OBJ(const string& s) {
        int n = s.size();
        P.resize(n + 1);
        P[0] = 1;
        for (int i = 1; i <= n; i++) {
            P[i] = P[i - 1] * base % mod;
        }
        H.resize(n + 1);
        H[0] = 0;
        for (int i = 1; i <= n; i++) {
            H[i] = (H[i - 1] * base + s[i - 1]) % mod;
        }
    }

    ull query(int l, int r) {
        if (l > r) return 0;
        return (H[r + 1] - H[l] * P[r - l + 1] + mod) % mod;
    }
};


class Solution {
public:
    bool reportSpam1(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<ull> us;
        for (auto& ban: bannedWords) {
            us.insert(StringHash(ban));
        }
        int ct = 0;
        for (string& m: message) {
            if (us.count(StringHash(m)) > 0 and ++ct >= 2) return true;
        }
        return false;
    }

    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<ull> us;
        for (auto& ban: bannedWords) {
            OBJ obj(ban);
            us.insert(obj.query(0, ban.size() - 1));
        }
        int ct = 0;
        for (string& m: message) {
            OBJ obj(m);
            if (us.count(obj.query(0, m.size() - 1)) > 0 and ++ct >= 2) return true;
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["hello","world","leetcode"]\n["world","hello"]\n
// @lcpr case=end

// @lcpr case=start
// ["hello","programming","fun"]\n["world","programming","leetcode"]\n
// @lcpr case=end

 */

