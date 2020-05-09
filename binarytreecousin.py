# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        xinfo = []
        yinfo = []
        depth = 0
        parent = None
        if root is None:
            return False

        self.dfs(root,x,y,0,None,xinfo,yinfo)
        return xinfo[0][0]==yinfo[0][0] and xinfo[0][1]!=yinfo[0][1]

        def dfs(self,root,x,y,depth,parent,xinfo,yinfo):
            if root is None:
                return None
            if root.val == x:
                xinfo.append((depth,parent))
            if root.val == y:
                yinfo.append((depth,parent))

            self.dfs(root.left,x,y,depth+1,root,xinfo,yinfo)
            self.dfs(root.right,x,y,depth+1,root,xinfo,yinfo)


    
