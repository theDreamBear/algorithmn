#include <iostream>
#include <vector>
using namespace std;

// 回溯
void subsetHelper(vector<vector<int>>& ans, vector<int> nums, int pos,
                  const vector<int>& source) {
    ans.push_back(nums);
    if (pos >= source.size()) {
        return;
    }
    // 遍历所有子树
    for (int i = pos; i < source.size(); ++i) {
        nums.push_back(source[i]);
        subsetHelper(ans, nums, i + 1, source);
        // 回溯
        nums.pop_back();
    }
}

int main() {
    vector<int> source{1, 2, 3};
    vector<vector<int>> ans;
    vector<int> nums;
    subsetHelper(ans, nums, 0, source);
    for (int i = 0; i < ans.size(); ++i) {
        cout << "subset " << i << " : ";
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}