struct DSU{
    int n;
    vector<int> parent, rank;
    DSU(int _n) : n(_n), parent(_n), rank(_n) {
        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a), b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
    int components() {
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(find_set(i) == i) cnt++;
        }
        return cnt;
    }
};