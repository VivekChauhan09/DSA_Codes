// C program to implement binary search tree
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct BinaryTreeNode {
	int data;
	struct BinaryTreeNode *left, *right;
};

// Function to create a new node with a given value
struct BinaryTreeNode* newNodeCreate(int value)
{
	struct BinaryTreeNode* temp= (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	temp->data = value;
	temp->left = temp->right = NULL;
	return temp;
}

// Function to search for a node with a specific data in the
// tree
struct BinaryTreeNode * searchNode(struct BinaryTreeNode* root, int key)
{
	if (root == NULL || root->data == key) {
		return root;
	}
	if (root->data < key) {
		return searchNode(root->right, key);
	}
	return searchNode(root->left, key);
}

// Function to insert a node with a specific value in the
// tree
struct BinaryTreeNode * insertNode(struct BinaryTreeNode* root, int value)
{
	if (root == NULL) {
		return newNodeCreate(value);
	}
	if (value < root->data) {
		root->left = insertNode(root->left, value);
	}
	else if (value > root->data) {
		root->right = insertNode(root->right, value);
	}
	return root;
}

// Function to perform post-order traversal
void postOrder(struct BinaryTreeNode* root)
{
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf(" %d ", root->data);
	}
}

// Function to perform in-order traversal
void inOrder(struct BinaryTreeNode* root)
{
	if (root != NULL) {
		inOrder(root->left);
		printf(" %d ", root->data);
		inOrder(root->right);
	}
}

// Function to perform pre-order traversal
void preOrder(struct BinaryTreeNode* root)
{
	if (root != NULL) {
		printf(" %d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

// Function to find the minimum value
struct BinaryTreeNode* findMin(struct BinaryTreeNode* root)
{
	if (root == NULL) {
		return NULL;
	}
	else if (root->left != NULL) {
		return findMin(root->left);
	}
	return root;
}

// Function to delete a node from the tree
struct BinaryTreeNode* delete (struct BinaryTreeNode* root,
							int x)
{
	if (root == NULL)
		return NULL;

	if (x > root->data) {
		root->right = delete (root->right, x);
	}
	else if (x < root->data) {
		root->left = delete (root->left, x);
	}
	else {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		else if (root->left == NULL
				|| root->right == NULL) {
			struct BinaryTreeNode* temp;
			if (root->left == NULL) {
				temp = root->right;
			}
			else {
				temp = root->left;
			}
			free(root);
			return temp;
		}
		else {
			struct BinaryTreeNode* temp
				= findMin(root->right);
			root->data = temp->data;
			root->right = delete (root->right, temp->data);
		}
	}
	return root;
}

int main()
{
	// Initialize the root node
	struct BinaryTreeNode* root = NULL;

	// Insert nodes into the binary search tree
	root = insertNode(root, 50);
	insertNode(root, 30);
	insertNode(root, 20);
	insertNode(root, 40);
	insertNode(root, 70);
	insertNode(root, 60);
	insertNode(root, 80);

	// Search for a node with data 60
	if (searchNode(root, 60) != NULL) {
		printf("60 found");
	}
	else {
		printf("60 not found");
	}

	printf("\n");

	// Perform post-order traversal
	postOrder(root);
	printf("\n");

	// Perform pre-order traversal
	preOrder(root);
	printf("\n");

	// Perform in-order traversal
	inOrder(root);
	printf("\n");

	// Perform delete the node (70)
	struct BinaryTreeNode* temp = delete (root, 70);
	printf("After Delete: \n");
	inOrder(root);

	// Free allocated memory (not done in this code, but
	// good practice in real applications)

	return 0;
}
