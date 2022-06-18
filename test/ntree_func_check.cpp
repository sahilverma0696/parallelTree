#include "../src/lib/ntree/ntree.hpp"
#include <random>


std::vector<int> randomValues(int number, int min, int max)
{
    std::vector<int> values;
    std::random_device dev;
    std::mt19937 rng(dev());
    for(int i = 0;i<number;i++)
    {
        std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max); // distribution in range [1, 6]
        values.push_back(dist6(rng));
    }

    return values;
}

int main()
{
    NodeNT* root = new NodeNT();

    std::vector<std::vector<std::vector<int>>> values;
    values.push_back({{0}});

    int level = 5;
    int maxChild = 2;
    for(int i = 1;i<=level;i++)
    {
        std::vector<std::vector<int>> levelVec;
        for(int j = 0;j<i;j++)
        {
            levelVec.push_back(randomValues(maxChild,1,100));
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