/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
 public:
    int reachNumber_bfs(int target) {
        queue<long long> q;
        q.push(0);
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                long long pos = q.front();
                q.pop();
                // 正
                long long des = pos + ans;
                if (des == target) {
                    return ans;
                }
                q.push(des);
                // 负
                des = pos - ans;
                if (des == target) {
                    return ans;
                }
                q.push(des);
            }
        }
        return -1;
    }

   int reachNumber_bad(int target) {
        int ans = 0;
        int cur = 0;
        if (target < 0) {
            target = -target;
        }
        while (cur != target) {
            ++ans;
            if (cur + ans <= target) {
                cur += ans;
            } else {
                ans += (2 * abs(target - cur)) - 1;
                cur = target;
            }
        }
        return ans;
    }

    int reachNumber(int target) {
        target = abs(target);
        int pos = 0;
        int step = 0;
        while (pos < target) {
            pos += ++step;
        } 
        if (pos == target) {
            return step;
        }
        if ((pos - target) % 2 == 0) {
            return step;
        }
        if (step % 2 == 0) {
            return step + 1;
        }
        return step + 2;
    }

};
// @lc code=end

