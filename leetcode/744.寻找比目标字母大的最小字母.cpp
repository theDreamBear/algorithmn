// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */
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
// @lc code=start
class Solution {
public:

    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (letters[mid] > target) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (letters[low] > target) {
            return letters[low];
        }
        if (letters[high] > target) {
            return letters[high];
        }
        return letters[0];
    }
};
// @lc code=end

int main() {
    vector<char> in = {'e','e','e','e','e','e','n','n','n','n'};
    cout << Solution{}.nextGreatestLetter(in, 'e');
}
