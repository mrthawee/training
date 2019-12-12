def generate(numRows):
    if numRows == 0:
        return []

    curRow = []
    triangle = []

    for n in range (0, numRows):
        curRow.append(1)
        nextRow = list(curRow)
        print('nextRow',n, '=',nextRow)


        for i in range(1,len(nextRow)-1):
            #nextRow[i] = curRow[i-1] + curRow[i]
            nextRow[i] = triangle[n-1][i-1] + triangle[n-1][i]

        triangle.append(nextRow)

    print('triangle=',triangle)

def leetcode_soln(numRows):
    triangle = []

    for n in range (0, numRows):        # row_index = 0, 1, 2, 3
        #row = [ None for _ in range (n+1)]
        #row[0], row[-1] = 1, 1
        row = [ 1 for _ in range (n+1)]

        for i in range(1,len(row)-1):   # elem_index = 1, 2, 3, .. , n-1
            row[i] = triangle[n-1][i-1] + triangle[n-1][i]

        triangle.append(row)
    print('triangle=',triangle)

    return triangle

if __name__ == '__main__':
    #generate(2)
    #generate(3)
    leetcode_soln(5)
