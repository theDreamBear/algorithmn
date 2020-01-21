/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (67.39%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    47.3K
 * Total Submissions: 69.9K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 
 * 说明:
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
/**
 *  STL 函数
 * 
 * 
 * **/
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.size() == 0 || nums2.size() == 0) {
            return ans;
        }
        unordered_set<int> set;
        for (int i = 0; i < nums1.size(); ++i) {
            set.insert(nums1[i]);
        }
        sort(nums2.begin(), nums2.end());
        auto pos = unique(nums2.begin(), nums2.end());
        #ifdef F1
        nums2.erase(pos, nums2.end());
        for (int i = 0; i < nums2.size(); i++) {
            if (set.find(nums2[i]) != set.end()) {
                ans.push_back(nums2[i]);
            }
        }
        return ans;
        #endif  //  F!

        // 方法2
        for (auto ite = nums2.begin(); ite != pos; ++ite) {
            if (set.find(*ite) != set.end()) {
                ans.push_back(*ite);
            }
        }
        return ans;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.size() == 0 || nums2.size() == 0) {
            return ans;
        }
        unordered_set<int> s1, s2;
        for (auto& x : nums1) {
            s1.insert(x);
        }
        for (auto& x : nums2) {
            s2.insert(x);
        }
        for (auto x : s1) {
            if (s2.find(x) != s2.end()) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
// @lc code=end

