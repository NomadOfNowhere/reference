int getLCP(int i, int j, int len) {
    int l = 1, r = len;
    while(l <= r) {
        int m = (l+r) >> 1;
        ll left = (hashes[i+m] - hashes[i] + MOD) % MOD;
        ll right = (hashes[j+m] - hashes[j] + MOD) % MOD;
        left = left * p[j-i] % MOD;
        if(left == right) l = m + 1;
        else r = m - 1;
    }
    return r;
}
// Compute prefix hashes for the text
// LCP: getLCP(idx, idx+len, n)
// length of most repeated substring: LCP+len