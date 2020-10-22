/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
    /*
    O^3 超时
    */
    vector<vector<int>> threeSum1(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> exist;
        for (int i = 2; i < nums.size(); ++i) {
            for (int j = 1; j < i; ++j) {
                for (int k = 0; k < j; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> r = {nums[i], nums[j], nums[k]};
                        sort(r.begin(), r.end(), less<int>());
                        if (exist.find(r) == exist.end()) {
                            result.push_back(r);
                            exist.insert(r);
                        } else {
                            cout << "exist" << endl;
                        }
                    }
                }
            }
        }
        for (auto x : result) {
            for (auto y : x) {
                cout << y << " ";
            }
            cout << endl;
        }
        return result;
    }

    /*
        n^2 超时
    */
    vector<vector<int>> threeSum2(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> exist;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end(), less<int>());
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = i;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                // 添加 nums[j] == nums[j - 1] 优化终于没超时
                if ((j > 0 && nums[j] == nums[j - 1]) || nums[j] > 0) {
                    continue;
                }
                int left = 0 - nums[i] - nums[j];
                if (mp.find(left) != mp.end() && mp[left] > i) {
                    vector<int> r = {nums[j],nums[i], left};
                    if (exist.find(r) == exist.end()) {
                        result.push_back(r);
                        exist.insert(r);
                    } else {
                        cout << "exist" << endl;
                    }
                }
            }
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end(), less<int>());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum < -1 * nums[i]) {
                    ++l;
                } else if (sum > -1 * nums[i]) {
                    --r;
                } else {
                    result.emplace_back(move(vector<int>{nums[i], nums[l], nums[r]}));
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1]) {
                        ++l;
                    }
                    while (l < r && nums[r] == nums[r + 1]) {
                        --r;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

template <typename Result, typename... Input>
struct tester {
    Result r;
    tuple<Input...> input;
    tester(Result r, Input... input) : r(r), input(input...) {}

    template <typename Obj, typename Fn>
    bool checkResultObj(Obj obj, Fn&& fn) {
        if constexpr (tuple_size<decltype(input)>::value == 0) {
            return r == (obj->*fn)();
        } else if constexpr (tuple_size<decltype(input)>::value == 1) {
            return r == (obj->*fn)(get<0>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 2) {
            return r == (obj->*fn)(get<0>(input), get<1>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 3) {
            return r == (obj->*fn)(get<0>(input), get<1>(input), get<2>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 4) {
            return r == (obj->*fn)((get<0>(input), get<1>(input), get<2>(input),
                                    get<3>(input)));
        } else {
            cout << "too many" << endl;
            return false;
        }
    }

    template <typename Fn>
    bool checkResult(Fn&& fn) {
        if constexpr (tuple_size<decltype(input)>::value == 0) {
            return r == fn();
        } else if constexpr (tuple_size<decltype(input)>::value == 1) {
            return r == fn(get<0>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 2) {
            return r == fn(get<0>(input), get<1>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 3) {
            return r == fn(get<0>(input), get<1>(input), get<2>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 4) {
            return r == fn((get<0>(input), get<1>(input), get<2>(input),
                            get<3>(input)));
        } else {
            cout << "too many" << endl;
            return false;
        }
    }

    template <size_t...>
    struct index_sequence {};
    template <size_t N, size_t... S>
    struct make_index_sequence_helper
        : make_index_sequence_helper<N - 1, N - 1, S...> {};
    template <size_t... S>
    struct make_index_sequence_helper<0, S...> {
        typedef index_sequence<S...> type;
    };
    template <size_t N>
    using make_index_sequence = typename make_index_sequence_helper<N>::type;

    template <typename Obj, typename F, size_t... i, typename T>
    bool checkResultCommonHelperObject(Obj obj, F f, index_sequence<i...>,
                                       T&& t) {
        return r == (obj.*f)(get<i>(t)...);
    }

    template <typename Obj, typename F, typename... T>
    bool _checkResultCommonObject(Obj obj, F f, std::tuple<T...>& t) {
        return checkResultCommonHelperObject(
            obj, f, make_index_sequence<sizeof...(T)>(), t);
    }

    template <typename Obj, typename F>
    bool checkResultCommonObject(Obj obj, F f) {
        return _checkResultCommonObject(obj, f, input);
    }

    template <typename F, size_t... i, typename T>
    bool checkResultCommonHelper(F f, index_sequence<i...>, T&& t) {
        return r == f(get<i>(t)...);
    }

    template <typename F, typename... T>
    bool _checkResultCommon(F f, const std::tuple<T...>& t) {
        return checkResultCommonHelper(f, make_index_sequence<sizeof...(T)>(),
                                       t);
    }

    template <typename F>
    bool checkResultCommon(F&& f) {
        return _checkResultCommon(f, input);
    }
};

int main() {
    vector<vector<int>> (Solution::*pf)(vector<int> & nums) =
        &Solution::threeSum;  //修改函数名
    Solution s;
    vector<tester<vector<vector<int>>, vector<int>>> ve = {
        {{{-1, 0, 1}, {-1, -1, 2}}, {-1, 0, 1, 2, -1, -4}}};
    for (int i = 0; i < ve.size(); ++i) {
        int v = ve[i].checkResultCommonObject(s, pf);
        if (!v) {
            cout << i << " " << v << endl;
        }
    }
}
