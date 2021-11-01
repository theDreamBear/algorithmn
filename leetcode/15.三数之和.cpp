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
class Solution2 {
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


class Solution1 {
public:
    static constexpr int E = 2e5 + 1;
    static constexpr int A = 1e5;
    unordered_set<unsigned int> exist;

    void get_three_random(vector<int> &nums, vector<vector<int>> &ans, int times) {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> u(0, nums.size() - 1);
        for (int i = 0; i < times; i++) {
            int first = u(mt);
            int second = u(mt);
            while (first == second) {
                second = u(mt);
            }
            int third = u(mt);
            while (first == third || second == third) {
                third = u(mt);
            }
            if (nums[first] > nums[second]) {
                swap(first, second);
            }
            if (nums[second] > nums[third]) {
                swap(second, third);
            }
            if (nums[first] > nums[second]) {
                swap(first, second);
            }
            unsigned int hash = (((unsigned int)nums[first] + A) * E + (nums[second]) + A) * E + nums[third] + A;
            if (exist.count(hash) > 0) {
                continue;
            }
            if (nums[first] + nums[second] + nums[third] == 0) {
                ans.push_back({nums[first], nums[second], nums[third]});
            }
            exist.insert(hash);
        }
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        for (int i = 0; i < 1; i++) {
            get_three_random(nums, result, 100000);
        }
        return result;
    }
};

vector<vector<int>> nSum(vector<int>& nums, int n, int target) {
    function<vector<vector<int>>(const vector<int>&, vector<int>&, int, int)> n_sum = [&](const vector<int>& nums, vector<int>& before, int n, int target) {
        vector<vector<int>> res;
        if (n <= 0) {
            return res;
        }
        if (n == 1) {
            for (auto value : nums) {
                if (value == target) {
                    res.push_back({value});
                }
            }
            return res;
        }
        if (n == 2) {
            int i = -1;
            if (!before.empty()) {
                i = before.back();
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                vector<int> temp = before;
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    temp.push_back(left);
                    temp.push_back(right);
                    vector<int> t;
                    for (auto index : temp) {
                        t.push_back(nums[index]);
                    }
                    res.push_back(t);
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        --right;
                    }
                    continue;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
            return res;
        }
        int i = -1;
        if (!before.empty()) {
            i = before.back();
        }
        for (int j = i + 1; j < nums.size(); ++j) {
             if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            before.push_back(j);
            auto r1 = n_sum(nums, before, n - 1, target - nums[j]);
            if (!r1.empty()) {
                for (auto& v : r1) {
                    res.push_back(v);
                }
            }
            before.pop_back();
        }
        return res;
    };
    vector<vector<int>> ans;
    if (nums.size() < n) {
        return ans;
    }
    sort(nums.begin(), nums.end());
    vector<int> before;
    return n_sum(nums, before, n, target);
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        return nSum(nums, 3, 0);
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
