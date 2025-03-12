#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct BST {
    int data;
    struct BST *left;
    struct BST *right;
    struct BST *parent;
};
typedef struct BST Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
        root->left->parent = root;
    } else if (data > root->data) {
        root->right = insert(root->right, data);
        root->right->parent = root;
    }

    return root;
}

// Function to search for a node in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to perform in-order traversal of the BST
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform pre-order traversal of the BST
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal of the BST
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to find the minimum value in the BST
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
        if (root->left) root->left->parent = root;
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
        if (root->right) root->right->parent = root;
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            if (temp) temp->parent = root->parent;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            if (temp) temp->parent = root->parent;
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor
        Node* temp = findMin(root->right);

        // Copy the in-order successor's data
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
        if (root->right) root->right->parent = root;
    }
    return root;
}

// Main function with a menu-driven interface
int main() {
    Node* root = NULL;
    int choice, data;
    Node* searchResult;

    while (1) {
        printf("\n\n--- Binary Search Tree Operations ---\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. SEARCH\n");
        printf("4. INORDER TRAVERSAL\n");
        printf("5. PREORDER TRAVERSAL\n");
        printf("6. POSTORDER TRAVERSAL\n");
        printf("7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("%d inserted into the BST.\n", data);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("%d deleted from the BST.\n", data);
                break;

            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                searchResult = search(root, data);
                if (searchResult != NULL) {
                    printf("Node with data %d found in the BST.\n", data);
                } else {
                    printf("Node with data %d not found in the BST.\n", data);
                }
                break;

            case 4:
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Pre-order traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Post-order traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}