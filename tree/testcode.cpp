#include "effectTree.h"

int main(int argc, char const *argv[])
{
    using namespace std;
    int data[] = {1, 3, 4, 6, 86, 4, 2};
    int len = sizeof(data) / sizeof(int);

    EffectTree *pTree = new EffectTree(data, len);
    pTree->drawTree();
    return 0;
}
