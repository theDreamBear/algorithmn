/*
 * @lc app=leetcode.cn id=2502 lang=cpp
 * @lcpr version=30204
 *
 * [2502] 设计内存分配器
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
class Allocator {
public:
    vector<int> memo;
    unordered_map<int, vector<int>> outer;
    Allocator(int n): memo(n) {}
    
    int allocate(int size, int mID) {
        int len = 0;   
        for (int i = 0; i < memo.size(); i++) {
            if (memo[i] == 0) {
                if (++len == size) {
                    for (int j = i - len + 1; j <= i; j++) {
                        memo[j] = mID;
                    }
                    outer[mID].push_back(i - len + 1);
                    return i - len + 1;
                }
            } else {
                len = 0;
            }
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        int sz = 0;
        if (!outer.contains(mID)) {
            return 0;
        }
        for (auto& start: outer[mID]) {
            while (start < memo.size() and memo[start] == mID) {
                sz++;
                memo[start++] = 0;
            }
        }
        return sz;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
// @lc code=end



