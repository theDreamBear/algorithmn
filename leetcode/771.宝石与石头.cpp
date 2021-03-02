/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
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

using namespace std;

// @lc code=start
class Solution {
public:
    struct mymap {
        vector<int> _data;
        
        mymap():_data(52){};

        int index(char c) {
            if (c > 'Z') {
                return c - 'a' + 26;
            } else {
                return c - 'A';
            }
        }

        void add(char c) {
            _data[index(c)] = 1;
        }

        bool contains(char c) {
            return _data[index(c)] == 1;
        }
    };

    int numJewelsInStones(string jewels, string stones) {
        mymap hash;
        for (auto c : jewels) {
            hash.add(c);
        }
        int ans = 0;
        for (auto c : stones) {
            if (hash.contains(c)) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

