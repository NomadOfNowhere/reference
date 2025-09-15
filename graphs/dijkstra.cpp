void dijkstra(int start, int n) {
    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    for(int i=0; i<n; i++) {
        dist[i] = 1e14;
    }

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto &[v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}