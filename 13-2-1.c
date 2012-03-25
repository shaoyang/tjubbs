/*
    Auther: Shao Yang
    Date  : 2012/03/24
    Desc  : Double Linked List DataStructure
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int data;
    struct student *prev;
    struct student *next;
}dnode;

//creat double link list
dnode *creat(){
    dnode *head,*nnode,*pnode;
    int cycle=1,x;
    head = (dnode*)malloc(sizeof(dnode));
    pnode = head;
    while(cycle){
        printf("Enter data:");
        scanf("%d",&x);
        if(x != 0){
            //new node
            nnode = (dnode*)malloc(sizeof(dnode));
            nnode->data = x;
            nnode->next = NULL;
            nnode->prev = pnode;
            //previous node
            pnode->next = nnode;
            pnode = nnode;
        }else{
            cycle = 0;
        }
    }
    head = head->next;
    head->prev = NULL;
    pnode->next = NULL;
    return head;
}

//print
void *print(dnode *head){
    dnode *p = head;
    while(p){
        printf("%d\n",p->data);
        p = p->next;
    }
}

//length
int dlength(dnode *head){
    dnode *p = head;
    int n = 0;
    while(p){
        n++;
        p = p->next;
    }
    return n;
}

//delete node
dnode *delete(dnode *head,int num){
    dnode *p1,*p2;
    p1 = head;

    while( p1 != NULL && num != p1->data){
        p2 = p1;
        p1 = p1->next;
    }//p2 -> p1
    
    //p1 is the last node;
    if(num == p2->data){
        //head node
        if(p2 == head){
            head = head->next;
            head->prev = NULL;
        }else if(p1 == NULL){
            p2->prev->next = NULL;
            free(p2);
        }else{
            p2->prev->next = p1;
            p1->prev = p2->prev;
        }
    }else{
        printf("Fail to find target num: %d\n",num);
    }
    return head;
}

//insert node
dnode *insert(dnode *head,int num){

}

int main(){


}
