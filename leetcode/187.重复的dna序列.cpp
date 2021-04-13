/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
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
    vector<string> findRepeatedDnaSequences1(string s) {
        unordered_map<string, int> hash;
        for (int i = 0; i + 9 < s.size(); ++i) {
            string temp = s.substr(i, 10);
            ++hash[temp];
        }
        vector<string> ans;
        for (auto& kv : hash) {
            if (kv.second > 1) {
                ans.push_back(kv.first);
            }
        }
        return ans;
    }

    int string_hash(const string& s, int* pri) {
        int mod = 1e9 + 7;
        int hash = 0;
        for (auto c : s) {
            // 26 容易越界
            //hash = 26 * hash + (c - 'A');
            // 优化为 4 进制 A0, T1 C2 G3
            hash = 4 * hash + pri[c - 'A'];
            hash %= mod;
        }
        return hash;
    }

    vector<string> findRepeatedDnaSequences2(string s) {
        unordered_map<int, int> hash;
        vector<string> ans;
        int pri[26];
        pri[0] = 0;
        pri['T' - 'A'] = 1;
        pri['C' - 'A'] = 2;
        pri['G' - 'A'] = 3;
        for (int i = 0; i + 9 < s.size(); ++i) {
            string temp = s.substr(i, 10);
            int hash_code = string_hash(temp, pri);
            if (++hash[hash_code] == 2) {
                ans.emplace_back(temp);
            }
        }
        return ans;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> seen;
        vector<string> ans;
        int mask = 0;
        int pri[26];
        pri[0] = 0;
        pri['T' - 'A'] = 1;
        pri['C' - 'A'] = 2;
        pri['G' - 'A'] = 3;
        // mask 没两位记录一个字符
        for (int i = 0; i + 9 < s.size(); ++i) {
            if (i != 0) {
                mask <<= 2;
                // 删除 21, 22 位
                mask &= (~(3 << 20));
                // 添加末尾
                mask |= (pri[s[i + 9] - 'A']);
            } else {
                for (int j = 0; j < 10; ++j) {
                    mask <<= 2;
                    mask |= (pri[s[j] - 'A']);
                }
            }
            if (++seen[mask] == 2) {
                ans.emplace_back(s.substr(i, 10));
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution{}.findRepeatedDnaSequences(s);
}