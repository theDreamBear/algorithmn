/*
 * @lc app=leetcode.cn id=2241 lang=cpp
 * @lcpr version=30204
 *
 * [2241] 设计一个 ATM 机器
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
class ATM {
public:
    int cnt[5]{};
    int ref[5] = {20, 50, 100, 200, 500};
    //unordered_map<int, int> to;
    ATM() {
        // to[20] = 0;
        // to[50] = 1;
        // to[100] = 2;
        // to[200] = 3;
        // to[500] = 4;
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++) {
            cnt[i]+= banknotesCount[i];
        } 
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5);
        auto can = [&](int left) {
            for (int i = 4; i >= 0 and left > 0; i--) {
                if (cnt[i]) {
                    int x = min(cnt[i], left / ref[i]);
                    left = left - x * ref[i];
                    ans[i] = x;
                }
            }
            return left == 0;
        };
        if (!can(amount)) return {-1};
        for (int i = 0; i < 5; i++) cnt[i] -= ans[i];
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
// @lc code=end



/*
// @lcpr case=start
// ["ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"][[], [[0,0,1,2,1]], [600], [[0,1,0,1,1]], [600], [550]]\n
// @lcpr case=end

 */

