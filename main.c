#include <stdio.h>
#include "bstAsLinkedDS.h"

int main(int argc, char *argv[]) {

    char dictionaryFileName[] = "dictionary.txt"; //File path for opening/running the program from the cmd promopt

    _bstNode *newNode = malloc(sizeof(_bstNode)); //Initializing a node so that it is not null.
    newNode->data = 'm';
    newNode->left = NULL;
    newNode->center = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    readFileIn(newNode); //Testing read file
    insertWord(newNode, "BALL"); //Testing word insertion
    printInorderBST(newNode); //Printing for sake of verifying
    //int o = 0;
    //if (checkTree(newNode, "CUT", o) == 1) { //Testing check function
      //  printf("True");
    //}
    //else {
      //  printf("False");
    //}
    destroyTree(newNode); //Destroying tree to deallocate memory

    return 0;
}
