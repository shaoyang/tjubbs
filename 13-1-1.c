/*
    Author:Shao Yang
    Date  :2012/03/22
    Desc  :single-link-list
*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define DEFAULT_SIZE 100
typedef struct SingleNode{
    int val;
    struct SingleNode* next;
} *Node;


/* creat single link list with DEFAULT_SIZE */
Node creat_list(){
    struct SingleNode nodes[DEFAULT_SIZE];
    return  (Node)nodes;
}

/* creat with customized size */
Node creat_list2(int size){
    Node header = NULL;
    if( (header = (Node)malloc(sizeof(struct SingleNode)*size) == NULL)){
        return NULL;
    }else{
        return header;
    }
}

/* add node which is int to tail*/
void add_tail(Node header,int e){
    while(header && header->next){
        header = header->next;
    }
    Node nnode = (Node)malloc(sizeof(struct SingleNode));
    nnode->val = e;
    nnode->next = NULL;
    header->next = nnode;
}

/*add node at random position*/
Node add_random(Node rnode,int e){
    Node next = rnode->next;
    Node nnode = (Node)malloc(sizeof(struct SingleNode));
    rnode->next = nnode;
    nnode->val = e;
    nnode->next = next;
    return nnode;
}

/* print the linked-list */
void print_list(Node header){
    
    while(header){
        printf("%d\n",header->val);
        header = header->next;
    }
}

/* delete spcificed node*/
void delete(Node header,Node dnode){
    while(header && header->next && header->next != dnode){
        header = header->next;
    }
    header->next = dnode->next;
    /* free the deleted node*/
    free(dnode);
}

/* find special value*/
Node find (Node header,int e){
    while(header && header->next && header->next->val != e){
        header = header->next;
    }

    return header->next;
}

/* calculate size of list*/
int llength(Node header){
    int len = 0;
    while(header){
        printf("val:%d\n",header->val);
        header = header->next;
        len++;
    }
    return len;
}

int main(){
    int i=0;
    //Node header = creat_list2(1);
    Node header = (Node)malloc(sizeof(struct SingleNode));
    header->val = -1;
    header->next = NULL;
    //add_tail
    for(;i<10;i++){
        add_tail(header,i);
    }
    print_list(header);
    //add_random
    add_random(header->next,11);
    print_list(header);
    //find & delete
    delete(header,find(header,8));   
    //print_list(header);
    printf("%d\n",llength(header));
    return 0;
}
