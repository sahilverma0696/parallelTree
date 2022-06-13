#include "btree.hpp"

void    insert      (NodeBT* root,std::list<int>& values)
{
    if(!root)
        return;
    
    std::queue<NodeBT*> q;

    root->value = values.front();values.pop_front();
    q.push(root);

    NodeBT* current;
    current = nullptr;

    while(!q.empty())
    {
        current = q.front();q.pop();
        if(values.empty()) break;
        current->left = new NodeBT();
        current->left->value = values.front();values.pop_front();
        q.push(current->left);

        if(values.empty()) break;
        current->right = new NodeBT();
        current->right->value = values.front();values.pop_front();
        q.push(current->right); 
    }

    current = nullptr;
}


void    insert      (NodeBT* root, int value)
{
    if(!root)
        return;
    
    root->value = value;

}

void    printDFS    (NodeBT* root)
{
    if(!root)
        return;
    NodeBT* current = root;

    
    std::stack<NodeBT*> st;

    while(!st.empty() || current != nullptr)
    {
        while(current!=nullptr)
        {
            st.push(current);
            if(current->left)
                current = current->left;

        }
        current = st.top();st.pop();
        std::cout<<current->value<<"\t";
        current = current->right;
    }
    std::cout<<std::endl;

}
void    printBFS    (NodeBT* root)
{
    if(!root)
        return;

    std::queue<NodeBT*> q;
    q.push(root);

    NodeBT* current;
    current = nullptr;

    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            current = q.front();q.pop();
            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);
            
            std::cout<<current->value<<"\t";
        }
        std::cout<<std::endl;
    }
    current = nullptr;
}