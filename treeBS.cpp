#include <iostream>
#include <vector>


/** Class treeBS
 * Represents a Binary Search Tree and some
 * operations of the BS tree.
 * More information click 
 * https://en.wikipedia.org/wiki/Binary_search_tree
 */
template <typename T>
class treeBS {
    /** Class treeBSNode
    * Represents a Binary Search Tree Node
    */
    private:

    class treeBSNode {
        public:

        
        /** Constructor */
        treeBSNode(T e) {
            elem = e;
            left = nullptr;
            right = nullptr;
        }

        // DATA
        T elem;
        treeBSNode* left;
        treeBSNode* right;

    };
    
    /** 
     * brief Returns the more left child node of a given node.
     * 
     * @param node Particular node to search to
    */
    treeBSNode*  getMinSucValue(treeBSNode* node) {
        treeBSNode* current = node;
        while (current != nullptr && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    public:
    
    /** 
    *   brief Prints the entire tree starting from the _root
    *   in pre-order traversal
    */
    void printTree() {

        traversalPreOrder(_root);
        std::cout << " \n";

    }

    /** 
    *  Traversal and prints the entire tree from a given node in pre-order
    *  
    * @param node Starting node to traversal
    */
    void traversalPreOrder(treeBSNode* node) {
        if (node == nullptr) {
            return;
        }
        
        std::cout << " Node:  " << node->elem << " ";
        traversalPreOrder(node->left);
        traversalPreOrder(node->right);
    }

    // @todo
    // Add post-order
    // Add in-order

    /** 
    *   Search for a node into the tree if exist return the node,
    *   otherwise return nullptr.
    * 
    *  @param elem Element to find
    */
    treeBSNode* findElem(T elem) {
        treeBSNode* node = _root;
        while (node->elem != elem) {
            if (node != nullptr) {
                
                if (node->elem > elem) {
                    node = node->left;
                } else {
                    node = node->right;
                }
                if (node == nullptr) {
                    return nullptr;
                }
            }
        }
        return node; 
    }
    
    /** 
    *   Insert a node into the tree recursively
    * 
    *   @param node: treeBSNode to be inserted
    *   @param elem: Element the type T to be inserted
    */
    treeBSNode insertRe (treeBSNode * node, T elem) {
        if (node == nullptr) {
            return new treeBSNode(elem);
        }
        if (node->elem > elem) {
            node->left = insertRe(node->left);
        } else {
            node->right = insertRe(node->right);
        }
        return node;
    }

    /** 
    *   brief Insert a node into the tree iteratively 
    * 
    *   @param node: treeBSNode to be inserted
    *   @param elem: Element the type T to be inserted
    */
    void insert(T elem) {
        if (_root == nullptr) {
            _root = new treeBSNode(elem);
            return;
        }
        treeBSNode* current = _root;
        treeBSNode* prev = nullptr;

        while (current != nullptr) {
            prev  = current;
            if (current->elem > elem) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        if (prev->elem > elem) {
            prev->left = new treeBSNode(elem);
        } else {
            prev->right = new treeBSNode(elem);
        }
    }
    
    /** 
    *   brief Delete a node into the tree iteratively
    * 
    *   @param elem: Element the type T to be deleted
    */
    void deleteNode( T elem) {
        treeBSNode* node = _root;
        treeBSNode* prev = nullptr;

        // encontrar al elem a eliminar
        while (node != nullptr && node->elem != elem) {
            prev = node;
            if (node->elem > elem) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        if (node == nullptr) {
            return;
        }
        treeBSNode* tmp = nullptr;
        // caso en que al menos no tenia un  hijo
        if (node->left == nullptr || node->right == nullptr) {
            if (node->left == nullptr) {
                tmp = node->right;
            } else {
                tmp = node->left;
            }

            if (prev == nullptr) {
                free(node);
                _root = tmp;
                return;
            }

            if (prev->left == node) {
                prev->left = tmp;
            } else {
                prev->right = tmp;
            }
            free(node);
        } else {
            tmp = getMinSucValue(_root->right);
            node->elem = tmp->elem;
            free(tmp);
        }
    }

    // DATA
    //! The root node of the BS tree
    treeBSNode* _root = nullptr;
};