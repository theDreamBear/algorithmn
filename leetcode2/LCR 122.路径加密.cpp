/*
 * @lc app=leetcode.cn id=LCR 122 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 122] 路径加密
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
    string pathEncryption(string path) {
        transform(path.begin(), path.end(), path.begin(), [](char c) {
            return c == '.' ? ' ' : c;
        });
        return path;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a.aef.qerf.bb"\n
// @lcpr case=end

 */

