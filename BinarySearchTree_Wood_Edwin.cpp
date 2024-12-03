#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Represents a node in the BST, containing the data, left child pointer, and right child pointer.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

//Contains functions to insert, traverse in order, simple search, search via nodes, find min/max, and remove.
class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    Node* search(Node* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return search(node->left, value);
        }
        else {
            return search(node->right, value);
        }
    }

    Node* searchWithNodes(Node* current, int value) {
        if (current == nullptr || current->data == value) {
            if (current == nullptr)
                std::cout << "Search key not found" << std::endl;
            return current;
        }
        if (value < current->data) {
            std::cout << current->data << " -> ";
            return searchWithNodes(current->left, value);
        }
        std::cout << current->data << " -> ";
        return searchWithNodes(current->right, value);
    }

    Node* findMin(Node* node) {
        if (node == nullptr || node->left == nullptr) {
            return node;
        }
        return findMin(node->left);
    }

    Node* findMax(Node* node) {
        if (node == nullptr || node->right == nullptr) {
            return node;
        }
        return findMax(node->right);
    }

    Node* remove(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = remove(node->left, value);
        }
        else if (value > node->data) {
            node->right = remove(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }

        return node;
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }

    bool search(int value) {
        return search(root, value) != nullptr;
    }
    void searchWithNodes(int value) {
        std::cout << "Searching for node " << value << " " << endl;
        if (searchWithNodes(root, value) == nullptr) {
            std::cout << "search key not found";
        }
        std::cout << std::endl;
    }

    void remove(int value) {
        root = remove(root, value);
    }

    int findMin() {
        Node* minNode = findMin(root);
        if (minNode != nullptr) {
            return minNode->data;
        }
        else {
            throw runtime_error("Tree is empty");
        }
    }

    int findMax() {
        Node* maxNode = findMax(root);
        if (maxNode != nullptr) {
            return maxNode->data;
        }
        else {
            throw runtime_error("Tree is empty");
        }
    }
};

//case statement that takes user input and creates a vector of values. Also passes values to specific functions based on case selected.
int main() {
    BST bst;
    vector<int> values;
    int n, ch, value;
    //nodesTraversed = 0;
    while (1)
    {
        cout << endl << endl;
        cout << " Binary Search Tree Operations " << endl;
        cout << " ----------------------------- " << endl;
        cout << " 1. Create a BST " << endl;
        cout << " 2. Insert a node " << endl;
        cout << " 3. Remove a node " << endl;
        cout << " 4. Find the largest node " << endl;
        cout << " 5. Find the smallest node " << endl;
        cout << " 6. Search for a node " << endl;
        cout << " 7. Exit " << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1: cout << "Enter the number of elements: ";

            cin >> n;

            cout << "Enter the values separated by a space: ";
            for (int i = 0; i < n; ++i) {
                cin >> value;
                values.push_back(value);
            }

            for (int v : values) {
                bst.insert(v);
            }

            cout << "BTS nodes are: ";
            bst.inorderTraversal();
            break;

        case 2: cout << "Enter a node to insert: ";
            cin >> value;
            if (bst.search(value)) {
                cout << "Node " << value << " is a duplicate node. Cannot insert node " << value << " again." << endl;
            }
            else {
                bst.insert(value);
            }            

            cout << "BST nodes are: ";
            bst.inorderTraversal();
            break;

        case 3: cout << "Enter a value to remove: ";
            cin >> value;
            if (bst.search(value)) {
                bst.remove(value);
                
            }
            else { 
                cout << "Value not found in the tree." << endl;
            }            

            cout << "BST nodes are: ";
            bst.inorderTraversal();
            break;

        case 4: cout << "BST node with the largest value: " << bst.findMax() << endl;

            cout << "BST nodes are: ";
            bst.inorderTraversal();
            break;

        case 5: cout << "BST node with the smallest value: " << bst.findMin() << endl;

            cout << "BST nodes are: ";
            bst.inorderTraversal();
            break;

        case 6: cout << "Enter a value to search: ";
           
            cin >> value;

            bst.searchWithNodes(value);
            cout << "BST nodes are: ";
            bst.inorderTraversal();
            break;

        case 7:
            return 0;
        }
    }
}