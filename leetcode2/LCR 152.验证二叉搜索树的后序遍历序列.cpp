/*
 * @lc app=leetcode.cn id=LCR 152 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 152] 验证二叉搜索树的后序遍历序列
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
    bool canMakeTree(const vector<int>& inorder, const vector<int>& postorder, int l1, int h1, int l2, int h2) {
        if (l1 > h1 and l2 > h2) {
            return true;
        }
        if (l1 > h1 or l2 > h2 or h1 - l1 != h2 - l2) {
            return false;
        }
        int mid = l1;
        while (mid <= h1 and inorder[mid] != postorder[h2]) {
            mid++;
        }
        if (mid > h1) {
            return false;
        }
        int sz = mid - l1;
        return canMakeTree(inorder, postorder, l1, mid - 1, l2, l2 + sz - 1) and
               canMakeTree(inorder, postorder, mid + 1, h1, l2 + sz, h2 - 1);
    }

    bool verifyTreeOrder(vector<int>& postorder) {
        if (postorder.size() <= 1) {
            return true;
        }
        vector<int> inorder = postorder;
        sort(inorder.begin(), inorder.end());
        return canMakeTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,9,6,5,8]\n
// @lcpr case=end

// @lcpr case=start
// [4,6,5,9,8]\n
// @lcpr case=end

 */

