struct node {
    int ch[26] = {};
    int fin = 0, suffixLink = 0, endLink = 0;
};
vector<node> aho;

void init() { aho.assign(1, node()); }

void insert(string s) {
    int curr = 0;
    for (int i = 0; i < SZ(s); i++) {
        if (!aho[curr].ch[s[i] - 'a']) {
            aho[curr].ch[s[i] - 'a'] = SZ(aho);
            aho.push_back(node());
        }
        curr = aho[curr].ch[s[i] - 'a'];
    }
    aho[curr].fin = s.size();
}

void initAho() {
    queue<int> q;
    rep(i, 0, 26) if (aho[0].ch[i]) q.push(aho[0].ch[i]);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        rep(i, 0, 26) {
            int v = aho[u].ch[i];
            if (v) {
                aho[v].suffixLink = aho[aho[u].suffixLink].ch[i], q.push(v);
                if (aho[aho[v].suffixLink].fin) aho[v].endLink = aho[v].suffixLink;
                else aho[v].endLink = aho[aho[v].suffixLink].endLink;
            }
            else aho[u].ch[i] = aho[aho[u].suffixLink].ch[i];
        }
    }
}

void search(string &t) {
    int u = 0;
    for (int i = 0; i < SZ(t); i++) {
        u = aho[u].ch[t[i] - 'a'];
        for (int v = aho[u].fin ? u : aho[u].endLink; v; v = aho[v].endLink) {
            // patron de longitud aho[v].fin termina en i
        }
    }
}
