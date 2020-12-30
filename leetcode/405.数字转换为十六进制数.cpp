/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */
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

using namespace std;

// @lc code=start
char strs[] = "0123456789abcdef";
class Solution {
public:
    string toHex(int num) {
        string ans;
        unsigned int n = num;
        do {
            int x = n & 0b1111;
            n >>= 4;
            ans.push_back(strs[x]);
        } while (n);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end


int main() {
    cout << (-1 )% 16 << endl;
}