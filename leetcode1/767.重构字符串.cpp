/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
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
    string reorganizeString1(string s) {
        vector<int> alphaCount(26);
        int threshold = (s.size() + 1) >> 1;
        for (auto c : s) {
            if (++alphaCount[c - 'a'] > threshold) {
               return "";
            }
        }
        priority_queue<pair<int, char>> priorityQueue;
        for (int i = 0; i < 26; ++i) {
            if (alphaCount[i] > 0) {
                priorityQueue.push({alphaCount[i], i + 'a'});
            }
        }
        string ans;
        int preCount = 0;
        char preChar = '#';
        while (!priorityQueue.empty()) {
            auto [ct, c] = priorityQueue.top();
            priorityQueue.pop();
            ans.push_back(c);
            if (preCount > 0) {
                priorityQueue.push({preCount, preChar});
            }
            --ct;
            preCount = 0;
            if (ct > 0) {
                preCount = ct;
                preChar = c;
            }
        }
        if (preCount > 0) {
            return "";
        }
        return ans;
    }

    // 使用基于排序的拼接应该也可以, 根据个数进行排序, 首先取两个, 然后把这两个进行拼接, 然后再取一个把没用完的那个消耗完   aabbcc 这个方法不可行
    // 还是需要重新添加进去, 然后再取, 这样还是需要排序, 所以还是需要优先队列
    string reorganizeString_bad(string s) {
        vector<int> alphaCount(26);
        int threshold = (s.size() + 1) >> 1;
        for (auto c : s) {
            if (++alphaCount[c - 'a'] > threshold) {
                return "";
            }
        }
        vector<pair<int, char>> vec;
        for (int i = 0; i < alphaCount.size(); i++) {
            if (alphaCount[i] > 0) {
                vec.emplace_back(alphaCount[i], i + 'a');
            }
        }
        // 决定最终复杂度 nlgn
        sort(vec.begin(), vec.end(), greater<>{});
        string ans;
        // 已知 vec.size() > 2
        char lhs = '#';
        int lhsLeft = 0;
        char rhs = '#';
        int rhsLeft = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (0 == lhsLeft) {
                lhs = vec[i].second;
                lhsLeft = vec[i].first;
                continue;
                i++;
                rhs = vec[i].second;
                rhsLeft = vec[i].first;
            } else if (0 == rhsLeft) {
                rhs = vec[i].second;
                rhsLeft = vec[i].first;
                if (lhsLeft < vec[i].first) {
                    swap(lhs, rhs);
                    swap(lhsLeft, rhsLeft);
                }
            }
            while (lhsLeft > 0 && rhsLeft > 0) {
                ans.push_back(lhs);
                ans.push_back(rhs);
                lhsLeft--;
                rhsLeft--;
            }
        }
        if (lhsLeft > 0) {
            ans.push_back(lhs);
        }
        return ans;
    }
};


// 2. 上面的算法, 每次取两个能让算法简单

// 3. 使用基于排序的拼接应该也可以, 根据个数进行排序, 首先取两个, 然后把这两个进行拼接, 然后再取一个把没用完的那个消耗完   aabbcc 这个方法不可行
// 这个有点像 求 在 n 个数中求, 大于其总数的 n / 2 的那个思想,但是那个不用排序

// 基于计数的贪心算法
/// 这个是 leet 官方的, 思想非常有意思
class Solution_leet {
public:
    string reorganizeString(string s) {
        if (s.length() < 2) {
            return s;
        }
        vector<int> counts(26, 0);
        int maxCount = 0;
        int length = s.length();
        for (int i = 0; i < length; i++) {
            char c = s[i];
            counts[c - 'a']++;
            maxCount = max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2) {
            return "";
        }
        string reorganizeArray(length, ' ');
        int evenIndex = 0, oddIndex = 1;
        int halfLength = length / 2;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            while (counts[i] > 0 && counts[i] <= halfLength && oddIndex < length) {
                reorganizeArray[oddIndex] = c;
                counts[i]--;
                oddIndex += 2;
            }
            while (counts[i] > 0) {
                reorganizeArray[evenIndex] = c;
                counts[i]--;
                evenIndex += 2;
            }
        }
        return reorganizeArray;
    }
};
// @lc code=end

