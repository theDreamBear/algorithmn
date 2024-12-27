// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=403 lang=cpp
 * @lcpr version=30204
 *
 * [403] 青蛙过河
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
    bool canCross_dfs(vector<int>& stones) {
        unordered_map<int, int> pos;
        for (int i = 0; i < stones.size(); i++) {
            pos[stones[i]] = i;
        }
        int n = stones.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1, -1));
        auto dfs = [&](auto&& dfs, int i, int k) {
            if (i == n - 1) return 1;
            auto& ans = f[i][k];
            if (ans != -1) return ans;
            ans = 0;
            for (int c = k - 1; c <= k + 1; c++) {
                if (c > 0 and pos.contains(stones[i] + c)) {
                    ans |= dfs(dfs, pos[stones[i] + c], c);
                }
            }
            return ans;
        };
        return dfs(dfs, 0, 0);                                                                                                                                                                                                            
    }

    bool canCross1(vector<int>& stones) {
        unordered_map<int, int> pos;
        for (int i = 0; i < stones.size(); i++) {
            pos[stones[i]] = i;
        }
        int n = stones.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
        f[0][0] = 1;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (f[i][j]) {
                    for (int c = j - 1; c <= j+1; c++) {
                        if (c > 0 and pos.contains(stones[i] + c)) {
                            f[pos[stones[i] + c]][c] = 1;
                        }
                    }
                }
            }
        }
        return ranges::count(f[n - 1], 1) > 0;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int, int> pos;
        for (int i = 0; i < stones.size(); i++) {
            pos[stones[i]] = i;
        }
        int n = stones.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int dis = stones[i] - stones[j];
                if (dis > j + 1) break;
                f[i][dis] = f[j][dis - 1] || f[j][dis] || f[j][dis + 1];
                if (i == n - 1 and f[i][dis]) return true;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,3,5,6,8,12,17]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,3,4,8,9,11]\n
// @lcpr case=end

 */

