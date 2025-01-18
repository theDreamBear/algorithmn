/*
 * @lc app=leetcode.cn id=1481 lang=cpp
 * @lcpr version=30204
 *
 * [1481] 不同整数的最少数目
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
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (auto v: arr) cnt[v]++;
        vector<int> freq;
        for (auto& [_, t]: cnt) {
            freq.emplace_back(t);
        }
        ranges::sort(freq);
        int i = 0;
        for (; i < freq.size(); i++) {
            if (freq[i] <= k) {
                k -= freq[i];
            } else {
                break;
            }
        }
        return freq.size() - i;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,5,4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [4,3,1,1,3,3,2]\n3\n
// @lcpr case=end

 */

