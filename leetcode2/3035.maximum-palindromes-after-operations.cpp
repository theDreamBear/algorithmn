/*
 * @lc app=leetcode.cn id=3035 lang=cpp
 * @lcpr version=30204
 *
 * [3035] 回文字符串的最大数量
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // 居然过了
    int maxPalindromesAfterOperations1(vector<string>& words) {
        // 所有字符都可以重新组合
        // 但是有一个组合长度
        // a:4, b:4
        int cnt[26]{};
        vector<int> sz;
        for (auto& word: words) {
            sz.push_back(word.size());
            for (auto ch: word) {
                cnt[ch - 'a']++;
            }
        }
        queue<int> even, odd;
        for (auto v: cnt) {
            if (v) {
                if (v % 2 == 0) {
                    even.push(v);
                } else {
                    odd.push(v);
                }
            }
        }
        ranges::sort(sz);
        int ans = 0;
        for (auto v: sz) {
            if (v % 2 != 0) {
                if (odd.size()) {
                    int x = odd.front();
                    odd.pop();
                    v -= 1;
                    if (x > 1) {
                        even.push(x - 1);
                    }
                } else if (even.size()) {
                    int x = even.front(); even.pop();
                    v -= 1;
                    odd.push(x - 1);
                } else {
                    break;
                }
            }
            while (v > 0 and even.size()) {
                int x = even.front(); even.pop();
                int diff = min(v, x);
                v -= diff;
                if (x - diff) {
                    even.push(x - diff);
                }
            }
            queue<int> tmp;
            while (v > 1 and odd.size()) {
                int x = odd.front(); odd.pop();
                int diff = min(v, x - 1);
                v -= diff;
                if (x - diff) {
                    tmp.push(x - diff);
                }
            }
            while (tmp.size()) {
                odd.push(tmp.front());
                tmp.pop();
            }
            ans += v == 0;
            if (v > 0) break;
        }
        return ans;
    }

    int maxPalindromesAfterOperations2(vector<string> &words) {
        int ans = 0, tot = 0, mask = 0;
        for (auto &w : words) {
            tot += w.length();
            for (char c : w) {
                mask ^= 1 << (c - 'a');
            }
        }
        tot -= __builtin_popcount(mask); // 减去出现次数为奇数的字母

        ranges::sort(words, [](const auto &a, const auto &b) {
            return a.length() < b.length();
        });
        for (auto &w : words) {
            tot -= w.length() / 2 * 2; // 长为奇数的字符串，长度要减一
            if (tot < 0) break;
            ans++;
        }
        return ans;
    }

    int maxPalindromesAfterOperations(vector<string> &words) {
        int oddL = 0; // 奇数长度字符串个数
        int mask = 0; // 奇数个数的字母集合
        for (auto &w : words) {
            oddL += w.length() % 2;
            for (char c : w) {
                mask ^= 1 << (c - 'a');
            }
        }

        ranges::sort(words, [](const auto &a, const auto &b) {
            return a.length() > b.length();
        });

        int ans = words.size();
        int left = __builtin_popcount(mask) - oddL; // S 中的剩余字母个数
        for (auto &w : words) {
            if (left <= 0) break;
            left -= w.length() / 2 * 2;
            ans--;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["abbb","ba","aa"]\n
// @lcpr case=end

// @lcpr case=start
// ["abc","ab"]\n
// @lcpr case=end

// @lcpr case=start
// ["cd","ef","a"]\n
// @lcpr case=end

 */

