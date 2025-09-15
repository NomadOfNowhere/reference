int in[N], low[N], timer;
/* Articulation bridges */
void dfs(int u, int p = -1) {
    in[u] = low[u] = ++timer;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        if(!in[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > in[u]) IS_BRIDGE(U, V);
        }
        else low[u] = min(low[u], in[v]);
    }
}

/* Bridge tree */
// Use dfs to find bridges, but change
if(low[v] <= in[u]) dsu.union_sets(u, v);

// Iterate over the edges
for(auto [u, v] : edges) {
    u = dsu.find_set(u);
    v = dsu.find_set(v);
    if(u != v) {
        bridgeTree[u].pb(v);
        bridgeTree[v].pb(u);
    }
}

/* Articulation points */
// Use same code as finding bridges
if(low[v] >= in[u]) IS_ARTICULATION_POINT(U, V);