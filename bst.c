#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
BStree bstree_ini(int size) {
    BStree bst = (BStree) malloc(sizeof(BStree_struct));
    (*bst).tree_nodes = (Node *) malloc((size+1)*sizeof(int));
    (*bst).is_free = (unsigned char *) malloc((size+1)*sizeof(char));
    int i;
    for(i=0;i<size+1;i++) (*bst).is_free[i] = '1';
    (*bst).size = size;
    return bst;
}
void bstree_insert(BStree bst, Key *key, int data) {
    int index=1;
    insert(bst,key,data,index);
}
void bstree_traversal(BStree bst) {
    int index=1;
    inorder(bst,index);
}

void bstree_free(BStree bst) {
    free((*bst).tree_nodes);
    free((*bst).is_free);
    free(bst);
}
void insert(BStree bst, Key *key, int data, int index){
if(index>(*bst).size){
    printf("index out of range error");
}
else{
    if((*bst).is_free[index]=='1'){
        (*bst).tree_nodes[index].key=key;
        (*bst).tree_nodes[index].data=data;
        (*bst).is_free[index]='0';
    }
    else{
        if(key_comp(*key,*((*bst).tree_nodes[index].key))<0){
            insert(bst,key,data,index*2);
        }
        else if(key_comp(*key,*((*bst).tree_nodes[index].key))>0){
            insert(bst,key,data,index*2+1);
        }
    }
}
}

void inorder(BStree bst, int index){
    if(index<(*bst).size){
        inorder(bst,index*2);
        print_node((*bst).tree_nodes[index]);
        inorder(bst,index*2+1);
    }
}
int main(){
    BStree bst;
    bst = bstree_ini(100);
    bstree_insert(bst, key_construct("Once", 1), 99);
    bstree_insert(bst, key_construct("upon", 30), 34);
    bstree_insert(bst, key_construct("!!", 19), 45);
    print_node((*bst).tree_nodes[1]);
    print_node((*bst).tree_nodes[2]);
    print_node((*bst).tree_nodes[3]);
}
