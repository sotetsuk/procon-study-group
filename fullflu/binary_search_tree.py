#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

# BinaryTree: init, insert, find, and delete.
# inefficient
# Time limit exceeding at the last test (of BinaryTree 2 and 3).

class BinaryTree(object):
    def __init__(self):
        self.tree = None
        self.root = None

    def insert(self,v):
        #v: insert node
        #z: transition node
        z = self.root
        if z == None:
            # tree: {key:[left child, right chile, parent]}
            self.tree = {v:[None,None,None]}
            self.root = v
        else:
            while z != None:
                #y: parent node
                y = z
                if v < z:
                    flg = 0
                    z = self.tree[z][flg]
                else:
                    flg = 1
                    z = self.tree[z][flg]

            self.tree[y][flg] = v
            # insert node v to the tree
            self.tree.update({v:[None,None,y]})

    def inorder(self,z):
        if z == None:
            return
        self.inorder(self.tree[z][0])
        #print "{}".format(z),
        sys.stdout.write(" "+str(z))
        self.inorder(self.tree[z][1])

    def preorder(self,z):
        if z == None:
            return
        #print "{}".format(z),
        sys.stdout.write(" "+str(z))
        self.preorder(self.tree[z][0])
        self.preorder(self.tree[z][1])

    def find(self,v):
        ans = v in self.tree.keys()
        if ans:
            print "yes"
        else:
            print "no"

    def delete(self,v):
        # v: delete node
        if self.root == None or v not in self.tree.keys():
            print "cannot delete, the node:{} is not included in the tree".format(v)
            return
        # parent list is not "list", but parent node.
        parent_list = self.tree[v][2]

        # when v is the root
        if parent_list == None:
            ## when v has no child
            if self.tree[v][:2] == [None,None]:
                # clear tree
                self.root = None
            ## when v has two children
            elif None not in self.tree[v][:2]:
                # go: transition node
                # tmp: change node
                go = self.tree[v][1]
                while go != None:
                    tmp = go
                    go = self.tree[go][0]
                # set root
                self.root = tmp
                # set tmp to a parent
                self.tree[self.tree[v][0]][2] = tmp
                self.tree[self.tree[v][1]][2] = tmp
                # set the left child of the parent of tmp to None
                self.tree[self.tree[tmp][2]][0] = None
                # set the left child of tmp to the left child of v
                self.tree[tmp][0] = self.tree[v][0]
                # when tmp is not the right child of v                
                if self.tree[v][1] != tmp:
                    right_child = self.tree[tmp][1]
                    self.tree[self.tree[tmp][2]][0] = right_child
                    if right_child != None:
                        self.tree[right_child][2] = self.tree[tmp][2]
                    self.tree[tmp][1] = self.tree[v][1]
                self.tree[tmp][2] = parent_list
            ## when v has a left child, but not has a child child
            elif self.tree[v][1] == None:
                self.root = self.tree[v][0]
                self.tree[self.root][2] = None
            ## when v has a right child, but not has a left child
            else:
                self.root = self.tree[v][1]
                self.tree[self.root][2] = None

        # when v is not the root
        ## when v has no child
        elif self.tree[v][:2] == [None,None]:
            if self.tree[parent_list][0] == v:
                self.tree[parent_list][0] = None
            else:
                self.tree[parent_list][1] = None
        ## when v has two children
        elif None not in self.tree[v][:2]:
            # go: transition node
            # tmp: change node
            go = self.tree[v][1]
            while go != None:
                tmp = go
                go = self.tree[go][0]
            # when v is a left child
            if self.tree[parent_list][0] == v:
                self.tree[parent_list][0] = tmp
                self.tree[self.tree[v][0]][2] = tmp
                self.tree[self.tree[v][1]][2] = tmp

                self.tree[tmp][0] = self.tree[v][0]
                # when tmp is not the right child of v
                if self.tree[v][1] != tmp:
                    right_child = self.tree[tmp][1]
                    self.tree[self.tree[tmp][2]][0] = right_child
                    if right_child != None:
                        self.tree[right_child][2] = self.tree[tmp][2]
                    self.tree[tmp][1] = self.tree[v][1]

                self.tree[tmp][2] = parent_list
            # when v is a right child
            else:
                self.tree[parent_list][1] = tmp
                self.tree[self.tree[v][0]][2] = tmp
                self.tree[self.tree[v][1]][2] = tmp
                # when tmp is not the right child of v
                self.tree[tmp][0] = self.tree[v][0]
                if self.tree[v][1] != tmp:
                    right_child = self.tree[tmp][1]
                    self.tree[self.tree[tmp][2]][0] = right_child
                    if right_child != None:
                        self.tree[right_child][2] = self.tree[tmp][2]
                    self.tree[tmp][1] = self.tree[v][1]

                self.tree[tmp][2] = parent_list
        elif self.tree[v][1] == None:
            if self.tree[parent_list][0] == v:
                self.tree[parent_list][0] = self.tree[v][0]
                self.tree[self.tree[v][0]][2] = parent_list
            else:
                self.tree[parent_list][1] = self.tree[v][0]
                self.tree[self.tree[v][0]][2] = parent_list
        else:
            if self.tree[parent_list][0] == v:
                self.tree[parent_list][0] = self.tree[v][1]
                self.tree[self.tree[v][1]][2] = parent_list
            else:
                self.tree[parent_list][1] = self.tree[v][1]
                self.tree[self.tree[v][1]][2] = parent_list
        del self.tree[v]


if __name__ == '__main__':
    i = 0
    bt = BinaryTree()
    n = int(raw_input())
    while i < n:
        i += 1
        #flg = i < n
        #print flg,i,n
        a = raw_input()
        a = a.split(" ")
        #print a[0],a[1]
        if a[0] == "insert":
            bt.insert(int(a[1]))
        elif a[0] == "print":
            #print "",
            #print ""
            bt.inorder(bt.root)
            print ""
            #print "",
            bt.preorder(bt.root)
            print ""
        elif a[0] == "find":
            bt.find(int(a[1]))
        elif a[0] == "delete":
            bt.delete(int(a[1]))
        else:
            print "error input"
