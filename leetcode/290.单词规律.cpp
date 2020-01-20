/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (41.42%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    16.1K
 * Total Submissions: 38.7K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    /**
     * 错误代码
     * 
     * 
     * **/
    vector<string> split1(char* source, const char* d) {
        vector<string> ans;
        if (source == NULL) {
            return ans;
        }
        char* p = strtok(source, d);
        ans.push_back(p);
        while (p) {
            p = strtok(NULL, d);
            // p == NULL 的时候 push_back会报错
            ans.push_back(p);
        }
        return ans;
    }
    
    vector<string> split(char* source, const char* d) {
        vector<string> ans;
        if (source == NULL) {
            return ans;
        }
        char* p = strtok(source, d);
        while (p) {
            ans.push_back(p);
            p = strtok(NULL, d);
        }
        return ans;
    }
    bool wordPattern1(string pattern, string str) {
        string hashMap[26];
        char temp[str.size() + 1];
        memcpy(temp, str.c_str(), str.size());
        temp[str.size()] = '\0';
        unordered_set<string> hashSet;
        const char* d = " ";
        auto source = move(split(temp, d));
        if (source.size() != pattern.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); ++i) {
            if (hashMap[pattern[i] - 'a'] == "") {
                if (hashSet.find(source[i]) != hashSet.end()) {
                    return false;
                }
                hashMap[pattern[i] - 'a'] = source[i];
                hashSet.insert(source[i]);
            } else if (hashMap[pattern[i] - 'a'] != source[i]) {
                return false;
            }
        }
        return true;
    }

    bool wordPattern(string pattern, string str) {
        string hashMap[26];
        char temp[str.size() + 1];
        memcpy(temp, str.c_str(), str.size());
        temp[str.size()] = '\0';
        unordered_set<string> hashSet;
        const char* d = " ";

        char* p = strtok(temp, d);
        for (int i = 0; i < pattern.size(); ++i) {
            if (p != NULL) {
                if (hashMap[pattern[i] - 'a'] == "") {
                    if (hashSet.find(p) != hashSet.end()) {
                        return false;
                    }
                    hashMap[pattern[i] - 'a'] = p;
                    hashSet.insert(p);
                } else {
                    if (hashMap[pattern[i] - 'a'] != p) {
                        return false;
                    }
                }
                p = strtok(NULL, d);
            } else {
                // pattern 多
                return false;
            }
        }
        // str 多
        return p == NULL;
    }
};
// @lc code=end

