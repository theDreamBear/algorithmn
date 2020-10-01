#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class countSorter {
   private:
    // function<bool(int, int)> _compare;

   public:  
    countSorter() {}

    /*
        nums里面不能有负数
    */
    static void sort(vector<int>& nums, int maxValue) {
        vector<int> helper(maxValue + 1, 0);
        vector<int> output(nums.size());
        for (auto x : nums) {
            helper[x]++;
        }
//#define __OLD__
#ifdef __OLD__
        int idx = 0;
        int i = 0;
        while (idx < nums.size()) {
            for (int j = 0; j < helper[i]; ++j) {
                output[idx++] = i;
            }
            ++i;
        }
#else
        for (int i = 1; i < helper.size(); ++i) {
            helper[i] += helper[i - 1];
        }
        for (int i = 0; i < nums.size(); ++i) {
            output[helper[nums[i]] - 1] = nums[i]; 
            helper[nums[i]]--;
        }
#endif
        nums.assign(output.begin(), output.end());
        return;
    }
};

int main() {
    vector<int> res = {2, 2, 1, 1, 3, 4, 3, 3, 3};
    countSorter::sort(res, 4);
    for (auto x : res) {
        cout << x << " ";
    }
    cout << endl;
}