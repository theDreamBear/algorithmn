/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 * @lcpr version=30204
 *
 * [1734] 解码异或后的排列
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
    vector<int> decode(vector<int>& encoded) {
        int x = 0;
        int s1 = 0;
        for (auto v: encoded) {
            x ^= v;
            s1 ^= x;
        }
        int n = encoded.size() + 1;
        int left = (n + 1) % 4;
        int start = n / 4 * 4;
        for (int i = 0; i < left; i++) {
            s1 ^= (start + i);
        }
        vector<int> res{s1};
        for (auto v: encoded) {
            res.push_back(v ^ res.back());
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,6]\n
// @lcpr case=end

 */

