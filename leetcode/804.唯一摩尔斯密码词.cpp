/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    string hash[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> ans;
        for (const string& str : words) {
            string temp;
            for (auto c : str) {
                temp += hash[c - 'a'];
            }
            if (ans.count(temp) == 0) {
                ans.insert(temp);
            }
        }
        return ans.size();
    }
};
// @lc code=end

