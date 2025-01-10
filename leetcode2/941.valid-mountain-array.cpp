/*
 * @lc app=leetcode.cn id=941 lang=cpp
 * @lcpr version=30204
 *
 * [941] 有效的山脉数组
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
    bool validMountainArray1(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int x = 0;
        for (; x + 1 < arr.size(); x++) {
            if (arr[x] == arr[x + 1]) return false;
            else if (arr[x] > arr[x + 1]) break;
        }
        if (x + 1 == arr.size() or x == 0) return false;
        for (; x + 1 < arr.size(); x++) {
            if (arr[x] == arr[x + 1]) return false;
            else if (arr[x] < arr[x + 1]) return false;
        }
        return true;
    }

    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int i = 0;
        while (i + 1 < arr.size() and arr[i] < arr[i + 1]) i++;
        if (i == 0 or i + 1 == arr.size()) return false;
        while (i + 1 < arr.size() and arr[i] > arr[i + 1]) i++;
        return i + 1 == arr.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,5,5]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,2,1]\n
// @lcpr case=end

 */

