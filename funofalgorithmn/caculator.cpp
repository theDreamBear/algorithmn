#include <math.h>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**** 基本计算器
 * 支持运算符
 * 一元运算符    特殊处理 - -> _     +直接删去
 * 二元运算符 + - * /
 * 特殊（） [] {}
 * 扩充一元运算符
 * sin -> s
 * cos -> c
 * tan -> t
 *
 * 扩充二元运算符 ｜(二进制与) &（二进制或） ^(二进制异或)
 */

using OPTYPE = double;
int err_no = 0;

class Operator {
   private:
    int cnt = 2;

    virtual OPTYPE cal(OPTYPE* buffer) = 0;

   public:
    explicit Operator(int cnt) : cnt(cnt) {}

    virtual OPTYPE cal(stack<OPTYPE>& st) {
        if (st.size() < cnt) {
            cout << "st.size() < cnt";
            err_no = -1;
            return errno;
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
    OPTYPE cal(OPTYPE* buffer) override { return buffer[0]; }
};

class UnarySubOperator : public Operator {
   public:
    UnarySubOperator() : Operator(1) {}

   private:
    OPTYPE cal(OPTYPE* buffer) override { return -buffer[0]; }
};

class AddOperator : public Operator {
   public:
    explicit AddOperator() : Operator(2) {}

   private:
    OPTYPE cal(OPTYPE* buffer) override { return buffer[0] + buffer[1]; }
};

class SubOperator : public Operator {
   public:
    explicit SubOperator() : Operator(2) {}

   private:
    OPTYPE cal(OPTYPE* buffer) override { return buffer[0] - buffer[1]; }
};

class MultiplyOpeator : public Operator {
   public:
    MultiplyOpeator() : Operator(2) {}

   private:
    OPTYPE cal(OPTYPE* buffer) override { return buffer[0] * buffer[1]; }
};

class DivideOperator : public Operator {
   public:
    DivideOperator() : Operator(2) {}

   private:
    OPTYPE cal(OPTYPE* buffer) override { return buffer[0] / buffer[1]; }
};

class SinOperator : public Operator {
   public:
    SinOperator() : Operator(1) {}

   private:
    OPTYPE cal(OPTYPE* buffer) override { return sin(buffer[0]); }
};

class CosOperator : public Operator {
   public:
    CosOperator() : Operator(1) {}

   private:
    OPTYPE cal(OPTYPE* buffer) override { return cos(buffer[0]); }
};

class TanOperator : public Operator {
   public:
    TanOperator() : Operator(1) {}

   private:
    OPTYPE cal(OPTYPE* buffer) override { return tan(buffer[0]); }
};

class ModOperator : public Operator {
   public:
    ModOperator() : Operator(2) {}

   private:
    OPTYPE cal(OPTYPE* buffer) override { return (long long)buffer[0] % (long long)buffer[1]; }
};

class BitAndOperator : public Operator {
   public:
    BitAndOperator() : Operator(2) {}

   private:
    OPTYPE cal(OPTYPE* buffer) override {
        if constexpr (sizeof(OPTYPE) == 8) {
            return (long long)buffer[0] & (long long)buffer[1];
        }
        return (int)buffer[0] & (int)buffer[1];
    }
};

class RPN {
   private:
    static unordered_map<string, char> opname_map;

    static unordered_set<char> canMiss;

    string rpn;
    string result;
    static unordered_map<char, Operator*> opfunc_map;

    // 左结合运算符 取正
    // 右结合运算符取负, 目前只支持sin cos tan
    int priority(char op) {
        switch (op) {
            case '(':
                return 100000;
            case '!':
            case '~':
            case 'z':  // z --> 一元+
            case 'y':  // y --> 一元-
                return 10000;
            case '*':
            case '/':
            case '%':
                return 1000;
            case '+':
            case '-':
                return 100;
            case '&':
            case '^':
                return 50;
            case ')':
                return 0;
            case 's':
            case 't':
            case 'c':
                return -10000;
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
                        err_no = -4;
                        cout << "bad op";
                        return "bad";
                    }
                    string temp = s.substr(i, 3);
                    if (opname_map.count(temp) == 0) {
                        err_no = -2;
                        cout << "op not exit";
                        return "bad";
                    }
                    ans.push_back(opname_map[temp]);
                    i += 2;
                    break;
                }
                default:
                    ans.push_back(s[i]);
            }
        }
        return ans;
    }

    void pop_until(char ch, stack<char>& st) {
        if (ch != '(' && priority(ch) < 0) {
            st.push(ch);
            return;
        }
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
    string getResult() { return result; }

    void pn_to_rpn(const string& s) {
        string fixStr = formatSpecialFix(s);
        if (err_no != 0) {
            return;
        }
        cout << fixStr << endl;
        stack<char> st;
        for (int i = 0; i < fixStr.size(); i++) {
            if (canMiss.count(fixStr[i])) {
                continue;
            }
            if (isdigit(fixStr[i])) {
                rpn.push_back(fixStr[i]);
                while (i + 1 < fixStr.size() && (isdigit(fixStr[i + 1]) || fixStr[i + 1] == '.')) {
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
        cout << rpn << endl;
        stack<OPTYPE> st;
        for (int i = 0; i < rpn.size(); i++) {
            // 空字符
            if (canMiss.count(rpn[i])) {
                continue;
            }
            // 数字
            if (isdigit(rpn[i])) {
                bool dot = false;
                double base = 0.1;
                OPTYPE value = rpn[i] - '0';
                while (i + 1 < rpn.size() && (isdigit(rpn[i + 1]) || rpn[i + 1] == '.')) {
                    if (rpn[i + 1] == '.') {
                        dot = true;
                    } else {
                        if (!dot) {
                            value = value * 10 + (rpn[i + 1] - '0');
                        } else {
                            value += ((rpn[i + 1] - '0') * base);
                            base /= 10;
                        }
                    }
                    i++;
                }
                st.push(value);
                continue;
            }
            if (opfunc_map.count(rpn[i]) == 0) {
                err_no = -3;
                cout << "unsupport op";
                break;
            }
            auto op = opfunc_map[rpn[i]];
            auto v = op->cal(st);
            if (err_no != 0) {
                break;
            }
            cout << v << endl;
            st.push(v);
        }
        if (err_no != 0) {
            return INT64_MIN;
        }
        cout << st.top() << endl;
        return st.top();
    }
};

unordered_map<string, char> RPN::opname_map{
    {"+", 'z'}, {"-", 'y'}, {"tan", 't'}, {"sin", 's'}, {"cos", 'c'},

};

unordered_set<char> RPN::canMiss{' '};

unordered_map<char, Operator*> RPN::opfunc_map{
    {'z', new UnaryAddOperator}, {'y', new UnarySubOperator}, {'+', new AddOperator}, {'-', new SubOperator}, {'*', new MultiplyOpeator}, {'/', new DivideOperator}, {'s', new SinOperator}, {'c', new CosOperator}, {'t', new TanOperator}, {'%', new ModOperator}, {'&', new BitAndOperator},
};

extern "C" {
OPTYPE calculate(const char* s) {
    err_no = 0;
    RPN rpn;
    rpn.pn_to_rpn(s);
    if (err_no != 0) {
        return INT64_MIN;
    }
    return rpn.cal();
}
}

//
int main() {
    cout << calculate("7+8*6");
}
