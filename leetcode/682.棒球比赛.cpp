/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
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
#include <stdio.h>

using namespace std;

// @lc code=start
class Solution {
public:

    /*
        注意负数
    */
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        for (auto& str : ops) {
            //if (!isdigit(str[0]) && str[0] != '-') {
            if (str[0] == '+' || str[0] == 'D' || str[0] == 'C') {
                switch(str[0]) {
                    case '+' : {
                        int score = scores[scores.size() - 1] + scores[scores.size() - 2];
                        scores.push_back(score);
                        break;
                    }
                    case 'D' : {
                        int score = 2 * scores.back();
                        scores.push_back(score);
                        break;
                    }
                    case 'C' : {
                        scores.pop_back();
                        break;
                    }
                }
            } else {
                int score = strtol(str.c_str(), NULL, 10);
                scores.push_back(score);
            }
        }
        int sum = 0;
        for (auto val : scores) {
            sum += val;
        }
        return sum;
    }
};
// @lc code=end

int main() {
    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    cout << Solution{}.calPoints(ops) << endl;
}

