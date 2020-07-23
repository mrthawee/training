def combine(n, k):
    """
    :type n: int
    :type k: int
    :rtype: List[List[int]]
    """

    result = []

    def helper(n, i, k, slate):
        # Backtracking case
        if len(slate) == k:
            result.append(slate[:])
            return

        # Base case
        if i == n+1:
            return

        # Recursive case
        # Exclude i
        helper(n, i+1, k, slate)
        
        # Include i
        slate.append(i)
        helper(n, i+1, k, slate)
        slate.pop()

    helper(n, 0, k, [])

    return result

print(combine(4, 2))
