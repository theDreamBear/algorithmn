#include <iostream>
#include <vector>
using namespace std;

class bubleSorter {
 private:
 public:
    static void sort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }

#ifdef __OLD__
        for (int i = 0; i + 1 < nums.size(); ++i) {
            for (int j = 1; j + i < nums.size(); ++j) {
                if (nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                }
            }
        }
#else
        bool ordered = true;
        for (int end = nums.size(); end > 0; --end) {
            for (int cur = 1; cur < end; ++cur) {
                if (nums[cur] < nums[cur - 1]) {
                    ordered = false;
                    swap(nums[cur], nums[cur - 1]);
                }
            }
            // 最好情况 O(N)
            if (ordered) {
                break;
            }
        }
#endif
        for (auto x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }
};


void bubbleSort_common(vector<int>& data) {
    for (int i = 0; i + 1 < data.size(); i++) {
        for (int j = 0; j + i + 1 < data.size(); j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void bubbleSort_optimize_1(vector<int>& data) {
    for (int i = 0; i + 1 < data.size(); i++) {
        bool ordered = true;
        for (int j = 0; j + i + 1 < data.size(); j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                ordered = false;
            }
        }
        if (ordered) {
            break;
        }
    }
}

void bubbleSort_optimize_best(vector<int>& data) {
    int lastSortedIndex = data.size();
    // 1、[lastSortedIndex, +INF） 有序
    bool ordered = false;
    while (!ordered) {
        ordered = true;
        int  swapIndex = 0;
        // 2、[swapIndex, lastSortedIndex) 本次有序
        for (int j = 0; j + 1 < lastSortedIndex; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                swapIndex = j + 1;
                ordered = false;
            }
        }
        lastSortedIndex = swapIndex;
    }
}

int main() {
    vector<int> res{1, 3, 2, 5, 2, 4, 9, 2, 1, 3};
    bubleSorter::sort(res);
}