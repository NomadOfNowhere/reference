const int N = 3e5+5, B = 550;
int values[N], freq[N], res[N], ans, has[B];
void add(int idx) {
    has[values[idx]/B]++;
    freq[values[idx]]++;
}
void remove(int idx) {
    has[values[idx]/B]--;
    freq[values[idx]]--;
}
int getAns(int k) {
    rep(i,0,B) if(has[i] > k) rep(j,i*B,(i+1)*B) 
        if(freq[j] > k) return j;
    return -1;
}
void mos(vector<array<int, 4>> &queries) {
    sort(all(queries), [](array<int, 4> &a, array<int, 4> &b) {
        if(a[0]/B != b[0]/B) return a[0] < b[0];
        return (a[0]/B & 1 ? a[1] < b[1] : a[1] > b[1]);
    });
 
    int l = 0, r = -1;
    for(auto &[ql, qr, k, idx] : queries) {
        while(l > ql) add(--l);
        while(r < qr) add(++r);
        while(l < ql) remove(l++);
        while(r > qr) remove(r--);
        res[idx] = getAns(k);
    }
}