// Compute prefix sum 2D
rep(i,1,n+1) rep(j,1,m+1) 
    prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] 
                                  - prefix[i-1][j-1] 
                                  + matrix[i-1][j-1]

// Query prefix sum 2D
query = prefix[i][j] - prefix[i-1][j] - prefix[i][j-1] + prefix[i-1][j-1]

// Specific parts
query = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];