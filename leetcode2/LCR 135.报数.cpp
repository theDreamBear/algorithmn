/*
 * @lc app=leetcode.cn id=LCR 135 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 135] 报数
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
    int len(int v) {
        return to_string(v).size();
    }

    vector<int> countNumbers1(int cnt) {
        vector<int> ans;
        int i = 1;
        while (true) {
            if (len(i) > cnt) {
                break;
            }
            ans.push_back(i++);
        }
        return ans;
    }

    vector<int> countNumbers(int cnt) {
        vector<int> ans(pow(10, cnt) - 1);
        int i = 1;
        int next = 10;
        int ll = 1;
        while (true) {
            if (i == next) {
                next *= 10;
                if (++ll > cnt) {
                    break;
                }
            }
            ans[i - 1] = i;
            i++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

 */

