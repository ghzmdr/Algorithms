def binc(n,m):
    bc = [[0 for i in range(1000)] for j in range(1000)];

    for x in range(m+1):
        bc[0][x] = 1;
    bc[1][0] = 1;
        
    for i in range(1,n):
        for j in range(i+1):            
            print("I", i, "J", j);
            bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
            print(bc[i][j]);
            
    return bc[n][m];





print(binc(5,2));