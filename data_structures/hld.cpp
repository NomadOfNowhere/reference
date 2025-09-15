int sz[N], in[N], out[N], timer, head[N], parent[N];
void dfs_sz(int u = 0, int p = -1) {
    sz[u] = 1;
    parent[u] = p;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
        if(adj[u][0] == p || sz[v] > sz[adj[u][0]]) {
            swap(v, adj[u][0]);
        }
    }
}
void dfs_hld(int u = 0, int p = -1) {
    in[u] = timer++;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        head[v] = (adj[u][0] == v ? head[u] : v);
        dfs_hld(v, u);
    }
    out[u] = timer;
}
ll query_path(int u, int v) {
    ll res = 0;
    while(head[u] != head[v]) {
        if(in[u] < in[v]) swap(u, v);
        res += query(0, timer-1, in[head[u]], in[u], 0);
        u = parent[head[u]];
    }
    if(in[u] > in[v]) swap(u, v);
    res += query(0, timer-1, in[u]+1, in[v], 0);  
    // in[u] (node)  / in[u]+1 (edge)
    return res;
}