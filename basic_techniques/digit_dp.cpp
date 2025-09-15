int dp[11][2][2];
auto calc = [&](auto self, int idx, bool f1, bool f2) -> int {
    if(idx >= n) return 0;

    int &x = dp[idx][f1][f2];
    if(x != -1) return x;

    int num1 = a[idx] - '0', num2 = b[idx] - '0';
    int l = (f1 ? 0 : num1);
    int r = (f2 ? 9 : num2);
    int mn = 1e9+5;

    rep(i,l,r+1) {
        mn = min(mn, self(self, idx+1, f1 | (i > num1), f2 | (i < num2)) + (num1==i) + (num2==i));
    }
    return x = mn;
};
memset(dp, -1, sizeof(dp));
cout << calc(calc, 0, 0, 0) << endl;