/*
 * @lc app=leetcode.cn id=LCR 060 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 060] 前 K 个高频元素
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
class Solution {
public:

    using value_type = pair<int, int>;
    class Heap {
    public:
        int capacity;
        function<bool(value_type, value_type)> cmp;
        vector<value_type> data;
        int size;

        Heap(int capacity, function<bool(value_type, value_type)> cmp) :capacity(capacity), cmp(cmp), data(capacity), size(0) {}

        void _heap_up(int i) {
            auto v = data[i];
            while ((i - 1) >> 1 >= 0) {
                int p = (i - 1) >> 1;
                if (!cmp(v, data[p])) {
                    break;
                }
                data[i] = data[p];
                i = p;
            }
            data[i] = v;
        }

        void _heap_down(int i = 0) {
            auto v = data[i];
            while (2 * i + 1 < size) {
                int mm = 2 * i + 1;
                int ma = mm + 1;
                if (ma < size and cmp(data[ma], data[mm])) {
                    mm = ma;
                }
                if (!cmp(data[mm], v)) {
                    break;
                }
                data[i] = data[mm];
                i = mm;
            }
            data[i] = v;
        }

        void push(const value_type& v) {
            if (size >= capacity and !cmp(data[0], v)) {
                return;
            }
            if (size >= capacity and cmp(data[0], v)) {
                swap(data[0], data[size - 1]);
                --size;
                _heap_down();

            }
            data[size] = v;
            _heap_up(size);
            size++;
        }

        value_type pop() {
            auto v = data[0];
            swap(data[0], data[size - 1]);
            --size;
            _heap_down();
            return v;
        }

        bool empty() {
            return size == 0;
        }
    };

    vector<int> topKFrequent1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ct = 0, v = 0;
        auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.first < rhs.first;
            };
        Heap pq(k, cmp);
        for (auto val : nums) {
            if (ct == 0 || (ct > 0 and v == val)) {
                v = val;
                ++ct;
            }
            else {
                pq.push({ ct, v });
                v = val;
                ct = 1;
            }
        }
        pq.push({ ct, v });
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.pop().second);
        }
        return ans;
    }

    vector<int> topKFrequent2(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ct = 0, v = 0;
        auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.first > rhs.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
        for (auto val : nums) {
            if (ct == 0 || (ct > 0 and v == val)) {
                v = val;
                ++ct;
            }
            else {
                if (pq.size() < k) {
                    pq.push({ ct, v });
                }
                else if (pq.size() >= k and pq.top().first < ct) {
                    pq.pop();
                    pq.push({ ct, v });
                }
                v = val;
                ct = 1;
            }
        }
        if (pq.size() < k) {
            pq.push({ ct, v });
        }
        else if (pq.size() >= k and pq.top().first < ct) {
            pq.pop();
            pq.push({ ct, v });
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ct;
        for (auto v : nums) {
            ct[v]++;
        }
        vector<pair<int, int>> data;
        for (auto& kv : ct) {
            data.push_back({kv.second, kv.first});
        }
        nth_element(data.begin(), data.begin() + k - 1, data.end(), greater<>{});
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(data[i].second);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

