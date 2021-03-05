//Jeff Leonard, Joel LaFever, Aaron Shinn       
//CS 3800 DAY AA

//AVL TREE

class nodeCreation  //avl tree node creation
{
    public:
        int current;
        nodeCreation *left;
        nodeCreation *right;
        int height;

    public:
        nodeCreation *insertNode(nodeCreation* , int current);
        nodeCreation *rightRotate(nodeCreation*);
        nodeCreation *leftRotate(nodeCreation*);
        nodeCreation* newNode(int current);
        void preOrder(nodeCreation *);
        void inOrder(nodeCreation *);
        void postOrder(nodeCreation *);
        int heightCalc(nodeCreation *);
        void printHeight();
        
};