#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxLengthBetweenEqualCharacters(string s) {
    if (s.size() == 1) {
        return -1;
    }
    map<char, int> map_left;
    map<char , int> map_right;
    for (int i = 0; i < s.size(); ++i) {
        if (map_left.find(s[i]) == map_left.end()) {
            map_left[s[i]] = i;
        }
    }
    for (int i = (int)(s.size() - 1); i >= 0; --i) {
        if (map_right.find(s[i]) == map_right.end()) {
            map_right[s[i]] = i;
        }
    }
    int m = -1;
    for (int i = 0; i < s.size(); ++i) {
        int left = map_left[s[i]];
        int right = map_right[s[i]];
        if (left < right) {
            m = max(m, right - left - 1);
        }
    }
    return m;
}

struct te
{
    string s;
    int len;
};


int main() {
    vector<te> r = {
        {"aa", 0},
        {"abca", 2},
        {"cbzxy", -1},
        {"cabbac", 4},
    };
    
    for (int i = 0; i < r.size(); ++i) {
        if (r[i].len != maxLengthBetweenEqualCharacters(r[i].s)) {
            cout << maxLengthBetweenEqualCharacters(r[i].s) << endl;
        }
    }
}