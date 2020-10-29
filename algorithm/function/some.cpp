#include <mydef.h>

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
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

int main() {
    Solution s;
    vector<int> nums = {1, 2, 4, 5};
    auto x = s.twoSum(nums, 7);
    if (x.size() > 0) {
        cout << x[0] << " " << x[1] << endl;
    }
    int v;
    rotate(nums.begin(), nums.begin() + 2, nums.end());
    for (auto& x : nums) {
        cout << x << endl;
    }
}