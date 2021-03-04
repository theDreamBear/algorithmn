/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
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
#include <numeric>
//#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    void getAll(int val, vector<int>& ys) {
        ys.push_back(val);
        for (int i = 2; i * i <= val; ++i) {
            if (val % i == 0) {
                ys.push_back(i);
                if (i * i != val) {
                    ys.push_back(val / i);
                }
            }
        }
    }

    bool hasGroupsSizeX1(vector<int>& deck) {
        unordered_map<int, int> hash;
        for (auto v : deck) {
            ++hash[v];
        }
        int min_times = INT_MAX;
        for (auto& kv : hash) {
            if (kv.second < 2) {
                return false;
            }
            if (min_times > kv.second) {
                min_times = kv.second;
            }
        }
        
        vector<int> yushu;
        getAll(min_times, yushu);

        for (auto v : yushu) {
            if (deck.size() % v != 0) {
                continue;
            }
            int t = 0;
            for (auto& kv : hash) {
                if (kv.second % v != 0) {
                    break;
                }
                ++t;
            }
            if (t == hash.size()) {
                return true;
            }
        }
        return false;
       
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> hash;
        for (auto v : deck) {
            ++hash[v];
        }
        int g = 0;
        for (auto& kv : hash) {
            if (g) {
                g = gcd(g, kv.second);
            } else {
                g = kv.second;
            }
        }
        return g > 1;
    }
};
// @lc code=end

int main() {
    vector<int> data;
    Solution{}.getAll(100, data);
    for (auto v : data) {
        cout << v << endl;
    }
}