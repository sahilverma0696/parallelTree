#include "../src/lib/btree/btree.hpp"
#include <random>


std::list<int> randomValues(int number, int min, int max)
{
    std::list<int> values;
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
    NodeBT* root = new NodeBT();

    std::list<int> values = randomValues(1000000,1,100);
    
    insert(root,values);

    printBFS(root);

    return 0;


}