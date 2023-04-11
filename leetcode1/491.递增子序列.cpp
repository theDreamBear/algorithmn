/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution1 {
public:
    uint32_t hash1(vector<int>& data) {
        uint32_t code = 0;
        for (int i = 0; i < data.size(); i++) {
            code = (code << 5) | (code >> 27);
            code += (data[i] + 200);
        }
        return code;
    }

    uint32_t hash2(vector<int>& data) {
        constexpr unsigned int primeRK = 16777619;
        uint32_t code = 0;
        for (int i = 0; i < data.size(); i++) {
            code = (code * primeRK) + data[i] + 200;
        }
        return code;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<pair<int, int>> exist;
        for (int i = 0; i < (1 << n); i++) {
            int sz = __builtin_popcount(i);
            if (sz < 2) {
                continue;
            }
            vector<int> temp(sz);
            int k = i;
            bool ok = true;
            for (int j = 0; j < sz; j++) {
                if (k == 0) {
                    break;
                }
                int p = __builtin_ffs(k) - 1;
                if (j == 0 || nums[p] >= temp[j - 1]) {
                    temp[j] = nums[p];
                    k ^= (1 << p);
                } else {
                    ok = false;
                    break;
                }
            }
            if (!ok){
                continue;
            }
            auto h1 = hash1(temp);
            auto h2 = hash2(temp);
            auto pi = make_pair(h1, h2);
            if (exist.count(pi) == 0) {
                ans.push_back(temp);
                exist.insert(pi);
            }
        }
        return ans;
    }
};

class Solution {
public:
    void findSubsequencesHelper(int pos, int last, vector<int>& temp, vector<vector<int>>& ans, const vector<int> &nums) {
        if (pos >= nums.size()) {
            if (temp.size() >= 2) {
                ans.push_back(temp);
            }
            return;
        }
        if (last != nums[pos]) {
            findSubsequencesHelper(pos + 1, last, temp, ans, nums);
        }
        if (last <= nums[pos]) {
            temp.push_back(nums[pos]);
            findSubsequencesHelper(pos + 1, nums[pos], temp, ans, nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        findSubsequencesHelper(0, -1000, temp, ans, nums);
        return ans;
    }
};
// @lc code=end

