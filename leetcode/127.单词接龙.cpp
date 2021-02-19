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
    bool oneDiffrent(const string &left, const string &right) {
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
        string *str;
        int index;
    };

    /*
        迷宫寻宝 bfs
    */
    int ladderLength1(string beginWord, string endWord,
                      vector<string> &wordList) {
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
    void dfs(int &min_len, int step, vector<string> &wordList,
             const string &curWord, const string &endWord,
             vector<int> &visited) {
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
                      vector<string> &wordList) {
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

    int ID = 0;
    unordered_map<string, int> words_to_id;
    unordered_map<int, vector<int>> edgs;

    void addWord(string &str) {
        if (words_to_id.count(str) != 0) {
            return;
        }
        words_to_id[str] = ID++;
        int id1 = words_to_id[str];
        for (auto &c : str) {
            char temp = c;
            c = '*';
            if (words_to_id.count(str) == 0) {
                words_to_id[str] = ID++;
            }
            int id2 = words_to_id[str];
            edgs[id1].push_back(id2);
            edgs[id2].push_back(id1);
            c = temp;
        }
    }

    int ladderLength3(string beginWord, string endWord,
                      vector<string> &wordList) {
        for (auto &str : wordList) {
            addWord(str);
        }
        if (words_to_id.count(endWord) == 0) {
            return 0;
        }
        addWord(beginWord);
        // 对图进行宽度优先遍历
        int endId = words_to_id[endWord];
        int beginId = words_to_id[beginWord];
        int min_len = 0;
        queue<pair<int, int>> q;
        q.push({0, beginId});

        vector<int> vistied(ID);
        while (!q.empty()) {
            int sz = q.size();
            ++min_len;
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();
                q.pop();
                vistied[cur.second] = 1;
                if (cur.second == endId) {
                    return min_len / 2 + 1;
                }
                if (edgs.count(cur.second) > 0) {
                    for (auto &id : edgs[cur.second]) {
                        if (vistied[id] == 1) {
                            continue;
                        }
                        q.push({cur.first + 1, id});
                    }
                }
            }
        }
        return 0;
    }
    /*
        双向 bfs, 加速
    */
    int ladderLength4(string beginWord, string endWord,
                      vector<string> &wordList) {
        for (auto &str : wordList) {
            addWord(str);
        }
        if (words_to_id.count(endWord) == 0) {
            return 0;
        }
        addWord(beginWord);

        // 对图进行宽度优先遍历
        queue<int> bq, eq;

        int endId = words_to_id[endWord];
        int beginId = words_to_id[beginWord];

        vector<int> bdistance(ID, INT_MAX);
        vector<int> edistance(ID, INT_MAX);

        bdistance[beginId] = 0;
        edistance[endId] = 0;

        bq.push(beginId);
        eq.push(endId);

        while (!bq.empty()) {
            // 先 bigin
            int bsz = bq.size();
            for (int i = 0; i < bsz; ++i) {
                int cur = bq.front();
                bq.pop();
                if (edistance[cur] != INT_MAX) {
                    return (edistance[cur] + bdistance[cur]) / 2 + 1;
                }
                for (auto id : edgs[cur]) {
                    if (bdistance[id] == INT_MAX) {
                        bdistance[id] = bdistance[cur] + 1;
                        bq.push(id);
                    }
                }
            }
            // 后 end

            int esz = eq.size();
            for (int i = 0; i < esz; ++i) {
                int cur = eq.front();
                eq.pop();
                if (bdistance[cur] != INT_MAX) {
                    return (edistance[cur] + bdistance[cur]) / 2 + 1;
                }
                for (auto id : edgs[cur]) {
                    if (edistance[id] == INT_MAX) {
                        edistance[id] = edistance[cur] + 1;
                    }
                }
            }
        }
        return 0;
    }

    /*
        枚举
        枚举结果更快
    */

    int ladderLength5(string beginWord, string endWord,
                      vector<string> &wordList) {
        int min_len = 0;
        unordered_set<string> exist(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int sz = q.size();
            ++min_len;
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();
                q.pop();
                if (cur == endWord) {
                    return min_len;
                }
                for (int i = 0; i < cur.size(); ++i) {
                    char temp = cur[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        cur[i] = c;
                        if (exist.count(cur) > 0) {
                            q.push(cur);
                            exist.erase(cur);
                        }
                    }
                    cur[i] = temp;
                }
            }
        }
        return 0;
    }

    /*
        双向 bfs
    */
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

        unordered_set<string> bexist(wordList.begin(), wordList.end());
        unordered_set<string> eexist(wordList.begin(), wordList.end());

        if (bexist.count(endWord) == 0) {
            return 0;
        }

        queue<string> bq;
        queue<string> eq;

        unordered_set<string> bdi, edi;

        int left = 0, right = 0;

        bq.push(beginWord);
        eq.push(endWord);

        while (!bq.empty() && !eq.empty()) {
            // begin
            int sz = bq.size();
            ++left;
            for (int i = 0; i < sz; ++i) {
                auto cur = bq.front();
                bq.pop();
                bdi.insert(cur);
                if (edi.count(cur) > 0) {
                    return left + right - 1;
                }
                for (int i = 0; i < cur.size(); ++i) {
                    char temp = cur[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        cur[i] = c;
                        if (bexist.count(cur) > 0) {
                            bq.push(cur);
                            bexist.erase(cur);
                        }
                    }
                    cur[i] = temp;
                }
            }

            // end
            sz = eq.size();
            ++right;
            for (int i = 0; i < sz; ++i) {
                auto cur = eq.front();
                eq.pop();
                edi.insert(cur);
                if (bdi.count(cur) > 0) {
                    return left + right - 1;
                }
                for (int i = 0; i < cur.size(); ++i) {
                    char temp = cur[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        cur[i] = c;
                        if (eexist.count(cur) > 0) {
                            eq.push(cur);
                            eexist.erase(cur);
                        }
                    }
                    cur[i] = temp;
                }
            }
        }
        return 0;
    }
};
// @lc code=end

int main() {
    string b = "hot";
    string end = "dog";
    vector<string> words = {"hot", "dog"};
    Solution{}.ladderLength(b, end, words);
}
