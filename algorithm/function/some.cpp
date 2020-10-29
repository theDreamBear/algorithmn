
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <mydef.h>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
 public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;

        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     auto pos = hashmap.find(target - nums[i]);
        //     if (pos != hashmap.end() && (*pos).second > i) {
        //         return {int(i), (*pos).second};
        //     }
        // }
        for (auto [id, v] : rangeVec(nums)) {
            hashmap[v] = id;
        }
        // for (auto [id, v] : rangeVec(nums)) {
        //     auto pos = hashmap.find(target - v);
        //     if (pos != hashmap.end() && pos->second > id) {
        //         return {id, pos->second};
        //     }
        // }
        // return vector<int>{};

        vector<int> res;
        const auto& vec = rangeVec(nums);
        accumulate(vec.begin(), vec.end(), res,
                   [&](vector<int>& container, pair<int, int> p) {
                       int id = p.first;
                       int v = p.second;
                       auto pos = hashmap.find(target - v);
                       if (pos != hashmap.end() && pos->second > id) {
                           if (container.empty()) {
                               container.push_back(id);
                               container.push_back(pos->second);
                           }
                       }
                       return container;
                   });
        if (res.size() > 0) {
            return res;
        }
        return {};
    }
};
// @lc code=end

void myRotate(vector<int>& nums, int k) {
    int first = 0, last = nums.size();
    k = k % last;
    int mid = k;
    while (mid < last) {
        swap(nums[first], nums[mid]);
        ++first;
        ++mid;
    }
    if (first < k) {
        mid = k;
        while (mid < last) {
            swap(nums[first], nums[mid]);
            ++first;
            ++mid;
        }
    }
}

struct Goods {
    Goods(string s) {
        cout << "GOODS" << endl;
        this->s = s;
    }
    string s;
};

int main() {
    // vector<int> nums = {1, 2, 4, 5};

    // for (auto x : range(10)) {
    //     cout << x << endl;
    // }

    // for (auto [idx, v] : rangeVec(nums)) {
    //     cout << idx << " " << v << endl;
    // }

    vector<Goods> good = {Goods("hello"), Goods("world")};
    for (auto& [idx, v] : rangeVec(good)) {
        cout << idx << " " << v.s << endl;
    }

    auto fib = [a = 0, b = 1]() mutable {
    	a = exchange(b, a + b);
    	return a;
    };

    for (auto idx : range(10)) {
        cout << fib() << endl;
    }
}