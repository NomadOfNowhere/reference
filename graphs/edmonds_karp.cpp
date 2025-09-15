const int N = 1e3+5;
vector<int> adj[N];
int parent[N], cap[N][N];

void add_edge(int u, int v, int c) {
    adj[u].pb(v);
    adj[v].pb(u);
    cap[u][v] += c;
}
int bfs(int s, int t) {
    memset(parent, -1, sizeof(parent));
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, (int)1e9});

    while(!q.empty()) {
        auto [u, f] = q.front();
        q.pop();

        for(auto &v : adj[u]) {
            if(parent[v] != -1 || !cap[u][v]) continue;

            parent[v] = u;
            int flow = min(cap[u][v], f);
            if(v == t) return flow;

            q.push({v, flow});
        }
    }
    return 0;
}
int maxFlow(int s, int t) {
    int mx = 0, flow;
    while(flow = bfs(s, t)) {
        mx += flow;
        int curr = t;
        while(curr != s) {
            int prev = parent[curr];
            cap[prev][curr] -= flow;
            cap[curr][prev] += flow;
            curr = prev;
        }
    }
    return mx;
}
