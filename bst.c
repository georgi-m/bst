#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct node {
    int key;
    struct node *left;
    struct node *right;
};

// Create a new node with a given value
struct node* create_node(int value)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Find for a node with a specific key in the tree
struct node* search_node(struct node* root, const int target_key)
{
    while (root != NULL && root->key != target_key) {
        root = (target_key < root->key) ? root->left : root->right;
    }
    return root;
}

// Insert a node with a specific value into the tree
struct node* insert_node(struct node* root, int value)
{
    if(root == NULL) {
        return create_node(value);
    }
    if(value < root->key) {
        root->left = insert_node(root->left, value);
    } else if(value > root->key) {
        root->right = insert_node(root->right, value);
    }
    return root;
}

// Recursively print nodes
void bts_print(struct node* root)
{
    if(root != NULL) {
        printf(" %d ", root->key);
        bts_print(root->left);
        bts_print(root->right);
    }
}

// Find the minimum value
struct node* find_min(struct node* root)
{
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node from the tree
struct node* delete_node(struct node* root, const int value)
{
    if(root == NULL) {
        return NULL; // Base case: the element is not found
    }

    if (value < root->key) {
        root->left = delete_node(root->left, value);
    } else if (value > root->key) {
        root->right = delete_node(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            printf("Case 1: Node with no children\n");
            free(root);
            return NULL;
        }

        if (root->left == NULL || root->right == NULL) {
            struct node* child = (root->left) ? root->left : root->right;
            printf("Case 2: Node with one child\n");
            free(root);
            return child;
        }

        struct node* successor = find_min(root->right);          // Find the inorder successor
        root->key = successor->key;                              // Replace key with successor's key
        root->right = delete_node(root->right, successor->key);  // Delete successor
        printf("Case 3: Node with two children\n");
    }
    return root;
}

// Free the nodes
void free_tree(struct node* root) {
    if(root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main()
{
    // Init root node
    struct node* root = NULL;

    const int search_key = 17;

    // Insert nodes into the binary search tree
    root = insert_node(root, 44);
    insert_node(root, 36);
    insert_node(root, 17);
    insert_node(root, 40);
    insert_node(root, 60);
    insert_node(root, 58);
    insert_node(root, 76);

    // Search key
    if(search_node(root, search_key) != NULL) {
        printf("key %d found\n", search_key);
    } else {
        printf("key %d not found!\n", search_key);
    }

    printf("\n");

    // print
    bts_print(root);

    printf("\n");

    // deleting existing and not existing one.
    root = delete_node(root, 14);
    root = delete_node(root, 60);
    printf("After Deleting: \n");
    bts_print(root);
    printf("\n");

    // Free allocated memory
    free_tree(root);

    return 0;
}
