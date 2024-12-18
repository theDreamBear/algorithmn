/*
 * @lc app=leetcode.cn id=1713 lang=cpp
 * @lcpr version=30204
 *
 * [1713] 得到子序列的最少操作次数
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

// 我擦
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        // target 最长递增子序列
        unordered_map<int, int> index;
        vector<int> seq;
        for (int i = 0; i < target.size(); i++) {
            index[target[i]] = i;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (index.contains(arr[i])) {
                seq.push_back(index[arr[i]]);
            }
        }
        vector<int> pp;
        for (int i = 0; i < seq.size(); i++) {
            auto it = ranges::lower_bound(pp, seq[i]);
            if (it == pp.end()) {
                pp.push_back(seq[i]);
            } else {
                *it = seq[i];
            }
        }
        return target.size() - pp.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,1,3]\n[9,4,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [6,4,8,1,3,2]\n[4,7,6,2,3,8,6,1]\n
// @lcpr case=end

 */

