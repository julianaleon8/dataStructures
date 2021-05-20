#include <iostream>
#include <stack>

/** 
 * Build a min-heap array structure from an array
 * that does not satisfy the heap property.
 * This is a recursive algorithm.
 * 
 * Left child of i-th node is at (2*i + 1)th index.
 * Right child of i-th node is at (2*i + 2)th index.
 * Parent of i-th node is at (i-1)/2 index.
 * 
 * @param a: Input array to be heapify
 * @param n: numbers of nodes (size on the array)
 */
template < typename T>
void heapify(T a[], int index, int n) {
    int currentParent = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    // check left child
    // Change here for converting into a max-heap
    if (leftChild < n && a[currentParent] > a[leftChild]) {
        currentParent = leftChild;
    }
    // Change here for converting into a max-heap
    if (rightChild < n && a[currentParent] > a[rightChild]) {
        currentParent = rightChild;
    }

    if (index != currentParent) {
        std::swap(a[currentParent], a[index]);
        heapify(a, currentParent, n);
    }
}

/** 
 * Build a min-heap array structure from an array
 * that does not satisfy the heap property.
 * This is a iterative algorithm.
 * 
 * Left child of i-th node is at (2*i + 1)th index.
 * Right child of i-th node is at (2*i + 2)th index.
 * Parent of i-th node is at (i-1)/2 index.
 * 
 * @param a: Input array to be heapify
 * @param n: numbers of nodes (size on the array)
 */
template < typename T>
void heapifyIt(T a[], int index, int n) {
    while (1) {
        int currentParent = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        // check left child
        if (leftChild < n && a[currentParent] > a[leftChild]) {
            currentParent = leftChild;
        }
        if (rightChild < n && a[currentParent] > a[rightChild]) {
            currentParent = rightChild;
        }
        if (index == currentParent) {
            break;
        }

        std::swap(a[currentParent], a[index]);
        index = currentParent;
    
    }
}

/**
 * Sort the array using the min-heap structure
 * recursively
 * @param a: Input array to be sorted 
 * @param n: Size of the array
 */
template < typename T>
void heapSortArray(T a[], int len) {
    // build heap
    for (int i = len -1; i >= 0; i--) {
        heapify(a, i,len);
    }

    for (int j = len -1; j >= 0; j--) {
        std::swap(a[j], a[0]);
        heapify(a, 0 , j);
    }

    for (int k = 0; k <len ; k++) {
        std::cout << " " << a[k];
    }
}

/**
 * Sort the array using the min-heap structure
 * iterative
 * @param a: Input array to be sorted 
 * @param n: Size of the array
 */
template < typename T>
void heapSortArrayIt(T a[], int len) {
    // build heap
    for (int i = len -1; i >= 0; i--) {
        heapifyIt(a, i,len);
    }

    for (int j = len -1; j >= 0; j--) {
        std::swap(a[j], a[0]);
        heapifyIt(a, 0 , j);
    }

    for (int k = 0; k <len ; k++) {
        std::cout << " " << a[k];
    }
}

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
 * a < b
 * @param a: Final array after the merge
 * @param low: Smaller index of the array 
 * @param mid: Middle index of the array
 * @param high: Greater index of the array
 */

template < typename T>
void mergeSort(T a[], int low, int mid, int high) {
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
    mergeSort(a, low, mid, high);
}

/**
 * Sort the array using the merge algorithm
 * iterative
 * @param a: Array to be sorted 
 * @param low: Smaller index of the array 
 * @param high: Greater index of the array
 */
template < typename T>
void mergeSortArrayIt(T a[], int low, int high) {
    std::stack<int> s;
    int len = high;
    int min = low;
    s.push(low);
    s.push(high);
    while (!s.empty()) {
        
        high = s.top();
        s.pop();
        low =  s.top();
        s.pop();
        int mid = (low + high) / 2;
        
        if (mid > low) {
            s.push(low);
            s.push(mid);
        } 
        if ( mid + 1 < high) {
            s.push(mid + 1);
            s.push(high);
        }
        mergeSort(a, low, mid, high);
    }
    int mid = (len + min) /2;
    mergeSort(a, min, mid, len);
}

/**
 * Partitions the array putting all smallest 
 * elements than the pivot to the left and the 
 * greater elements to the right of the pivot
 * The pivot is the middle of the array
 * @param a: Array to be sorted 
 * @param low: Smaller index of the array 
 * @param high: Greater index of the array
 */
template < typename T>
int partitionM(T a[], int low, int high) {
    int mid = (low + high)/2;
    int pivot = a[mid];
    int i = low;
    int j = high;
    while (1) { 
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }

        if (i >= j) {
            return j;
        }
        std::swap(a[j], a[i]);
    }
}

/**
 * Partitions the array putting all smallest 
 * elements than the pivot to the left and the 
 * greater elements thighesto the right of the pivot
 * The pivot is last the  element of the array
 *
 * @param a: Array to be sorted 
 * @param low: Smaller index of the array 
 * @param high: Greater index of the array
 */
template < typename T>
int partition(T a[], int low, int high) {
    int pivot = a[high];
    int relPosPivot = low;
    for (int j = low; j < high ; j++) {
        if (a[j] < pivot) {
            std::swap(a[j], a[relPosPivot]);
            relPosPivot++;
        }
    }
    std::swap(a[high], a[relPosPivot]);
    return relPosPivot;
}

/**
 * Sort the array using the quick sort algorithm
 * This is a recursive algorithm.
 * @param a: Array to be sorted 
 * @param low: Smaller index of the array 
 * @param high: Greater index of the array
 */
template < typename T>
void quickSortArrayRe(T a[], int low, int high) {
    if (low >= high) {
        return;
    }

    int pos = partition(a, low, high);
    quickSortArrayRe(a, low, pos-1);
    quickSortArrayRe(a, pos +1, high);
}

/**
 * Sort the array using the quick sort algorithm
 * This is a iterative algorithm.
 * @param a: Array to be sorted 
 * @param low: Smaller index of the array 
 * @param high: Greater index of the array
 */
template < typename T>
void quickSortArrayIt(T a[], int low, int high) {
    
    std::stack<int> s;
    s.push(low);
    s.push(high);
    
    while (!s.empty()) {
        high = s.top();
        s.pop();
        low =  s.top();
        s.pop();
        int pos = partition(a, low, high);
        if (pos - 1 > low) {
            s.push(low);
            s.push(pos -1);
        } 
        if ( pos + 1 < high) {
            s.push(pos + 1);
            s.push(high);
        }
    }
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





