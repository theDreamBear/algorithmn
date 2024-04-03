/*
 * @lc app=leetcode.cn id=LCR 058 lang=cpp
 * @lcpr version=30121
 *
 * [LCR 058] 我的日程安排表 I
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
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class MyCalendar1 {
private:
    set<pair<int, int>>  calendar;

public:
    MyCalendar1() {

    }

    bool is_intersect(int l1, int h1, int l2, int h2) {
        if (l1 > l2) {
            return is_intersect(l2, h2, l1, h1);
        }
        return !(l2 > h1);
    }

    bool book(int start, int end) {
        for (auto& p : calendar) {
            if (is_intersect(p.first, p.second, start, end - 1)) {
                return false;
            }
        }
        calendar.insert({start, end - 1});
        return true;
    }
};

class MyCalendar2 {
private:
    vector<pair<int, int>>  calendar;

public:
    MyCalendar2() {

    }
    bool is_intersect(int l1, int h1, int l2, int h2) {
        if (l1 > l2) {
            return is_intersect(l2, h2, l1, h1);
        }
        return !(l2 > h1);
    }

    bool book(int start, int end) {
        for (auto& p : calendar) {
            if (is_intersect(p.first, p.second, start, end - 1)) {
                return false;
            }
        }
        calendar.push_back({start, end - 1});
        return true;
    }
};

class MyCalendar3 {
private:
    set<pair<int, int>>  calendar;

public:
    MyCalendar3() {}

    bool book(int start, int end) {
        auto it = calendar.lower_bound({start, end});
        if (it != calendar.end()) {
            if (end > (*it).first) {
                return false;
            }
            if (it != calendar.begin()) {
                --it;
                if (start + 1 <= (*it).second) {
                    return false;
                }
            }
        } else if (!calendar.empty() and calendar.rbegin()->second >= start + 1) {
            return false;
        }
        calendar.insert({start, end});
        return true;
    }
};

class MyCalendar4 {
private:
    set<pair<int, int>>  calendar;

public:
    MyCalendar4() {}

    bool book(int start, int end) {
        // 这个地方
        auto it = calendar.lower_bound({end, 0});
        if (it == calendar.begin() || (--it)->second <= start) {
            calendar.insert({start, end});
            return true;
        }
        return false;
    }
};

// 线段树
class MyCalendar {
private:
    class SegementTree {
    public:
        unordered_set<int> tree, lazy;

        bool query(int start, int end, int idx, int s = 0, int e = 1e9) {
            if (start > e or end < s) {
                return false;
            }
            if (lazy.count(idx)) {
                return true;
            }
            if (start <= s and e <= end) {
                return tree.count(idx);
            }
            int mid = ((e - s) >> 1) + s;
            return query(start, end, idx << 1, s, mid) || query(start, end, (idx << 1) + 1, mid + 1, e);
        }

        void update(int start, int end, int idx, int s = 0, int e = 1e9) {
            if (start > e or end < s) {
                return;
            }
            tree.insert(idx);
            if (start <= s and end >= e) {
                lazy.insert(idx);
                return;
            }
            int mid = ((e - s) >> 1) + s;
            update(start, end, idx << 1, s, mid);
            update(start, end, (idx << 1) + 1, mid + 1, e);
            // 合并
            if (lazy.count(idx << 1) and lazy.count((idx << 1) + 1)) {
                lazy.insert(idx);
            }
        }
    };

    SegementTree tree;
public:
    MyCalendar() {}

    bool book(int start, int end) {
        if (tree.query(start, end - 1, 1)) {
            return false;
        }
        tree.update(start, end - 1, 1);
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyCalendar","book","book","book"][[],[10,20],[15,25],[20,30]]\n
// @lcpr case=end

 */

