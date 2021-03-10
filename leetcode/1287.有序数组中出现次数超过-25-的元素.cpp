/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 *
 * [1287] 有序数组中出现次数超过25%的元素
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
    int findSpecialInteger1(vector<int>& arr) {
        int target = arr.size() / 4 + 1;
        int i = 0;
        while (i < arr.size()) {
            int ct = 1, j = i + 1;
            while (j < arr.size() && arr[j] == arr[i]) {
                ++j;
                ++ct;
            }
            if (ct >= target) {
                return arr[i];
            }
            i = j;
        }
        return 0;
    }

    int findSpecialInteger2(vector<int>& arr) {
        int target = arr.size() / 4;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == arr[i + target]) {
                return arr[i];
            }
        }
        return 0;
    }

    /*
        根据题目要求，满足条件的整数 x 至少在数组 arr 中出现了 span = arr.length / 4 + 1 次，那么我们可以断定：数组 arr 中的元素 arr[0], arr[span], arr[span * 2], ... 一定包含 x。
        这个结论有点意思
    */
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int span = n / 4 + 1;
        for (int i = 0; i < n; i += span) {
            auto iter_l = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto iter_r = upper_bound(arr.begin(), arr.end(), arr[i]);
            if (iter_r - iter_l >= span) {
                return arr[i];
            }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    vector<int> data{1,2,2,6,6,6,6,7,10};
    cout << Solution{}.findSpecialInteger(data);
}
