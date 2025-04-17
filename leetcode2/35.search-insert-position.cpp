/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=30204
 *
 * [35] 搜索插入位置
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
template<typename T>
int findInsertPos(vector<T>& arr, int v) {
    int low = 0, high = arr.size() - 1;
    while (low + 1 < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < v) {
            low = mid;
        } else {
            high = mid;
        }
    }
    if (arr[low] >= v) {
        return low;
    }
    if (arr[high] >= v) {
        return high;
    }
    return high + 1;
}

template<typename T>
int findFirstPos(vector<T>& arr, int v) {
    int low = 0, high = arr.size() - 1;
    while (low + 1 < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < v) {
            low = mid;
        } else {
            high = mid;
        }
    }
    if (arr[low] == v) {
        return low;
    }
    if (arr[high] == v) {
        return high;
    }
    return -1;
}

template<typename T>
int findLastPos(vector<T>& arr, int v) {
    int low = 0, high = arr.size() - 1;
    while (low + 1 < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > v) {
            high = mid;
        } else {
            low = mid;
        }
    }
    if (arr[high] == v) {
        return high;
    }
    if (arr[low] == v) {
        return low;
    }
    return -1;
}


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return findInsertPos(nums, target);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */

