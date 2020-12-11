/*
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
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
    /*
        check ok
    */
    int getDepth(int label) {
        int depth = 1;
        while (label != 1) {
            label >>= 1;
            ++depth;
        }
        return depth;
    }

    /*
    check pass
    */
    int getParent(int label) {
        if (label == 1) {
            return -1;
        }
        int depth = getDepth(label);
        int start = pow(2, depth - 1);
        int dif = (label - start) / 2 + 1;
        return start - dif;
    }

    void testCheck(const vector<int>& values, const vector<int>& expecteds,
                   int (Solution::*pf)(int)) {
        for (int i = 0; i < values.size(); ++i) {
            int v = (this->*pf)(values[i]);
            if (expecteds[i] == v) {
                cout << "case pass" << endl;
            } else {
                cout << values[i] << " wrong " << v << endl;
            }
        }
    }

    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        ans.push_back(label);
        while (label != 1) {
            label = getParent(label);
            ans.push_back(label);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end


int main() {
    vector<int> values = {1, 3, 6, 12, 8, 26};
    vector<int> expecteds = {-1, 1, 2, 5, 7, 10};
    Solution{}.testCheck(values, expecteds, &Solution::getParent);
}
