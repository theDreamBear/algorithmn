#include <assert.h>
#include <mydef.h>

#include <iostream>
#include <random>
#include <vector>

using namespace std;

struct lazyQuickSorter {
    vector<int>& _data;
    // 步长
    int _step;

    // 当前已排序的最后位置
    int _pos;
    lazyQuickSorter(vector<int>& data, int step = 2)
        : _data(data), _step(step) {
        _pos = -1;
    }

    int partition(int low, int high) {
        if (low == high) {
            return low;
        }
        int seperator = low - 1;
        int temp = _data[high];
        for (int i = low; i < high; ++i) {
            if (_data[i] < temp) {
                ++seperator;
                if (seperator != i) {
                    swap(_data[i], _data[seperator]);
                }
            }
        }
        if (++seperator != high) {
            swap(_data[seperator], _data[high]);
        }
        return seperator;
    }

    void lazyQuickSort(int low, int high) {
        if (low > high) {
            return;
        }
        int p = partition(low, high);
        // _pos + _step 为期待排序的最后位置
        if (p < _pos + _step) {
            lazyQuickSort(p + 1, high);
        }
        lazyQuickSort(low, p - 1);
    }

    int operator[](int n) {
        assert(n < _data.size());
        if (n < _pos) {
            return _data[n];
        }
        while (_pos < n) {
            cout << "need sort!" << endl;
            lazyQuickSort(_pos + 1, _data.size());
            _pos += _step;
        }
        return _data[n];
    }
};

vector<int> randomInput(int sz, int val = 1000000) {
    vector<int> res;
    default_random_engine dre;
    uniform_int_distribution<unsigned> u(0, val);
    dre.seed(time(0));
    for (int i = 0; i < sz; ++i) {
        res.push_back(u(dre));
    }
    return res;
}


st


int main() {
    vector<int> num = randomInput(30, 100);
    lazyQuickSorter lq(num, 10);
    for (int i = num.size() - 1; i >= 0; --i) {
        lq[i];
        cout << "times: " << i << " " << lq[i] << endl;
        for (auto& x : num) {
            cout << x << " ";
        }
        cout << endl;
    }
}