/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
void backTracking(const string &s, int pos, unordered_map<char, int>& rMaks, vector<int> &ans, vector<int> &temp) {
    if (pos > (int)s.size()) {
        return;
    }
    if (pos == (int)s.size()) {
        if (temp.size() > ans.size()) {
            ans = temp;
            return;
        }
    }
    unordered_set<char> mask;
    auto right = pos;
    for (; right < (int)s.size(); right++) {
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
            //temp.pop_back();
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

    void greedy(const string &s, vector<int> &ans) {
        if (s.empty()) {
            return;
        }
        if (s.size() == 1) {
            ans.push_back(1);
            return;
        }
        int rMaks[26]{};
        for (auto ch : s) {
            rMaks[ch - 'a']++;
        }
        int mask[26]{};
        int kind = 0;
        auto left = 0;
        auto right = 0;
        for (; right < (int)s.size(); right++) {
            int idx = s[right] - 'a';
            if (1 == ++mask[idx]) {
                ++kind;
            }
            if (0 == --rMaks[idx]) {
                --kind;
            }
            if (0 == kind) {
                // 符合
                ans.push_back(right - left + 1);
                left = right + 1;
            }
        }
    }

    void greedy2(const string &s, vector<int> &ans) {
        if (s.empty()) {
            return;
        }
        if (s.size() == 1) {
            ans.push_back(1);
            return;
        }
        int cLast[26]{};
        for (int i = 0; i < s.size(); i++) {
            cLast[s[i] - 'a'] = i;
        }
        int end = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, cLast[s[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
    }

public:
    // 1 <= s.length <= 500
    // s 仅由小写英文字母组成
    // n ^ 3 = 1.25e8
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        greedy2(s, ans);
        return ans;
    }
};
// @lc code=end

