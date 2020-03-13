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
void printheap();

int heap[100];
int size;
int counter = 0;
int position;

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
    //buildTree();
    for (int i = 0; i < position; i++) {//iterate through pasred array and add to tree
        buildTree(heap[i], head);
    }
}

void printheap()
{
    for (int i = 0; i < position; i++)
    {
        cout << heap[i] << " ";
    }
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
    
    /*if(heap[current] <= t->getRoot()->getData())
     {
     tree* left = new tree(heap[current]);
     t -> setLeft(left);
     current++;
     }
     
     if(heap[current] > t->getRoot()->getData())
     {
     cout << heap[current];
     tree* right = new tree(heap[current]);
     t -> setRight(right);
     current++;
     }
     }
     if (current == 2)
     {
     for(int i = 0; i < position; i++)
     {
     
     }
     }
     return NULL;*/
}
