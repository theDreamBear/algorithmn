/*
 * @lc app=leetcode.cn id=350 lang=cpp
 * @lcpr version=30204
 *
 * [350] 两个数组的交集 II
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int, int> cnt1, cnt2;
        for (auto& v: nums1) {
            cnt1[v]++;
        }
        for (auto& v: nums2) {
            if (cnt1.contains(v) and cnt1[v] > 0) {
                ans.push_back(v);
                cnt1[v]--;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */

