//
//  main.cpp
//  SearchTree
//
//  Created by Mostafa Osman on 3/3/20.
//  Copyright © 2020 Mostafa Osman. All rights reserved.

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include "tree.h"

using namespace std;
void buildTree(int value, tree* current);
void visualPrint(tree* root, int space);
void print(tree* root);
tree* search(tree* current, int value);
tree* findGreatest(tree* current);
void deleteNode(tree* current, int value);

int heap[100];
int size;
int counter = 0;
int position;
int num;
int ten = 10;
bool yes = true;

tree* head = NULL;

int main()
{
    int type;
    char input[1000];
    char fileName[10];
    cout << "How would you like to input? Direct input (1) or file input (2)" << endl;
    cin >> type;
    cin.clear();
    cin.ignore(10000, '\n');
    
    
    int i = 0;
    if (type == 1) // Compares to see which type of input
    {
        // direct input
        
        cout << "Please input numbers sperated by spaces." << endl;
        cin.get(input, 1000);
        cin.clear();
        cin.ignore(10000, '\n');
        cout << input << endl;
        
    }
    
    if (type == 2)
    {
        // file input, credit to Omar Nassar
        cout << endl << "What is the name of the file?" << endl << ">> ";
        cin.get(fileName, 20);
        cin.clear();
        cin.ignore(1000000, '\n');
        //        ifstream inputFile;
        //        inputFile.open(fileName);
        //        while (inputFile>>input)
        //        {
        //            cout<<input<<" ";
        //        };
        streampos size;
        ifstream file(fileName, ios::in | ios::binary | ios::ate);
        if (file.is_open())
        {
            size = file.tellg();
            file.seekg(0, ios::beg);
            file.read(input, size);
            file.close();
        }
        cout << input;
    }
    
    // parsing algorithim
    char my_number [100];
    while (input[i] != '\0')
    {
        // If the input has a space then do nothing or "skip" it
        if (input[i] == ' ')
        {
            
        }
        else
        {
            int z = 0;
            for (int j = counter; j <= sizeof(input); j++)
            {
                if(input[j] == ' ')
                {
                    // my_number[j]='\0';
                    counter++;
                    z++;
                    break;
                }
                else
                {
                    
                    my_number[z] = input[j];
                    counter++;
                    z++;
                    //heap[i] = atoi(input[j]);
                }
                
            }
            //cout<<"my number is  "<<my_number<<"\n";
            if(atoi(my_number) == 0)
            {
                
            }
            else
            {
                heap[position] = atoi(my_number);
                position++;
                for (int z = 0; z < sizeof(my_number); z++)
                {
                    my_number[z] = '\0';
                }
            }
        }
        i++;
    }
    
    //printheap();
    for (int i = 0; i < position; i++)
    {//iterate through pasred array and add to tree
        buildTree(heap[i], head);
    }
    
    print(head);
    //3 cout << findGreatest(head) -> getData() << "\n";
    // cout << search(head, 4)-> getData();
    
    while (yes == true)
    {
        cout << "\nWhat would you like to  do? Search (1) Delete (2) Add (3) or  Print (4)" << endl;
        cin >> type;
        cin.clear();
        cin.ignore(10000, '\n');
        
        if (type == 1)
        {
            cout << "What number would you like to search for?"<< endl;
            cin >> num;
            cin.clear();
            cin.ignore(10000, '\n');
            if(search(head, num) != NULL)
            {
                cout << "\nFound!" << endl;
            }
            else
            {
                cout << "\nNot Found." << endl;
            }
        }
        
        if (type == 2)
        {
            cout << "What number would you like to delete" << endl;
            cin >> num;
            cin.clear();
            cin.ignore(10000, '\n');
            deleteNode(head, num);
        }
        
        if (type == 3)
        {
            cout << "What number would you like to add?" << endl;
            cin >> num;
            cin.clear();
            cin.ignore(10000, '\n');
            buildTree(num, head);
        }
        
        if (type == 4)
        {
            print(head);
        }
        
        else
        {
            
        }
        
    }
    
}


void visualPrint(tree* root, int space)
{
    // If the tree is empty
    if(root == NULL)
    {
        return;
    }
    // increase distance
    space += ten;
    
    // Process right child
    visualPrint(root->getRight(), space);
    
    // Print current node
    cout << endl;
    for (int i = ten; i < space; i++)
    {
        cout << " ";
    }
    cout << root -> getData() << "\n";
    
    // Process Left Child
    visualPrint(root->getLeft(), space);
}

void print(tree* root)
{
    visualPrint(root, 0);
}

