#define M ((l + r) >> 1)
#define op(x, y) (x + y)
ll st[4*N], lazy[4*N], arr[N];
void build(int l, int r, int i) {
    lazy[i] = 0;
    if (l == r) {st[i] = arr[l]; return;}
    build(l, M, 2*i+1);
    build(M+1, r, 2*i+2);
    st[i] = op(st[2*i+1], st[2*i+2]);
}
void push(int l, int r, int i) {
    if (!lazy[i]) return;
    st[i] += (r-l+1) * lazy[i];   // change for min/max
    if (l != r) {
        lazy[2*i+1] += lazy[i];
        lazy[2*i+2] += lazy[i];
    }
    lazy[i] = 0;   // change for multiplication
}
void update(int l, int r, int a, int b, ll x, int i) {
    push(l, r, i);
    if (a > r || b < l) return;
    if (a <= l && r <= b) {
        lazy[i] += x;
        push(l, r, i);
        return;
    }
    update(l, M, a, b, x, 2*i+1);
    update(M+1, r, a, b, x, 2*i+2);
    st[i] = op(st[2*i+1], st[2*i+2]);
}
ll query(int l, int r, int a, int b, int i) {
    if (a > r || b < l) return 0;   // change for min/max
    push(l, r, i);
    if (a <= l && r <= b) return st[i];
    return op(query(l, M, a, b, 2*i+1), query(M+1, r, a, b, 2*i+2));
}  // i=0, l=0, r=n-1, x=value, a,b=range query