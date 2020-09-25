/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include<iostream>
#include<algorithm>

/ 最蠢的merge排序,占用大量空间
// 出错地方,
// 1. 下标改变位置, 
// 2. 如果为偶数结果的时候, 因为要得到浮点数结果需要乘以 1.0

double findMedianSortedArrays_Merge(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int temp[nums1Size + nums2Size];
    // merge排序
    int lindex = 0, rindex = 0, index = 0;
    while (lindex < nums1Size && rindex < nums2Size) {
        if (nums1[lindex] < nums2[rindex]) {
            temp[index++] = nums1[lindex];
            ++lindex;
        } else {
             temp[index++] = nums2[rindex];
            ++rindex;
        }
    }
    while (lindex < nums1Size) {
        temp[index++] = nums1[lindex++];
    }
    while (rindex < nums2Size) {
        temp[index++] = nums2[rindex++];
    }
    int mid = (nums1Size + nums2Size - 1) / 2;
    if ((nums1Size + nums2Size) % 2 == 0) {
        return (temp[mid] + temp[mid + 1]) * 1.0 / 2;
    }
    return temp[mid];
}

// 我们可以发现上面的代码有连个问题
// 1. 使用了大量的内存
// 2. 明明到了目的位置, 却还没有停止
// 所以下面的代码会考虑这个问题
/** 1. 停止的位置在哪?  若 nums1Size + nums2Size 为偶数, 则目标位置有两个 1, index = mid, 以及 lindex 和 rindex 中较小的那个数
 * 
 * 
*/
double findMedianSortedArrays_notbad(int* nums1, int nums1Size, int* nums2, int nums2Size){
    // 有一个为空
    if (nums1Size * nums2Size == 0) {
        int* temp = nums1;
        int sz = nums1Size;
        if (nums1Size == 0) {
            temp = nums2;
            sz = nums2Size;
        }
        int mid = (sz - 1) / 2;
        if (sz % 2 == 0) {
            return (temp[mid] + temp[mid + 1]) / 2.0;
        }
        return temp[mid];
    }
    // 都不为空
    int lindex = 0, rindex = 0, index = -1;
    int midIndex = (nums1Size + nums2Size - 1) / 2;
    int midValue = 0;
    while (lindex < nums1Size && rindex < nums2Size) {
        if (nums1[lindex] < nums2[rindex]) {
            midValue = nums1[lindex];
            ++lindex;
        } else {
            midValue = nums2[rindex];
            ++rindex;
        }
        if (++index == midIndex) {
            break;
        }
    }
    while (index < midIndex && lindex < nums1Size) {
         midValue = nums1[lindex];
         ++lindex;
          if (++index == midIndex) {
            break;
        }
    }
     while (index < midIndex && rindex < nums2Size) {
         midValue = nums2[rindex];
         ++rindex;
          if (++index == midIndex) {
            break;
        }
    }
    if ((nums1Size + nums2Size) % 2 != 0) {
        return midValue;
    }
    int other = 0;
    if (lindex < nums1Size && rindex < nums2Size) {
        if (nums1[lindex] < nums2[rindex]) {
            other = nums1[lindex];
        } else {
            other = nums2[rindex];
        }
    } else if (lindex == nums1Size) {
        other = nums2[rindex];
    } else {
        other = nums1[lindex];
    }
    return (midValue + other) / 2.0;
}


// 增加哨兵 减少算法实现复杂度
// 当指针指向数组最后一个元素时, 将指针指向 guard
double findMedianSortedArrays_no(int* nums1, int nums1Size, int* nums2, int nums2Size){
     // 有一个为空
    if (nums1Size * nums2Size == 0) {
        int* temp = nums1;
        int sz = nums1Size;
        if (nums1Size == 0) {
            temp = nums2;
            sz = nums2Size;
        }
        int mid = (sz - 1) / 2;
        if (sz % 2 == 0) {
            return (temp[mid] + temp[mid + 1]) / 2.0;
        }
        return temp[mid];
    }
    const int* p = nums1, *q = nums2;
    int midIndex = (nums1Size + nums2Size - 1) / 2;
    int index = -1;
    int midValue = 0;
    const int guard = 0x7fffffff;
    while (true) {
        if (*p < *q) {
            midValue = *p;
            if (p != &guard) {
                if (nums1 + nums1Size - 1 == p) {
                    p = &guard;
                } else {
                    ++p;
                }
            }
        } else {
            midValue = *q;
            if (q != &guard) {
                if (nums2 + nums2Size - 1 == q) {
                    q = &guard;
                } else {
                    ++q;
                }
            }
        }
        if (++index == midIndex) {
            break;
        }
    }
    if ((nums1Size + nums2Size) % 2 != 0) {
        return midValue;
    }
    int other = (*p > *q) ? *q : *p;
    return (midValue + other) / 2.0;
 }


// struct guardSafeArr {
//     public:
//         guardSafeArr(const int* arr, const int sz): begin(arr),current(arr),sz(sz) {}

//         guardSafeArr& operator++() {
//             if (current != &guard) {
//                 if (current == begin + sz - 1) {
//                     current = &guard;
//                 } else {
//                     ++current;
//                 }
//             }
//             return *this;
//         }

//         const int operator*() {
//             return *current;
//         }

//         const int* begin;
//         const int* current;
//         const int sz;
//         static const int guard ;

// };

// const int guardSafeArr::guard = 0x7fffffff;

// double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
//      // 有一个为空
//     if (nums1Size * nums2Size == 0) {
//         int* temp = nums1;
//         int sz = nums1Size;
//         if (nums1Size == 0) {
//             temp = nums2;
//             sz = nums2Size;
//         }
//         int mid = (sz - 1) / 2;
//         if (sz % 2 == 0) {
//             return (temp[mid] + temp[mid + 1]) / 2.0;
//         }
//         return temp[mid];
//     }
//     // const int* p = nums1, *q = nums2;
//     int midIndex = (nums1Size + nums2Size - 1) / 2;
//     int index = -1;
//     int midValue = 0;
//     // const int guard = 0x7fffffff;
//     guardSafeArr p(nums1, nums1Size);
//     guardSafeArr q(nums2, nums2Size);
//     while (true) {
//         if (*p < *q) {
//             midValue = *p;
//             ++p;
//         } else {
//             midValue = *q;
//             ++q;
//         }
//         if (++index == midIndex) {
//             break;
//         }
//     }
//     if ((nums1Size + nums2Size) % 2 != 0) {
//         return midValue;
//     }
//     int other = (*p > *q) ? *q : *p;
//     return (midValue + other) / 2.0;
//  }


// 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
// 看复杂度发现上面的集中实现方式的时间复杂度不满足要求为O(m+n), 看到 log 以及有序可想到二分查找
// 对两个数组分别进行二分
// 起始
// 迭代
// 终止

/**
 *   1. size_left = (m + n + 1) / 2; 保证左边的个数比右边的个数相等或者多一个
 *   2. i 数组一分割线右边第一个元素的下标,同时也代表分割线左边元素的个数
 *   3. j 数组二分割线右边第一个元素的下标,同时也代表分割线左边元素的个数
 *   4. 分割线左边的最大元素小于分割线右边最小元素
 *   5. 结果为分割线左边最大元素, 如果 m+n 为偶数则 结果为 左边最大元素和右边最小元素之和除以2
 * **/

// double findMedianSortedArrays_11(int* nums1, int nums1Size, int* nums2, int nums2Size){
//     if (nums2Size > nums1Size) {
//         return findMedianSortedArrays_11(nums2, nums2Size, nums1, nums1Size);
//     }
//     int total_left = (nums1Size + nums2Size + 1) / 2;
//     // left 
//     int left = 0;
//     int right = nums1Size;
//     while (left < right) {
//         // 记住 i的定义
//         int i = left + (right - left + 1) / 2;
//         int j = total_left - i;
//         if (nums1[i - 1] > nums2[j]) {
//             right = i - 1;
//         } else {
//             left = i;
//         }
//     }
//     int i = left;
//     int j = total_left - i;
//     int nums1LeftMax = (i == 0) ? 0x80000000:nums1[i - 1];
//     int nums1RightMin = (i == nums1Size) ? 0x7fffffff : nums2[i];

//     int nums2LeftMax = (j == 0) ? 0x80000000:nums2[j - 1];
//     int nums2RightMin = (j == nums2Size) ? 0x7fffffff : nums2[j];

//     if ((nums1Size + nums2Size) % 2 == 0) {
//         return std::max(nums1LeftMax, nums2LeftMax);
//     }
//     return (std::max(nums1LeftMax, nums2LeftMax) + std::min(nums1RightMin, nums2RightMin)) / 2.0;
// }

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};
// @lc code=end