int color[N];
// directed graph
bool dfs(int u, int p = -1) {
    color[u] = 1;
    for(auto &v : adj[u]) {
        if(!color[v]) if(!dfs(v, u)) return false;
        if(color[v] == 1) return false;
    }
    color[u] = 2;
    return true;
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

