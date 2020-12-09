/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
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
    void leftRotate(vector<int>& nums, int low, int high, int k) {
        for (int i = low, j = low + k - 1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        for (int i = low + k, j = high; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        for (int i = low, j = high; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
    }

    int removeDuplicates_1(vector<int>& nums) {
        int left = -1, right = -1;
        int ans = nums.size();
        for (int i = 0; i < ans;) {
            if (left == -1) {
                left = i;
                ++i;
                continue;
            } else {
                if (nums[left] == nums[i]) {
                    right = i;
                    ++i;
                    continue;
                }
                if (right > left) {
                    int k = right - left - 1;
                    ans -= k;
                    if (k > 0) {
                        leftRotate(nums, left, nums.size() - 1, k);
                    }
                    left = i - k;
                    right = -1;
                    i -= k;
                    ++i;
                } else {
                    left = i;
                    right = -1;
                    ++i;
                }
            }
        }
        if (right - left > 1) {
            int k = right - left - 1;
            ans -= k;
        }
        return ans;
    }

    int removeDuplicates_2(vector<int>& nums) {
        int left = 0, right = left;
        int ans = nums.size();
        for (int i = 0; i < ans;) {
            if (nums[i] == nums[left]) {
                if (i > left) {
                    ++right;
                }
                ++i;
            } else {
                if (right - left > 1) {
                    int k = right - left - 1;
                    if (k > 0) {
                        leftRotate(nums, left, nums.size() - 1, k);
                        ans -= k;
                        i -= k;
                    }
                }
                left = i;
                right = left;
            }
        }
        if (right - left > 1) {
            int k = right - left - 1;
            if (k > 0) {
                leftRotate(nums, left, nums.size() - 1, k);
                ans -= k;
            }
        }
        return ans;
    }

    // [0, j) 区间的数是有效的
    //

    int removeDuplicates_3(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int j = 1, count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                ++count;
            } else {
                count = 1;
            }
            if (count <= 2) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }

    // [0, j) 区间的数是有效的
    // [j, i) 待覆盖区间

    int removeDuplicates(vector<int>& nums) {
        int j = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                ++j;
                ++count;
                continue;
            }
            if (nums[i] == nums[i - 1]) {
                ++count;
            } else {
                count = 1;
            }
            if (count <= 2) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }

    int removeDuplicates_4(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int L = 0;
        for (int R = 0; R < nums.size(); ++R) {
            // nums[L-2] < nums[R]
            //    如果重复数字个数不大于2，那么这个判断肯定是成立的
            //    如果重复个数大于2，那么nums[L-2] < nums[R]就是不成立的
            //      即 多余重复项都被忽视了，直到遇到新的数字或者数字结束
            if (L < 2 || nums[L - 2] < nums[R]) {
                nums[L] = nums[R];
                ++L;
            }
        }
        return L;
    }
};
// @lc code=end

int main() {
    vector<int> ans = {0, 0, 0, 0, 0, 1, 2, 2, 3, 3, 4, 4};
    int len = Solution{}.removeDuplicates(ans);
    for (int i = 0; i < len; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
