set<int> factors;
for(int i=2; i*i<=n; i++) {
    while(!(n % i)) {
        factors.insert(i);
        n /= p;
    }
}
if(n > 1) factors.insert(n);