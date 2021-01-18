/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
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
class Solution {
public:
    bool checkRecord(string s) {
         int ct_absent = 0;
         int ct_late = 0;
         for (auto c : s) {
            if (c == 'A') {
                ct_late = 0;
                if (++ct_absent > 1) {
                    return false;
                }
             } else if (c == 'P') {
                 ct_late = 0;
             } else if ((++ct_late)> 2) {
                 return false;
             }
         }
         return true;
    }
};
// @lc code=end

int main() {
    cout << Solution{}.checkRecord("PPALLP") << endl;
}