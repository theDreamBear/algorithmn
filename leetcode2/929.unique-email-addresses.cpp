/*
 * @lc app=leetcode.cn id=929 lang=cpp
 * @lcpr version=30204
 *
 * [929] 独特的电子邮件地址
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
    int numUniqueEmails1(vector<string>& emails) {
        unordered_set<string> uniq;
        for (auto& s: emails) {
            int p = s.find("@");
            string base = s.substr(0, p);
            string domain = s.substr(p + 1);
            int q = base.find('+');
            if (q != string::npos) {
                base = base.substr(0, q);
            }
            if (base.find('.') != string::npos) {
                string nb;
                for (auto ch: base) {
                    if (ch != '.') nb += ch;
                }
                base = nb;
            }
            uniq.insert(base + "@" + domain);
        }
        return uniq.size();
    }

    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniq;
        for (auto& s: emails) {
            string nb;
            for (auto ch: s) {
                if (ch == '+' or ch == '@') {
                    break;
                }
                if (ch != '.') nb += ch;
            }
            uniq.emplace(nb + s.substr(s.find('@')));
        }
        return uniq.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]\n
// @lcpr case=end

// @lcpr case=start
// ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]\n
// @lcpr case=end

 */

