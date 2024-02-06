/*
 * @lc app=leetcode.cn id=LCR 120 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 120] 寻找文件副本
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
    int findRepeatDocument(vector<int>& documents) {
        sort(documents.begin(), documents.end());
        for (int i = 1; i < documents.size(); i++) {
            if (documents[i] == documents[i - 1]) {
                return documents[i];
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2, 5, 3, 0, 5, 0]\n
// @lcpr case=end

 */

