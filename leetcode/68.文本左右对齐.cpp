/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
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
    // 这个函数写的还行
    // [i, j) 区间为前开后闭
    tuple<bool, int, int, int> getNextLinxIndex(const vector<string>& words, int maxWidth, int startPos) {
        if (startPos >= int(words.size())) {
            return {true, -1, -1, -1};
        }
        int i = startPos;
        int j = i + 1;
        int left = maxWidth - words[i].size();
        for (; j < int(words.size()) && left > 0; ++j) {
            int diff = words[j].size() + 1;
            if (left - diff < 0) {
                break;
            } else {
                left -= diff;
            }
        }
        if (j == int(words.size())) {
            // 最后一行
            return {true, i, j, left};
        }
        return {false, i, j, left};
    }

    /*
        这个函数写的稀碎
        snprintf会在末尾补零
        strcpy strncpy 可能会在末尾补零

    */
    void fillWord1(const vector<string>& words, vector<string>& ans, int maxWidth, int i, int j, int left, bool direct = false) {
        char buffer[maxWidth + 1];
        fill(buffer, buffer + maxWidth, ' ');
        buffer[maxWidth] = 0;
        // 非最后一行且有多余空格
        if (!direct && left > 0) {
            if (j - i > 1) {
                int pos = maxWidth - 1;
                for (int k = j - 1; k > i && left >= 0; --k) {
                    int start = pos - words[k].size();
                    //sprintf(buffer + start + 1, "%s", words[k].c_str());
                    strncpy(buffer + start + 1, words[k].c_str(), words[k].size());
                    int numOfSpace = left / (k - i);
                    left -= numOfSpace;
                    start -= (numOfSpace + 1);
                    pos = start;
                }
            }
            strncpy(buffer, words[i].c_str(), words[i].size());
            ans.push_back(buffer);
            //cout << buffer << endl;
            return;
        }
        // 最后一行或者没有多余空格
        //int pos = 0;
        //pos = sprintf(buffer, "%s ", words[i].c_str());
        char* pos = strncpy(buffer, words[i].c_str(), words[i].size());
        pos += words[i].size();
        ++pos;
        int k = i + 1;
        while (k < j) {
            //pos = sprintf(buffer + pos, " %s", words[k].c_str());
            pos = strncpy(pos, words[k].c_str(), words[k].size());
            pos += words[k].size();
            ++pos;
            ++k;
        }
        ans.push_back(buffer);
        return;
    }

    /*
        非常稚嫩的解法
        很多地方可以优化来降低出错的概率
    */
    vector<string> fullJustify1(vector<string>& words, int maxWidth) {
        vector<string> ans;
        bool flag = true;
        int pos = 0;
        while (flag) {
            auto next = getNextLinxIndex(words, maxWidth, pos);
            bool end = get<0>(next);
            int i = get<1>(next);
            int j = get<2>(next);
            int left = get<3>(next);
            pos = j;
            if (end != true) {
                fillWord1(words, ans, maxWidth, i, j, left, false);
            } else {
                if (i != -1) {
                    fillWord1(words, ans, maxWidth, i, j, left, true);
                } else {
                    break;
                }
            }
        }
        return ans;
    }

    void fillWord(const vector<string>& words, vector<string>& ans, int maxWidth, int i, int j, int left) {
        if (i >= words.size()) {
            return;
        }
        string temp = words[i];
        // 只有一个单词 或者最后一行
        if (i + 1 == j || j == words.size()) {
            for(int k = i + 1; k < j; ++k) {
                temp += (" " + words[k]);
            }
            temp += string(left, ' ');
        } else {
            int spaceSuffix = 1;
            int spaceAvg = left / (j - i - 1);
            for (int k = i + 1; k < j; ++k) {
                int extraSpace = (k - i) <= (left % (j - i - 1));
                temp += string(spaceSuffix + spaceAvg + extraSpace, ' ') + words[k];
            }
        }
        ans.emplace_back(temp);
        return;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int pos = 0;
        while (true) {
            auto next = getNextLinxIndex(words, maxWidth, pos);
            bool end = get<0>(next);
            int i = get<1>(next);
            int j = get<2>(next);
            int left = get<3>(next);
            pos = j;
            if (end != true || i != -1) {
                fillWord(words, ans, maxWidth, i, j, left);
            } else {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    vector<string> words= {
        "What","mxzfcst","asdsb","acknowlent","shsdall","be"
    };
    int maxWidth = 16;
    auto ans = Solution{}.fullJustify(words, maxWidth);
    for (auto str : ans) {
        cout << str << endl;
    }
}