/*
 * @lc app=leetcode.cn id=2007 lang=cpp
 * @lcpr version=30122
 *
 * [2007] 从双倍数组中还原原数组
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
#include <map>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> findOriginalArray1(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) {
            return {};
        }
        map<int, int> ct;
        for (auto v : changed) {
            ct[v]++;
        }
        vector<pair<int, int>> nc;
        for (auto& [k, v] : ct) {
            nc.emplace_back(k, v);
        }
        vector<int> ans;
        for (auto& [v, t]: nc) {
            if (ct.find(v) == ct.end()) {
                continue;
            }
            t = ct[v];
            if (v != 0) {
                auto dit = ct.find(2 * v);
                if (dit == ct.end()) {
                    return {};
                }
                if (dit->second < t) {
                    return {};
                }
                dit->second -= t;
                if (dit->second == 0) {
                    ct.erase(dit);
                }
            } else if (t % 2 != 0) {
                return {};
            } else {
                t >>= 1;
            }
            for (int i = 0; i < t; i++) {
                ans.push_back(v);
            }
            ct.erase(v);
            if (ans.size() * 2 == n) {
                break;
            }
        }
        return ans;
    }

    vector<int> findOriginalArray2(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) {
            return {};
        }
        map<int, int> ct;
        for (auto v : changed) {
            ct[v]++;
        }
        vector<int> ans;
        for (auto& [v, t]: ct) {
            if (t <= 0) {
                continue;
            }
            if (v != 0) {
                if (!ct.count(v << 1)) {
                    break;
                }
                if ((ct[v << 1] -= t) < 0) {
                    break;
                }
                for (int i = 0; i < t; i++) {
                    ans.push_back(v);
                }
            } else {
                if (t % 2 != 0) {
                    break;
                }
                for (int i = 0; i < t >> 1; i++) {
                    ans.push_back(v);
                }
            }
        }
        return ans.size() == (n >> 1) ? ans : vector<int>{};
    }

    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) {
            return {};
        }
        unordered_map<int, int> ct;
        for (auto v : changed) {
            ct[v]++;
        }
        vector<int> ans;
        sort(changed.begin(), changed.end());
        for (auto v : changed) {
            if (ct[v] <= 0) {
                continue;
            }
            if (ct.count(v << 1) and ct[v << 1] > 0) {
               if (v != 0) {
                    ans.push_back(v);
                    ct[v]--;
                    ct[v << 1]--;
                } else {
                    if (ct[0] % 2 == 0) {
                        ans.push_back(0);
                    } else {
                        break;
                    }
                    ct[0] -= 2;
                }
            } else {
                break;
            }
        }
        return ans.size() == (n >> 1) ? ans : vector<int>{};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4,2,6,8]\n
// @lcpr case=end

// @lcpr case=start
// [6,3,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

