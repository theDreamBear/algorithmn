/*
 * @lc app=leetcode.cn id=365 lang=cpp
 * @lcpr version=30114
 *
 * [365] 水壶问题
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
#include <numeric>
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
class Solution {
  public:
    /*
        这到底怎么想的
    */
    bool canMeasureWater_傻乎乎的错误解法(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }
        if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity || jug1Capacity + jug2Capacity == targetCapacity) {
            return true;
        }
        if (jug1Capacity > jug2Capacity) {
            swap(jug1Capacity, jug2Capacity);
        }
        int times = lcm(jug1Capacity, jug2Capacity) / jug1Capacity;
        int l = 0, r = 0;
        for (int i = 0; i < 2 * times; i++) {
            l += jug1Capacity;
            int rcv = jug2Capacity - r;
            if (rcv >= l) {
                r += l;
                l = 0;
                if (l + r == targetCapacity) {
                    return true;
                }
            } else {
                l -= rcv;
                r += rcv;
                if (l + r == targetCapacity) {
                    return true;
                }
                r = l;
                l = 0;
                if (r == targetCapacity) {
                    return true;
                }
            }
        }
        return false;
    }

    bool canMeasureWater2(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int L = jug1Capacity;
        int R = jug2Capacity;
        int T = targetCapacity;
        if (L + R < T) {
            return false;
        }
        if (L + R == T || L == T || R == T) {
            return true;
        }
        // 理论上应该是一个搜索
        set<int> visited;
        int      l, r = l = 0;
        if (L < R) {
            swap(L, R);
        }
        while (!visited.count(r)) {
            visited.insert(r);
            // 大杯倒满
            l = L;
            // 小杯剩余
            int rcv = R - r;

            // 小杯满
            l -= rcv;
            r = R;
            // 大杯单独 或者 大杯 + 小杯容量等于T
            if (l == T || l + r == T) {
                return true;
            }
            // 大杯逐渐往小杯倒入
            while (l >= R) {
                // 大杯剩余
                l -= R;
                // 大杯剩余 或者 大杯 + 小杯和等于T
                if (l == T || l + r == T) {
                    return true;
                }
            }
            // 大杯剩余倒入小杯， 进入下一个循环
            r = l;
            l = 0;
        }
        return false;
    }

    /*
        数学
    */
    bool canMeasureWater_math(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x = gcd(jug1Capacity, jug2Capacity);
        if (targetCapacity % x != 0 || jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }
        return true;
    }

    using PII = pair<int, int>;
    bool canMeasureWaterHelper(int x, int y, int z) {
        stack<PII> stk;
        stk.emplace(0, 0);
        auto                                        hash_function = [](const PII& o) { return hash<int>()(o.first) ^ hash<int>()(o.second); };
        unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
        while (!stk.empty()) {
            if (seen.count(stk.top())) {
                stk.pop();
                continue;
            }
            seen.emplace(stk.top());

            auto [remain_x, remain_y] = stk.top();
            stk.pop();
            if (remain_x == z || remain_y == z || remain_x + remain_y == z) {
                return true;
            }
            // 把 X 壶灌满。
            stk.emplace(x, remain_y);
            // 把 Y 壶灌满。
            stk.emplace(remain_x, y);
            // 把 X 壶倒空。
            stk.emplace(0, remain_y);
            // 把 Y 壶倒空。
            stk.emplace(remain_x, 0);
            // 把 X 壶的水灌进 Y 壶，直至灌满或倒空。
            stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
            // 把 Y 壶的水灌进 X 壶，直至灌满或倒空。
            stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
        }
        return false;
    }

    bool canMeasureWater3(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        return canMeasureWaterHelper(jug1Capacity, jug2Capacity, targetCapacity);
    }

    // bfs ok
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        unordered_set<pair<int, int>, HashType> seen;
        queue<pair<int, int>>                   q;
        q.push({0, 0});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == targetCapacity || y == targetCapacity || x + y == targetCapacity) {
                return true;
            }

            // 将当前状态标记为已访问
            if (seen.count({x, y}))
                continue;
            seen.insert({x, y});

            // 倒满
            q.push({jug1Capacity, y});
            q.push({x, jug2Capacity});

            // 倒空
            q.push({0, y});
            q.push({x, 0});

            // 从一个水壶向另一个水壶倒水
            int pourAtoB = min(x, jug2Capacity - y);
            int pourBtoA = min(y, jug1Capacity - x);

            q.push({x - pourAtoB, y + pourAtoB});
            q.push({x + pourBtoA, y - pourBtoA});
        }

        return false;
    }

    // 修正后的哈希函数，确保pair的两个元素都被考虑
    struct HashType {
        size_t operator()(const pair<int, int>& pr) const {
            // 使用位操作来混合两个哈希值，以减少哈希冲突
            return hash<int>{}(pr.first) ^ (hash<int>{}(pr.second) << 1);
        }
    };

    // 深度优先搜索函数，尝试通过递归寻找解决方案
    bool dfs(unordered_set<pair<int, int>, HashType>& seen, int x, int y, int L, int R, int T) {
        // 如果这个状态已经被访问过，就跳过
        if (seen.count({x, y})) {
            return false;
        }
        seen.insert({x, y});

        // 检查是否达到目标
        if (x == T || y == T || x + y == T) {
            return true;
        }

        // 尝试所有可能的操作
        if (dfs(seen, L, y, L, R, T) || dfs(seen, x, R, L, R, T) || dfs(seen, 0, y, L, R, T) || dfs(seen, x, 0, L, R, T)) {
            return true;
        }

        // 从一个水壶向另一个水壶倒水
        int pourAtoB = min(x, R - y);
        int pourBtoA = min(y, L - x);
        if (dfs(seen, x - pourAtoB, y + pourAtoB, L, R, T) || dfs(seen, x + pourBtoA, y - pourBtoA, L, R, T)) {
            return true;
        }
        return false;
    }

    bool canMeasureWater4(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        /*
            状态枚举
            1、 A倒满, B不变
            2、 A倒空， B不变
            3、 A不变， B倒满
            4、 A 倒满， B倒空
            5、 A 往 B   倒
            6、 B 往 A   倒
        */
        unordered_set<pair<int, int>, HashType> seen;
        return dfs(seen, 0, 0, jug1Capacity, jug2Capacity, targetCapacity);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n5\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n3\n
// @lcpr case=end

 */
