
def numPaths(matrix):
    def cp(m,n):
        dp = [ [[0]*(n+1)] *(m+1)]
        print(dp)

        for i in range(0, 2):
            dp[i][0] = 1
        ''' 
        for j in range(0, m):
            dp[0][j] = 1
        ''' 

        print(dp)
        for r in range (1,m):
            for c in range (1, n):
                #dp[r][c] = dp[r-1][c] + dp[r][c-1]
                print(r,c, dp[r][c])

        #return dp[n-1][m-1]

    m = len(matrix)
    n = len(matrix[0])
    return cp(m,n)

if __name__ == '__main__':
    n = 3
    m = 4
    matrix = [ [1,1,1,1],
               [1,1,1,1],
               [1,1,1,1] ]

    res = numPaths(matrix)

    print(res)
