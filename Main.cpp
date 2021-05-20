#include <iostream>
#include "array.cpp"

int main() {
    int a[8] = {1,7,4,5, 0 ,3 ,4,5};
    unsigned int len = sizeof(a)/sizeof(a[0]);

    heapSortArrayIt<int>(a, len);
    
    for (int i = 0; i < len ; i++) {
        std::cout << " " << a[i];    
    }
    
    return 0;
}