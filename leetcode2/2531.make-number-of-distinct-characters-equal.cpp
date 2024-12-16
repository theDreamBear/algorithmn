/*
 * @lc app=leetcode.cn id=2531 lang=cpp
 * @lcpr version=30204
 *
 * [2531] 使字符串中不同字符的数目相等
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
    bool isItPossible(string word1, string word2) {
        int ct1[26]{}, ct2[26]{};
        int x1 = 0, x2 = 0;
        for (auto ch: word1) {
            if (++ct1[ch - 'a'] == 1)
                x1++;
        }
        for (auto ch: word2) {
            if (++ct2[ch - 'a'] == 1)
                x2++;
        }
        if (abs(x1 - x2) > 2) return false;
        for (int i = 0; i < 26; i++) {
            if (ct1[i]) {
                for (int j = 0; j < 26; j++) {
                    if (ct2[j]) {
                        --ct1[i];
                        ++ct2[i];
                        ++ct1[j];
                        --ct2[j];
                        int x = count(begin(ct1), end(ct1), 0);
                        int y = count(begin(ct2), end(ct2), 0);
                        if (x == y) {
                            return true;
                        }
                        ++ct1[i];
                        --ct2[i];
                        --ct1[j];
                        ++ct2[j];
                    }
                }
            }
        }
        return false;
    }

    bool isItPossible1(string word1, string word2) {
        // > 2 直接返回false

        // 差2个
        // left - 1, right + 1
        // cnt1[i] = 1 and cnt2[i] = 0
        // cnt1[j] > 0 and cnt2[j] > 1
        // i != j

        // 差1个
        // left - 1, right不变
        // cnt1[i] = 1 and  cnt2[i] == 0
        // cnt1[j] > 0 and cnt2[j] = 1

        // cnt1[i] = 1 and cnt2[i] > 0
        // cnt1[j] > 0 and cnt2[j] > 1

        // left 不变, right + 1
        // cnt1[i] > 1 and cnt2[i] == 0
        // cnt1[j] > 0 and cnt2[j] > 1;

        // 差0
        // 交换任意一个双方都有的
        // 交换彼此唯一一个的 left , right
        // 交换双方唯一且多个的 left + 1, righjt + 1

        int ct1[26]{}, ct2[26]{};
        int x1 = 0, x2 = 0;
        for (auto ch: word1) {
            if (++ct1[ch - 'a'] == 1)
                x1++;
        }
        for (auto ch: word2) {
            if (++ct2[ch - 'a'] == 1)
                x2++;
        }
        if (abs(x1 - x2) > 2)
            return false;
        if (x1 < x2) {
            swap(x1, x2);
            swap(ct1, ct2);
        }
        if (x1 - x2 == 0) {
            for (int i = 0; i < 26; i++) {
                if (ct1[i] > 0 and ct2[i] > 0) return true;
            }
            // 相互交换独有且唯一的
            // left - 1 + 1, right - 1 + 1
            for (int i = 0; i < 26; i++) {
                if (ct1[i] == 1 and ct2[i] == 0) {
                    for (int j = 0; j < 26; j++) {
                        if (ct2[j] == 1 and ct1[j] == 0) {
                            return true;
                        }
                    }
                }
            }
            // left - 1, right - 1
            for (int i = 0; i < 26; i++) {
                if (ct1[i] == 1 and ct2[i] > 0) {
                    for (int j = 0; j < 26; j++) {
                        if (ct2[j] == 1 and ct1[j] > 0) {
                            return true;
                        }
                    }
                }
            }
            // left + 1 , right + 1
            // 相互交换
            for (int i = 0; i < 26; i++) {
                if (ct1[i] > 1 and ct2[i] == 0) {
                    for (int j = 0; j < 26; j++) {
                        if (ct2[j] > 1 and ct1[j] == 0) {
                            return true;
                        }
                    }
                }
            }
            // left, right都不变
            for (int i = 0; i < 26; i++) {
                if (ct1[i] > 1 and ct2[i] > 0) {
                    for (int j = 0; j < 26; j++) {
                        if (ct2[j] > 1 and ct1[j] > 0) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        // 差1个
        if (x1 - x2 == 1) {
            // left - 1, right - 1 + 1
            // cnt1[i] = 1 and  cnt2[i] == 0
            // cnt1[j] > 0 and cnt2[j] = 1
            for (int i = 0; i < 26; i++) {
                if (ct1[i] == 1 and ct2[i] == 0) {
                    for (int j = 0; j < 26; j++) {
                        if (i == j) continue;
                        if (ct1[j] > 0 and ct2[j] == 1) {
                            return true;
                        }
                    }
                }
            }
            // left - 1, right
            // cnt1[i] = 1 and cnt2[i] > 0
            // cnt1[j] > 0 and cnt2[j] > 0
            for (int i = 0; i < 26; i++) {
                if (ct1[i] == 1 and ct2[i] > 0) {
                    for (int j = 0; j < 26; j++) {
                        if (i == j) continue;
                        if (ct1[j] > 0 and ct2[j] > 1) {
                            return true;
                        }
                    }
                }
            }
            // left, right + 1
            // cnt1[i] > 1 and cnt2[i] == 0
            // cnt1[j] > 0 and cnt2[j] > 1;
            for (int i = 0; i < 26; i++) {
                if (ct1[i] > 1 and ct2[i] == 0) {
                    for (int j = 0; j < 26; j++) {
                        if (i == j) continue;
                        if (ct1[j] > 0 and ct2[j] > 1) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        // 2
        if (x1 - x2 == 2) {
            for (int i = 0; i < 26; i++) {
                if (ct1[i] == 1 and ct2[i] == 0) {
                    for (int j = 0; j < 26; j++) {
                        if (ct2[j] > 1 and ct1[j] > 0) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ac"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// "abcc"\n"aab"\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n"fghij"\n
// @lcpr case=end

 */
