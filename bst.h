//
// Created by karen on 2018/11/11.
//

#ifndef UNTITLED6_BST_H
#define UNTITLED6_BST_H
#include "data.h"
typedef struct {Node *tree_nodes; unsigned char *is_free; int size;} BStree_struct;
typedef BStree_struct* BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key *key, int data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);
void insert(BStree bst,Key *key, int data, int index);
void inorder(BStree bst, int index);
//int main();
#endif //UNTITLED6_BST_H
