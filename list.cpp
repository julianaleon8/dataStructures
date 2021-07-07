#include <iostream>
#include <stack>

/** Class List
 * Represents a List of elements of type T and 
 * operations of the data structure List
 */
template < typename T>
class List {
    /** Class listNode
    * Represents a List node of an element of type T
    */
    struct listNode {
        T elem;
        listNode* next = nullptr;
        listNode(T e) {
        elem = e;
        }
    };

    public:

    //! type node type
    typedef List<T>::listNode node_type;
    //! type node pointer
    typedef node_type* node_pointer;

    /** 
     * Brief Get the head of the List
     */
    node_pointer getListHead() {
           return _head;
    }
    
    /** 
     * brief Prints the entire List from the head
     */
    void printList () {
        if (_head == nullptr) {
            std::cout << " empty list \n";
            return;
        }
        node_pointer current = _head;
        while (current != nullptr)
        {
            std::cout << " " << current->elem;
            current = current->next;
        }
        std::cout << "\n";
    }

    /** 
     * brief Prints the entire List from a specific 
     * head 
     * 
     * @param head The node in the List from where is printed
     */
    void printList (node_pointer head) {
        if (head == nullptr) {
            std::cout << " empty list \n";
            return;
        }
        node_pointer current = head;
        while (current != nullptr)
        {
            std::cout << " " << current->elem;
            current = current->next;
        }
        std::cout << "\n";
    }

    /** 
     * brief Add an element of type T at the end of the List
     * 
     * @param elem Element of type T to be added at the end
     */
    void addEnd(T elem) {
        node_pointer node = new listNode(elem);
        if (_head == nullptr) {
            _head = node;
        } else {
            node_pointer current = _head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
    }

    /** 
     * brief Add an element of type T at the beginning of the List
     * 
     * @param elem Element of type T to be added at the beginning
     */
    void addBegining(T elem) {
        node_pointer node = new listNode(elem);
        if (_head == nullptr) {
            _head = node;
        } else {
            node->next = _head;
            _head = node;
        }
    }

    /** 
     * brief Remove a particular element of type T of the List
     * 
     * @param elem Element of type T to be removed
     */
    void removeElemList(T elem) {
        node_pointer node = findElemOnlist(elem);
        if (node != nullptr) {
            if (node == _head) {
                _head = _head->next;
            } else {
                node_pointer current = _head;
                node_pointer prev = nullptr;
                while (current != nullptr) {
                    prev = current;
                    current = current->next;
                    if (current == node) {
                        break;
                    }
                }
                prev->next = current->next;
            }
            free(node);
        }
    }

    /** 
     * brief Build a List from an array
     * 
     * @param a[] Array to build the List from
     * @param len The length of the array
     */
    void buildListFromArray(T a[], int len) {
        for (int i = 0; i < len; i++) {
            addEnd(a[i]);
        }
    }

    /**
     * brief Search for an element on the List returns
     * the node if the element exists, nullptr otherwise
     * 
     * @param elem Element to be found
     */
    node_pointer findElemOnlist(T elem) {
        node_pointer current = _head;
        while (current != nullptr) {
            if (current->elem == elem) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    /**
     * brief Reverse a List, returns a new List reversed
     * 
     * @param head Head of the List to be reversed
     */
    List reverseListAux(node_pointer head) {
        List<T> result;
        result.addEnd(head->elem);
        node_pointer current = head;
        while(current->next != nullptr) {
            result.addBegining(current->next->elem);
            current = current->next;
        }
        return result;
    }

    /**
     * brief Reverse a List in place
     * 
     * @param head Head of the List to be reversed
     */
    void reverseList(node_pointer root) {
        node_pointer current = root;
        node_pointer next = nullptr;
        node_pointer prev = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        _head = prev;
    }
    
    //DATA 
    //! node pointer to the head of the List
    node_pointer _head = nullptr;
    
};
