# time = O(n)
# since we need to examine every element once

# space = O(n)
# If full Bin Tree, the leaf level has n/2 nodes --> O(n) 

def isBST(root):
    if root is None:
        return []

    result = []
    
    q = collections.deque([root])
    while len(q) != 0:
        numnodes = len(q)
        temp = []
        for _ in range(numnodes):
            node = q.popleft()
            if node.left is not None:
                q.append(node.left)
            if node.right is not None:
                q.append(node.right)
        result.append(temp)
    return result
