int depth[N], up[N][LOG];
void dfs1(int u, int p) {
    up[u][0] = p;
    rep(i,1,LOG) {
        if(up[u][i-1] != -1) 
            up[u][i] = up[up[u][i-1]][i-1];
        else
            up[u][i] = -1;
    }
    for(auto &v : adj[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs1(v, u);
    }
}
int lift(int u, int k) {
    for(int i=LOG-1; i>=0; i--) {
        if(k & (1 << i)) {
            u = up[u][i];
            if(u == -1) return 0;
        }
    }
    return u;
}
int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    u = lift(u, depth[u] - depth[v]);
    if(u == v) return u;
 
    for(int i=LOG-1; i>=0; i--) {
        if(up[u][i] != -1 && up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0] == -1 ? 0 : up[u][0];
}