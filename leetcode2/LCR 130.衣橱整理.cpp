/*
 * @lc app=leetcode.cn id=LCR 130 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 130] 衣橱整理
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
    void dfs(int x, int y, vector<vector<bool>>& visited, int& ans, const vector<int>& cache, int cnt) {
        if (x < 0 || y < 0 || x >= visited.size() || y >= visited[x].size() || visited[x][y] ||cache[x] +cache[y] > cnt) {
            return;
        }
        visited[x][y] = true;
        ++ans;
        dfs(x + 1, y, visited, ans, cache, cnt);
        dfs(x, y + 1, visited, ans, cache, cnt);

    }

    int wardrobeFinishing(int m, int n, int cnt) {
        int max_val = max(m, n);
        vector<int> cache(max_val);
        for (int i = 0; i < max_val; i++) {
            int sum = 0;
            int v = i;
            while (v > 0) {
                sum += v % 10;
                v /= 10;
            }
            cache[i] = sum;
        }
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        dfs(0, 0, visited, ans, cache, cnt);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n7\n5\n
// @lcpr case=end

 */

