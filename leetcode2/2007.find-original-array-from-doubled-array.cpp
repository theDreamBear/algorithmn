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

    vector<int> findOriginalArray3(vector<int>& changed) {
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

    vector<int> findOriginalArray2(vector<int>& changed) {
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

    vector<int> findOriginalArray4(vector<int>& changed) {
        unordered_map<int, int> cnt;
        for (int x : changed) {
            cnt[x]++;
        }

        // 单独处理 0
        int cnt0 = cnt[0];
        if (cnt0 % 2) {
            return {};
        }
        cnt.erase(0);
        vector<int> ans(cnt0 / 2);

        for (auto [key, _] : cnt) {
            int x = key;
            // 如果 x/2 在 cnt 中，则跳过
            if (x % 2 == 0 && cnt.contains(x / 2)) {
                continue;
            }
            // 把 x, 2x, 4x, 8x, ... 全部配对
            while (cnt.contains(x)) {
                // 每次循环，把 cnt_x 个 x 和 cnt_x 个 2x 配对
                int cnt_x = cnt[x];
                // 无法配对，至少要有 cnt_x 个 2x
                if (cnt_x > cnt[x * 2]) {
                    return {};
                }
                ans.insert(ans.end(), cnt_x, x);
                if (cnt_x < cnt[x * 2]) {
                    // 还剩下一些 2x
                    cnt[x * 2] -= cnt_x;
                    x *= 2;
                } else {
                    x *= 4;
                }
            }
        }
        return ans;
    }

    // 空间换时间
    vector<int> findOriginalArray(vector<int>& changed) {
        int counts[100001]{};
        for(int x:changed) ++counts[x];
        if(counts[0]&1) return {};
        vector<int> ans(counts[0]>>1,0);
        for(int i=1;i<100001;++i){
            if(counts[i]<0){
                return {};
            }else if(counts[i]>0){
                if(2*i>100000) return {};
                counts[2*i]-=counts[i];
                while(counts[i]--){
                    ans.push_back(i);
                }
            }
        }
        return ans;
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

