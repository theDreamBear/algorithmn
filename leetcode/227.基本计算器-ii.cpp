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
#include <functional>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    /*
        减法变加法
        * / 提前算出来， 最终运算栈只剩下+
        *  所以栈op 栈其实是不需要的
    */
    int calculate(string s) {
        stack<char> op;
        stack<int> num;
        bool waitNext = false;
        int left = 0;
        function<int(int, int)> func = nullptr;
        int sign = 1;
        for (int i = 0; i < int(s.size()); ++i) {
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
            while (j < int(s.size()) && isdigit(s[j])) {
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
        Node *left, *right;
        const string& val;
        Node(const string& val) :left(nullptr), right(nullptr), val(val){}
    };

    unordered_map<char, int> priority;

    int getPriority(int i, char c) {
        return priority[c] * 1e7 + i;
    }

    int getRootIndex(const vector<string>& s, int low, int high) {
        int ans = -1;
        for (int i = low; i <= high; ++i) {
            char c = s[i][0];
            if (!isdigit(c)) {
                if (ans == -1 || getPriority(i, c) > getPriority(ans, s[ans][0])) {
                    ans = i;
                }
            }
        }
        return ans;
    }

    Node* makeTree(const vector<string>& s, int low, int high) {
        if (low > high) {
            return NULL;
        }
        if (low == high) {
            return new Node(s[low]);
        }
        int rootIndex = getRootIndex(s, low, high);
        Node* root = new Node(s[rootIndex]);
        root->left = makeTree(s, low, rootIndex - 1);
        root->right = makeTree(s, rootIndex + 1, high);
        return root;
    }

    int postTraversal(Node* root) {
        if (!root) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return stol(root->val);
        }
        int left = postTraversal(root->left);
        int right = postTraversal(root->right);
        cout << root->val << "\t";
        switch(root->val[0]) {
            case '+' : {
                return left + right;
            }
            case '-' : {
                return left - right;
            }
            case '*' : {
                return left * right;
            }
            case '/' : {
                return left / right;
            }
        }
        return 0;
    }

    int calculate1(string s) {
        priority['+']= 2;
        priority['-'] = 2;
        priority['/'] = 1;
        priority['*'] = 1;

        vector<string> input;
        for (int i = 0; i < int(s.size()); ++i) {
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
                while (j < int(s.size()) && isdigit(s[j])) {
                    val = 10 * val + (s[j] - '0');
                    ++j;
                }
                temp = to_string(val);
                i = j - 1;
            }
            input.push_back(temp);
        }
        // 构造逆波兰表达式数树🌲求解
        Node* root = makeTree(input, 0, input.size() - 1);
        int ans = 0;
        ans = postTraversal(root);
        return ans;
    }
};
// @lc code=end

int main() {
    string s = "1 * 2 + 4 / 4 - 5";
    cout << Solution{}.calculate(s);
}
