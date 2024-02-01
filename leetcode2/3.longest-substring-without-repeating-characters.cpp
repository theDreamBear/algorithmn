/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30114
 *
 * [3] 无重复字符的最长子串
 */

// @lcpr-template-start
#include <cstring>
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
    class Helper {
      private:
        char ct[300];
        int start = 0, end = 0, max_len = 0;

        void init() {
            start = 0;
            end = 0;
            max_len = 0;
            bzero(ct, sizeof(ct));
        }

        void moveAndSet(string& s) {
            while (!terminal(s) && ++ct[s[end]] == 1) ++end;
            max_len = max(max_len, end - start);
        }

        void holdon(string& s) {
            // 1、保证ct 中不存在 > 2 的
            // 2、保证 start <= end
            // 3、保证 end 是还没有被处理的
            while (start < end && --ct[s[start]] != 1) ++start;
            ++start;
            ++end;
        }

        bool terminal(string& s) {
            return end == s.size();
        }

      public:
        int run(string& s) {
            init();
            while (!terminal(s)) {
                moveAndSet(s);
                if (!terminal(s)) {
                    holdon(s);
                }
            }
            return max_len;
        }
    };

    /*
        0 <= s.length <= 5 * 104
        s 由英文字母、数字、符号和空格组成
    */
    int lengthOfLongestSubstring(string s) {
        return Helper{}.run(s);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
