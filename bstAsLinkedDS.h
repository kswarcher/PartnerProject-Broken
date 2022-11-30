/** bstAsLinkedDT.h
* ================================================================
* Name: 
* Section: 
* Project: Header for BST library
* =================================================================
*/

#ifndef BSTASLINKEDDS_H
#define BSTASLINKEDDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _bstNode { //Used for the passing and creation of our tree
    char data;
    struct _bstNode* left;
    struct _bstNode* center;
    struct _bstNode* right;
    struct  _bstNode* parent;
} _bstNode;

typedef struct dictionaryTree { //Originally thought we would need this but decided not to use

    struct _bstNode* root;

} dictionaryTree;



/** ----------------------------------------------------------
 * insertBST() inserts an item into a BST
 * @param node - a pointer to the root of the BST to instert
 * the item in.
 * @param item - the data item to insert into the BST
 * @return returns a pointer to the root of the BST
 * ----------------------------------------------------------
 */
struct _bstNode* insertBST(_bstNode* node, char item);


/** ----------------------------------------------------------
 * printInorderBST() traverses and prints the BST
 * inorder.
 * @param node - a pointer to the root of the BST
 * ----------------------------------------------------------
 */
void printInorderBST(_bstNode* nodePtr);


/** ----------------------------------------------------------
 * printPreorderBST() traverses and prints the BST
 * preorder.
 * @param node - a pointer to the root of the BST to
 * ----------------------------------------------------------
 */
void printPreorderBST(_bstNode* nodePtr);


/** ----------------------------------------------------------
 * printPostorderBST() traverses and prints the BST
 * postorder.
 * @param node - a pointer to the root of the BST
 * ----------------------------------------------------------
 */
void printPostorderBST(_bstNode* nodePtr);

/** ----------------------------------------------------------
 * readFileIn(struct _bstNode* tree) reads in a dictionary
 * file and then closes the file.
 * @param tree - a pointer to the BST tree
 * ----------------------------------------------------------
 */
void readFileIn(struct _bstNode* tree);

/** ----------------------------------------------------------
 * insertWord(struct _bstNode*, char*) inserts a word to the tree
 * @param tree - a pointer to the BST tree
 * @param word - a pointer to the word that is being added
 * ----------------------------------------------------------
 */

void insertWord(struct _bstNode*, char*);

/** ----------------------------------------------------------
 * checkTreePointer(struct _bstNode* node, char* word, int i) checks what node
 * the function is currently at for purposes of insertion
 * @param node - a pointer to the BST tree
 * @param word - a pointer to the word that is being added/checked
 * @param i - Counter for traversing through a word
 * ----------------------------------------------------------
 */

struct _bstNode* checkTreePointer(struct _bstNode* node, char* word, int i);

/** ----------------------------------------------------------
 * stripNewline(char *word) removes the newline character from a string
 * @param word - a pointer to the word to have the charcter removed
 * ----------------------------------------------------------
 */

void stripNewline(char *word);

/** ----------------------------------------------------------
 * rootNode(struct _bstNode* root) finds the root node of the tree
 * @param root - a pointer to the root node
 * ----------------------------------------------------------
 */

struct _bstNode* rootNode(struct _bstNode* root);

/** ----------------------------------------------------------
 * destroyNode(struct _bstNode* node) destroys the passed node
 * @param node - a pointer to the node to be destroyed
 * ----------------------------------------------------------
 */

void destroyNode(struct _bstNode* node);

/** ----------------------------------------------------------
 * destroyTree(struct _bstNode* root) destroys the entire tree
 * @param root - a pointer to the tree to be destroyed
 * ----------------------------------------------------------
 */

void destroyTree(struct _bstNode* root);

/** ----------------------------------------------------------
 * checkTree(_bstNode* node, char* word, int i) checks if a word is already
 * in the current tree
 * @param node - a pointer to the tree
 * @param word - a pointer to the word being checked
 * @param i - counter variable for traversing through the word
 * ----------------------------------------------------------
 */

bool checkTree(_bstNode* node, char* word, int i);

#endif BSTASLINKEDDS_H
