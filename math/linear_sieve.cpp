const int N = 1e7+5;  // N: range to get primes
int p[N];
vector<int> pr;
void linearSieve() {    
    for(int i=2; i<N; i++) {
        if(!p[i]) {
            p[i] = i;
            pr.push_back(i);
        }
        for(int j=0; i*pr[j] < N; j++) {
            p[i*pr[j]] = pr[j];
            if(pr[j] == p[i]) 
                break;
        }
    }
}