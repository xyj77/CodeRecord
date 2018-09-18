# -*- coding: utf-8 -*-

class BinaryTree(object):
    def __init__(self,value=0):
        self.value=value
        self.left=None
        self.right=None

    def is_leaf(self):
        return self.left is None and self.right is None

class BinarySearchTree(BinaryTree):
    def __init__(self,value=0):
        super(BinarySearchTree,self).__init__(value)

    def insert(self,node):
        if node.value>self.value:
            self.right=self.right and self.right.insert(node) or node
        else:
            self.left=self.left and self.left.insert(node) or node
        return self

def preorder(root):
    if root:
        print root.value
        preorder(root.left)
        preorder(root.right)


def inorder(root):
    if root:
        inorder(root.left)
        print root.value
        inorder(root.right)


def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print root.value


if __name__=="__main__":
    N = int(raw_input())
    nodes=[int(x) for x in raw_input().strip().split(' ')]
    root=BinarySearchTree(nodes[0])
    length = len(nodes)
    for i in range(1, length):
        root.insert(BinarySearchTree(nodes[i]))

    preorder(root)
    inorder(root)
    postorder(root)