void buildTree(int value, tree* current)
{
    // If the tree does not exist yet
    if(head == NULL)
    {
        tree* t = new tree(value);
        head = t;
    }
    
    else // if the tree exists
    {
        // If the value is larger than the previous node
        if(value > current -> getData())
        {
            if(current -> getRight() == NULL)
            {
                tree* right = new tree(value);
                current -> setRight(right);
                right -> setParent(current);
            }
            else
            {
                buildTree(value, current-> getRight());
            }
        }
        // If the value is less than, set as left
        else if(value < current -> getData())
        {
            if(current -> getLeft() == NULL)
            {
                tree* left = new tree(value);
                current -> setLeft(left);
                left -> setParent(current);
            }
            else
            {
                buildTree(value, current-> getLeft());
            }
        }
        else // the value is duplicate
        {
            
        }
    }
}

tree* search (tree* current, int value)
{
    if (value == current->getData())
    {
        return current;
    }
    
    if (current -> getLeft()== NULL && current -> getRight() == NULL)
    {
        return NULL;
    }
    
    else if (value > current->getData())
    {
        if(current->getRight() == NULL)
        {
            return NULL;
        }
        else
        {
            if( current -> getRight() != NULL)
            {
                return search(current->getRight(), value);
            }
        }
    }
    else if (value < current -> getData())
    {
        if (current-> getLeft() == NULL)
        {
            return NULL;
        }
        else
        {
            if(current ->getLeft() != NULL)
            {
                return search(current->getLeft(), value);
            }
        }
    }
    
    
    return NULL;
}

void deleteNode(tree* current, int value)
{    // If we want to delete the head
    if(current -> getParent() == NULL && current -> getLeft() == NULL && current -> getRight()==NULL && isalnum(current->getData()))
    {
        head = NULL;
        return;
    }
    
    tree* temp = search(current, value);
    
    if(temp -> getLeft() == NULL && temp-> getRight() == NULL) // If the node has no children
    {
        if(temp -> getParent() -> getLeft() == temp) // if it is the left child
        {
            temp -> getParent() -> setLeft(NULL);
            delete temp;
            return;
        }
        
        if(temp -> getParent() -> getRight() == temp) // if it is the right child
        {
            temp -> getParent() -> setRight(NULL);
            delete temp;
            return;
        }
    }
    
    if((temp -> getLeft() != NULL && temp -> getRight() == NULL) || (temp -> getLeft() == NULL && temp -> getRight() != NULL)) // If the node has one child
    {
        if(temp -> getLeft() != NULL && temp -> getRight() == NULL) // if it is the left child
        {
            temp -> getLeft() -> setParent(temp->getParent());
            temp -> getParent() -> setLeft(temp->getLeft());
            delete temp;
            return;
        }
        
        if(temp -> getLeft() == NULL && temp -> getRight() != NULL) // if it is the right child
        {
            tree* temp2 = temp->getRight();
            temp2 -> setParent(temp->getParent());
            temp -> getParent() -> setRight(temp2);
            // delete temp;
            return;
        }
    }
    
    else if(temp->getRight() != NULL && temp -> getLeft() != NULL) // If the node has two children
    {
        if(temp -> getParent() == NULL || temp -> getData() < head -> getData())
        {
            tree* tbd = findGreatest(temp);
            if(tbd -> getLeft() == NULL && tbd -> getRight() == NULL &&  tbd -> getParent() -> getLeft() -> getData() == tbd -> getData()) // If tbd is a left child
            {
                tbd -> getParent() -> setLeft(NULL);
                temp -> setData(tbd -> getData());
                delete tbd;
                
            }
            else  // tbd is a right child
            {
                tbd -> getParent() -> setRight(tbd -> getRight());
                temp -> setData(tbd -> getData());
                delete tbd;
            }
        }
        else
        {
            tree* tbd = findGreatest(temp);
            
            if(tbd -> getData() > temp -> getData())
            {
                tbd -> getParent() -> setRight(tbd -> getRight());
                temp -> setData(tbd -> getData());
                delete tbd;
            }
            
            if(tbd -> getData() < temp -> getData())
            {
                tbd -> getParent() -> setLeft(tbd -> getRight());
                temp -> setData(tbd -> getData());
                delete tbd;
            }
        }
        
    }
    
    else
    {
        
    }
    
}

tree* findGreatest(tree* current)
{
    // go right once then left all the way
    if(current == NULL || current->getRight() == NULL)
    {
        
    }
    else
    {
        current = current -> getRight();
        
        while(current->getLeft() != NULL)
        {
            current = current->getLeft();
        }
    }
    return current;
}
