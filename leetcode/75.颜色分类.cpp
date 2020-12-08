/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
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
    void sortColors_sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return;
    }

    /*
        [0, p1)  0
        [p1, i)  1
        [i, p2] 未定区域
        (p2, len - 1]  2


    */
    void sortColors1(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int p1 = 0;
        int i = 0;
        int p2 = nums.size() - 1;
        while (i <= p2) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p1]);
                ++p1;
                ++i;
            } else if (nums[i] == 1) {
                ++i;
            } else {
                swap(nums[i], nums[p2]);
                --p2;
            }
        }
    }

    /*

    */
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        multi_partition(nums);
    }

    /*
        [low, p) < temp
        [p, i) >= temp;
        [i, high) 未处理
        故p 就是最左位置
    */

   int _partition(vector<int>& nums, int low, int high, int temp) {
        int i = low, p = low;
        for (; i <= high; ++i) {
            // 处理0的部分 这部分和 partition一致
            if (nums[i] < temp) {
                if (i > p) {
                    swap(nums[i], nums[p]);
                }
                ++p;
            }
        }
        return p;
   }

    /*
        循环不变式

        [0, p) 0
        [p, i)  1
        [i, p1) 未处理区域
        [p1, high) 2
    */
    void partition_once(vector<int>& nums) {
        int temp = 1;
        int i = 0, p = 0, p1 = nums.size() - 1;
        for (; i <= p1;) {
            // 处理0的部分 这部分和 partition一致
            if (nums[i] < temp) {
                if (i > p) {
                    swap(nums[i], nums[p]);
                }
                ++p;
                ++i;
            } else if (nums[i] > temp) {
                swap(nums[i], nums[p1]);
                --p1;
            } else {
                ++i;
            }
        }
    }

    void multi_partition(vector<int>& nums) {
       int p = 0, i = 0;
       p = _partition(nums, 0, nums.size() - 1, 1);
       _partition(nums, p, nums.size() - 1, 2);
    }
};
// @lc code=end

