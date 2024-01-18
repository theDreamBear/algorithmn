/*
 * @lc app=leetcode.cn id=2171 lang=cpp
 * @lcpr version=30113
 *
 * [2171] 拿出最少数目的魔法豆
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
     long long minimumRemoval1(vector<int>& beans) {
        if (beans.size() == 1) {
            return 0;
        }
        sort(beans.begin(), beans.end());
        vector<long long> pre(beans.size() + 1, 0);
        for (int i = 0; i < beans.size(); i++) {
            pre[i + 1] = pre[i] + beans[i];
        }
        long long ans = beans.size() * beans.back();
        for (int i = 0; i < beans.size(); i++) {
            if (i > 0 && beans[i] == beans[i - 1]) {
                continue;
            }
            long long now = pre[i] + (pre.back() - pre[i]) - beans[i] * (beans.size() - i);
            if (now < ans) {
                ans = now;
            }
        }
        return ans;
    }

    long long minimumRemoval2(vector<int>& beans) {
        if (beans.size() == 1) {
            return 0;
        }
        sort(beans.begin(), beans.end());
        vector<long long> pre(beans.begin(), beans.end());
        for (int i = 1; i < pre.size(); i++) {
            pre[i] += pre[i - 1];
        }
        long long ans = pre.back() - pre[0] * pre.size();
        for (int i = 1; i < pre.size(); i++) {
            // 去掉重复的
            if (pre[i] == pre[i - 1]) {
                continue;
            }
            long long now = pre[i - 1] + (pre.back() - pre[i]) - (pre[i] - pre[i - 1]) * (pre.size() - i - 1);
            if (now < ans) {
                ans = now;
            }
        }
        return ans;
    }

    long long minimumRemoval(vector<int>& beans) {
        if (beans.size() == 1) {
            return 0;
        }
        sort(beans.begin(), beans.end());
        long long total = accumulate(beans.begin(), beans.end(), 0LL);
        long long ans = total - beans[0] * beans.size();
        for (int i = 1; i < beans.size(); i++) {
            if (beans[i] == beans[i - 1]) {
                continue;
            }
            long long now = total - beans[i] * (beans.size() - i);
            if (now < ans) {
                ans = now;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,6,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,10,3,2]\n
// @lcpr case=end

 */

