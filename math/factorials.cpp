void pre() {
    fact[0] = 1;
    for(int i=1; i<N; i++) {
        fact[i] = 1LL * fact[i-1] * i % MOD;
    }
    
    ifact[N-1] = binpow(fact[N-1], MOD-2, MOD);
    for(int i=N-2; i>=0; i--) {
        ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;
    }
}