#include<vector>

using namespace std;


class ShellSorter {
public:
    vector<int> sortArray(vector<int>& nums) {
        int max_gap = 1;
        // knuth 增量
        int n = nums.size();
        while (max_gap <= n / 3) {
            max_gap = max_gap *3 + 1;
        }
        for (int gap = max_gap;  gap > 0; gap = (gap - 1) / 3) {
            for (int i = gap; i < n; i++)  {
                int v = nums[i];
                int j = i - gap;
                while (j >= 0 and nums[j] > v) {
                    nums[j + gap] = nums[j];
                    j -= gap;
                }
                nums[j + gap] = v;
            }
        }
        return nums;
    }
};