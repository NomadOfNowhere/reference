// Parallel Binary Search
void parallel_bs() {
    // Rango de busqueda de cada query: [l, r] = [1, q]
    vector<array<int, 2>> queries(n+1);
    for(int i=1;i<=n;i++) queries[i] = {1, q};
    bool f = 1;
    while(f) {
        f = 0;
        vector<vector<int>> mids(m+2);
        for(auto &it : queries) {
            if(it.l <= it.r) {
                int mid = (it.l + it.r) >> 1;
                mids[mid].pb(it.idx);
                f = 1;
            }
        }
        // Resetear Estructura
        obj.reset();
        for(int mid=1;mid<=q;mid++) {
            // Aplicar el update mid; ya estan aplicados los updates 1..mid
            auto &[l, r, k] = values[mid];
            obj.update(l, r, k);
 
            for(auto &idx : mids[mid]) {
                Queries &q = queries[idx];
                // ok: la query idx ya se cumple con la estructura actual
                if(ok) q.r = mid - 1;
                else q.l = mid + 1;
            }
        }
    }
}