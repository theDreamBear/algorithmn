#
# @lc app=leetcode.cn id=222 lang=python3
#
# [222] 完全二叉树的节点个数
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def treeHigh(root):
    h = 0
    while root:
        h += 1
        root = root.left
    return h


def treeRightHigh(root):
    h = 0
    while root:
        h += 1
        root = root.right
    return h



def exist(root, value, index):
    while root and index > 1:
        v = (1 << (index - 2))
        if value & v:
            value ^= v
            root = root.right
        else:
            root = root.left
        index -= 1
    return root is not None


class Solution:
    def countNodes1(self, root: Optional[TreeNode]) -> int:
        # 空
        if root is None:
            return 0
        high = treeHigh(root)
        left = 1 << (high - 1)
        right = (1 << high) - 1
        while left + 1 < right:
            mid = (left + right) // 2
            if exist(root, mid, high):
                left = mid
            else:
                right = mid
        if exist(root, right, high):
            return right
        return left

    def countNodes(self, root: Optional[TreeNode]) -> int:
        # 空
        if root is None:
            return 0
        left = treeHigh(root)
        right = treeRightHigh(root)
        if left == right:
            return (1 << left) - 1
        left_sum = self.countNodes(root.left)
        right_sum = self.countNodes(root.right)
        return left_sum + right_sum + 1
# @lc code=end

