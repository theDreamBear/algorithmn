/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
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
    /*
        减法变加法
        * / 提前算出来， 最终运算栈只剩下+
    */
    int calculate1(string s) {
        stack<char> op;
        stack<int> num;
        bool waitNext = false;
        int left = 0;
        function<int(int, int)> func = nullptr;
        int sign = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            if (!isdigit(s[i])) {
                switch (s[i]) {
                    case '-':
                        sign = -1;
                    case '+': {
                        op.push('+');
                        break;
                    }
                    case '*':
                    case '/': {
                        if (s[i] == '*') {
                            func = multiplies<int>();
                        } else {
                            func = divides<int>();
                        }
                        left = num.top();
                        num.pop();
                        waitNext = true;
                        break;
                    }
                }
                continue;
            }
            int val = s[i] - '0';
            int j = i + 1;
            while (j < s.size() && isdigit(s[j])) {
                val = 10 * val + (s[j] - '0');
                ++j;
            }
            if (waitNext) {
                val = func(left, val);
                waitNext = false;
                func = nullptr;
            } else if (sign == -1) {
                val *= -1;
                sign = 1;
            }
            num.push(val);
            i = j - 1;
        }
        if (op.empty()) {
            return num.top();
        }
        while (!num.empty()) {
            int right = num.top();
            num.pop();
            int left = num.top();
            num.pop();
            char opt = op.top();
            op.pop();
            int ans = 0;
            ans = left + right;
            if (num.empty()) {
                return ans;
            }
            num.push(ans);
        }
        return -1;
    }

    struct Node {
        Node* left, *right;
        string val;

        Node(string& val) :val(val), left(nullptr), right(nullptr) {}
    };

    unordered_map<char, int> priority;

    bool fatherPriority(char left, char right) {
        if (priority[left] <= priority[right]) {
            return true;
        }
        return false;
    }

    Node* makeTree(const vector<string>& s) {
        int i = 0;
        Node* root = NULL;
        char pre = 0;
        while (i < s.size()) {
            if (isdigit(s[i][0])) {

            } else {
                
            }
        }
    }

    int calculate(string s) {
        priority['+']= 2;
        priority['-'] = 2;
        priority['/'] = 1;
        priority['*'] = 1;

        vector<string> input;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            string temp;
            if (!isdigit(s[i])) {
                switch (s[i]) {
                    case '-':
                        temp.push_back('-');
                        break;
                    case '+': {
                        temp.push_back('+');
                        break;
                    }
                    case '*':
                        temp.push_back('*');
                        break;
                    case '/': {
                        temp.push_back('/');
                        break;
                    }
                }
            } else {
                int val = s[i] - '0';
                int j = i + 1;
                while (j < s.size() && isdigit(s[j])) {
                    val = 10 * val + (s[j] - '0');
                    ++j;
                }
                temp = to_string(val);
                i = j - 1;
            }
            input.push_back(temp);
        }
        return 0;
    }
};
// @lc code=end

int main() {
    string s = "3+ 2 * 2";
    cout << Solution{}.calculate(s);
}
