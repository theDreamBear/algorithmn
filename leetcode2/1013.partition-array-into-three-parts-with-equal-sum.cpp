/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 * @lcpr version=30204
 *
 * [1013] 将数组分成和相等的三个部分
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
class Solution1 {
public:
    // tot 区间 + 0区间
    bool canThreePartsEqualSum(vector<int>& arr) {
        int tot = accumulate(arr.begin(), arr.end(), 0);
        if (tot % 3 != 0) return false;
        tot /= 3;
        int sum = 0, p = 0;
        int i = 0;
        for (; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == tot) {
                p++;
                sum = 0;
                if (p == 3) break;
            }
        }
        return p == 3;
    }
};

class Solution {
public:
    // tot 区间 + 0区间
    bool canThreePartsEqualSum(vector<int>& arr) {
        int tot = accumulate(arr.begin(), arr.end(), 0);
        if (tot % 3 != 0) return false;
        tot /= 3;
        int sum = 0, p = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == tot) {
                sum = 0;
                if (++p == 2 and i + 1 < arr.size()) return true;
            }
        }
        return false;
        // // sum和tot异号,导致后面的sum 可以和前面的区间合并成0区间
        // if (sum * tot < 0 and sum % tot == 0) return p >= 3;
        // return sum == 0 and p >= 3;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,2,1,-6,6,-7,9,1,2,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,1,-6,6,7,9,-1,2,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,6,5,-2,2,5,1,-9,4]\n
// @lcpr case=end

 */

