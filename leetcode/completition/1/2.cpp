#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool valid(vector<int>& nums, int low, int high) {
        vector<int> temp;
        for (int k = low; k <= high; ++k) {
            temp.push_back(nums[k]);
        }
        sort(temp.begin(), temp.end());
        int diff = temp[1] - temp[0];
        for (int i = 1; i < temp.size(); ++i) {
            if (temp[i] - temp[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(), false);
        for (int i = 0; i < l.size(); ++i) {
            ans[i] = valid(nums, l[i], r[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums={4,6,5,9,3,7};
    vector<int> l = {0, 0, 2};
    vector<int> r = {2, 3, 5};
    auto  a = Solution{}.checkArithmeticSubarrays(nums,l , r);
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << endl;
    }
}