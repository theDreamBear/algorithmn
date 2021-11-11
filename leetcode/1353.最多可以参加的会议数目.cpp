/*
 * @lc app=leetcode.cn id=1353 lang=cpp
 *
 * [1353] 最多可以参加的会议数目
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
    struct CMP {
        bool operator()(const pair<int, int> &left, const pair<int, int> &right) {
            if (left.first != right.first) {
                return left.first > right.first;
            }
            return left.second > right.second;
        }
    };

    int maxEvents2(vector<vector<int>> &events) {
        // cmp 是后面和前面的交换条件
        using pInt = pair<int, int>;
        priority_queue<pInt, vector<pInt>, CMP> small;
        for (auto &vec : events) {
            small.push(make_pair(vec[0], vec[1]));
        }
        int now = -1;
        int ans = 0;
        while (!small.empty()) {
            int l = now;
            while (!small.empty() && small.top().first <= now) {
                auto node = small.top();
                small.pop();
                node.first = l + 1;
                if (node.first <= node.second) {
                    small.push(node);
                    ++l;
                }
            }
            if (!small.empty()) {
                auto p = small.top();
                small.pop();
                if (p.second <= now) {
                    continue;
                }
                if (now < p.first) {
                    now = p.first;
                    ++ans;
                    continue;
                }
            }
        }
        return ans;
    }

    int maxEvents(vector<vector<int>> &events) {
        // cmp 是后面和前面的交换条件
        priority_queue<int, vector<int>, greater<>> small;
        unordered_map<int, vector<int>> hash;
        int max_day = 0;
        for (auto& vec : events) {
            hash[vec[0]].push_back(vec[1]);
            max_day = max(max_day, vec[1]);
        }
        int now = -1;
        int ans = 0;
        for (int cur = 0; cur <= max_day; cur++) {
            if (hash.count(cur) != 0) {
                // 当前天
                auto &data = hash[cur];
                for (auto v : data) {
                    if (v > now) {
                        small.push(v);
                    }
                }
            }
            while(!small.empty() && small.top() <= now) {
                small.pop();
            }
            if (!small.empty()) {
                now = cur;
                small.pop();
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

