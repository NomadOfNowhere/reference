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
    if(idx > r || idx < l) return 0;       // change for min/max
    if(idx <= l && r <= idx) return st[i];
    return op(op(query(l, M, idx, 2*i+1), query(M+1, r, idx, 2*i+2)), st[i]);
}