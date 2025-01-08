/*
 * @lc app=leetcode.cn id=3297 lang=cpp
 * @lcpr version=30204
 *
 * [3297] 统计重新排列后包含另一个字符串的子字符串数目 I
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
    long long validSubstringCount(string word1, string word2) {
        if (word1.size() < word2.size()) return 0;
        long long ans = 0;
        int cnt[26]{};
        for (auto ch: word2) cnt[ch - 'a']++;
        int less = 0;
        for (auto i : cnt) {
            less += (i > 0);
        }
        for (int left = 0, right = 0; right < word1.size(); right++) {
            if (--cnt[word1[right] - 'a'] == 0) {
                less--;
            }
            while (less == 0) {
                if (++cnt[word1[left] - 'a'] > 0) ++less;
                left++;
            }
            ans += left;
        }
        return ans;
    }

    // [0, ... right] 符合区间
    // [left, right] 不符合区间
    // [0, left) 是新增的
    //
    long long validSubstringCount2(string word1, string word2) {
        if (word1.size() < word2.size()) return 0;
        long long ans = 0;
        int cnt[26]{};
        for (auto ch: word2) cnt[ch - 'a']++;
        int cx[26]{};
        auto ok = [&]() {
            for (int i = 0; i < 26; i++) {
                if (cx[i] < cnt[i]) return false;
            }
            return true;
        };
        for (int left = 0, right = 0; right < word1.size(); right++) {
            cx[word1[right] - 'a']++;
            if (right - left + 1 < word2.size()) continue;
            if (ok()) {
                while (ok()) {
                    cx[word1[left] - 'a']--;
                    left++;
                }
                
            }
            ans += left;
        }
        return ans;
    }

    long long validSubstringCount1(string word1, string word2) {
        if (word1.size() < word2.size()) return 0;
        long long ans = 0;
        int cnt[26]{};
        for (auto ch: word2) cnt[ch - 'a']++;
        int cx[26]{};
        auto ok = [&]() {
            for (int i = 0; i < 26; i++) {
                if (cx[i] < cnt[i]) return false;
            }
            return true;
        };
        for (int left = 0, right = 0; right < word1.size(); right++) {
            cx[word1[right]- 'a']++;
            if (right - left + 1 < word2.size()) continue;
            if (ok()) {
                while (ok()) {
                    ans += (word1.size() - right);
                    cx[word1[left] - 'a']--;
                    left++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "bcca"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"aaabc"\n
// @lcpr case=end

 */

