// Centroid decomposition: O(n log n), el arbol de centroides tiene
// profundidad O(log n). par[c] = padre de c en el arbol de centroides.
// Llamar decompose(1). Todo camino u-v pasa por el centroide que los separa.
int sz[N], par[N];
bool removed[N];
// tamano de los subarboles (ignorando nodos ya removidos)
int dfs(int u, int p) {
    sz[u] = 1;
    for(int v : adj[u]) if(v != p && !removed[v]) sz[u] += dfs(v, u);
    return sz[u];
}
// baja al hijo con mas de n/2 nodos hasta que no haya ninguno
int getCentroid(int u, int p, int n) {
    for(int v : adj[u]) if(v != p && !removed[v] && 2 * sz[v] > n) return getCentroid(v, u, n);
    return u;
}
void decompose(int u, int p = -1) {
    int c = getCentroid(u, -1, dfs(u, -1));
    removed[c] = 1, par[c] = p;
    // aqui va lo del problema, con c como raiz
    for(int v : adj[c]) if(!removed[v]) decompose(v, c);
}
