/*
 * @lc app=leetcode.cn id=LCR 071 lang=cpp
 * @lcpr version=30115
 *
 * [LCR 071] 按权重随机选择
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
private:
    vector<int> data;
public:
    Solution(vector<int>& w):data(w.size()) {
        partial_sum(w.begin(), w.end(), data.begin());
    }

    int pickIndex() {
        int upper = data.back();
        int r = random() % upper;
        int idx = upper_bound(data.begin(), data.end(), r) - data.begin();
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end



/*
// @lcpr case=start
// ["Solution"\n[[[1]],[]]\n
// @lcpr case=end

// @lcpr case=start
// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex"\n[[[1,3]],[],[],[],[],[]]\n
// @lcpr case=end

 */

