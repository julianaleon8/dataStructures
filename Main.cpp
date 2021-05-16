#include <iostream>
#include "array.cpp"

int main() {
    int a[4] = {1,7,4,5};
    unsigned int len = sizeof(a)/sizeof(a[0]);

    int pos = linealSearch<int>(a, 6, len);
    mergeSortArrayRe<int>(a, 0, len-1);
    pos = binarySearch<int>(a, 6, len);

    for (int i = 0; i < len ; i++) {
        std::cout << " " << a[i];    
    }

    //std::cout << "posicion of elem " << pos;
    return 0;
}