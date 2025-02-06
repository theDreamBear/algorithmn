/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <ranges.h>

using namespace std;
// @lc code=start
mt19937 mt(random_device{}());

template<typename T>
T rnd(T a, T b) {
   return uniform_int_distribution<T>(a, b)(mt);
}
long long MOD = 1e18 + rnd(1, (int)1e9), BASE = 233 + rnd(0, (int)1e3);
struct HashObj {
    vector<__int128_t> P, H;

    template<typename Container>
    HashObj(Container& s) {
        int n = s.size();
        P.resize(n + 1), H.resize(n + 1);
        P[0] = 1;
        for (int i = 0; i < n; i++) {
            P[i + 1] = P[i] * BASE % MOD;
            H[i + 1] = (H[i] * BASE + s[i]) % MOD;
        }
    }

    long long  query(int l, int r) {
        if (l > r) return 0;
        return  (H[r + 1] - H[l] * P[r - l + 1] % MOD + MOD) % MOD;
    }
};


class Solution {
public:
    /*
        1. 使用set取重
    */
    void permuteUniqueHelper(set<vector<int>>& ans, vector<int>& nums, int pos) {
        if (pos >= nums.size()) {
            ans.insert(nums);
            return;
        }
        permuteUniqueHelper(ans, nums, pos + 1);
        for (int i = pos + 1; i < nums.size(); ++i) {
            if (nums[i] != nums[pos]) {
                swap(nums[i], nums[pos]);
                permuteUniqueHelper(ans, nums, pos + 1);
                swap(nums[i], nums[pos]);
            }
        }
    }

    vector<vector<int>> permuteUnique1(vector<int>& nums) {
        set<vector<int>> ans;
        permuteUniqueHelper(ans, nums, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    int hashCode(const vector<int>& vec) {
        int seed = 21, mod = 1e9 + 7;
        int val = 0;
        for (int i = 0; i < vec.size(); ++i) {
            val = (((long long)val * seed) + vec[i]) % mod;
        }
        return val;
    }

    long long hashCode2(const vector<int>& vec) {
        HashObj obj(vec);
        return obj.query(0, vec.size() - 1);
    }

    void permuteUniqueHelper2(vector<vector<int>>& ans, unordered_set<long long>& exist , vector<int>& nums, int pos) {
        if (pos >= nums.size()) {
            auto code = hashCode2(nums);
            if (exist.count(code) == 0) {
                exist.insert(code);
                ans.push_back(nums);
            }
            return;
        }
        //permuteUniqueHelper2(ans, exist, nums, pos + 1);
        for (int i = pos; i < nums.size(); ++i) {
            swap(nums[i], nums[pos]);
            permuteUniqueHelper2(ans, exist, nums, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<long long> exist;
        permuteUniqueHelper2(ans, exist, nums, 0);
        return ans;
    }

    // 官方还有种解法，比较赞，下次再写出来
};
// @lc code=end

int main() {
    vector<int> data{1, 1, 2};
    auto ans = Solution{}.permuteUnique(data);
    for (auto vec : ans) {
        for (auto v : vec) {
            cout << v << " ";
        }
        cout << endl;
    }
}
