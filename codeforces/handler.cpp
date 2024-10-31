        auto handler = [&](int i, int h)->pair<bool, int> {
            if (i < 0) {
                return {true, h == 0 ? 0 : INT_MIN / 2};
            }
            return {false, 0};
        };
        int n = prices.size();
        int dp[n][2];
        fill_array(&dp[0][0], INT_MIN / 2, n, 2);
        auto get_v = [&](int i, int h) {
            if (auto res = handler(i, h); res.first) {
                return res.second;
            }
            return dp[i][h];
        };