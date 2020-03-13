//
//  tree.cpp
//  SearchTree
//
//  Created by Mostafa Osman on 3/3/20.
//  Copyright © 2020 Mostafa Osman. All rights reserved.
//

#include <iostream>
#include "tree.h"

// A tree node will have a left pointer, right pointer, data, and a next
tree::tree(int setData)
{
    data = setData;
    right = NULL;
    left = NULL;
    next = NULL;
    root = NULL;
}

void tree::setRight(tree* inRight)
{
    right = inRight;
}

tree* tree::getRight()
{
    return right;
}

void tree::setLeft(tree* inLeft)
{
    left = inLeft;
}

tree* tree::getLeft()
{
    return left;
}

void tree::setRoot(tree* inRoot)
{
    root = inRoot;
}

tree* tree::getRoot()
{
    return root;
}

void tree::setNext(tree* inNext)
{
    next = inNext;
}

tree* tree::getNext()
{
    return next;
}

void tree::setData(int inData)
{
    data = inData;
}

int tree::getData()
{
    return data;
}
