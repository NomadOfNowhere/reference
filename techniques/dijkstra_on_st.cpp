vector<pair<int, int>> adj[2*4*N];
ll dist[2*4*N];
int mp[N], vis[2*4*N];
void build(int l, int r, int i) {
    if (l == r) {
        mp[l] = i;
        adj[i].pb({i+4*N, 0});
        adj[i+4*N].pb({i, 0});
        return;
    }
    int m = (l+r)>>1;
    build(l, m, 2*i+1);
    build(m+1, r, 2*i+2);
    adj[i].pb({2*i+1, 0});
    adj[i].pb({2*i+2, 0});
    adj[2*i+1+4*N].pb({i+4*N, 0});
    adj[2*i+2+4*N].pb({i+4*N, 0});
}
void add(int l, int r, int u, int a, int b, int w, int op, int i) {
    if (a > r || b < l) return;
    if (a <= l && r <= b) {
        if(op == 2) adj[mp[u]].pb({i, w});
        else adj[i+4*N].pb({mp[u]+4*N, w});
        return;
    }
    int m = l+r>>1;
    add(l, m, u, a, b, w, op, 2*i+1);
    add(m+1, r, u, a, b, w, op, 2*i+2);
}