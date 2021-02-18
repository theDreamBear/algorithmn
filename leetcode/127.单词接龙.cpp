/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    bool oneDiffrent(const string& left, const string& right) {
        if (left.size() != right.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < left.size(); ++i) {
            if (left[i] != right[i]) {
                if (++diff > 1) {
                    return false;
                }
            }
        }
        return diff == 1;
    }

    struct dd {
        string* str;
        int index;
    };

    /*
        迷宫寻宝 bfs
    */
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int min_len = 1;
        vector<int> visit(wordList.size());
        queue<dd> q;
        for (int i = 0; i < wordList.size(); ++i) {
            if (oneDiffrent(beginWord, wordList[i])) {
                q.push({&wordList[i], i});
            }
        }
        while (!q.empty()) {
            int sz = q.size();
            ++min_len;
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();
                q.pop();
                if (*cur.str == endWord) {
                    return min_len;
                }
                if (visit[cur.index]) {
                    continue;
                }
                visit[cur.index] = 1;
                for (int k = 0; k < wordList.size(); ++k) {
                    if (!visit[k] && oneDiffrent(*(cur.str), wordList[k])) {
                        q.push({&wordList[k], k});
                    }
                }
            }
        }
        return 0;
    }

    // dfs
    // dfs 会超时
    void dfs(int& min_len, int step, vector<string>& wordList,
             const string& curWord, const string& endWord,
             vector<int>& visited) {
        // 边界
        // 剪枝
        if (step > min_len) {
            return;
        }
        if (curWord == endWord) {
            if (step < min_len) {
                min_len = step;
            }
            return;
        }
        for (int i = 0; i < wordList.size(); ++i) {
            if (!visited[i] && oneDiffrent(curWord, wordList[i])) {
                visited[i] = 1;
                dfs(min_len, step + 1, wordList, wordList[i], endWord, visited);
                visited[i] = 0;
            }
        }
    }

    int ladderLength2(string beginWord, string endWord,
                      vector<string>& wordList) {
        vector<int> visited(wordList.size());
        int min_len = wordList.size() + 1;
        dfs(min_len, 1, wordList, beginWord, endWord, visited);
        if (min_len == wordList.size() + 1) {
            return 0;
        }
        return min_len;
    }

    /*
        构造图, 邻接表
    */
};
// @lc code=end
