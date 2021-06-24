/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
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
    int longestSubstring1(string s, int k) {
        int ans = 0;
        for (int start = 0; start < (int) s.size(); ++start) {
            vector<int> ah(26);
            int char_ct = 0;
            int satisfy_ct = 0;
            for (int j = start; j < (int) s.size(); ++j) {
                int cIndex = s[j] - 'a';
                if (++ah[cIndex] == 1) {
                    ++char_ct;
                }
                if (ah[cIndex] == k) {
                    ++satisfy_ct;
                }
                if (char_ct == satisfy_ct) {
                    ans = max(ans, j - start + 1);
                }
            }
        }
        return ans;
    }

    int dfs(const string &s, int low, int high, int k) {
        if (low > high || high - low + 1 < k) {
            return 0;
        }
        vector<int> cnt(26);
        for (int i = low; i <= high; ++i) {
            ++cnt[s[i] - 'a'];
        }
        unordered_set<char> split_set;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split_set.insert(i + 'a');
            }
        }
        if (split_set.empty()) {
            return high - low + 1;
        }
        int ans = 0;
        int l = low;
        while (l <= high) {
            while (l <= high && split_set.count(s[l]) > 0) {
                ++l;
            }
            if (l > high) {
                break;
            }
            int r = l;
            while (r <= high && split_set.count(s[r]) == 0) {
                ++r;
            }
            int temp = dfs(s, l, r - 1, k);
            ans = max(temp, ans);
            l = r;
        }
        return ans;
    }

    /*
     *  分治
     * */
    int longestSubstring2(string s, int k) {
        return dfs(s, 0, s.size() - 1, k);
    }


    /*
     *  真正的滑动窗口, 枚举窗口包含字符种类个数
     * */

    int longestSubstring(string s, int k) {
        int ans = 0;
        for (int t = 1; t <= 26; ++t) {
            vector<int> cnt(26);
            // 实际字符种类
            int rt = 0;
            // 实际满足条件的种类
            int lt = 0;
            // 滑动窗口的两个边界
            int low = 0, high = 0;
            while (high < (int) s.size()) {
                if (++cnt[s[high] - 'a'] == 1) {
                    ++rt;
                }
                if (cnt[s[high] - 'a'] == k) {
                    ++lt;
                }
                while (rt > t) {
                    if (cnt[s[low] - 'a']-- == k) {
                        --lt;
                    }
                    if (cnt[s[low] - 'a'] == 0) {
                        --rt;
                    }
                    ++low;
                }
                if (lt == rt) {
                    ans = max(ans, high - low + 1);
                }
                ++high;
            }
        }
        return ans;
    }
};

// @lc code=end

