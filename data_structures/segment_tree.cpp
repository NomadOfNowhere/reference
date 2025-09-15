#define M ((l + r) >> 1)
#define op(x, y) (x + y)
int st[4*N], values[N];
void build(int l, int r, int i) {
    if(l == r) {
        st[i] = values[l];
        return;
    }
    build(l, M, 2*i+1);
    build(M+1, r, 2*i+2);
    st[i] = op(st[2*i+1], st[2*i+2]);  // #!
}
// Point update - range query
void update(int l, int r, int idx, int x, int i) {
    if(l == r) {
        st[i] += x;
        return;
    }
    if(idx <= M) update(l, M, idx, x, 2*i+1);
    else update(M+1, r, idx, x, 2*i+2);
    st[i] = op(st[2*i+1], st[2*i+2]);
}
int query(int l, int r, int a, int b, int i) {
    if(a > r || b < l) return 0;       // change for min/max
    if(a <= l && r <= b) return st[i];
    return op(query(l, M, a, b, 2*i+1), query(M+1, r, a, b, 2*i+2));
} 
// l = 0, r = n-1, i = 0