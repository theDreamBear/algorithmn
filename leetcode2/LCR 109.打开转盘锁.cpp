/*
 * @lc app=leetcode.cn id=LCR 109 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 109] 打开转盘锁
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
class Solution {
public:
    int openLock1(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }
        unordered_set<string> visited(deadends.begin(), deadends.end());
        // 本身已经锁定了
        if (visited.count("0000")) {
            return -1;
        }
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int ct = 0;
        while (!q.empty()) {
            ct++;
            int sz = q.size();
            while (sz-- > 0) {
                auto node = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    string tmp = node;
                    tmp[i] = (tmp[i] - '0' + 1) % 10 + '0';
                    if (!visited.count(tmp)) {
                        if (tmp == target) {
                            return ct;
                        }
                        q.push(tmp);
                        visited.insert(tmp);
                    }
                    tmp[i] = node[i];
                    tmp[i] = (tmp[i] - '0' + 9) % 10 + '0';
                    if (!visited.count(tmp)) {
                        if (tmp == target) {
                            return ct;
                        }
                        q.push(tmp);
                        visited.insert(tmp);
                    }
                }
            }
        }
        return -1;
    }

    string roll(string& str, int i, int step) {
        string tmp = str;
        tmp[i] = (tmp[i] - '0' + step + 10) % 10  + '0';
        return tmp;
    }

    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }
        unordered_set<string> dead(deadends.begin(), deadends.end());
        // 本身已经锁定了
        if (dead.count("0000")) {
            return -1;
        }
        queue<string> lq, rq;
        lq.push("0000");
        rq.push(target);

        unordered_set<string> lv, rv;
        lv.insert("0000");
        rv.insert(target);

        int lt = 0, rt = 0;
        while (!lq.empty() and !rq.empty()) {
            ++lt;
            int sz = lq.size();
            while (sz-- > 0) {
                auto node = lq.front(); lq.pop();
                for (int i = 0; i < 4; i++) {
                    auto next = roll(node, i, 1);
                    if (!dead.count(next) and !lv.count(next)) {
                        if (rv.count(next)) {
                            return lt + rt;
                        }
                        lq.push(next);
                        lv.insert(next);
                    }
                    auto pre = roll(node, i , -1);
                    if (!dead.count(pre) and !lv.count(pre)) {
                        if (rv.count(pre)) {
                            return lt + rt;
                        }
                        lq.push(pre);
                        lv.insert(pre);
                    }
                }
            }
            ++rt;
            sz = rq.size();
            while (sz-- > 0) {
                auto node = rq.front(); rq.pop();
                for (int i = 0; i < 4; i++) {
                    auto next = roll(node, i, 1);
                    if (!dead.count(next) and !rv.count(next)) {
                        if (lv.count(next)) {
                            return lt + rt;
                        }
                        rq.push(next);
                        rv.insert(next);
                    }
                    auto pre = roll(node, i , -1);
                    if (!dead.count(pre) and !rv.count(pre)) {
                        if (lv.count(pre)) {
                            return lt + rt;
                        }
                        rq.push(pre);
                        rv.insert(pre);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["0201","0101","0102","1212","2002"]\n"0202"\n
// @lcpr case=end

// @lcpr case=start
// ["8888"]\n"0009"\n
// @lcpr case=end

// @lcpr case=start
// ["8887","8889","8878","8898","8788","8988","7888","9888"]\n"8888"\n
// @lcpr case=end

// @lcpr case=start
// ["0000"]\n"8888"\n
// @lcpr case=end

 */

