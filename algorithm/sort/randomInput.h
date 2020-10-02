#ifndef __RANDOMINPUT_H__
#define __RANDOMINPUT_H__
#include <vector>
#include <random>

using namespace std;

vector<int> randomInput(int sz, int mval = 1000000) {
    vector<int> res;
    default_random_engine dre;
    uniform_int_distribution<unsigned> u(0, mval);
    dre.seed(time(0));
    for (int i = 0; i < sz; ++i) {
        res.push_back(u(dre));
    }
    return res;
}

#endif // __RANDOMINPUT_H__

