int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for(auto &it : a) cin >> it;
    for(auto &it : b) cin >> it;

    auto subsets = [](vector<long long> &a, vector<long long> &b, bool f){
        int n = a.size();
        vector<long long> aux;
        for(int mask=0; mask<(1<<n); mask++) {
            long long sum = 0;
            for(int j=0; j<n; j++) {
                if((1 << j) & mask) sum += a[j];
                else sum -= b[j];
            }
            if(f) sum = abs(sum);
            aux.push_back(sum);
        }
        return aux;
    };

    if(n <= 20) {
        vector<long long> res = subsets(a, b, 1);
        sort(res.begin(), res.end());
        for(auto &it : res) cout << it << " ";
        cout<< endl;
        return 0;
    }

    vector<long long> leftA(a.begin(), a.begin()+n/2),
                      leftB(b.begin(), b.begin()+n/2),
                      rightA(a.begin()+n/2, a.end()),
                      rightB(b.begin()+n/2, b.end());

    vector<long long> left = subsets(leftA, leftB, 0),
                      right = subsets(rightA, rightB, 0);
    sort(right.begin(), right.end());

    priority_queue<tuple<long long, int, int, int>, vector<tuple<long long, int, int, int>>, greater<tuple<long long, int, int, int>>> pq;
    for(int i=0; i<left.size(); i++) {
        int idx = lower_bound(right.begin(), right.end(), -left[i]) - right.begin();
        long long best = LONG_LONG_MAX, curr;
        int idxBest;
        for(int j=-1; j<=1; j++) {
            if(idx + j >= 0 && idx + j < right.size()) {
                curr = abs(left[i] + right[idx+j]);
                if(curr < best) {
                    best = curr;
                    idxBest = idx+j;
                }
            }
        }
        pq.push({best, idxBest, i, 0});
    }

    int req = 1 << 20, cnt = 0;
    while(!pq.empty() && cnt < req) {
        auto [sum, idx, i, event] = pq.top();
        pq.pop();
        cout << sum << " ";
        cnt++;
        if(event <= 0 && idx-1 >= 0) {
            long long lsum = abs(left[i] + right[idx-1]);
            pq.push({lsum, idx-1, i, -1});
        }
        if(event >=0 && idx+1 < right.size()) {
            long long rsum = abs(left[i] + right[idx+1]);
            pq.push({rsum, idx+1, i, 1});
        }
    }
    cout << endl;

    return 0;
}