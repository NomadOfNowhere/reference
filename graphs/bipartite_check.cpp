int color[N];
bool f = 1;
// memset(color, -1, sizeof(color));
bool dfs(int u = 0, int c = 0) {
    color[u] = c;
    for(auto &v : adj[u]) {
        if(color[v] == -1 && !dfs(v, 1-c)) return false;
        else if(color[v] == c) return false;
    }
}