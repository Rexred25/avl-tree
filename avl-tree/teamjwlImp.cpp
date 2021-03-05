//Jeff Leonard, Joel LaFever, Aaron Shinn       
//CS 3800 DAY AA
//big difference from the bst is that I created more functions to spread out the code for a much easier time to read what it does
//AVL TREE

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "teamjwl.h"
using namespace std;

int leftHeight = 0;         //counts the height of the left
int rightHeight = 0;        //counts the height of the right
nodeCreation test;
int maxInt(int x, int y);   // gets max of two integers


nodeCreation* nodeCreation::newNode(int current) //allocates new node with given root and NULL for left and right
{
    nodeCreation *node = new nodeCreation();
    node->current = current;
    node->left = NULL;  //set to null because atm there is nothing in the tree
    node->right = NULL; //set to null because atm there is nothing in the tree
    node->height = 1;   //initially the new node is added at the leaf
    return (node);
}

nodeCreation *nodeCreation::rightRotate(nodeCreation *b) //right rotate subtree
{

    nodeCreation *a = b->left;
    nodeCreation *temp = a->right;

    a->right = b; //does rotation
    b->left = temp; //does rotation
    
    b->height = maxInt(test.heightCalc(b->left), test.heightCalc(b->right)) + 1;    //updates the height
    a->height = maxInt(test.heightCalc(a->left), test.heightCalc(a->right)) + 1;    //updates the height

    return a;   //return the new root
}

nodeCreation *nodeCreation::leftRotate(nodeCreation *a) //does the left rotation
{
    nodeCreation *b = a->right;
    nodeCreation *temp = b->left;

    b->left = a;        //does rotation
    a->right = temp;    //does rotation

    a->height = maxInt(test.heightCalc(a->left), test.heightCalc(a->right)) + 1;    //updates the height
    b->height = maxInt(test.heightCalc(b->left), test.heightCalc(b->right)) + 1;    //updates the height

    
    return b;   //return the new root
}

int getBalance(nodeCreation *p) //gets balance for the node p
{
    if (p == NULL)
    {
        return 0;
    }
    leftHeight = test.heightCalc(p->left);
    rightHeight = test.heightCalc(p->right);
    return test.heightCalc(p->left) - test.heightCalc(p->right);
}

int nodeCreation::heightCalc(nodeCreation *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return p-> height;
}

int maxInt(int x, int y) //gets max of two integers
{
    return (x > y)? x : y;
}

nodeCreation* nodeCreation::insertNode(nodeCreation *node, int current) //recursivly insert root in the subtree with the node and returns the new root of the subtree
{
    if (node == NULL)
    {
        return (test.newNode(current)); //cant have an empty tree
    }

    if (current < node->current)
    {
        node->left = test.insertNode((node->left), current);    //pushes it left
    }
    else if (current > node->current)
    {
        node->right = test.insertNode((node->right), current);  //pushes it right
    }
    else //cannot have equal roots in a BST or AVL
    {
        return (node);
    }

    
    node->height = 1 + maxInt(test.heightCalc(node->left), test.heightCalc(node->right));  //updates the height

    
    int balance = getBalance(node); //determines if it became unblanced or not


    if (balance > 1 && current < (node->left->current))   //left left
    {
        return test.rightRotate(node);
    }

    if (balance > 1 && current > (node->left->current))   //left right
    {
        node->left = test.leftRotate(node->left);
        return test.rightRotate(node);
    }

    if (balance < -1 && current > (node->right->current)) //right right
    {
        return test.leftRotate(node);
    }

    if (balance < -1 && current < (node->right->current)) //right left
    {
        node->right = test.rightRotate(node->right);
        return test.leftRotate(node);
    }

    
    return node; //return the node
}

void nodeCreation::preOrder(nodeCreation *root) //NLR
{
    if (root != NULL)
    {
        cout << " " << (root->current) << " ";      //prints out node
        preOrder(root->left);                       //Prints out left
        preOrder(root->right);                      //prints out right
    }
}

void nodeCreation::postOrder(nodeCreation *root) //LRN
{

    if (root != NULL)
    {
        postOrder(root->left);                 //Prints out left
        postOrder(root->right);                //prints out right
        cout << " " << (root->current) << " "; //prints out node
    }
}
void nodeCreation::inOrder(nodeCreation *root) //LNR
{
    if (root != NULL)
    {
        inOrder(root->left);                    //prints out left
        cout << " " << (root->current) << " ";  //prints out node
        inOrder(root->right);                   //prints out right
    }

}

void nodeCreation::printHeight()
{
    cout << "  *left:\t" << leftHeight << endl;
    cout << "  *right:\t" << rightHeight << endl;
}


