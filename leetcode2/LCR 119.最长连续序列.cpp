/*
 * @lc app=leetcode.cn id=LCR 119 lang=cpp
 * @lcpr version=30121
 *
 * [LCR 119] 最长连续序列
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int longestConsecutive_sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int max_len = 0;
        for (auto v : nums) {
            int len = 1;
            int pre = v - 1;
            if (mp.count(pre)) {
                len += mp[pre];
            }
            if (len > max_len) {
                max_len = len;
            }
            mp[v] = len;
        }
        return max_len;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());
        int max_len = 0;
        for (auto v : nums) {
            // 这个地方有点意思
            if (!mp.count(v - 1)) {
                int next = v + 1;
                int len = 1;
                while (mp.count(next)) {
                    len++;
                    ++next;
                }
                if (len > max_len) {
                    max_len = len;
                }
            }
        }
        return max_len;
    }

    class UF {
     public:
        unordered_map<int, int> data;
        vector<int> parent;
        vector<int> len;
        int max_len = 0;

        UF(int size):parent(size), len(size) {
            iota(parent.begin(), parent.end(), 0);
            fill(len.begin(), len.end(), 1);
        }

        int find(int v) {
            if (parent[v] == v) {
                return v;
            }
            return parent[v] = find(parent[v]);
        }

        void merge(int nowIndex, int nowValue) {
            if (data.count(nowValue)) {
                return;
            }
            if (data.count(nowValue - 1)) {
                int preIndex = data[nowValue - 1];
                int prep = find(preIndex);
                len[nowIndex] += len[prep];
                parent[prep] = nowIndex;
            }
            if (data.count(nowValue + 1)) {
                int nextIndex = data[nowValue + 1];
                int np = find(nextIndex);
                len[np] += len[nowIndex];
                parent[nowIndex] = np;
                if (len[np] > max_len) {
                    max_len = len[np];
                }
            }
            if (len[nowIndex] > max_len) {
                max_len = len[nowIndex];
            }
            data[nowValue] = nowIndex;
        }

        int ans() const {
            return max_len;
        }

    };

    int longestConsecutive_UF(vector<int>& nums) {
        UF uf(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            uf.merge(i, nums[i]);
        }
        return uf.ans();
    }

};
// @lc code=end



/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

 */

