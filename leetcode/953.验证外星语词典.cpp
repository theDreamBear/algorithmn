/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    bool AlienCompare(const string& left, const string& right,
                      const vector<int> sequence) {
        for (int j = 0; j < left.size() && j < right.size(); ++j) {
            if (sequence[left[j] - 'a'] > sequence[right[j] - 'a']) {
                return false;
            } else if (sequence[left[j] - 'a'] < sequence[right[j] - 'a']) {
                return true;
            }
        }
        return left.size() <= right.size();
    }

    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> sequence(order.size());
        for (int i = 0; i < order.size(); ++i) {
            sequence[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); ++i) {
            if (!AlienCompare(words[i - 1], words[i], sequence)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main() {
    vector<string> ws = {"word", "world", "row"};
    string ord = "worldabcefghijkmnpqstuvxyz";
    cout << Solution{}.isAlienSorted(ws, ord);
}
