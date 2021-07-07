#include <iostream>
#include <vector>

template <typename T>
class tree {
    public:

    class treeNode {
        T elem;
        std::vector<treeNode> children;
    }
    treeNode* _root = nullptr;

    void printNtree() {

    }

    treeNode* findElem(T elem) {

    }
};