/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
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

    bool lemonadeChange1(vector<int>& bills) {
        deque<int> change;
        for (auto val : bills) {
            if (val == 5) {
                change.push_front(5);
            } else {
                if (change.empty()) {
                    return false;
                }
                if (val == 10) {
                    if (change.front() == 5) {
                        change.pop_front();
                        change.push_back(10);
                    } else {
                        return false;
                    }
                } else {
                    if (change.front() == 5 && change.back() == 10) {
                        change.pop_front();
                        change.pop_back();
                    } else if (change.front() == 5 && change.size() >= 3) {
                        change.pop_front();
                        change.pop_front();
                        change.pop_front();
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool lemonadeChange(vector<int>& bills) {
        int cf = 0, ct = 0;
        for (auto val : bills) {
            if (val == 5) {
                ++cf;
            } else if (val == 10) {
                if(cf > 0) {
                    --cf;
                    ++ct;
                } else {
                    return false;
                }
            } else if (val == 20) {
                if (cf >= 1 && ct >= 1) {
                    --cf;
                    --ct;
                } else if (cf >= 3) {
                    cf -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

