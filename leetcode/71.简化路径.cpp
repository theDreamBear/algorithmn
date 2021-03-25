/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include <ranges.h>
#include <string.h>
#include <sstream>
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
    string simplifyPath1(string path) {
        vector<string> vec;
        // 包含delimiters指定的某一个字符是多个连续的情况时，
        // 多个连续的字符会被认为是一个，但是只有一个字符被替换会 '\0',其他的未被替换的被略过。
        char* pos = strtok((char*)path.c_str(), "/");
        while (pos != NULL) {
            vec.emplace_back(pos);
            pos = strtok(NULL, "/");
        }
        vector<string> temp;
        int i = 0;
        for (int j = 0; j < vec.size(); ++j) {
            if (vec[j] == "..") {
                --i;
                if (i < 0) {
                    i = 0;
                }
                continue;
            }
            if (vec[j] == ".") {
                continue;
            }
            if (i >= temp.size()) {
                temp.emplace_back(vec[j]);
            } else {
                temp[i] = vec[j];
            }
            ++i;
        }
        string ans;
        for (int k = 0; k < i; ++k) {
            ans += ("/" + temp[k]);
        }
        if (ans == "") {
            return "/";
        }
        return ans;
    }

    string simplifyPath1_plus(string path) {
        vector<string> vec;
        char* pos = strtok((char*)path.c_str(), "/");
        while (pos != NULL) {
            vec.emplace_back(pos);
            pos = strtok(NULL, "/");
        }
        vector<string> temp;
        for (int j = 0; j < vec.size(); ++j) {
            if (vec[j] == "..") {
                if (!temp.empty()) {
                    temp.pop_back();
                }
                continue;
            }
            if (vec[j] == ".") {
                continue;
            }
            temp.emplace_back(vec[j]);
        }
        string ans;
        for (int k = 0; k < temp.size(); ++k) {
            ans += ("/" + temp[k]);
        }
        if (ans == "") {
            return "/";
        }
        return ans;
    }

    /*
        istringstream, getline分割字符串
        “//” 
    */
    string simplifyPath(string path) {
        stringstream is(path);
        string temp;
        vector<string> ans;
        // 不会忽律连续的的分隔符
        while (getline(is, temp, '/')) {
            if (temp == "." || temp.empty()) {
                continue;
            }
            if (temp == "..") {
                if (!ans.empty()) {
                    ans.pop_back();
                }
                continue;
            }
            ans.emplace_back(temp);
        }
        string r;
        for (int i = 0; i < ans.size(); ++i) {
            r += ("/" + ans[i]);
        }
        if (r.empty()) {
            return "/";
        }
        return r;
    }

};
// @lc code=end
int main() {
    cout << Solution{}.simplifyPath("//home/");
}