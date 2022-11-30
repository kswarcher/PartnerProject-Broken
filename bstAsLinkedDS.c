/** bstAsLinkedDT.c
* ================================================================
* Name: 
* Section: 
* Project: Header for BST library
* =================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "bstAsLinkedDS.h"

/** ----------------------------------------------------------
 * insertBST() inserts an item into a BST
 * @param node - a pointer to the root of the BST to insert
 * the item in.
 * @param item - the data item to insert into the BST
 * @return returns a pointer to the root of the BST
 * ----------------------------------------------------------
 */
struct _bstNode* insertBST(_bstNode* node, char item) {
    if (node == NULL) {
        _bstNode *newNode = malloc(sizeof(_bstNode));
        dictionaryTree *newTree = malloc(sizeof(dictionaryTree));
        newNode->data = item;
        newNode->left = NULL;
        newNode->center = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
        newTree->root = newNode;
        return newNode;
    }
    if (item < node->data) {
        node->left = insertBST(node->left, item);
    } else if (item == node->data) {
        node->left = insertBST(node->center, item);
    } else {
        node->right = insertBST(node->right, item);
    }
    return node;
}



/** ----------------------------------------------------------
 * printInorderBST() traverses and prints the BST
 * inorder.
 * @param node - a pointer to the root of the BST
 * ----------------------------------------------------------
 */
void printInorderBST(_bstNode* node) {
    if (node == NULL) {
        return;
    }
    printInorderBST(node->left);
    printf("%c ",node->data);
    printInorderBST(node->center);
    printInorderBST(node->right);
}

/** ----------------------------------------------------------
 * printPreorderBST() traverses and prints the BST
 * preorder.
 * @param node - a pointer to the root of the BST to
 * ----------------------------------------------------------
 */
void printPreorderBST(_bstNode* node) {
    if (node == NULL) {
        return;
    }
    printf("%c ",node->data);
    printPreorderBST(node->left);
    printInorderBST(node->center);
    printPreorderBST(node->right);
}

/** ----------------------------------------------------------
 * printPostorderBST() traverses and prints the BST
 * postorder.
 * @param node - a pointer to the root of the BST
 * ----------------------------------------------------------
 */
void printPostorderBST(_bstNode* node) {
    if (node == NULL) {
        return;
    }
    printPostorderBST(node->left);
    printInorderBST(node->center);
    printPostorderBST(node->right);
    printf("%c ",node->data);
}


/** ----------------------------------------------------------
 * readFileIn() reads the file in
 * @param tree - node in the tree
 * @return returns nothing
 * ----------------------------------------------------------
 */
void readFileIn(struct _bstNode* tree){

    FILE *dictionaryFile = fopen("../test_dictionary.txt" ,"r");
    if(dictionaryFile==NULL){
        printf("error couldn't open");
        fclose(dictionaryFile);
    }
    int numberOfWords = 0;

    char trash[22];

    while(!feof(dictionaryFile)){

        fscanf(dictionaryFile, "%s\n", trash);
        numberOfWords++;
    }

    int numerator = 1;
    int denominator = 2;

    while (denominator<= numberOfWords){

        if(numerator!=denominator){
            for(int i = 0; i<(numerator*numberOfWords/denominator);++i){
                fscanf(dictionaryFile, "%c\n", trash);
            }
            insertWord(tree, trash);
            numerator++;
        }

        else {
            denominator = denominator*2;
            numerator = 1;
        }

    }

    for(int i = 0; i<(numerator*numberOfWords/denominator);++i){
        fscanf(dictionaryFile, "%c\n", trash);
        stripNewline(trash);
        insertWord(tree, trash);
    }


fclose(dictionaryFile);

}

/** ----------------------------------------------------------
 * insertWord() inserts a word into the tree
 * @param currTree- pointer to a node
 * @param newWord- the word to be inserted
 * @return returns nothing
 * ----------------------------------------------------------
 */

