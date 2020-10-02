#include <iostream>
#include <queue>

#include "randomInput.h"

using namespace std;

class bucketSorter {
 private:
    int _bucket_num;
    vector<vector<int>> _helper;
    priority_queue<int, vector<int>, greater<int>> heap;

    void init() { _helper = vector<vector<int>>(_bucket_num, vector<int>()); }

    void _sort(vector<int>& nums) {
        for (int i = 0; i < _bucket_num; ++i) {
            _quick_sort(0, _helper[i].size() - 1, _helper[i]);
            cout << "sorted " << i << ": ";
            for (int j = 0; j < _helper[i].size(); ++j) {
                cout << _helper[i][j] << " ";
            }
            cout << endl;
        }
        _merge(nums);
    }
    void _merge(vector<int>& result) {
        int idx[_bucket_num];
        memset(idx, 0, sizeof(int) * _bucket_num);
        int i = 0;
        while (true) {
            for (int bindex = 0; bindex < _bucket_num; ++bindex) {
                if (idx[bindex] < _helper[bindex].size()) {
                    heap.push(_helper[bindex][idx[bindex]++]);
                }
            }
            if (heap.empty()) {
                break;
            }
            int v = heap.top();
            heap.pop();
            result[i++] = v;
        }
        for (auto x : result) {
            cout << x << " ";
        }
        cout << endl;
    }

    int _partition(int low, int high, vector<int>& nums) {
        if (low >= high) {
            return low;
        }
        // 第一个
        int blockIndex = low - 1;
        int val = nums[high];
        for (int i = low; i < high; ++i) {
            if (nums[i] < val) {
                ++blockIndex;
                if (blockIndex != i) {
                    swap(nums[blockIndex], nums[i]);
                }
            }
        }
        if (++blockIndex != high) {
            swap(nums[blockIndex], nums[high]);
        }
        return blockIndex;
    }

    void _quick_sort(int low, int high, vector<int>& nums) {
        if (low >= high) {
            return;
        }
        int p = _partition(low, high, nums);
        _quick_sort(low, p - 1, nums);
        _quick_sort(p + 1, high, nums);
    }

 public:
    bucketSorter(int bucket_num = 5) : _bucket_num(bucket_num) {}
    void sort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        init();
        for (int i = 0; i < nums.size(); ++i) {
            _helper[nums[i] % _bucket_num].push_back(nums[i]);
        }
        _sort(nums);
    }
};

int main() {
    auto res = randomInput(10000);
    bucketSorter bs(10);
    bs.sort(res);
}