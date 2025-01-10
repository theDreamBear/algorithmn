/*
 * @lc app=leetcode.cn id=989 lang=cpp
 * @lcpr version=30204
 *
 * [989] 数组形式的整数加法
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
    vector<int> addToArrayForm1(vector<int>& num, int k) {
        int carry = 0;
        vector<int> add;
        string ks = to_string(k);
        for (auto ch: ks) {
            add.push_back(ch - '0');
        }
        if (add.size() > num.size()) swap(num, add);
        for (int i = num.size() - 1, j = add.size() - 1; i >= 0; i--, j--) {
            int x = num[i] + (j >= 0 ? add[j] : 0) + carry;
            num[i] = x % 10;
            carry = x / 10;
            k /= 10;
        }
        if (carry) {
            num.insert(num.begin(), 1);
        }
        return num;
    }

    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        for (int i = num.size() - 1; i >= 0; i--) {
            int x = num[i] + k % 10;
            k /= 10;
            if (x >= 10) {
                k++;
                x -= 10;
            }
            res.push_back(x);
        }
        for (; k; k/=10) res.push_back(k % 10);
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,0,0]\n34\n
// @lcpr case=end

// @lcpr case=start
// [2,7,4]\n181\n
// @lcpr case=end

// @lcpr case=start
// [2,1,5]\n806\n
// @lcpr case=end

 */

