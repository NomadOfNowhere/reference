vector<int> in(n+1), out(n+1), euler(n+1);
int timer = 0;
auto dfs = [&](auto self, int u, int p = -1) -> void {
    in[u] = ++timer;
    euler[timer] = u;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        self(self, v, u);
    }
    out[u] = timer;
};
dfs(dfs, 0);
queries[i] = {in[u], out[u], k, i};
int x = values[euler[idx]];