int color[N];
// directed graph
bool dfs(int u, int p = -1) {
    color[u] = 1;
    for(auto &v : adj[u]) {
        if(!color[v] && dfs(v, u)) return true;
        if(color[v] == 1) return true;
    }
    color[u] = 2;
    return false;
}

// undirected graph
bool dfs(int u, int p = -1) {
    color[u] = 1;
    parent[u] = p;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        if(!color[v]) {
            if(dfs(v, u)) return true;
        }
        else {
            t = u, s = v;
            return true;
        }
    }
    return false;
}

