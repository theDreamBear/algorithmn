/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        ans.reserve(strs.size());
        unordered_map <string, vector<string>*> hashmap;
        for (auto& str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            if (hashmap.count(temp) == 0) {
                ans.emplace_back();
                // vector 在扩张的时候,可能会导致以前存的指针失效, 故需要预设capacity
                hashmap[temp] = &(ans.back());
            }
            hashmap[temp]->emplace_back(str);
        }
        return ans;
    }

    // 字母计数 再 hash 也可
};
// @lc code=end

int main() {
    vector<string> vec = {"eat", "tea", "tan", "ate", "nat", "bat"};
    hash<string> haser;
    auto ans = Solution{}.groupAnagrams(vec);
}