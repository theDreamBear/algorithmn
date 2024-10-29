        auto handler = [&](int i) -> pair<bool, int> {
            if (i < 0) {
                return {true, };
            }
            return {false, };
        };

        auto memo = [&](auto&& dfs, int i) {
            if (h) {
                return max(dfs(i - 1), dfs(i - 2));
            }
            return max(dfs(i - 1), dfs(i - 1);
        };
        return cache_nvec<1, int(int)>(memo, {}, INT_MAX, handler)();