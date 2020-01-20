/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 *
 * https://leetcode-cn.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (53.46%)
 * Likes:    201
 * Dislikes: 0
 * Total Accepted:    45.4K
 * Total Submissions: 84.5K
 * Testcase Example:  '[3,0,1]'
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 * 
 * 示例 1:
 * 
 * 输入: [3,0,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [9,6,4,2,3,5,7,0,1]
 * 输出: 8
 * 
 * 
 * 说明:
 * 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 * 
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // trick 戏法
        #ifdef DEBUG
        bitset<10000> bt;
        for (int i = 0; i < nums.size(); ++i) {
            bt[nums[i]] = 1;
        }
        for (int i = 0; i < 10000; ++i) {
            if (bt[i] != 1) {
                return i;
            }
        }
        return 0;
        #endif  //  DEBUG

        #ifdef XX
        // 排序
        /**
         *  1. 边界: 缺少第一个
         *          缺少最后一个
         * 
         * **/
        int x = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size(); ++i) {
            if (x != nums[i]) {
                return x;
            }
            ++x;
        }
        // 缺少最后一个
        return x;
        #endif  // XX

        // #ifdef XOR
        // 异或运算
        int missing = nums.size();
        for (int i = 0; i < nums.size() ; ++i) {
            missing = (missing ^ i ^ nums[i]);
        }
        return missing;
        //  #endif  //  XOR

        #ifdef GAOS
        // 高斯求和
        int ans = (0 + nums.size()) * (nums.size() + 1) / 2;
        for (int i = 0; i < nums.size(); ++i) {
            ans -= nums[i];
        }
        return ans;
        #endif  //  GAOS
    }
};
// @lc code=end

