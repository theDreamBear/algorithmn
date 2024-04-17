/*
 * @lc app=leetcode.cn id=LCR 033 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 033] 字母异位词分组
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
#include <set>
#include <map>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        map<string, vector<string>> ct;
        for (auto& str : strs) {
            auto key = str;
            sort(key.begin(), key.end());
            ct[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& [key, ss] : ct) {
            vector<string> one;
            for (auto& value : ss) {
                one.push_back(value);
            }
            ans.push_back(move(one));
        }
        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, string> reflect;
        for (auto& str : strs) {
            auto key = str;
            sort(key.begin(), key.end());
            reflect[str] = key;
        }
        sort(strs.begin(), strs.end(), [&](const string& lhs, const string& rhs) {\
            return reflect[lhs] < reflect[rhs];
        });
        vector<vector<string>> ans;
        vector<string> one{strs[0]};
        for (int i = 1; i < strs.size(); i++) {
            if (reflect[one.back()] == reflect[strs[i]]) {
                one.push_back(strs[i]);
            } else {
                ans.push_back(move(one));
                one.clear();
                one.push_back(strs[i]);
            }
        }
        ans.push_back(move(one));
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */

