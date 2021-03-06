/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
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
class RecentCounter {
public:
    RecentCounter() {
    }
    
    /*
        lower_bound 在递增数组是代表大于等于
    */
    int ping1(int t) {
        if (records.empty()) {
             records.push_back(t);
            return 1;
        }
        records.push_back(t);
        auto pos = lower_bound(records.begin(), records.end(), t - 3000);
        return records.end() - pos;
    }

    int ping(int t) {
        if (re.empty()) {
            re.push(t);
            return 1;
        }
        re.push(t);
        while (re.front() < t - 3000){
            re.pop();
        }
        return re.size();
    }

private:
    vector<int> records;
    queue<int> re;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

