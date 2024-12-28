/*
 * @lc app=leetcode.cn id=1366 lang=cpp
 * @lcpr version=30204
 *
 * [1366] 通过投票对团队排名
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
    string rankTeams(vector<string>& votes) {
        int cnt[26][26]{};
        for (int i = 0; i < votes.size(); i++) {
            for (int j = 0; j < votes[i].size(); j++) {
                cnt[votes[i][j] - 'A'][j]++;
            }
        }
        string ans = votes[0];
        sort(ans.begin(), ans.end(), [&](char a, char b) {
            for (int i = 0; i < 26; i++) {
                if (cnt[a - 'A'][i] != cnt[b - 'A'][i]) {
                    return cnt[a - 'A'][i] > cnt[b - 'A'][i];
                }
            }
            return a < b;
        });
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["ABC","ACB","ABC","ACB","ACB"]\n
// @lcpr case=end

// @lcpr case=start
// ["WXYZ","XYZW"]\n
// @lcpr case=end

// @lcpr case=start
// ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]\n
// @lcpr case=end

 */

