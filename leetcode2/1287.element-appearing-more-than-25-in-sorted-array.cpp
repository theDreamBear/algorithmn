/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 * @lcpr version=30204
 *
 * [1287] 有序数组中出现次数超过25%的元素
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
    int findSpecialInteger1(vector<int>& arr) {
        unordered_map<int, int> freq;
        int n = arr.size();
        int need = n / 4;
        for (auto v: arr) {
            if (++freq[v] > need) return v;
        }
        return 0;
    }

    int findSpecialInteger(vector<int>& arr) {
        // 分组循环
        int n = arr.size();
        int need = n / 4;
        for (int i = 0; i < n;) {
            int start = i++;
            while (i < n and arr[i] == arr[start]) i++;
            if (i - start > need) return arr[start];
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,6,6,6,6,7,10]\n
// @lcpr case=end

 */

