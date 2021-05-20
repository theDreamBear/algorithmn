/*
 * @lc app=leetcode.cn id=880 lang=cpp
 *
 * [880] 索引处的解码字符串
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
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
        超时
    */
    string decodeAtIndex1(string s, int k) {
        string ans;
        for (auto c : s) {
            if (isalpha(c)) {
                ans.push_back(c);
            } else {
                string temp = ans;
                for (int i = 0; i < c - '0' - 1 && ans.size() < k; ++i) {
                    ans += temp;
                }
            }
            if (ans.size() >= k) {
                break;
            }
        }
        //cout << ans << endl;
        //cout << ans[k - 1] << endl;
        return string(1, ans[k - 1]);
    }

    /*
        逆向工作, 注意越界
    */
    string decodeAtIndex(string s, int k) {
        long long sz = 0;
        int i = 0;
        for(; i < s.size(); i++) {
            if (isalpha(s[i])) {
                ++sz;
            } else {
                sz *= (s[i] - '0');
            }
            if (sz >= k) {
                break;
            }
        }
        for (; i >= 0; --i) {
            k %= sz;
            if (k == 0 && isalpha(s[i])) {
                return string("") + s[i];
            }
            if (isalpha(s[i])) {
                --sz;
            } else {
                sz /= (s[i] - '0');
            }
        }
        return "";
    }

};
// @lc code=end

int main() {
    string s = "ha22";
    int k = 10;
    cout << Solution{}.decodeAtIndex(s, 5);
}