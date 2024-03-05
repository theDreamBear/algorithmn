/*
 * @lc app=leetcode.cn id=LCR 186 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 186] 文物朝代判断
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
    bool checkDynasty(vector<int>& places) {
        sort(places.begin(), places.end());
        int i = 0;
        while (i < 5 && places[i] == 0) {
            i++;
        }
        if (i == 5) {
            return true;
        }
        int wn = i;
        int pre = places[i];
        for (int j = i + 1; j < 5; j++) {
            if (places[j] == pre + 1) {
                pre = places[j];
                continue;
            }
            if (places[j] == pre) {
                return false;
            }
            if (places[j] - pre != 1) {
                if (places[j] - pre - 1 > wn) {
                    return false;
                }
                wn -= places[j] - pre;
            }
            pre = places[j] ;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0, 6, 9, 0, 7]\n
// @lcpr case=end

// @lcpr case=start
// [7, 8, 9, 10, 11]\n
// @lcpr case=end

 */

