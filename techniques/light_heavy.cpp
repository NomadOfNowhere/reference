vector<pair<int, int>> adj[N];
bitset<N> heavy;
const int B = 2050;
vector<pair<int, int>> heavyVertices[N];
int values[N], deg[N];

void solve() {
    ll res = 0;
    auto dfs = [&](auto self, int u, int p = -1) -> void {
        for(auto &[v, x] : adj[u]) {
            if(v == p) continue;
            if(values[u] != values[v]) res += 1ll * x;
            deg[u]++, deg[v]++;
            self(self, v, u);
        }
    };
    dfs(dfs, 0);

    rep(i,0,n) if(deg[i] >= B) heavy[i] = 1;

    rep(u,0,n) {
        if(heavy[u]) {
            for(auto &[v, x] : adj[u]) {
                colors[u][values[v]] += 1ll * x;
                if(heavy[v]) 
                    heavyVertices[u].pb({v, x});
                    heavyVertices[v].pb({u, x});
            }
        }
    }

    while(q--) {
        int u, c;
        cin >> u >> c;
        u--;

        if(heavy[u]) {
            res += 1ll * colors[u][values[u]];
            res -= 1ll * colors[u][c];
            for(auto &[v, x] : heavyVertices[u]) {
                colors[v][values[u]] -= 1ll * x;
                colors[v][c] += 1ll * x;
            }
            values[u] = c;
        }
        else {
            for(auto &[v, x] : adj[u]) {
                if(values[u] != values[v]) {
                    if(c == values[v]) res -= 1ll * x;
                }
                else {
                    if(c != values[v]) {
                        res += 1ll * x;
                    }
                }
                if(heavy[v]) {
                    colors[v][values[u]] -= 1ll * x;
                    colors[v][c] += 1ll * x;
                }
            }
            values[u] = c;
        }

        cout << res << endl;
    }
}