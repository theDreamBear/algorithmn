#include <assert.h>

#include <iostream>
#include <vector>
#include "randomInput.h"

using namespace std;

class radixSorter {
 private:
    int _countWidth;
    int _baseMax;
    int _block_count;
    int _bitwidth;
    vector<int> helper;

    constexpr static int BASE = 2;

    int getPosNum(int val, int pos) {
        int v = ((val >> (_countWidth * pos) & _baseMax));
        return v;
    }

    bool isOrdered(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
    /*
       十进制计数排序
    */

    /*
    1. 空间占用稍多
    */
    void countSortHelper(vector<int>& nums, int pos) {
        fill(helper.begin(), helper.end(), 0);
        vector<int> temp = nums;
        for (int i = 0; i < temp.size(); ++i) {
            int v = getPosNum(temp[i], pos);
            helper[v]++;
        }
        for (int i = 1; i <= _baseMax; ++i) {
            helper[i] += helper[i - 1];
        }
        for (int i = temp.size() - 1; i >= 0; --i) {
            int v = getPosNum(temp[i], pos);
            nums[helper[v] - 1] = temp[i];
            helper[v]--;
        }
        for (auto& x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }

    void init() {
        _baseMax = (1 << _countWidth) - 1;

        _bitwidth = sizeof(int) * 8;

        _block_count = _bitwidth / _countWidth;

        if (_bitwidth % _countWidth) {
            ++_block_count;
        }
        helper = vector<int>(_baseMax + 1, 0);
    }

    void print() {
        cout << "_baseMax: " << _baseMax << endl;
        cout << "_block_count: " << _block_count << endl;
        cout << "_countWidth: " << _countWidth << endl;
    }

 public:
    radixSorter(int _countWidth = 4) : _countWidth(_countWidth) {
        init();
        print();
    }

    void sort(vector<int>& nums, int width = 1) {
        for (int i = 0; i < _block_count; ++i) {
            if (isOrdered(nums)) {
                break;
            }
            countSortHelper(nums, i);
        }
        cout << "finally result: " << endl;
        for (auto& x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> res = randomInput(100);
    radixSorter(10).sort(res);
}