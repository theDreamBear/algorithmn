/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
void backTracking(const string &s, int pos, unordered_map<char, int>& rMaks, vector<int> &ans, vector<int> &temp) {
    auto n = s.size();
    if (pos > n) {
        return;
    }
    if (pos == n) {
        if (temp.size() > ans.size()) {
            ans = temp;
            return;
        }
    }
    unordered_set<char> mask;
    auto right = pos;
    int start = pos;
    for (; right < n; right++) {
        mask.insert(s[right]);
        rMaks[s[right]]--;
        bool flag = true;
        for (auto it = mask.begin(); it != mask.end();) {
            if (rMaks[*it] != 0) {
                flag = false;
                break;
            } else {
                it = mask.erase(it);
            }
        }
        // 都没有
        if (flag) {
            // 符合
            temp.push_back(right - pos + 1);
            backTracking(s, right + 1, rMaks, ans, temp);
            break;
            //temp.pop_back();
            //start = right + 1;
        }
    }


}

class Solution {
private:

    void normal_partition(const string &s, vector<int> &ans) {
        if (s.empty()) {
            return;
        }
        if (s.size() == 1) {
            ans.push_back(1);
            return;
        }
        unordered_map<char, int> rMaks;
        for (auto ch : s) {
            rMaks[ch]++;
        }
        vector<int> temp;
        backTracking(s, 0, rMaks, ans, temp);
        return;
    }

public:
    // 1 <= s.length <= 500
    // s 仅由小写英文字母组成
    // n ^ 3 = 1.25e8
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        normal_partition(s, ans);
        return ans;
    }
};
// @lc code=end

