vector<int> adj[N]; // [0,n)->[0,m)
int n, m, mat[M];
bool vis[N];
int match(int x){
	if(vis[x]) return 0;
	vis[x] = 1;
	for(auto y : adj[x]) if(mat[y]<0 || match(mat[y])) {mat[y]=x; return 1;}
	return 0;
}
vector<pair<int,int>> max_matching(){
	vector<pair<int, int>> r;
	memset(mat, -1, sizeof(mat));
	for(int i=0; i<n; i++) memset(vis, false, sizeof(vis)), match(i);
	for(int i=0; i<m; i++) if(mat[i] >= 0) r.pb({mat[i], i});
	return r;
}