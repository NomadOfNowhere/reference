vector<int> greatestPrimeFactor(int n){
	vector<int> gp(n+1);
	iota(gp.begin(), gp.end(), 0);
	for(int i = 4; i <= n; i += 2) gp[i] = 2;
	for(int i = 3; i <= n; i += 2)
		if(gp[i] == i)
			for(int j = 2*i; j <= n; j += i)
				gp[j] = i;
	return gp;
}