//Jeff Leonard, Joel LaFever, Aaron Shinn       
//CS 3800 DAY AA

//AVL TREE

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "teamjwl.h"
using namespace std;

int main()
{

    nodeCreation *root = NULL;
    nodeCreation insertVariable;
    nodeCreation test;
    ifstream file;
    file.open("integerData.txt");
    int word;
    while (file >> word)
    {
        root = insertVariable.insertNode(root, word);   //runs thru file getting each input
    }
    
    freopen("output.txt", "w", stdout); //this puts all the console stuff into a txt file

    cout << "Preorder Traversal: " << endl;
    test.preOrder(root);    //prints nlr
    cout << " " << endl;

    cout << "Postorder Traversal: " << endl;
    test.postOrder(root);   //prints lrn
    cout << " " << endl;

    cout << "Inorder Traversal: " << endl;
    test.inOrder(root);     //prints lnr
    cout << " " << endl;

    cout << "Height of each branch: " << endl;
    test.printHeight();

    freopen("CON", "w", stdout); //this allows things to be put back in console
    cout << "View output.txt for results!" << endl;
    return 0;
}
