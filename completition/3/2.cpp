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
    void dfs(int i, int j, int n, const vector<char>& charSet, vector<string>& ans, string current) {
        if (i >=
         n) {
            ans.push_back(current);
            return;
        }
        for (int low = j; low < charSet.size(); ++low) {
            current.push_back(charSet[low]);
            dfs(i + 1, low, n, charSet, ans, current);
            current.pop_back();
        }
    }

    int countVowelStrings_dfs(int n) {
        vector<char> charSet = {'a', 'e', 'i', '0', 'u'};
        vector<string> ans;
        dfs(0, 0, n, charSet, ans, "");
        return ans.size();
    }

    int countVowelStrings(int n) {
        vector<char> charSet = {'a', 'e', 'i', '0', 'u'};
        if (n == 1) {
            return 5;
        }
        int dp[] = {1, 1, 1, 1, 1};
        for (int i = 1; i < n; ++i) {
            for (int j = 4; j >= 0; --j) {
                for (int k = 0; k < j; ++k) {
                    dp[j] += dp[k];
                }
            }
        }
        return dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
    }
};


int main() {
    cout << Solution{}.countVowelStrings(2) << endl;
}
