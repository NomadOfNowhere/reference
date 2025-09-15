int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n), l(n), r(n);
    for(auto &it : v) cin >> it; 

    stack<pair<int, int>> st;
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && v[i] < st.top().first) {
            l[st.top().second] = i;
            st.pop();
        }
        st.push({v[i], i});
    } 

    while(!st.empty()) l[st.top().second] = -1, st.pop();

    rep(i,0,n) {
        while(!st.empty() && v[i] <= st.top().first) {
            r[st.top().second] = i;
            st.pop();
        }
        st.push({v[i], i});
    }

    while(!st.empty()) r[st.top().second] = n, st.pop();

    vector<int> res(n);
    rep(i,0,n) {
        int curr = r[i] - l[i] - 1;
        res[curr-1] = max(res[curr-1], v[i]);
    }
    for(int i=n-2; i>=0; i--) {
        res[i] = max(res[i], res[i+1]);
    }

    for(auto &it : res) cout << it << " ";
    cout << endl;

    return 0;
}