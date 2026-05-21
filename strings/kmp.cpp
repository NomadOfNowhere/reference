vector<int> prefix_function(const string &s){
    int n=s.length();
    vector<int>pi(n);
    for(int i=1,j=0; i<n; i++){
        while(j>0 && s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j])j++;
        pi[i]=j;
    }
    return pi;
}

vector<int> kmp_search(const string &s, const string &t){
    vector<int> ocu, pi=prefix_function(s);
    int n=s.length(), m=t.length();

    for(int i=0,j=0; i<m; i++){
        while(j>0 && t[i]!=s[j]) j=pi[j-1];
        if(t[i]==s[j]) j++;
        if(j==n) {
            ocu.pb(i-j+1);
            j=pi[j-1];
        }
    }
    return ocu;
}
// s=pattern, t=text