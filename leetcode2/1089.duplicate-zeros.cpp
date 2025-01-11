/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 * @lcpr version=30204
 *
 * [1089] 复写零
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
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        // [0, i) 保存的
        // [0, top) 对应的需要的容量
        int i = 0, top = 0;
        for (; top < n; i++) {
            if (arr[i] == 0) {
                top += 2;
            } else {
                top++;
            }
        }
        i--;
        top--;
        if (top == n) {
            arr[n - 1] = arr[i--];
            top = n - 2;
        }
        while (i >= 0) {
            if (arr[i] != 0) {
                arr[top--] = arr[i--];
            } else {
                arr[top--] = 0;
                arr[top--] = 0;
                i--;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,2,3,0,4,5,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

