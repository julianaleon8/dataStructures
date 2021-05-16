#include <iostream>
/**
 * Sort the array using the selection algorithm
 *
 * @param a: Input array to be sorted 
 * @param len: Size of the array
 */
template < typename T>
void selectionSortArray(T a[], unsigned int len) {

    for (int i = 0; i < len; i++) {
        int pos = i;

        for (int j = i; j < len; j++) {
            if (a[pos] > a[j]) {
                pos = j;
            }
        }
        if (i != pos) {
            std::swap(a[i],a[pos]);
        }
    }
}

/**
 * Sort the array using the insertion algorithm
 *
 * @param a: Input array to be sorted 
 * @param len: Size of the array
 */
template < typename T>
void insertionSortArray(T a[], unsigned int len) {

    for (int i = 1; i < len; i++) {
        int j = i;
        while (j > 0 && a[j] < a[j-1] ) {
            std::swap(a[j],a[j-1]);
            j--;
        }
    }
}

/**
 * Merge two arrays where the smaller elements
 * comes first
 *
 * @param a: Final array after the merge
 * @param low: Smaller index of the array 
 * @param mid: Middle index of the array
 * @param high: Greater index of the array
 */

template < typename T>
void mergeSortRe(T a[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int b[n1];
    int c[n2];
    
    for (int i = 0; i < n1; i++) {
        b[i] = a[low + i];
    }
    for (int j = 0; j < n2; j++) {
        c[j] = a[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = low;
    while (i < n1 && j < n2) {
        if (b[i] <= c[j]) {
            a[k] = b[i];
            i++;
        } else {
            a[k] = c[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = b[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = c[j];
        j++;
        k++;
    }

}

/**
 * Sort the array using the merge algorithm
 * recursive
 * @param a: Array to be sorted 
 * @param low: Smaller index of the array 
 * @param high: Greater index of the array
 */
template < typename T>
void mergeSortArrayRe(T a[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low+high)/2;
    mergeSortArrayRe(a, low, mid );
    mergeSortArrayRe(a, mid+1, high );
    mergeSortRe(a, low, mid, high);
}

/**
 * Sort the array using the quick sort algorithm
 *
 * @param a: Array to be sorted 
 * @param low: Smaller index of the array 
 * @param high: Greater index of the array
 */
template < typename T>
void quickSortArrayRe(T a[], int low, int high) {
    return;
}

/**
 * Sort the array using the heap sort algorithm
 *
 * @param a: Array to be sorted 
 * @param low: Smaller index of the array 
 * @param high: Greater index of the array
 */
template < typename T>
void heapSortArrayRe(T a[], unsigned int len) {
    return;
}

/**
 * Search element of an array using linear search
 *
 * @param a: The array where to search to 
 * @param elem: Element  to look for
 * @return int: Position of the element if the 
 *              element exists if it does not exist
 *              returns -1.
 */
template < typename T>
int linealSearch(T a[], T elem, unsigned int arrSize) {
    for (int i= 0; i < arrSize; i++){
        if(a[i] == elem) {
            return i;
        }
    }
    return -1;
}

/**
 * Search element of an array using binary search
 *
 * @param a: The array where to search to 
 * @param elem: Element  to look for
 * @return int: Position of the element if the 
 *              element exists if it does not exist
 *              returns -1.
 */
template < typename T>
int binarySearch(T a[], T elem, int arrSize) {
    selectionSortArray(a, arrSize);
    int low = 0;
    int high = arrSize;
    while (low < high) {
        int mid = (low + high-1)/2;
        if (a[mid] == elem) {
            return mid;
        } else if (a[mid] > elem) {
            high = mid-1;
        } else {
            low = mid+1;
        }    
    }
    return -1;
}





