const int mod = 1e9 + 7;
const int mx = 1e5;
long long f[mx + 1], inv[mx + 1];

long long pow_mod(long long base, long long exp) {
    long long ans = 1;
    while (exp) {
        if (exp & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return ans;
}

void init() {
    f[0] = 1;
    for (int i = 1; i <= mx; i++) {
        f[i] = (f[i - 1] * i) % mod;
    }
    inv[mx] = pow_mod(f[mx], mod - 2);
    for (int i = mx - 1; i >= 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}

// (n - 1)! * n = n!
// inv[n] * n = inv[n - 1]
int C(int n, int m) {
    if (m > n or m < 0) return 0;
    return (f[n] * inv[m] % mod * inv[n - m]) % mod;
}

long long dp[mx + 1][mx + 1];

void init2() {
    for (int i = 0; i <= mx; i++) {
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }
}