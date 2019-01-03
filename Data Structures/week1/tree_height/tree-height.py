# python3

import sys, threading
sys.setrecursionlimit(10**7) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

class TreeHeight:
        def __init__(self):
                self.n=0
                self.parent=[]
                self.memoize=[]
        def read(self):
                self.n = int(sys.stdin.readline())
                self.parent = list(map(int, sys.stdin.readline().split()))
                self.memoize=[0]*self.n
        def node2nodedist(self,node_index):
                parent=self.parent[node_index]
                if parent==-1:
                        return 1
                if self.memoize[node_index]!=0:
                        return self.memoize[node_index]
                self.memoize[node_index]=1+self.node2nodedist(self.parent[node_index])
                return self.memoize[node_index]
        def compute_height(self):
                return max([self.node2nodedist(i) for i in range(self.n)])
                
"""
        def compute_height(self):
                # Replace this code with a faster implementation
                maxHeight = 0
                for vertex in range(self.n):
                        height = 0
                        i = vertex
                        while i != -1:
                                height += 1
                                i = self.parent[i]
                        maxHeight = max(maxHeight, height);
                return maxHeight;
                """

def main():
  tree = TreeHeight()
  tree.read()
  print(tree.compute_height())

threading.Thread(target=main).start()
