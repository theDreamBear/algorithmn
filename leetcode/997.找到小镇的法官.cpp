/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int findJudge1(int N, vector<vector<int>>& trust) {
        vector<int> trusted_count(N + 1);
        vector<int> judge_candidate(N + 1, 1);
        for (auto& vec : trust) {
            judge_candidate[vec[0]] = 0;
            ++trusted_count[vec[1]];
        }
        for (int i = 1; i < judge_candidate.size(); ++i) {
            if (judge_candidate[i] == 1 && trusted_count[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }

    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusted_count(N + 1);
        for (auto& vec : trust) {
            --trusted_count[vec[0]];
            ++trusted_count[vec[1]];
        }
        for (int i = 1; i < trusted_count.size(); ++i) {
            if (trusted_count[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

