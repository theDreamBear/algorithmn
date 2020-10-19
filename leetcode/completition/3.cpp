#include <iostream>
#include <map>
#include <vector>
using namespace std;

int bestTeamScoreHelper(int lastScore, int i, const vector<pair<int, int>>& r) {
    if (i >= r.size()) {
        return 0;
    }
    int result = 0;
    // 选
    if (r[i].second >= lastScore) {
        result = r[i].second + bestTeamScoreHelper(r[i].second, i + 1, r);
    }
    // 不选
    return max(result, bestTeamScoreHelper(lastScore, i + 1, r));
}

// 穷举 超时
int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    vector<pair<int, int>> ans;
    for (int i = 0; i < scores.size(); ++i) {
        ans.push_back({ages[i], scores[i]});
    }
    // 按照age, score 排序
    sort(ans.begin(), ans.end(), less<pair<int, int>>());
    return bestTeamScoreHelper(-1, 0, ans);
}

/*
dp2[i][0] 当前不选的最大值
dp2[i][1] 当前选的最大值

dp[i][0] = dp[i + 1][]
*/
constexpr static int MAX = 1001;
constexpr static int AGE = 1001;

int bestTeamScore2(vector<int>& scores, vector<int>& ages) {
    vector<vector<int>> dp2(MAX, vector<int>(AGE, 0));
    // for (int i = 0; i < MAX; ++i) {
    //     for (int j = 0; j < AGE; ++j) {
    //         dp2[i][j] = 0;
    //     }
    // }
    vector<pair<int, int>> ans;
    for (int i = 0; i < scores.size(); ++i) {
        ans.push_back({ages[i], scores[i]});
    }
    // 按照age, score 排序
    sort(ans.begin(), ans.end(), less<pair<int, int>>());
    dp2[0][ans[0].second] = ans[0].second;
    int cm = ans[0].second;
    for (int i = 1; i < ans.size(); ++i) {
        cm = max(cm, ans[i].second);
        for (int j = 1; j <= cm; ++j) {
            int plus = 0;
            if (j == ans[i].second) {
                plus = ans[i].second;
            }
            dp2[i][j] = plus + max(dp2[i][j - 1], dp2[i - 1][j]);
        }
    }
    int m = 0;
    for (int i = 0; i < MAX; ++i) {
        if (dp2[scores.size() - 1][i] > m) {
            m = dp2[scores.size() - 1][i];
        }
    }
    return m;
}

/*
1 <= scores.length, ages.length <= 1000
scores.length == ages.length
1 <= scores[i] <= 106
1 <= ages[i] <= 1000

发现 scores 非常大 所以不应该选择 score 来搜索

下面算法即便采用滚动数组叶超时了
*/

int bestTeamScore3(vector<int>& scores, vector<int>& ages) {
    int ms = 0;
    for (auto x : scores) {
        if (ms < x) {
            ms = x;
        }
    }
    vector<int> dp2(ms + 1, 0);
    // cout << ms << endl;
    // // for (int i = 0; i < MAX; ++i) {
    // //     for (int j = 0; j < AGE; ++j) {
    // //         dp2[i][j] = 0;
    // //     }
    // // }

    vector<pair<int, int>> ans;
    for (int i = 0; i < scores.size(); ++i) {
        ans.push_back({ages[i], scores[i]});
    }
    // 按照age, score 排序
    sort(ans.begin(), ans.end(), less<pair<int, int>>());
    dp2[ans[0].second] = ans[0].second;
    for (int i = 1; i < ans.size(); ++i) {
        for (int j = 1; j <= ans[i].second; ++j) {
            int plus = 0;
            if (j == ans[i].second) {
                plus = ans[i].second;
            }
            dp2[j] = plus + max(dp2[j - 1], dp2[j]);
        }
    }
    int m = 0;
    for (int i = 0; i <= ms; ++i) {
        if (dp2[i] > dp2[m]) {
            m = i;
        }
    }
    cout << "idx: " << m;
    return dp2[m];
}

int bestTeamScore4(vector<int>& scores, vector<int>& ages) {
    int dp3[MAX];
    fill(dp3, dp3 + MAX, 0);
    vector<pair<int, int>> ans;
    for (int i = 0; i < scores.size(); ++i) {
        ans.push_back({scores[i], ages[i]});
    }
    // 按照age, score 排序
    sort(ans.begin(), ans.end(), less<pair<int, int>>());
    dp3[ans[0].second] = ans[0].first;
    for (int i = 1; i < ans.size(); ++i) {
        for (int j = 1; j <= ans[i].second; ++j) {
            int plus = 0;
            if (j == ans[i].second) {
                plus = ans[i].first;
            }
            dp3[j] = plus + max(dp3[j - 1], dp3[j]);
        }
    }
    int m = 0;
    for (int i = 0; i <= MAX; ++i) {
        if (dp3[i] > dp3[m]) {
            m = i;
        }
    }
    cout << "idx: " << m << endl;
    return dp3[m];
}

struct te {
    vector<int> scores;
    vector<int> ages;
    int output;
};

int main() {
    vector<te> r = {
        {{1, 3, 5, 10, 15}, {1, 2, 3, 4, 5}, 34},
        {{4, 5, 6, 5}, {2, 1, 2, 1}, 16},
        {{1, 2, 3, 5}, {8, 9, 10, 1}, 6},
    };

    for (int i = 0; i < r.size(); ++i) {
        if (r[i].output != bestTeamScore4(r[i].scores, r[i].ages)) {
            cout << i << endl;
        }
    }
}