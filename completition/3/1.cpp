#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;


class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int index = 0;
        vector<int> helper(pieces.size(), 0);
        while (index < arr.size()) {
            bool found = false;
            for (int j = 0; j < pieces.size(); ++j) {
                if (arr[index] == pieces[j][helper[j]]) {
                    found = true;
                    if (helper[j] < pieces[j].size() - 1) {
                        ++helper[j];
                    }
                    ++index;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> arr = {85};
    vector<vector<int>> pises = {{arr}};
    cout <<Solution{}.canFormArray(arr, pises) << endl;
}