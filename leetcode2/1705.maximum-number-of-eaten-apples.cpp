/*
 * @lc app=leetcode.cn id=1705 lang=cpp
 * @lcpr version=30204
 *
 * [1705] 吃苹果的最大数目
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
using pii = pair<int, int>;
class Solution {
public:
    int eatenApples1(vector<int>& apples, vector<int>& days) {
        // 按照过期时间吃
        struct Cmp {
            bool operator() (const pii& lhs, const pii& rhs) {
                return lhs.second > rhs.second;
            }
        };
        priority_queue<pii, vector<pii>, Cmp> pq;
        // t 时间轴
        int t = 0;
        // i下一个队列的下标
        int i = 0;
        // eat当前吃过的苹果数量
        int eat = 0;
        while (i < apples.size() or !pq.empty()) {
            if (t == i and i < apples.size()) {
                if (apples[i] > 0) {
                    pq.push({apples[i], i + days[i]});
                }
                i++;
            }
            // 当前没有吃的了
            if (pq.empty()) {
                t++;
                continue;
            }
            auto [cnt, d] = pq.top();
            pq.pop();
            if (t >= d) {
                continue;
            }
            // 最后一个了
            if (i == apples.size() and pq.empty()) {
                eat +=  min(cnt, d - t);
                t += min(cnt, d - t);
                break;
            }
            // 吃一个
            eat++;
            t++;
            if (--cnt) {
                pq.push({cnt, d});
            }
        }
        return eat;
    }

    int eatenApples(vector<int>& apples, vector<int>& days) {
        // 按照过期时间吃
        struct Cmp {
            bool operator() (const pii& lhs, const pii& rhs) {
                return lhs.second > rhs.second;
            }
        };
        priority_queue<pii, vector<pii>, Cmp> pq;
        int ans = 0, i = 0;
        for (; i < apples.size(); i++) {
            while (!pq.empty() and pq.top().second == i) {
                pq.pop();
            }
            if (apples[i]) {
                pq.emplace(apples[i], i + days[i]);
            }
            if (!pq.empty()) {
                ans++;
                auto [cnt, d] = pq.top();
                pq.pop();
                if (--cnt) {
                    pq.emplace(cnt, d);
                }
            }
        }
        while (!pq.empty()) {
            while (!pq.empty() and pq.top().second <= i) {
                pq.pop();
            }
            if (pq.empty()) {
                break;
            }
            auto [cnt, d] = pq.top();
            pq.pop();
            int k = min(cnt, d - i);
            ans += k;
            i += k;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,5,2]\n[3,2,1,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,0,0,0,0,2]\n[3,0,0,0,0,2]\n
// @lcpr case=end

 */

