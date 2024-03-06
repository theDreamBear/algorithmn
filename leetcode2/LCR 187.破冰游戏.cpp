/*
 * @lc app=leetcode.cn id=LCR 187 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 187] 破冰游戏
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
    // 一般逻辑， 超时
    int iceBreakingGame_arr(int num, int target) {
        if (num == 1) {
            return 0;
        }
        //target %= num;
        vector<int> data(num);
        iota(data.begin(), data.end(), 0);
        int left = num;
        int i = -1, ct = 0;
        while (left >= 1) {
            i = (i + 1) % num;
            if (data[i] == -1) {
                continue;
            }
            if (left == 1) {
                break;
            }
            if (++ct == target) {
                data[i] = -1;
                --left;
                ct = 0;
            }
        }
        return data[i];
    }

    // 队列来加速， 这样不用判断每个数是否已经被移除， 还是超时
    // 10^5 * 10^5
    int iceBreakingGame_queue(int num, int target) {
        if (num == 1) {
            return 0;
        }
        queue<int> q;
        for (int i = 0; i < num; i++) {
            q.push(i);
        }
        int left = num;
        int ct = 0;
        while (left > 1) {
            int v = q.front();
            q.pop();
            if (++ct == target) {
                --left;
                ct = 0;
                continue;
            }
            q.push(v);
        }
        return q.front();
    }

    /*
        提示：
        1 <= num <= 10^5
        1 <= target <= 10^6

    */
    int iceBreakingGame(int num, int target) {
        if (num == 1) {
            return 0;
        }

    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n4\n
// @lcpr case=end

// @lcpr case=start
// 12\n5\n
// @lcpr case=end

 */

