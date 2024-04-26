/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30122
 *
 * [416] 分割等和子集
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
#include <numeric>
#include <vector>
// @lcpr-template-end
// @lc code=start
class null_param {
};
template<typename Sig, class F>
class memoize_helper;

template<typename R, typename... Args, class F>
class memoize_helper<R(Args...), F> {
private:
    using function_type = F;
    using args_tuple_type = tuple<Args...>;

    function_type f;
    mutable map<args_tuple_type, R> cache;

public:
    template<class Function>
    memoize_helper(Function &&f, null_param) : f(std::forward<Function>(f)) {}

    memoize_helper(const memoize_helper &other) : f(other.f) {}

    template<class ...InnerArgs>
    R operator()(InnerArgs &&... args) const {
        auto args_tuple = make_tuple(std::forward<InnerArgs>(args)...);
        auto it = cache.find(args_tuple);
        if (it != cache.end()) {
            return it->second;
        }
        return cache[args_tuple] = f(*this, std::forward<InnerArgs>(args)...);
    }
};

template<class Sig, class F>
memoize_helper<Sig, std::decay_t<F>> cache(F &&f) {
    return memoize_helper<Sig, std::decay_t<F>>(std::forward<F>(f), null_param{});
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((total & 0x1) != 0) {
            return false;
        }
        ranges::sort(nums);
        int half = total >> 1;
        auto memo = [&](auto& dfs, int i, int j)->int {
            if (j == 0) {
                return 1;
            }
            if (i >= nums.size() || j < 0 || j < nums[i]) {
                return 0;
            }
            return dfs(i + 1, j) || dfs(i + 1, j - nums[i]);
        };
        return cache<int(int, int)>(memo)(0, half);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */

