#
# @lc app=leetcode.cn id=106 lang=python3
#
# [106] 从中序与后序遍历序列构造二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if len(inorder) == 0 or len(postorder) == 0:
            return None
        delimiter = 0
        val = postorder[len(postorder) - 1]

        for i in range(len(inorder)):
            if inorder[i] == val:
                delimiter = i
                break
            
        root = TreeNode(val)

        inLeft = inorder[:delimiter]
        inRight = inorder[delimiter + 1:]

        postLeft = postorder[:len(inLeft)]
        postRight = postorder[len(inLeft): -1]

        root.left = self.buildTree(inLeft, postLeft)
        root.right = self.buildTree(inRight, postRight)
        return root
# @lc code=end

