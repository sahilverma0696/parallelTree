#include "../src/lib/ntree/ntree.hpp"



std::vector<int> randomValues(int number, int min, int max)
{
    std::vector<int> values;
    srand((unsigned) time(0));
    int randomNumber;
    for (int index = 0; index < number; index++) {
        randomNumber = (rand() % max) + min;
        values.push_back(randomNumber);
    }
    return values;
}

int main()
{
    NodeNT* root = new NodeNT();

    std::vector<std::vector<std::vector<int>>> values;
    values.push_back({{0}});

    int level = 5;
    int maxChild = 5;
    for(int i = 1;i<=level;i++)
    {
        std::vector<std::vector<int>> levelVec;
        for(int j = 0;j<i;j++)
        {
            levelVec.push_back(randomValues(5,1,100));
        }
        values.push_back(levelVec);
        
    }

    for(auto x:values)
    {
        for(auto y:x)
        {
            for(auto z:y)
                std::cout<<z<<"  ";
            std::cout<<"\t";
        }
        std::cout<<std::endl;
    }

    
    insert(root,values);

    printBFS(root);

    return 0;


}