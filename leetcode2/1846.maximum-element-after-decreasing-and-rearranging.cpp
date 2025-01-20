/*
 * @lc app=leetcode.cn id=1846 lang=cpp
 * @lcpr version=30204
 *
 * [1846] 减小和重新排列数组后的最大元素
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging1(vector<int>& arr) {
        ranges::sort(arr);
        int pre = 0;
        //int ans = 0;
        for (int i = 0; i < arr.size();) {
            int start = i++;
            while (i < arr.size() and arr[i] == arr[start]) i++;
            int ct = i - start;
            //ans += min(ct, arr[start] - pre);
            pre += min(ct, arr[start] - pre);
        }
        return pre;
    }

    int maximumElementAfterDecrementingAndRearranging2(vector<int>& arr) {
        ranges::sort(arr);
        int pre = 0;
        for (auto v: arr) {
            pre = min(pre + 1, v);
        }
        return pre;
    }

    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n + 1);
        for (auto v: arr) {
            cnt[min(v, n)]++;
        }
        int miss = 0;
        for (int i = 1; i <= n; i++) {
            if (!cnt[i]) miss++;
            else {
                miss -= min(cnt[i] - 1, miss);
            }
        }
        return n - miss;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [100,1,1000]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

