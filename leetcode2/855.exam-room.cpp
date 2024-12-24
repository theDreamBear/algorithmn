/*
 * @lc app=leetcode.cn id=855 lang=cpp
 * @lcpr version=30204
 *
 * [855] 考场就座
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
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class ExamRoom1 {
  public:
    using pii = pair<int, int>;
    struct Cmp {
        bool operator()(const pii& lhs, const pii& rhs) {
            int d1 = (lhs.second - lhs.first) / 2;
            int d2 = (rhs.second - rhs.first) / 2;
            return (d1 < d2) or (d1 == d2 and lhs.first > rhs.first);
        }
    };

    int                                   n;
    set<int>                              seats;
    priority_queue<pii, vector<pii>, Cmp> pq;

    ExamRoom1(int n) {
        this->n = n;
    }

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        int left = *seats.begin(), right = n - 1 - *seats.rbegin();
        // 延迟删除
        while (seats.size() >= 2) {
            // isValid
            auto [l, r] = pq.top();
            if (seats.count(l) and seats.count(r) and *next(seats.find(l)) == r) {
                int d = r - l;
                if (d / 2 < right or d / 2 <= left) {
                    break;
                }
                pq.pop();
                int ans = (l + r) / 2;
                seats.insert(ans);

                pq.push({l, ans});
                pq.push({ans, r});
                return ans;
            }
            pq.pop();
        }
        // 两边的最大
        if (left >= right) {
            pq.push({0, left});
            seats.insert(0);
            return 0;
        } else {
            pq.push({*seats.rbegin(), n - 1});
            seats.insert(n - 1);
            return n - 1;
        }
    }

    void leave(int p) {
        if (p != *seats.begin() and p != *seats.rbegin()) {
            auto it = seats.find(p);
            pq.push({*prev(it), *next(it)});
        }
        seats.erase(p);
    }
};

int n;
int dist(const pair<int, int>& p) {
    auto [l, r] = p;
    if (l == -1 || r == n)
        return r - l - 1;
    return (r - l) >> 1;
}

struct Cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        int d1 = dist(a), d2 = dist(b);
        return d1 == d2 ? a.first < b.first : d1 > d2;
    };
};
class ExamRoom {
  public:
    using pii = pair<int, int>;

    set<pii, Cmp>           ss;
    unordered_map<int, int> left, right;
    //int                     n;

    ExamRoom(int _n) {
        n = _n;
        add({-1, n});
    }

    int seat() {
        auto [l, r] = *ss.begin();
        int ans     = (l + r) / 2;
        if (l == -1) {
            ans = 0;
        } else if (r == n) {
            ans = n - 1;
        }
        del(*ss.begin());
        add({l, ans});
        add({ans, r});
        return ans;
    }

    void leave(int p) {
        int l = left[p], r = right[p];
        del({l, p});
        del({p, r});
        add({l, r});
    }

  private:
    void add(pii p) {
        ss.insert(p);
        right[p.first] = p.second;
        left[p.second] = p.first;
    }

    void del(pii p) {
        ss.erase(p);
        left.erase(p.second);
        right.erase(p.first);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 *
 *
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

/*
// @lcpr case=start
// ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]\n
// @lcpr case=end

 */
