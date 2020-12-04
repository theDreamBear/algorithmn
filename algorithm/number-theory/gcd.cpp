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

int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    }
    while (b != 0) {
        int d = a % b;
        a = b;
        b = d;
    }
    return a;
}

/*
扩展 gcd 可以用于求逆元或者二元一次不定方程 等等
*/
int extGcd(int a, int b, int &x, int &y) {
    int d = a;
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        d = extGcd(b, a % b, y, x);
        y -= x * (a / b);
    }
    return d;
}