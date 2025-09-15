void dfs(int u, int p) {
    sz[u] = 1;
    for(auto &v : adj[u]) {
        if(v == p || centroid[v]) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int getCentroid(int u, int p, int n) {
    for(auto &v : adj[u]) {
        if(v == p || centroid[v]) continue;
        if(2 * sz[v] > n) return getCentroid(v, u, n);
    }
    return u;
}
void getCount(int u, int p, int depth) {
    if(depth > k) return;
    res += 0ll + cnt[k - depth];
    for(auto &v : adj[u]) {
        if(v == p || centroid[v]) continue;
        getCount(v, u, depth+1);
    }
}
void getPaths(int u, int p, int depth, int x) {
    if(depth > k) return;
    cnt[depth] += x;
    for(auto &v : adj[u]) {
        if(v == p || centroid[v]) continue;
        getPaths(v, u, depth+1, x);
    }
}
void decompose(int u, int p) {
    dfs(u, p);
    int c = getCentroid(u, p, sz[u]);
    centroid[c] = 1;
    cnt[0] = 1;
 
    for(auto &v : adj[c]) {
        if(centroid[v]) continue;
        getCount(v, c, 1);
        getPaths(v, c, 1, 1);
    }
 
    getPaths(c, p, 0, -1);
 
    for(auto &v : adj[c]) {
        if(v == c || centroid[v]) continue;
        decompose(v, c);
    }
}