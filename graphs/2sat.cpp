struct two_sat {
    int n;
    vector<vector<int>> g, gr;
    vector<int> comp, topological_order, answer;
    vector<bool> vis;
 
    two_sat(int _n) {
        n = _n;
        g.assign(2 * n, vector<int>());
        gr.assign(2 * n, vector<int>());
        comp.resize(2 * n);
        vis.resize(2 * n);
        answer.resize(2 * n);
    }
 
    void add_edge(int u, int v) {
        g[u].pb(v);
        gr[v].pb(u);
    }
 
    void dfs(int u) {
        vis[u] = true;
        each(v, g[u]) if (!vis[v]) dfs(v);
        topological_order.push_back(u);
    }
 
    void scc(int u, int id) {
        vis[u] = true, comp[u] = id;
        each(v, gr[u]) if (!vis[v]) scc(v, id);
    }
 
    bool satisfiable() {
        fill(vis.begin(), vis.end(), false);
        for (int i = 0; i < 2 * n; i++) if (!vis[i]) dfs(i);
        fill(vis.begin(), vis.end(), false);
        reverse(topological_order.begin(), topological_order.end());
        int id = 0;
        for(const auto &v : topological_order) if (!vis[v]) scc(v, id++);
        for(int i=0; i<n; i++) {
            if (comp[i] == comp[i + n]) return false;
            answer[i] = (comp[i] > comp[i + n] ? 1 : 0);
        }
        return true;
    }
 
    // Conditions
    void add_clause(int a, int b, string op, int c) {
        if(op=="=") {
            if(c==0) add_nor(a, b);
            else if(c==1) add_01_10(a, b);
            else add_and(a, b);
        }
        else if(op=="!=") {
            if(c==0) add_or(a, b);
            else if(c==1) add_same(a, b);
            else add_nand(a, b);
        }
        else if(op=="<") {
            if(c==0) {
                cout<<"No"<<endl;
                exit(0);
            }
            else if(c==1) add_nor(a, b);
            else add_nand(a, b);
        }
        else if(op==">") {
            if(c==0) add_or(a, b);
            else if(c==1) add_and(a, b);
            else {
                cout<<"No"<<endl;
                exit(0);
            }
        }
        else if(op=="<=") {
            if(c==0) add_nor(a, b);
            else if(c==1) add_nand(a, b);
            else return;
        }
        else {
            if(c==0) return;
            else if(c==1) add_or(a, b);
            else add_and(a, b);
        }
    }
    
    void add_nor(int a, int b) {
        add_edge(a, a+n);
        add_edge(b, b+n);
    }
    void add_01_10(int a, int b){
        add_or(a, b);
        add_nand(a, b);
    }
    void add_and(int a, int b) {
        add_edge(a+n, a);
        add_edge(b+n, b);
    }
    void add_or(int a, int b){
        add_edge(a+n, b);
        add_edge(b+n, a);
    }
    void add_same(int a, int b) {
        add_edge(a, b);
        add_edge(b+n, a+n);
        add_edge(a+n, b+n);
        add_edge(b, a);
    }
    void add_nand(int a, int b) {
        add_edge(a, b+n);
        add_edge(b, a+n);
    }
};
 
int main() { io
    int n, m; cin>>n>>m;
    two_sat ts(n);
    rep(i,0,m) {
        int a, b, c; string op;
        cin>>a>>b>>op>>c;
        ts.add_clause(a, b, op, c);
    }
    cout<< (ts.satisfiable() ? "Yes" : "No")<<endl;
    return 0;
}