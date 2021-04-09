/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int compareVersion1(string version1, string version2) {
        istringstream ss1(version1);
        istringstream ss2(version2);
        string left, right;
        while (true) {
            if (!getline(ss1, left, '.')) {
                while (getline(ss2, right, '.')) {
                    int r = stod(right);
                    if (r > 0) {
                        return -1;
                    }
                }
                return 0;
            }
            int l = stod(left);
            if (!getline(ss2, right, '.')) {
                if (l > 0) {
                    return 1;
                }
                while (getline(ss1, left, '.')) {
                    l = stod(left);
                    if (l > 0) {
                        return 1;
                    }
                }
                return 0;
            }
            int r = stod(right);
            if (l < r) {
                return -1;
            } else if (l > r) {
                return 1;
            }
        }
        return 0;
    }

    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;
        while (p1 < version1.size() || p2 < version2.size()) {
            int num1 = 0, num2 = 0;
            while (p1 < version1.size() && version1[p1] != '.') {
                num1 = num1 * 10 + (version1[p1] - '0');
                ++p1;
            }
            while (p2 < version2.size() && version2[p2] != '.') {
                num2 = num2 * 10 + (version2[p2] - '0');
                ++p2;
            }
            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
            ++p1;
            ++p2;
        }
        return 0;
    }
};
// @lc code=end

int main() {
    string v1 = "1.01", v2 = "1.001";
    cout << Solution{}.compareVersion(v1, v2);
}
