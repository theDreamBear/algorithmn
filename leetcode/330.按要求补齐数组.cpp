/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */
#include<vector>
#include<iostream>
#include<set>

using namespace std;

// @lc code=start
class Solution {
public:
    void getAllChilden(vector<vector<int>>& res, const vector<int>& nums) {
        res.push_back({});
        for (int i = 0 ; i < nums.size(); ++i) {
            int sz = res.size();
            for (int j = 0; j < sz; ++j) {
                auto x = res[j];
                x.push_back(nums[i]);
                res.push_back(x);
            }
        }
    }
    
    void 

    void printALl(vector<vector<int>>& res, set<int>& hashset) {
        vector<int> all;
        for (int i = 0; i < res.size(); ++i) {
            int sum = 0;
            for (int j = 0; j < res[i].size(); ++j) {
                sum += res[i][j];
            }
            all.push_back(sum);
        }
        sort(all.begin(), all.end());
        for_each(all.begin(), all.end(), [&](int x){hashset.insert(x);});
    }

    int minPatches(vector<int>& nums, int n) {
        vector<vector<int>> res;
        getAllChilden(res, nums);
        set<int> hashset;
        printALl(res, hashset);
        set<int> missset;
        for (int i = 1; i <= n; ++i) {
            if (hashset.find(i) == hashset.end()) {
                missset.insert(i);
            }
        }
        int ct = 0;
        while (!missset.empty()) {
            ++ct;
            auto x = *(missset.begin());
            set<int> add;
            for (auto v : hashset) {
                auto d = v + x;
                if (d <= n) {
                    if (missset.find(d) != missset.end()) {
                        add.insert(d);
                    }
                }
            }
            for (auto v : add) {
                missset.erase(v);
                hashset.insert(v);
            }
        }
        return ct;
    }
};

// @lc code=end
int main() {
    vector<int> nums = {1, 2, 5};
    int n = 10;
    vector<vector<int>> res;
    Solution s;
    cout << s.minPatches(nums, n) << endl;
}

