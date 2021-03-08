/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */
#include <ranges.h>
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
    bool dominoesEqual(int a, int b, int c, int d) {
        if (a == c && b == d) {
            return true;
        }
        if (a == d && b == c) {
            return true;
        }
        return false;
    }

    /*
        O(n^2)超时
    */
    int numEquivDominoPairs1(vector<vector<int>>& dominoes) {
        int ct = 0;
        for (int i = 1; i < dominoes.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dominoesEqual(dominoes[i][0], dominoes[i][1],
                                  dominoes[j][0], dominoes[j][1])) {
                    ++ct;
                }
            }
        }
        return ct;
    }

    int timesCount(int m) { return (m * (m - 1)) / 2; }

    /*
        O(nlgn);
    */
    int numEquivDominoPairs2(vector<vector<int>>& dominoes) {
        sort(dominoes.begin(), dominoes.end(),
             [&](vector<int>& last, vector<int>& before) {
                 if (last[0] > last[1]) {
                     swap(last[1], last[0]);
                 }
                 if (before[0] > before[1]) {
                     swap(before[1], before[0]);
                 }
                 return make_pair(last[0], last[1]) <
                        make_pair(before[0], before[1]);
             });
        int ans = 0;
        int i = 0;
        while (i < dominoes.size()) {
            int ct = 0;
            while (i + ct < dominoes.size() &&
                   dominoes[i + ct][0] == dominoes[i][0] &&
                   dominoes[i + ct][1] == dominoes[i][1]) {
                ++ct;
            }
            if (ct > 1) {
                ans += timesCount(ct);
            }
            i += ct;
        }
        return ans;
    }

    int numEquivDominoPairs3(vector<vector<int>>& dominoes) {
        sort(dominoes.begin(), dominoes.end(),
             [&](vector<int>& last, vector<int>& before) {
                 if (last[0] > last[1]) {
                     swap(last[1], last[0]);
                 }
                 if (before[0] > before[1]) {
                     swap(before[1], before[0]);
                 }
                 // 1 <= dominoes[i][j] <= 9  可以考虑用9进制
                 return last[0] * 9 + last[1] < before[0] * 9 + before[1];
             });
        int ans = 0;
        int i = 0;
        while (i < dominoes.size()) {
            int ct = 0;
            while (i + ct < dominoes.size() &&
                   dominoes[i + ct][0] == dominoes[i][0] &&
                   dominoes[i + ct][1] == dominoes[i][1]) {
                ++ct;
            }
            if (ct > 1) {
                ans += timesCount(ct);
            }
            i += ct;
        }
        return ans;
    }

    /*
        从方法三得到的灵感
    */
    int numEquivDominoPairs4(vector<vector<int>>& dominoes) {
        vector<int> hash(100);
        for (auto& vec : dominoes) {
            if (vec[0] > vec[1]) {
                swap(vec[0], vec[1]);
            }
            ++hash[vec[0] * 10 + vec[1]];
        }
        int ans = 0;
        for (int i = 0; i < hash.size(); ++i) {
            if (hash[i] > 1) {
                ans += timesCount(hash[i]);
            }
        }
        return ans;
    }

    /*
        4 优化
        C(n, 2) = 1 + 2 + ..(n - 1);
    */
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> hash(100);
        int ans = 0;
        for (auto& vec : dominoes) {
            if (vec[0] > vec[1]) {
                swap(vec[0], vec[1]);
            }
            int val = vec[0] * 10 + vec[1]; 
            ans += hash[val];
            ++hash[val];
        }
        return ans;
    }
    // 并查集
    
};
// @lc code=end
