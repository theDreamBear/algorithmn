/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
unordered_map<char, int> prority{
        make_pair(')', -1),
        make_pair('+', 0),
        make_pair('-', 0),
        make_pair('*', 10),
        make_pair('/', 10),
};

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int muilty(int a, int b) {
    return a * b;
}

int divid(int a, int b) {
    return a / b;
}

unordered_map<char, function<int(int, int)>> ops{
        {'+', add},
        {'-', sub},
        {'*', muilty},
        {'/', divid},
};

void pop_until(char cur, stack<char> &st, string &ans) {
    while (cur != '(' && !st.empty() && st.top() != '(' && prority[st.top()] >= prority[cur]) {
        ans.push_back(st.top());
        st.pop();
    }
    if (cur == ')') {
        if (st.empty() || st.top() != '(') {
            // bad
        } else {
            st.pop();
        }
        return;
    }
    st.push(cur);
}


string toPostOrder(const string &s) {
    string ans;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            continue;
        }
        if (isdigit(s[i])) {
            ans.push_back(s[i]);
            while (i + 1 < s.size() && isdigit(s[i + 1])) {
                ans.push_back(s[i + 1]);
                i++;
            }
            ans.push_back(' ');
            continue;
        }
        pop_until(s[i], st, ans);
    }
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

class Solution {
public:
    int calculate(string s) {
        string post = toPostOrder(s);
        stack<int> st;
        for (int i = 0; i < post.size(); i++) {
            if (post[i] == ' ') {
                continue;
            }
            if (isdigit(post[i])) {
                int value = post[i] - '0';
                while (i + 1 < post.size() && isdigit(post[i + 1])) {
                    value = value * 10 + (post[i + 1] - '0');
                    i++;
                }
                st.push(value);
                continue;
            }
            auto f = ops[post[i]];
            int right = st.top(); st.pop();
            int left =st.top(); st.pop();
            st.push(f(left, right));
        }
        return st.top();
    }
};

// @lc code=end

