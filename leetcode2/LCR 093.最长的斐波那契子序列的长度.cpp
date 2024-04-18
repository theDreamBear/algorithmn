/*
 * @lc app=leetcode.cn id=LCR 093 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 093] 最长的斐波那契子序列的长度
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
#include <tuple>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq_brute(vector<int>& arr) {
        int max_len = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int len = 2;
                int prepre = arr[i], pre = arr[j];
                long long next = prepre + pre;
                int k = j + 1;
                while (next < INT_MAX and k < arr.size()) {
                    while (k < arr.size() and arr[k] != next) {
                        k++;
                    }
                    if (k < arr.size()) {
                        prepre = pre;
                        pre = next;
                        next = prepre + pre;
                        ++len;
                        k++;
                    }
                }
                if (len > 2) {
                    max_len = max(max_len, len);
                }
            }
        }
        return max_len;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int max_len = 0;
        return max_len;
        function<int()>
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,7,11,12,14,18]\n
// @lcpr case=end

 */

