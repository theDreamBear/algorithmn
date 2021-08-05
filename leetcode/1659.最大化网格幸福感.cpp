/*
 * @lc app=leetcode.cn id=1659 lang=cpp
 *
 * [1659] 最大化网格幸福感
 */

// @lc code=start
class Solution {
private:
   int mask_span[729][6];
   int inner_score[729];
   int outer_score[729][729];
   int nx_count[729];
   int wx_count[729];
   int dp[729][6][7][7];

   int max_mask;
   int m, n;

   int cal(int x, int y) {
       if (x == 0 || y == 0) {
           return 0;
       }
       if (x == 1 && y == 1) {
           return -60;
       }
       if (x == 2 && y == 2) {
           return 40;
       }
       return -10;
   }

   void prepare() {
       for (int mask = 0; mask < max_mask; mask++) {
           // 初始化 mask_span;
           for (int temp_mask = mask, i = 0; i < n; ++i) {
               mask_span[mask][i] = temp_mask % 3;
               temp_mask /= 3;
           }
           // 计算内向外向人数
           nx_count[mask] = wx_count[mask] = inner_score[mask] = 0;
           for (int i = 0; i < n; i++) {
               if (mask_span[mask][i] == 0) {
                   continue;
               }
               if (mask_span[mask][i] == 1) {
                   ++nx_count[mask];
                   inner_score[mask] += 120;
               } else {
                   ++wx_count[mask];
                   inner_score[mask] += 40;
               }
               if (i >= 1) {
                   // 行内分数
                   inner_score[mask] += cal(mask_span[mask][i - 1], mask_span[mask][i]);
               }
           }
           // 计算行外分数
       }
       for (int m1 = 0; m1 < max_mask; m1++) {
           for (int m2 = 0; m2 < max_mask; ++m2) {
               outer_score[m2][m1] = 0;
               for (int i = 0; i < 6; i++) {
                   outer_score[m2][m1] += cal(mask_span[m2][i], mask_span[m1][i]);
               }
           }
       }
       memset(dp, -1, sizeof (dp));
   }

public:
    int dfs(int last_mask, int row, int nx, int wx) {
       if (row == m || nx + wx == 0) {
           return 0;
       }
       if (dp[last_mask][row][nx][wx] != -1) {
           return dp[last_mask][row][nx][wx];
       }
       int best = 0;
       for (int mask = 0; mask < max_mask; mask++) {
           if (nx_count[mask] > nx || wx_count[mask] > wx) {
               continue;
           }
           int score = inner_score[mask] + outer_score[mask][last_mask];
           best = max(best, score + dfs(mask, row + 1, nx - nx_count[mask], wx - wx_count[mask]));
       }
       return dp[last_mask][row][nx][wx] = best;
   }

    int getMaxGridHappiness(int m, int n, int nx, int wx) {
        this->m = m;
        this->n = n;
        this->max_mask = pow(3, n);
        prepare();
        return dfs(0, 0, nx, wx);
    }
};
// @lc code=end

