/*
 * @lc app=leetcode.cn id=274 lang=cpp
 * @lcpr version=30114
 *
 * [274] H 指数
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
    bool can(vector<int>& citations, int mid) {
        return count_if(citations.begin(), citations.end(), [&](const int v) {
            return v >= mid;
        }) >= mid;
    }

    int hIndex1(vector<int>& citations) {
        int low = 0, high = 1000;
        while (low + 1 != high) {
            int mid = low + (high - low) / 2;
            if (can(citations, mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (can(citations, high)) {
            return high;
        }
        return low;
    }

    // 暴力解法
    int hIndex2(vector<int>& citations) {
        int max_value = *max_element(citations.begin(), citations.end());
        for (int i = max_value; i > 0; i--) {
            int ct = count_if(citations.begin(), citations.end(), [&](int v) {
                return v >= i;
            });
            if (ct >= i) {
                return i;
            }
        }
        return 0;
    }

    /*
        时间复杂度: O(nlgn)
    */
    int hIndex3(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 0;
        for (int i = citations.size() - 1; i >= 0; ) {
            while (i > 0 && citations[i - 1] == citations[i]) {
                i--;
            }
            if (i >= 0) {
                ans = max(ans, min((int)citations.size() - i, citations[i]));
                i--;
            }
        }
        return ans;
    }

    int hIndex4(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<>{});
        int h = 0;
        while (h < citations.size() and citations[h] > h) {
            ++h;
        }
        return h;
    }

    /*
        计数排序
    */
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> data(n + 1, 0);
        for (auto v : citations) {
            if (v >= n) {
                data[n]++;
            } else {
                data[v]++;
            }
        }
        int ct = 0;
        for (int i = n; i >= 0; i--) {
            ct += data[i];
            if (ct >= i) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,0,6,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1]\n
// @lcpr case=end

 */

