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
#include <assert.h>
#include <getopt.h>
#include <algorithm>

using namespace std;

/*
从 [2, upperLimit]
埃氏筛选法
*/
vector<int> prime_screening(int upperLimit) {
    vector<bool> is_prime(upperLimit + 1, true);
    vector<int> res;
    assert(upperLimit < is_prime.size());
    for (int curNumer = 2; curNumer <= upperLimit; ++ curNumer) {
        if (is_prime[curNumer]) {
            res.push_back(curNumer);
            for (int setIndex = curNumer * 2; setIndex <= upperLimit; setIndex += curNumer) {
                is_prime[setIndex] = false;
            }
        }
    }
    return res;
}