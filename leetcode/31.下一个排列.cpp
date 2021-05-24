/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
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
    void getNext(vector<int> &s) {
        vector<int> vec;
        int i = s.size() - 1;
        vec.push_back(i);
        for (int j = i - 1; j >= 0; --j) {
            int pos = lower_bound(vec.begin(), vec.end(), j, [&](int cmp, int right) {
                return s[cmp] <= s[right];
            }) - vec.begin();
            if (pos < vec.size()) {
                swap(s[vec[pos]], s[j]);
                sort(s.begin() + j + 1, s.end());
                return;
            } else {
                vec.push_back(j);
            }
        }
        sort(s.begin(), s.end());
    }

    void nextPermutation(vector<int>& nums) {
        getNext(nums);
    }
};
// @lc code=end

