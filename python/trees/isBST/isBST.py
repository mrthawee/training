import math
import os
import random
import re
import sys

sys.setrecursionlimit(101000)

class TreeNode():
    def __init__(self, val=None, left_ptr=None, right_ptr=None):
        self.val = val
        self.left_ptr = left_ptr
        self.right_ptr = right_ptr

class BinaryTree():
    class Edge():
        def __init__(self, parentNodeIndex=None, childNodeIndex=None, leftRightFlag=None):
            self.BinaryTree = BinaryTree
            self.parentNodeIndex = parentNodeIndex
            self.childNodeIndex = childNodeIndex
            self.leftRightFlag = leftRightFlag

    def __init__(self):
        self.root = None
        self.noOfNodes = 0
        self.noOfEdges = 0
        self.rootIndex = -1
        self.nodeValues = []
        self.edges = []

    def readRawValues(self):
        self.noOfNodes = int(input())
        if self.noOfNodes > 0:
            nodeValueString = input().split(' ')
            for val in nodeValueString:
                self.nodeValues.append(int(val))

            self.rootIndex = int(input())
            self.noOfEdges = int(input())
            for i in range(self.noOfEdges):
                edgeInput = input().split(' ')
                self.edges.append(self.Edge(int(edgeInput[0]), int(edgeInput[1]), edgeInput[2]))

    def buildFromRawValues(self):
        if self.noOfNodes == 0:
            root = None
            return

        nodes = []
        for i in range(self.noOfNodes):
            nodes.append(TreeNode(self.nodeValues[i]))

        for i in range(self.noOfEdges):
            if self.edges[i].leftRightFlag == "L":
                nodes[self.edges[i].parentNodeIndex].left_ptr = nodes[self.edges[i].childNodeIndex]
            else:
                nodes[self.edges[i].parentNodeIndex].right_ptr = nodes[self.edges[i].childNodeIndex]

        self.root = nodes[self.rootIndex]

def readBinaryTree():
    inputBinaryTree = BinaryTree()
    inputBinaryTree.readRawValues()
    inputBinaryTree.buildFromRawValues()
    return inputBinaryTree.root

def helper(node, min_val, max_val):
    if node == None:
        return True
    elif (node.val < min_val or node.val > max_val):
        return False

    return helper(node.left_ptr, min_val, node.val) and helper(node.right_ptr, node.val, max_val)

def isBST(root):
    return helper(root, pow(-10,9), pow(10,9))

#if __name__ == "__main__":
def main():
    root = readBinaryTree()
    result = isBST(root)
    if result:
        print(1)
    else:
        print(0)

main()
