int sa[N], lcp[N];
int t_sa[N], c[N];
void countingSort (string &s, int ra[], int k) {
	memset(t_sa, 0, sizeof(t_sa));
	memset(c, 0, sizeof(c));
    int sum, n = s.size(), mx = max(300, n);

    for (int i = 0; i < n; i++)
        c[i+k<n?ra[i+k]:0]++;

    for (int i = sum = 0; i < mx; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (int i = 0; i < n; i++)
        t_sa[c[sa[i]+k<n?ra[sa[i]+k]:0]++] = sa[i];

    for (int i = 0; i < n; i++) sa[i] = t_sa[i];
}
 
int t_ra[N], ra[N];
void obtSA (string &s) {
    memset(t_ra, 0, sizeof(t_ra));
    memset(ra, 0, sizeof(ra));
    int r, n = s.size();

    for (int i = 0; i < n; i++) ra[i] = s[i];
    for (int i = 0; i < n; i++) sa[i] = i;
    for (int k = 1; k < n; k <<= 1) {
        countingSort(s, ra, k);
        countingSort(s, ra, 0);
        t_ra[s[0]] = r = 0;
        for (int i = 1; i < n; i++)
            if (ra[sa[i]] == ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k])
                t_ra[sa[i]] = r;
            else
                t_ra[sa[i]] = ++r;
        for (int i = 0; i < n; i++) ra[i] = t_ra[i];
        if (ra[sa[n-1]] == n-1) break;
    }
}
 
int phi[N], plcp[N];
void obtLCP (string &s) {
    int n = s.size();
    phi[sa[0]] = -1;
    
    for (int i = 1; i < n; i++) phi[sa[i]] = sa[i-1];
    for (int i = 0, l = 0; i < n; i++) {
        if (phi[i] == -1) {
            plcp[i] = 0;
            continue;
        }
        while (s[i+l] == s[phi[i]+l]) l++;
        plcp[i] = l;
        l = max(l-1, 0);
    }
    for (int i = 0; i < n; i++) lcp[i] = plcp[sa[i]];
}

// Sorting lexicographically using idx l, r
sort(all(res), [](const pair<int, int> &a, const pair<int, int> &b) {
    int szA = a.second-a.first+1, szB = b.second-b.first+1;
    if(a.first == b.first) return szA < szB;
    int prefix = st_query(min(ra[a.first], ra[b.first])+1, max(ra[a.first], ra[b.first]));
    int mn = min(szA, szB);
    if(prefix >= mn) {
        if(szA == szB) return a < b;
        return szA < szB;
    }
    return ra[a.first] < ra[b.first];
});
// Count distinct
for(1, n) 
    sum += 1ll*n - sa[i] - lcp[i];

// Usage
// s += "#"; obtSA(s); obtLCP(s);

