// op de los pesos de las aristas en el camino u-v (min, max, gcd, ...)
// Llamar dfs1(root, root, NEUTRO)
#define op(a,b) min(a,b)
const int NEUTRO = 1e9;
int depth[N], up[N][LOG], upm[N][LOG];
void dfs1(int u, int p, int w) {
    up[u][0] = p;
    upm[u][0] = w;
    rep(i,1,LOG) {
        up[u][i] = up[up[u][i-1]][i-1];
        upm[u][i] = op(upm[u][i-1], upm[up[u][i-1]][i-1]);
    }
    for(auto &[v, c] : adj[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs1(v, u, c);
    }
}
int query(int u, int v) {
    int ans = NEUTRO;
    if(depth[u] < depth[v]) swap(u, v);
    for(int i=LOG-1; i>=0; i--) {
        if(depth[u] - (1 << i) >= depth[v]) {
            ans = op(ans, upm[u][i]);
            u = up[u][i];
        }
    }
    if(u == v) return ans;
    for(int i=LOG-1; i>=0; i--) {
        if(up[u][i] != up[v][i]) {
            ans = op(ans, op(upm[u][i], upm[v][i]));
            u = up[u][i];
            v = up[v][i];
        }
    }
    return op(ans, op(upm[u][0], upm[v][0]));
}
