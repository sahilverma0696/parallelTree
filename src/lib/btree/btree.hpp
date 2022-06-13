#include<queue>
#include<list>
#include<stack>
#include<iostream>

class NodeBT {
public:
    int value;
    NodeBT* left;
    NodeBT* right;
};

void    insert      (NodeBT* root,std::list<int>& values);
void    insert      (NodeBT* root, int value);

void    printDFS    (NodeBT* root);
void    printBFS    (NodeBT* root);