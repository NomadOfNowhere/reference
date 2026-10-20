// Usar cuando: dp[i][j] = min_{k<j} dp[i-1][k] + cost(k+1, j),
// cost se calcula facil en O(1) u O(log n), y los grupos no se
// tocan entre si y son continuos (opt[i][j] <= opt[i][j+1]).
// dp[i][mid]: el i-esimo grupo tiene que acabar exactamente en mid.
// O(K * N log N * cost). Llamar compute(i, 1, n, 0, n-1) para i = 1..K
ll dp[K][N];
// costo de un grupo que empieza en l y acaba en r, O(1) u O(log n)
ll cost(int l, int r) {
    // ...
}
void compute(int i, int l, int r, int optl, int optr) {
    if(l>r)return;
    int mid=(l + r)/2;
    ll best_val=1e17;
    int best_k = optl;
    for (int k = optl; k <= min(mid, optr); ++k) {
        ll val = dp[i-1][k]+cost(k+1,mid);
        if (val<best_val) {
            best_val=val;
            best_k=k;
        }
    }
    dp[i][mid]=best_val;
    compute(i,l,mid-1,optl,best_k);
    compute(i,mid+1, r,best_k,optr);
}
