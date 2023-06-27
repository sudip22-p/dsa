#include <iostream>
using namespace std;
// Node definition for the binary search tree
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int data) {
        key = data;
        left = right = NULL;
    }
};
// Function to insert a new node into the BST
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}
// Function to perform preorder traversal of the BST
void preorderTraversal(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal of the BST
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->key << " ";
    }
}

// Function to search for a key in the BST
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Utility function to find the minimum value in a BST
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
Node* deleteNode(Node* root, int key) {
    // Base case: empty tree
    if (root == nullptr) {
        return root;
    }

    // If the key is smaller than the root's value, move to the left subtree
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    // If the key is greater than the root's value, move to the right subtree
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    // Node to delete found
    else {
        // Case 1: Deleting a node with no children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // Case 2: Deleting a node with one child
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Deleting a node with two children
        else {
            // Find the successor (smallest value in the right subtree)
            Node* successor = findMin(root->right);

            // Replace the node to delete with the successor value
            root->key = successor->key;

            // Delete the successor node from the right subtree
            root->right = deleteNode(root->right, successor->key);
        }
    }
    return root;
}
// Function to display the menu options
void displayMenu() {
    cout << "Binary Search Tree Operations:" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Inorder traversal" << endl;
    cout << "3. Preorder traversal" << endl;
    cout << "4. Postorder traversal" << endl;
    cout << "5. Search for a key" << endl;
    cout << "6. Delete a node with a given key" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

// Main function
int main() {
    Node* root = NULL;
    int choice, key;
    bool exit = false;

    while (!exit) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key to insert: ";
                cin >> key;
                root = insert(root, key);
                break;
            case 2:
                cout << "Inorder traversal of the BST: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder traversal of the BST: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder traversal of the BST: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter the key to search: ";
                cin >> key;
                if (search(root, key) != NULL) {
                    cout << key << " found in the BST." << endl;
                } else {
                    cout << key << " not found in the BST." << endl;
                }
                break;
            case 6:
                cout << "Enter the key to delete target node: ";
                cin >> key;
                if (search(root, key) != NULL) {
                    root = deleteNode(root, key);
                    cout << key << " is deleted from the BST." << endl;
                } else {
                    
                    cout << key << " not avilable in the BST." << endl;
                }
                break;
            case 7:
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}
