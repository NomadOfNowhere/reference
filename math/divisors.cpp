vector<int> div;
for(int i=1; i*i<=n; i++) {
    if(!(n % i)) {
        div.pb(d);
        if(d != n/d) div.pb(n / d);
    }
}
sort(all(div));