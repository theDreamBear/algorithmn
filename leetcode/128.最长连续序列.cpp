/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include<vector>
#include<unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        unordered_set<int> uSet;
        for (int i = 0; i < nums.size(); ++i) {
            uSet.insert(nums[i]);
        }
        int longest = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int now = nums[i];
            if (uSet.find(now) == uSet.end()) {
                continue;
            }
            int len = 1;
            while(true) {
                // left
                int left = now - 1;
                int right = now + 1;
                while (uSet.find(left) != uSet.end()) {
                    uSet.erase(left);
                    --left;
                    ++len;
                }
                // right
                while (uSet.find(right) != uSet.end()) {
                    uSet.erase(right);
                    ++right;
                    ++len;
                }
                if (len > longest) {
                    longest = len;
                }
                break;
            }
        }
        return longest;
    }
};
// @lc code=end

