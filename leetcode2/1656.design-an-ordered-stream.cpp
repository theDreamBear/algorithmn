/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 * @lcpr version=30204
 *
 * [1656] 设计有序流
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
#include <string>
// @lcpr-template-end
// @lc code=start
class OrderedStream {
public:
    vector<string> data;
    int ptr = 1;
    OrderedStream(int n) {
        data.resize(n + 1);
    }
    
    vector<string> insert(int idKey, string value) {
        data[idKey] = value;
        vector<string> ans;
        if (ptr == idKey) {
            int i = ptr;
            while (i < data.size() and data[i] != "") {
                ans.push_back(data[i++]);
            }
            ptr = i;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end



