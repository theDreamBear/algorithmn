/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
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
    /*
        暴力解法O(n);
    */
    int search1(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    /*
        二分
    */
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        if (nums.size() == 2) {
            if (nums[low] == target) {
                return low;
            }
            if (nums[high] == target) {
                return high;
            }
            return -1;
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }   
        }
        return -1;
    }
};
// @lc code=end

int main() {
    vector<int> data = {4, 5, 6, 7, 0, 1 ,2};
    cout << Solution{}.search(data, 0);
}
