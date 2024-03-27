/*
 * @lc app=leetcode.cn id=LCR 069 lang=cpp
 * @lcpr version=30120
 *
 * [LCR 069] 山脉数组的峰顶索引
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray_n(vector<int>& arr) {
        for (int i = 1; i + 1 < arr.size(); i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                return i;
            }
        }
        return -1;
    }

    int peakIndexInMountainArray1(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (mid > 0 and mid < arr.size() - 1) {
                if (arr[mid] > arr[mid - 1]) {
                    if (arr[mid] > arr[mid + 1]) {
                        return mid;
                    } else {
                        low = mid;
                    }
                } else {
                    high = mid;
                }
            } else {
                break;
            }
        }
        if (low > 0 and low < arr.size() - 1) {
            if (arr[low] > arr[low - 1] and arr[low] > arr[low + 1]) {
                return low;
            }
        }
        return high;
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (mid > 0 and mid < arr.size() - 1) {
                if (arr[mid] > arr[mid - 1]) {
                    if (arr[mid] > arr[mid + 1]) {
                        return mid;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    high = mid - 1;
                }
            } else if (mid == 0) {
                low++;
            } else if (high == arr.size() - 1) {
                high--;
            }
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,10,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1]\n
// @lcpr case=end

// @lcpr case=start
// [24,69,100,99,79,78,67,36,26,19]\n
// @lcpr case=end

 */

