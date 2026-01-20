/*
 * @lc app=leetcode.cn id=378 lang=cpp
 * @lcpr version=30204
 *
 * [378] 有序矩阵中第 K 小的元素
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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 枚举
        // 统计小于等于的个数
        int n = matrix[0].size();
        int low = matrix[0][0], high = matrix.back().back();
        
        auto guess = [&](int mid) {
            int ct = 0;
            for (int i = 0; i < n; i++) {
                int l = 0, h = n - 1;
                while (l + 1 < h) {
                    int m = (l + h) / 2;
                    if (matrix[i][m] <= mid) {
                        l = m;
                    } else h = m;
                }
                if (matrix[i][h] <= mid) {
                    ct += (h + 1);
                } else if (matrix[i][l] <= mid) {
                    ct += (l + 1);
                }
            }
            return ct >= k;
        };
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (guess(mid)) high = mid;
            else low = mid;
        }
        if (guess(low)) return low;
        if (guess(high)) return high;
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,5,9],[10,11,13],[12,13,15]]\n8\n
// @lcpr case=end

// @lcpr case=start
// [[-5]]\n1\n
// @lcpr case=end

 */

