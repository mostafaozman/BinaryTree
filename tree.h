//
//  tree.h
//  SearchTree
//
//  Created by Mostafa Osman on 3/3/20.
//  Copyright © 2020 Mostafa Osman. All rights reserved.
//

#ifndef TREE_H
#define TREE_H

using namespace std;

class tree
{
public:
    tree(int);
    // setters
    void setRight(tree* inRight);
    void setLeft(tree* inLeft);
    void setPrev(tree* inPrev);
    void setNext(tree* inNext);
    void setRoot(tree* inRoot);
    void setData(int inData);
    
    //getters
    tree* getRight();
    tree* getLeft();
    tree* getNext();
    tree* getRoot();
    int getData();
    // all tree pointers
    tree* next;
    tree* left;
    tree* right;
    tree* prev;
    tree* root;
    int data;
};
#endif