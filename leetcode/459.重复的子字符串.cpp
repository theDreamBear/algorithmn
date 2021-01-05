/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
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
    void rotate(string& s) {
        char temp = s[s.size() - 1];
        for (int i = s.size() - 2; i >= 0; --i) {
            s[i+ 1] = s[i];
        }
        s[0] = temp;
    }

    string rotate(string& s, int step) {
        string temp = s;
        for (int i = 0, j = step - 1; i < j; ++i, --j) {
            swap(temp[i], temp[j]);
        }
        for (int i = step, j = s.size() - 1; i < j; ++i, --j) {
            swap(temp[i], temp[j]);
        }
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            swap(temp[i], temp[j]);
        }
        return temp;
    }

    /*
        超时
    */
    bool repeatedSubstringPattern_timeout(string s) {
        string source = s;
        for (int i = 1; i < s.size(); ++i) {
            rotate(s);
            if (s == source) {
                return true;
            }
        }
        return false;
    }

    /*
        取所有的公约数
    */
    vector<int> getAll(int n) {
        vector<int> ans;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                ans.push_back(i);
                if (i != n / i &&  i != 1) {
                    ans.push_back(n / i);
                }
            }
        }
        return ans;
    }

    /*
    取公约数, 枚举公约数长度
    */
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1) {
            return false;
        }
        vector<int> divisors = getAll(s.size());
        for (auto x : divisors) {
            if (rotate(s, x) == s) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    string s = "aba";
    cout << Solution{}.repeatedSubstringPattern(s) << endl;
}

