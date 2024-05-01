#include "nonBinaryTree.h"

int main(){

    Isi_Tree Xtree;
    Create_tree(Xtree, 10);
    PrintTree(Xtree);
    PreOrder(Xtree);
    InOrder(Xtree, 1);
    Enter
    PostOrder(Xtree, 1);
    Enter
    LevelOrder(Xtree, 1);
    Enter
    bool AdaGaak = Search(Xtree, 1, 'E');
    printf("%d ",AdaGaak);
    Enter
    int BrpElmt = nbElmt(Xtree, 1);
    printf("%d ", BrpElmt);
    Enter
    int BrpLeaf = nbDaun(Xtree, 1);
    printf("%d ", BrpLeaf);
    Enter
    int BrpDalam = Depth(Xtree, 1);
    printf("%d ", BrpDalam);
    Enter
    int BrpLevel = Level(Xtree, 1, 'D');
    printf("%d ", BrpDalam);
    Enter

    return 0;
}   