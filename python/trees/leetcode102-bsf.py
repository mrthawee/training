def bsf(root):
    if root == None:
        return []

    q = []
    q.append(root)

    res = []
    while len(q) != 0:
        tmp = []
        for i in range (len(q)):
            node = q[0]
            del q[0]

            tmp.append(node.val)

            if node.left != None:
                q.append(node.left)
            if node.right != None:
                q.append(node.right)
        res.append(tmp)

    return res
