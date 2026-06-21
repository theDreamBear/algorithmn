/*
 * @lc app=leetcode.cn id=349 lang=cpp
 * @lcpr version=30204
 *
 * [349] 两个数组的交集
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
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        ranges::sort(nums1), ranges::sort(nums2);
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        for (int i = 0, j = 0; i < nums1.size() or j < nums2.size(); ) {
            if (i < nums1.size() and j < nums2.size()) {
                if (nums1[i] < nums2[j]) {
                    i++;
                } else {
                    if (nums1[i] > nums2[j]) {
                        j++;
                    } else {
                        ans.push_back(nums1[i]);
                        i++,j++;
                    }
                }
                continue;
            }
            break;
        }
        return ans;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> ans;
        vector<int>* x = &nums1, *y = &nums2;
        if (x->size() > y->size()) {
            x = &nums2;
            y = &nums1;
        }
        ranges::sort(*y);
        for (auto v: *x) {
            auto it = lower_bound(y->begin(), y->end(), v);
            if (it != y->end() and *it == v) ans.insert(v);
        }
        return {ans.begin(), ans.end()};
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

