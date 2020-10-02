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

int main() {
    vector<int> res{1, 3, 2, 5, 2, 4, 9, 2, 1, 3};
    bubleSorter::sort(res);
}