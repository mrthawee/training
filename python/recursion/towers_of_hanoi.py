def TowerOfHanoi(numDisks, startPeg, endPeg, aux):
    if numDisks:
        TowerOfHanoi(numDisks-1, startPeg, aux, endPeg)
        print("Move disk %d from peg %d to peg %d" % (numDisks, startPeg, endPeg))
        TowerOfHanoi(numDisks-1, aux, endPeg, startPeg)

TowerOfHanoi(2, 1, 3, 2)
