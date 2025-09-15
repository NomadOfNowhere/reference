// Compute prefix sum 2D
rep(i,1,n+1) rep(j,1,m+1) 
    prefix[i][j] = prefix[i-1][j] + prefix[i][j-1]
                                  - prefix[i-1][j-1]
                                  + matrix[i-1][j-1]

// Query prefix sum 2D
res = prefix[i][j] - prefix[i-1][j] - prefix[i][j-1] + prefix[i-1][j-1]