/*
 * @lc app=leetcode.cn id=726 lang=cpp
 *
 * [726] 原子的数量
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
private:
    map<string, int> hash;
public:
    int getNum(int& start, int end, const string& formula) {
        int ans = 0;
        while(start <= end && isdigit(formula[start])) {
            ans = ans * 10 + (formula[start++] - '0');
        }
        return ans;
    }

    void countOfAtomsHelper(int start, int end, int times, string formula) {
        if (start > end) {
            return;
        }
        while(start <= end && formula[start] != '(') {
            string name;
            if (!isupper(formula[start])) {
                return;
            }
            name.push_back(formula[start++]);
            while(start <= end  && islower(formula[start])) {
                name.push_back(formula[start++]);
            }
            int ct = times;
            if (start <= end && isdigit(formula[start])) {
                ct = getNum(start, end, formula) * times;
            }
            hash[name] += ct;
        }

        int l = 1, r = 0;
        int e = start + 1;
        while (e <= end && l > r) {
            if (formula[e] == '(') {
                ++l;
            }
            if (formula[e] == ')') {
                ++r;
            }
            ++e;
        }
        int t = times;
        if (e <= end && isdigit(formula[e])) {
            t = getNum(e, end, formula) * times;
        }
        countOfAtomsHelper(start + 1, e - 2, t, formula);
        countOfAtomsHelper(e, end, times, formula);
    }

    string countOfAtoms(string formula) {
        string ans;
        countOfAtomsHelper(0, formula.size(), 1, formula);
        for(auto kv : hash) {
            ans += kv.first;
            if (kv.second > 1) {
                ans += (to_string(kv.second));
            }
        }
        return ans;
    }
};

// @lc code=end

