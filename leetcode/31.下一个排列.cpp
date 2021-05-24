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
    /*
        nlgn
    */
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
                // 观察, 只需处理 [i + 1,end)区间且必为降序, 只需要逆转就行
                sort(s.begin() + j + 1, s.end());
                return;
            } else {
                vec.push_back(j);
            }
        }
        // 逆转就行
        sort(s.begin(), s.end());
    }

    void nextPermutation1(vector<int>& nums) {
        getNext(nums);
    }

    #define SPEED
    void nextPermutation(vector<int>& nums) {
        vector<int> vec;
        vec.push_back(nums.size() - 1);
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                #ifndef SPEED
                for (int k = nums.size() - 1; k > i; --k) {
                    if (nums[k] > nums[i]) {
                        swap(nums[i], nums[k]);
                        reverse(nums.begin() + i + 1, nums.end());
                        return;
                    }
                }
                #endif
                // 第二遍找使用二分查找加速
                #ifdef SPEED
                auto pos = lower_bound(vec.begin(), vec.end(), i, [&](int cmp, int right) {
                    return nums[cmp] <= nums[right];
                }) - vec.begin();
                if (pos != vec.size()) {
                    swap(nums[i], nums[vec[pos]]);
                    reverse(nums.begin() + i + 1, nums.end());
                }
                return;
                #endif
            } else {
                vec.push_back(i);
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end

