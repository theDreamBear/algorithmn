/*
 * @lc app=leetcode.cn id=面试题 10.05 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 10.05] 稀疏数组搜索
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
    // 减而治之
    int findString(vector<string>& words, string s) {
        int low = 0, high = words.size() - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            while (mid >= low and words[mid] == "") mid--;
            if (mid < low) {
                low =  low + (high - low) / 2 + 1;
                continue;
            }
            if (words[mid] >= s) {
                high = mid;
            } else {
                low = low + (high - low) / 2 + 1;
            } 
        }
        if (words[low] == s) return low;
        if (words[high] == s) return high;
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""]\n"ta"\n
// @lcpr case=end

// @lcpr case=start
// ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""]\n"ball"\n
// @lcpr case=end

 */

