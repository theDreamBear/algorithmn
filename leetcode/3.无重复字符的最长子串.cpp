/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring_1(string s) {
        int maxSize = 0;
        set<char> cSet;
        queue<char> cQ;
        for (int i = 0; i < s.size(); ++i) {
            if (cSet.find(s[i]) != cSet.end()) {
                if (cSet.size() > maxSize) {
                    maxSize = cSet.size();
                }
                // 一边修改容器, 一遍遍历荣容器, 注意下面记下容器大小
                int sz = cSet.size();
                for (int j = 0; j < sz; ++j) {
                    char c = cQ.front();
                    cQ.pop();
                    cSet.erase(c);
                    if (c == s[i]) {
                        break;
                    }
                }
            }
            cQ.push(s[i]);
            cSet.insert(s[i]);
        }
        if (cSet.size() > maxSize) {
            maxSize = cSet.size();
        }
        return maxSize;
    }

    /*
    时间复杂度 O(N), 空间复杂度O(N)
    */
    int lengthOfLongestSubstring_2(string s) {
        int maxSize = 0;
        // 换成 unordered_set 速度稍微快点
        unordered_set<char> cSet;
        queue<char> cQ;
        for (int i = 0; i < s.size(); ++i) {
            if (cSet.find(s[i]) != cSet.end()) {
                if (cQ.size() > maxSize) {
                    maxSize = cQ.size();
                }
                while (!cQ.empty()) {
                    char c = cQ.front();
                    cQ.pop();
                    cSet.erase(c);
                    if (c == s[i]) {
                        break;
                    }
                }
            }
            cQ.push(s[i]);
            cSet.insert(s[i]);
        }
        if (cQ.size() > maxSize) {
            maxSize = cQ.size();
        }
        return maxSize;
    }

    struct twoqueue {
        int left;
        int right;
        const string& s;

        twoqueue(const string& s, int left = -1, int right = -1)
            : s(s), left(left), right(right) {}

        void push(char c) { ++right; }

        void pop() { ++left; }

        char front() { return s[left + 1]; }

        int size() { return right - left; }

        bool empty() { return left >= right; }

        int begin() { return left + 1; }
    };

    // 上面的 queue 可以只用两个指针代替
    int lengthOfLongestSubstring_3(string s) {
        int maxSize = 0;
        // 换成 unordered_set 速度稍微快点
        unordered_set<char> cSet;
        twoqueue cQ(s);
        for (int i = 0; i < s.size(); ++i) {
            if (cSet.find(s[i]) != cSet.end()) {
                if (cQ.size() > maxSize) {
                    maxSize = cQ.size();
                }
                while (!cQ.empty()) {
                    char c = cQ.front();
                    cQ.pop();
                    cSet.erase(c);
                    if (c == s[i]) {
                        break;
                    }
                }
            }
            cQ.push(s[i]);
            cSet.insert(s[i]);
        }
        if (cQ.size() > maxSize) {
            maxSize = cQ.size();
        }
        return maxSize;
    }

    constexpr static int NO_EXIST = -1;
    struct charSet {
        int cSet[300];

        charSet() { fill(cSet, cSet + sizeof(cSet) / sizeof(int), NO_EXIST); }

        bool contains(char c) { return cSet[c] != NO_EXIST; }

        int index(char c) { return cSet[c]; }

        void add(char c, int i) { cSet[c] = i; }

        void reset(char c) { cSet[c] = NO_EXIST; }
    };

    struct helper {
        charSet cSet;
        twoqueue cQ;

        helper(const string& s) : cQ(s) {}

        int size() { return cQ.size(); }

        void erase(int i) {
            cSet.reset(cQ.s[i]);
            cQ.pop();
        }

        void add(int i) {
            cQ.push(cQ.s[i]);
            cSet.add(cQ.s[i], i);
        }

        bool contains(char c) { return cSet.contains(c); }

        int begin() { return cQ.begin(); }

        int index(int i) { return cSet.index(cQ.s[i]); }

        void removeRange(int left, int right) {
            for (int j = left; j <= right; ++j) {
                erase(j);
            }
        }
    };

    int lengthOfLongestSubstring(string s) {
        if (0 == s.size()) {
            return 0;
        }
        int maxSize = 0;
        helper h(s);
        for (int i = 0; i < s.size(); ++i) {
            if (h.contains(s[i])) {
                maxSize = max(maxSize, h.size());
                h.removeRange(h.begin(), h.index(i));
            }
            h.add(i);
        }
        return max(maxSize, h.size());
    }
};
// @lc code=end
