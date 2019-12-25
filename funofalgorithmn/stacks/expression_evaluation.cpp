#include<iostream>
#include<stack>

class Evaluation{
    public:
    //  默认构造函数
        Evaluation() = default;

        double calculate(const std::string strE) const{
            return 0;
        }        
    protected:
        bool isValidExpression(const std::string &strE) const {
            return true;
        }

        bool isBracketsMatch(const std:: string &strE) const {
            std::stack<char> bracketStack;
            bool isValide = true;
            for_each(begin(strE), end(strE),[&](char ch)->{
                if (ch == '(') {
                    bracketStack.push(ch)
                } else if (ch == ')') {
                    if (bracketStack.top() != '(') {
                        isValide = false;
                        return;
                    } else {
                        bracketStack.pop();
                    }
                }
            });            
            return isValide; 
        }


    private:
        std::stack<std::string> opStack;
        std::stack<double> numberStack;
};