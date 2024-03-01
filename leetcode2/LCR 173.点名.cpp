/*
 * @lc app=leetcode.cn id=LCR 173 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 173] 点名
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
    int takeAttendance1(vector<int>& records) {
        int n = records.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans ^= records[i];
        }
        for (int i = 0; i < n + 1; i++) {
            ans ^= i;
        }
        return ans;
    }

    int takeAttendance(vector<int>& records) {
        if (records.size() == 1) {
            return 1 - records[0];
        }
        int low = 0, high = records.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (records[mid] == mid) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (records[low] + 1 != records[high]) {
            return records[low] + 1;
        }
        if (records[0] == 0) {
            return records[high] + 1;
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,2,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [0, 1, 2, 3, 4, 5, 6, 8]\n
// @lcpr case=end

 */

