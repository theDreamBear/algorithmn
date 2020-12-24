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
    function<void(int)>
    vector<int> res = randomInput(100);
    radixSorter(10).sort(res);
}


/*
 比如int32 是32进制的, 我们可以提供 32个桶
 也可以提供32约数个桶
 * */
class radixSorter2 {
 private:
    int _bucket_num;
    int _base_val;
    int _max_bit_width;

    /*
     *  times 从 0 开始
     * */
    int _get_bucket_index(int val, int times) {
        int offset = _bucket_num * times;
        return (val >> offset) & _base_val;
    }

    void _sort_help(vector<int>& nums, int times) {
        vector<vector<int>> temp_buckets(_base_val + 1, vector<int>{});
        for (auto val : nums) {
            int index = _get_bucket_index(val, times);
            temp_buckets[index].push_back(val);
        }
        for (auto& vec : temp_buckets) {
            if (vec.size() > 0) {
                ::sort(vec.begin(), vec.end());
            }
        }
        int i = 0;
        for (auto& vec : temp_buckets) {
            if (vec.size() > 0) {
                for (auto x : vec) {
                    nums[i++] = x;
                }
            }
        }
    }
    int _get_max_bit_width(int val) {
        for (int i = 31; i >= 0; --i) {
            if ((val >> i) &0x1 == 1) {
                return i + 1;
            }
        }
        return 32;
    }

    void _sort(vector<int>& nums) {
        int times = _max_bit_width / _bucket_num;
        if (_max_bit_width % _bucket_num != 0) {
            ++times;
        }
        for (int i = 0; i < times; ++i) {
            _sort_help(nums, i);
        }
    }
 public:
    explicit radixSorter2(int bucketNum, int max_value): _bucket_num(bucketNum) {
        _base_val = (1 << bucketNum) - 1;
        _max_bit_width = _get_max_bit_width(max_value);
    }

    void sort(vector<int>& nums) {
        _sort(nums);
    }
};
