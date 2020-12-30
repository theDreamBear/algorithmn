/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 *
 * https://leetcode-cn.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (50.73%)
 * Likes:    102
 * Dislikes: 0
 * Total Accepted:    9.5K
 * Total Submissions: 18.6K
 * Testcase Example:  '0'
 *
 * 二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。
 *
 * 每个 LED 代表一个 0 或 1，最低位在右侧。
 *
 *
 *
 * 例如，上面的二进制手表读取 “3:25”。
 *
 * 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。
 *
 * 案例:
 *
 *
 * 输入: n = 1
 * 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16",
 * "0:32"]
 *
 *
 *
 * 注意事项:
 *
 *
 * 输出的顺序没有要求。
 * 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
 * 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
 *
 *
 */
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;  // NOLINT

// @lc code=start
string zero = "0";
class Solution {
public:
    void  getValue(vector<string>& ans, int value, int pos, int bitwidth, int numOfOne, int MAX, bool fill = false) {
        if (numOfOne == 0) {
            if (value <= MAX) {
                string temp = to_string(value);
                if (value < 10 && fill) {
                    temp = zero + temp;
                }
                ans.push_back(temp);
            }
            return;
        }
        for (int i = pos; i < bitwidth; ++i) {
            value += (0x1 << i);
            getValue(ans, value, i + 1, bitwidth, numOfOne - 1, MAX, fill);
            value -= (0x1 << i);
        }
    }

    vector<string> readBinaryWatch_recursion(int num) {
        vector<string> ans;
        for (int i = 0; i <= num; ++i) {
            int j = num - i;
            vector<string> hour;
            vector<string> minute;
            getValue(hour,0, 0, 4, i, 11);
            getValue(minute, 0, 0 , 6, j, 59, true);
            for (auto& h : hour) {
                for (auto& m : minute) {
                    string temp = h + ":" + m;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }

    int valueOneCount(int val) {
        int res = 0;
        while (val) {
            val &= (val - 1);
            ++res;
        }
        return res;
    }

    /*
        有限状态, 枚举
    */
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (valueOneCount(i) + valueOneCount(j) == num) {
                    string h = to_string(i);
                    string m = to_string(j);
                    if (j < 10) {
                        m = "0" + m;
                    }
                    ans.push_back(h + ":" + m);
                }
            }
        }
        return ans;
    }

};
// @lc code=end

int main() {
    auto t = Solution{}.readBinaryWatch(2);
    for (auto& x : t) {
        cout << x << endl;
    }
}

