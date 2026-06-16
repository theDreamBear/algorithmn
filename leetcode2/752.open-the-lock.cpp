/*
 * @lc app=leetcode.cn id=752 lang=cpp
 * @lcpr version=30204
 *
 * [752] 打开转盘锁
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
    int openLock(vector<string>& deadends, string target) {
        //string sec = "0000";
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;
        queue<string> q;
        q.push("0000");
        dead.insert("0000");
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int t = 0; t < sz; t++) {
                auto str = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    string news = str;
                    news[i] = (str[i] - '0' + 1) % 10 + '0';
                    if (news == target) return ans;
                    if (!dead.count(news)) {
                        dead.insert(news);
                        q.push(news);
                    }
                    news[i] = (str[i] - '0' + 9) % 10 + '0';
                    if (news == target) return ans;
                    if (!dead.count(news)) {
                        dead.insert(news);
                        q.push(news);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["0201","0101","0102","1212","2002"]\n"0202"\n
// @lcpr case=end

// @lcpr case=start
// ["8888"]\n"0009"\n
// @lcpr case=end

// @lcpr case=start
// ["8887","8889","8878","8898","8788","8988","7888","9888"]\n"8888"\n
// @lcpr case=end

 */

