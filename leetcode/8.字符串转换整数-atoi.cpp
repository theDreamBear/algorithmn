/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
 public:
    const char* trimLeft(const char* str) {
        while ('\0' != *str && ' ' == *str) {
            ++str;
        }
        return str;
    }

    int getSigned(const char* str) {
        if ('\0' != *str && '-' == *str) {
            ++str;
            return -1;
        }
        return 1;
    }

    constexpr static char* t = "";

    const char* skipSigned(const char* str) {
        if ('\0' != *str) {
            if ('+' == *str || '-' == *str) {
                return ++str;
            } else if ('0' > *str || '9' < *str) {
                return t;
            }
        }
        return str;
    }

    int myAtoi(string s) {
        const char* str = trimLeft(s.c_str());
        if ('\0' == *str) {
            return 0;
        }
        int sign = getSigned(str);
        str = skipSigned(str);
        if ('\0' == *str) {
            return 0;
        }
        long long num = 0;
        while ('\0' != *str && '0' <= *str && '9' >= *str) {
            num = 10 * num + *str - '0';
            if (sign == 1) {
                if (num >= INT32_MAX) {
                    return INT32_MAX;
                }
            } else {
                if (num * -1 <= INT32_MIN) {
                    return INT32_MIN;
                }
            }
            ++str;
        }
        return num * sign;
    }
};
// @lc code=end

template <typename Result, typename... Input>
struct tester {
    Result r;
    tuple<Input...> input;

    template <typename Obj, typename Fn>
    bool checkResult(Obj obj, Fn&& fn) {
        if constexpr (tuple_size<decltype(input)>::value == 0) {
            return r == (obj->*fn)();
        } else if constexpr (tuple_size<decltype(input)>::value == 1) {
            return r == (obj->*fn)(get<0>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 2) {
            return r == (obj->*fn)(get<0>(input), get<1>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 3) {
            return r == (obj->*fn)(get<0>(input), get<1>(input), get<2>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 4) {
            return r == (obj->*fn)((get<0>(input), get<1>(input), get<2>(input),
                                 get<3>(input)));
        } else {
            cout << "too many" << endl;
            return false;
        }
    }
};


int main() {
    int (Solution::*pf)(string s) = &Solution::myAtoi;  //修改函数名
    Solution s;
    vector<tester<int, string> > ve = {
                                       {42, string("42")},
                                       {-42, string("   -42")},
                                       {4193, string("4193 with words")},
                                       {0, string("words and 987")}};
    for (int i = 0; i < ve.size(); ++i) {
        int v =
            ve[i].checkResult(&s, pf);
        if (!v) {
            cout << i << " " << v << endl;
        }
    }
}