/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.16%)
 * Likes:    390
 * Dislikes: 0
 * Total Accepted:    102.3K
 * Total Submissions: 242.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */
#include<vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res = digits;
        /*
        *  for (size_t i =  digits.size() - 1; i >= 0; i--) 会出现无线循环
        **/
        for (int i =  digits.size() - 1; i >= 0; i--)
        {
            res[i]++;
            if (res[i] <= 9) {
                break;
            } else {
                res[i] = 0;
            }
        }
        if (res[0] == 0) {
            res.insert(res.begin(), 1);
        }
        return res;
    }
};
// @lc code=end

