#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "data.h"
Key *key_construct(char *in_name, int in_id) {
    Key *key = (Key *)malloc(sizeof(Key));
    key->name=strdup(in_name);
    key->id=in_id;
    return key;
}

int key_comp(Key key1, Key key2) {
    int result=0;
    if(key1.name==key2.name){
        if(key1.id>key2.id){
            return 1;
        }
        if(key1.id<key2.id){
            return -1;
        }
        if(key1.id==key2.id){
            return 0;
        }
    }
    else{
        result=strcmp(key1.name,key2.name);
    }
    return result;
}
void print_key(Key *key){
    printf("( %s                %d )",key->name,key->id);
}
void print_node(Node node){
    print_key(node.key);
    printf("         %d\n",node.data);
}
