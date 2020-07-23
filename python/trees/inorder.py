def inorder-dfs(root):
    inorder-dfs(root.left)
    print(root.val)
    inorder-dfs(root.right)
