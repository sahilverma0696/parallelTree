#include<queue>
#include<stack>
#include<iostream>
#include<vector>

class NodeNT {
public:
    int                     value;
    std::vector<NodeNT*>    children;
};

void    insert      (NodeNT* root,std::vector<std::vector<std::vector<int>>> values);
void    insert      (NodeNT* root, int value);

void    printDFS    (NodeNT* root);
void    printBFS    (NodeNT* root);