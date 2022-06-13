#include "ntree.hpp"

void    insert      (NodeNT* root,std::vector<std::vector<std::vector<int>>> values)
{
    if(!root)
        return;
    
    std::queue<std::vector<NodeNT*>> q;
    int level = 0;

    root->value = values[level][0][0];
    q.push({root});
    level++;

    while(level!=values.size())
    {
        std::vector<std::vector<int>> currentLevelVec = values[level];
        std::vector<NodeNT*> currentLevelNodes = q.front();q.pop();
        for(int i = 0;i<currentLevelVec.size();i++)
        {
            if(!currentLevelNodes[i])
                continue;
            NodeNT* current = currentLevelNodes[i];
            std::vector<NodeNT*> thisLevel;
            for(int j = 0;j<currentLevelVec[i].size();j++)
            {
                NodeNT* newNode = new NodeNT();
                newNode->value = currentLevelVec[i][j];
                current->children.push_back(newNode);
                thisLevel.push_back(newNode);
            }
            q.push(thisLevel);
        }
        level++;
    }

}


void    insert      (NodeNT* root, int value)
{
    if(!root)
        return;
    
    root->value = value;

}

void    printDFS    (NodeNT* root)
{
    if(!root)
        return;

    NodeNT* current = root;

    std::stack<NodeNT*> st;

    while(!st.empty() || current != nullptr)
    {
        while(current!=nullptr)
        {
            st.push(current);
            for(int i =0 ;i< current->children.size();i++)
            {
                if(!current->children[i])
                    continue;
                current = current->children[i];
            }

        }
        current = st.top();st.pop();
        std::cout<<current->value<<"\t";
    }
    std::cout<<std::endl;

}
void    printBFS    (NodeNT* root)
{
    if(!root)
        return;

    std::queue<NodeNT*> q;
    q.push(root);

    NodeNT* current;
    current = nullptr;

    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0;i<size;i++)
        {
            current = q.front();q.pop();
            if(!current)
                continue;
            for(int j = 0; j<current->children.size();j++)
            {
                if(current->children[j])
                    q.push(current->children[j]);
            }
            std::cout<<current->value<<"\t";

        }
        std::cout<<std::endl;
    }
    current = nullptr;
}