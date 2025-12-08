// Range update - point query
// same as classic segment tree, but comment this line #!
void update(int l, int r, int a, int b, int x, int i) {
    if (a > r || b < l) return;
    if (a <= l && r <= b) {
        st[i] += x;
        return;
    }
    update(l, M, a, b, x, 2*i+1);
    update(M+1, r, a, b, x, 2*i+2);
}

int query(int l, int r, int idx, int i) {
    if(l == r) return st[i];
    
    int sum;
    if(idx <= M) sum = query(l, M, idx, 2*i+1);
    else sum = query(M+1, r, idx, 2*i+2);
    return op(sum, st[i]);
}