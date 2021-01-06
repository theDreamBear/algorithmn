#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


/*
62进制
*/
class NBase {
 public:
    static string str;

    static void init() {
        if (!str.empty()) {
            return;
        }
        for (char c = '0'; c <= '9'; ++c) {
            str.push_back(c);
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            str.push_back(c);
        }
        for (char c = 'A'; c <= 'Z'; ++c) {
            str.push_back(c);
        }
    }

    static string toNBase(long long num) {
        init();
        string ans;
        while (num) {
            int a = num % 62;
            num /= 62;
            ans.push_back(str[a]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int num = 123456789;
    cout << NBase::toNBase(num) << endl;
}