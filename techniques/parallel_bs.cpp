void parallel_bs() {
    vector<array<int, 2>> queries(n+1);
    rep(i,1,n+1) queries[i] = {1, q};
 
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
 
        obj.reset();

        rep(mid,1,q+1) {
            auto &[l, r, k] = values[mid];
            obj.update(l, r, k);
 
            for(auto &idx : mids[mid]) {
                Queries &q = queries[idx];
                if(ok) q.r = mid - 1;
                else q.l = mid + 1;
            }
        }
    }
}