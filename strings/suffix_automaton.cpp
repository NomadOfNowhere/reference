const int M = 27;
struct state{
	int len, link;
	vector<int> child;
	state(int len = 0, int link = -1): len(len), link(link), child(M, -1){}
	state(int len, int link, const vector<int> &child): len(len), link(link), child(child){}
};

struct SuffixAutomaton{
	vector<state> st;
	int last = 0;
	SuffixAutomaton(){
		st.emplace_back();
	}
	void extend(char c){
		int curr = st.size();
		st.emplace_back(st[last].len + 1);
		int p = last;
		while(p != -1 && st[p].child[c-'A'] == -1){
			st[p].child[c-'A'] = curr;
			p = st[p].link;
		}
		if(p == -1){
			st[curr].link = 0;
		}
        else{
			int q = st[p].child[c-'A'];
			if(st[p].len + 1 == st[q].len){
				st[curr].link = q;
			}else{
				int clone = st.size();
				st.emplace_back(st[p].len + 1, st[q].link, st[q].child);
				while(p != -1 && st[p].child[c-'A'] == q){
					st[p].child[c-'A'] = clone;
					p = st[p].link;
				}
				st[q].link = st[curr].link = clone;
			}
		}
		last = curr;
	}
};

// extras
void compute_counts() {
    int n = st.size();
    vector<int> order[n+1];
    for(int i=1; i<n; i++)
        order[st[i].len].pb(i);
    for(int i=n-1; i>=0; i--) {
        for(auto &u : order[i]) {
            int prev = st[u].link;
            if(prev != -1)
                st[prev].cnt += st[u].cnt;
        }
    }
}

ll compute_distinct() {
    ll total = 0;
    for(int i=1; i<(int)st.size(); i++) 
        total = total + st[i].len - st[st[i].link].len;
    return total;
}

ll dp_distinct_dfs(int curr) {
    // pre: dp(st)={-1} - init: dfs(0)-1
    auto &x = dp[curr];
    if(x != -1) return x;
    x = 1;
    for(int i=0; i<M; i++) {
        if(st[curr].child[i] != -1) {
            x += dp_distinct_dfs(st[curr].child[i]);
        }
    }
    return x;
}
// Usage 
// SuffixAutomaton sa;
// for(it : s) sa.extend(it);

