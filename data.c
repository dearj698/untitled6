#include<stdio.h>
#include<string.h>
#include "data.h"

int  main() {
    /* code */
    Key keyA=*key_construct("hello",1);
    Key keyB =*key_construct("!!!",10);
    Node nodeA={&keyA,10};
    printf("compare key1 and key2: %d\n",key_comp(keyB,keyA));
    print_node(nodeA);
}
Key *key_construct(char *in_name, int in_id) {
    Key *thekey,mykey={"name",0};
    thekey=&mykey;
    thekey->name=strdup(in_name);
    thekey->id=in_id;
}

int key_comp(Key key1, Key key2) {
    int result;
    result=strcmp(key1.name,key2.name);
    return result;
}
void print_key(Key *key){
    printf("The NAME in the key is: %s\n",key->name);
    printf("The ID in the key is: %d\n",key->id);
}
void print_node(Node node){
    printf("the key of the node is with info below:\n");
    print_key(node.key);
    printf("the data of node is: %d ",node.data);
}