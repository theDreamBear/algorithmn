/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
using OPTYPE = int;

class Operator {
private:
    int cnt = 2;
    virtual OPTYPE cal(OPTYPE* buffer) = 0;
public:
     explicit Operator(int cnt) : cnt(cnt) {}

    virtual OPTYPE cal(stack<OPTYPE>& st) {
         if (st.size() < cnt) {
             throw logic_error("st.size() < cnt");
         }
        OPTYPE buffer[cnt];
        int idx = cnt;
        while (idx-- > 0) {
            buffer[idx] = st.top();
            st.pop();
        }
        return cal(buffer);
    }
};

class UnaryAddOperator : public Operator {
public:
    explicit UnaryAddOperator() : Operator(1) {}

private:
    OPTYPE cal(OPTYPE *buffer) override {
        return buffer[0];
    }
};

class UnarySubOperator : public Operator {
public:
    UnarySubOperator() : Operator(1) {}

private:
    OPTYPE cal(OPTYPE *buffer) override {
        return -buffer[0];
    }
};

class AddOperator : public Operator {
public:
    explicit AddOperator() : Operator(2) {}

private:
    OPTYPE cal(OPTYPE *buffer) override {
        return buffer[0] + buffer[1];
    }
};

class SubOperator : public Operator {
public:
    explicit SubOperator() : Operator(2) {}

private:
    OPTYPE cal(OPTYPE *buffer) override {
        return buffer[0] - buffer[1];
    }
};

class MultiplyOpeator : public Operator {
public:
    MultiplyOpeator() : Operator(2) {}

private:
    OPTYPE cal(OPTYPE *buffer) override {
        return buffer[0] * buffer[1];
    }
};

class DivideOperator : public Operator {
public:
    DivideOperator() : Operator(2) {}

private:
    OPTYPE cal(OPTYPE *buffer) override {
        return buffer[0] / buffer[1];
    }
};

class SinOperator : public Operator {
public:
    SinOperator() : Operator(1) {}

private:
    OPTYPE cal(OPTYPE *buffer) override {
        return sin(buffer[0]);
    }
};

class RPN {
private:
    static unordered_map<string, char> opname_map;

    static unordered_set<char> canMiss;


    string rpn;
    string result;
    static unordered_map<char, Operator*> opfunc_map;

    int priority(char op) {
        switch (op) {
            case '(':
                return 100000;
            case '!':
            case '~':
            case 'z':  // z --> 一元+
            case 'y':  // y --> 一元-
            case '&':
            case 's':
                return 10000;
            case '*':
            case '/':
            case '%':
                return 1000;
            case '+':
            case '-':
                return 100;
            case ')':
                return -1;
            default:
                return 0;
        }
    }

    // 特殊处理
    string formatSpecialFix(const string s) {
        string ans;
        bool has_num = false;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '+':
                case '-': {
                    bool unary = false;
                    if (i == 0) {
                        unary = true;
                    } else {
                        int j = i;
                        while (j - 1 >= 0 && canMiss.count(s[j - 1])) {
                            j--;
                        }
                        if (j - 1 >= 0 && s[j - 1] == '(') {
                            unary = true;
                        }
                    }
                    if (unary) {
                        string temp(1, s[i]);
                        ans.push_back(opname_map[temp]);
                    } else {
                        ans.push_back(s[i]);
                    }
                    break;
                }
                case 's':
                case 'c':
                case 't': {
                    if (i + 3 >= s.size()) {
                        throw logic_error("bad op");
                    }
                    string temp = s.substr(i, 3);
                    if (opname_map.count(temp) == 0) {
                        throw logic_error("op not exit");
                    }
                    ans.push_back(opname_map[temp]);
                    i+=2;
                    break;
                }
                default:
                    ans.push_back(s[i]);
            }
        }
        return ans;
    }

    void pop_until(char ch, stack<char>& st) {
        while (!st.empty() && st.top() != '(' && priority(st.top()) >= priority(ch)) {
            rpn.push_back(st.top());
            st.pop();
        }
        if (ch == ')') {
            st.pop();
        } else {
            st.push(ch);
        };
    }

public:
    string getResult() {
        return result;
    }

    void pn_to_rpn(const string &s) {
        string fixStr = formatSpecialFix(s);
        //cout << fixStr << endl;
        stack<char> st;
        for (int i = 0; i < fixStr.size(); i++) {
            if (canMiss.count(fixStr[i])) {
                continue;
            }
            if (isdigit(fixStr[i])) {
                rpn.push_back(fixStr[i]);
                while (i + 1 < fixStr.size() && isdigit(fixStr[i + 1])) {
                    rpn.push_back(fixStr[i + 1]);
                    i++;
                }
            } else if (fixStr[i] == '(') {
                st.push(fixStr[i]);
                continue;
            } else {
                pop_until(fixStr[i], st);
            }
            rpn.push_back(' ');
        }
        while (!st.empty()) {
            rpn.push_back(st.top());
            st.pop();
        }
    }

    OPTYPE cal() {
        //cout << rpn << endl;
        stack<OPTYPE> st;
        for (int i = 0; i < rpn.size(); i++) {
            // 空字符
            if (canMiss.count(rpn[i])) {
                continue;
            }
            // 数字
            if (isdigit(rpn[i])) {
                int value = rpn[i] - '0';
                while (i + 1 < rpn.size() && isdigit(rpn[i + 1])) {
                    value = value * 10 + (rpn[i + 1] - '0');
                    i++;
                }
                st.push(value);
                continue;
            }
            if (opfunc_map.count(rpn[i]) == 0) {
                throw logic_error("unsupport op");
            }
            auto op = opfunc_map[rpn[i]];
            auto v = op->cal(st);
            st.push(v);
        }
        return st.top();
    }
};

unordered_map<string, char> RPN::opname_map{
        {"+",   'z'},
        {"-",   'y'},
        {"tan", 't'},
        {"sin", 's'},
        {"cos", 'c'},

};

unordered_set<char> RPN::canMiss{' '};

unordered_map<char, Operator*> RPN::opfunc_map {
        {'z', new UnaryAddOperator},
        {'y', new UnarySubOperator},
        {'+', new AddOperator},
        {'-', new SubOperator},
        {'*', new MultiplyOpeator},
        {'/', new DivideOperator},
        {'s', new SinOperator},
};


class Solution {
public:
    int calculate(string s) {
        RPN rpn;
        rpn.pn_to_rpn(s);
        return rpn.cal();
    }
};
// @lc code=end