void insertWord(struct _bstNode* currentTree, char* newWord){//read until null char

    if(checkTreePointer(rootNode(currentTree), newWord, 1)!=NULL){
        for(int i = 0; i<strlen(newWord); ++i){

            if(checkTreePointer(rootNode(currentTree), newWord, 0)->data==newWord[i]){

                if ((checkTreePointer(rootNode(currentTree), newWord, 0)->parent == newWord[i-1] &&
                checkTreePointer(rootNode(currentTree), newWord, 0)->parent->center == newWord[i])||
                checkTreePointer(rootNode(currentTree), newWord, 0)->parent == NULL){

                    _bstNode *newNode = malloc(sizeof(_bstNode));
                    newNode->parent = checkTreePointer(rootNode(currentTree), newWord, 1);
                    checkTreePointer(rootNode(currentTree), newWord, 0)->center = newNode;
                    newNode->data = newWord[i];
                    newNode->left = NULL;
                    newNode->center = NULL;
                    newNode->right = NULL;


                }

            }

        }
    }

}

/** ----------------------------------------------------------
 * checkTreePointer() checks the tree for a word
 * @param node- node in the tree
 * @param word- word that is to be checked
 * @param i- number that tells where to start checking in the string, from
 * an outside for loop
 * @return returns the pointer of where a word stopped being in the tree
 * ----------------------------------------------------------
 */

struct _bstNode* checkTreePointer(struct _bstNode* node, char* word, int i) {
        if ((word[i] == '\0') && (word[i] == node->data)) {
            return NULL;
        }
        else if ((word[i] < node->data) && (node->left != NULL)) {
            checkTree(node->left, &word[i], i);
        }
        else if ((word[i] == node->data) && (node->center != NULL)) {
            checkTree(node->center, &word[i+1], (i + 1));
        }
        else if ((word[i] > node->data) && (node->right != NULL)) {
            checkTree(node->right, &word[i], i);
        }
    return node;
}

/** ----------------------------------------------------------
 * stripNewLine() replaces the last char in a string with \0
 * @param word- pointer to a word to be changed
 * @return returns nothing
 * ----------------------------------------------------------
 */

void stripNewline(char *word){
    char *newLine;
    if ((newLine = strchr(word, '\n')) != NULL) {
        *newLine = '\0';
    }
    if ((newLine = strchr(word, '\r')) != NULL) {
        *newLine = '\0';
    }

}


/** ----------------------------------------------------------
 * checkTree() checks the tree for a word
 * @param node- node in the tree
 * @param word- word that is to be checked
 * @param i- number that tells where to start checking in the string, from
 * an outside for loop
 * @return returns a boolean, true if it is found
 * ----------------------------------------------------------
 */
bool checkTree(_bstNode* node, char* word, int i) {
        if ((word[i] == '\0') && (word[i] == node->data)) {
            return true;
        } else if ((word[i] < node->data) && (node->left != NULL)) {
            checkTree(node->left, &word[i], i);
        } else if ((word[i] == node->data) && (node->center != NULL)) {
            checkTree(node->center, &word[i + 1], (i + 1));
        } else if ((word[i] > node->data) && (node->right != NULL)){
            checkTree(node->right, &word[i], i);
        }
        return false;
}

/** ----------------------------------------------------------
 * destroyNode() frees all the nodes in the tree
 * @param node- pointer to a node
 * @return returns nothing
 * ----------------------------------------------------------
 */

void destroyNode(struct _bstNode* node) {
    if (node == NULL) {
        return;
    }
    if (node->parent != NULL) {
        destroyNode(node->left);
        destroyNode(node->center);
        destroyNode(node->right);
        free(node);
    } else{
        free(node);
    }
}

/** ----------------------------------------------------------
 * rootNode() goes to the root of the tree
 * @param node- pointer to a node
 * @return returns a pointer the the root
 * ----------------------------------------------------------
 */

_bstNode* rootNode(struct _bstNode* root){

    while(root->parent != NULL){
        root = root->parent;
    }

    return root;
}

/** ----------------------------------------------------------
 * destroyTree() frees all the nodes in the tree
 * @param node- pointer to a node
 * @return returns nothing
 * ----------------------------------------------------------
 */

void destroyTree(struct _bstNode* root){
    destroyNode(rootNode(root));
}
