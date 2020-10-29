/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
     string intToRoman(int num) {
        string result;
        while (num > 0) {
            if(num >= 1000) {
                result += "M";
                num -= 1000;
                continue;
            }
            if (num >= 900) {
                result += "CM";
                num -= 900;
                continue;
            }
            if (num >= 500) {
                result += "D";
                num -= 500;
                continue;
            }
            if (num >= 400) {
                result += "CD";
                num -= 400;
                continue;
            }
             if (num >= 100) {
                result += "C";
                num -= 100;
                continue;
            }
            if (num >= 90) {
                result += "XC";
                num -= 90;
                continue;
            }
            if (num >= 50) {
                result += "L";
                num -= 50;
                continue;
            }
            if (num >= 40) {
                result += "XL";
                num -= 40;
                continue;
            }
            if (num >= 10) {
                result += "X";
                num -= 10;
                continue;
            }
            if (num >= 9) {
                result += "IX";
                num -= 9;
                continue;
            }
            if (num == 8) {
                result += "VIII";
                num -= 8;
                continue;
            }
             if (num == 7) {
                result += "VII";
                num -= 7;
                continue;
            }
             if (num == 6) {
                result += "VI";
                num -= 6;
                continue;
            }
             if (num == 5) {
                result += "V";
                num -= 500;
                continue;
            }
             if (num == 4) {
                result += "IV";
                num -= 4;
                continue;
            }
             if (num == 3) {
                result += "III";
                num -= 3;
                continue;
            }
             if (num == 2) {
                result += "II";
                num -= 2;
                continue;
            }
            if (num == 1) {
                result += "I";
                num -= 1;
                continue;
            }
        }
        return result;
    }
};
// @lc code=end

