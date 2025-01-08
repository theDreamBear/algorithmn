/*
 * @lc app=leetcode.cn id=面试题 16.02 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 16.02] 单词频率
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
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class WordsFrequency {
public:
    unordered_map<string, int> freq;
    WordsFrequency(vector<string>& book) {
        for (auto& s: book) freq[s]++;
    }
    
    int get(string word) {
        if (freq.contains(word)) return freq[word];
        return 0;
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
// @lc code=end



