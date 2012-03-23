#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int data;
    struct student* next;
}node;

//create
node* creat(){
    node *head,*p,*s;
    int x,cycle = 1;
    head = (node*)malloc(sizeof(node));
    p = head;
    while(cycle){
        printf("\nplease enter data:");
        scanf("%d",&x);
        if(x!=0){
            s=(node*)malloc(sizeof(node));
            s->data = x;
            p->next = s;
            p = s;
        }else{
            cycle = 0;
        }
    }
    head = head->next;      //make the second node as the real head node
    p->next = NULL;         //set the last node's next null
    return head;
}

//length
int length(node *head){
    int n = 0;
    node* p = head;
    while(p){
        n++;
        p = p->next;
    }
    return n;
}

//print
void print(node* head){
    node *p;
    int n;
    n = length(head);
    p=head;
    while(p){
        printf("%d\n",p->data);
        p = p->next;
    }
}

//delete node
node *del(node* head,int num){
    node *p1,*p2;
    p1 = head;
    while(num != p1->data && p1->next){
        p2 = p1;
        p1 = p1->next;
    }
    if(num == p1->data){
        if(p1 == head){
            head = p1->next;
            free(p1);
        }else
            p2->next = p1->next;
    }else{
        printf("fail to find the target num");
    }
    return head;
}

//insert node
node *insert(node *head, int num){
    node *p0, *p1, *p2;
    p1 = head;
    p0 = (node*)malloc(sizeof(node));
    p0->data = num;
    while(p0->data > p1->data && p1->next){
        p2 = p1;
        p1 = p1->next;
    }
    if(p1->data >= p0->data){
        //if inserted before head
        if(p1 == head){
            p0->next = head;
            head = p0;
        }else{
           p2->next = p0;
           p0->next = p1;
        }
    }else{
        p1->next = p0;
        p0->next = NULL;
    }
}

//reverse
node *reverse(node *head){
    node *p1,*p2,*p3;
    if( !head || !head->next)
        return head;
    p1 = head;
    p2 = p1->next;
    
    while(p2){
        p3 = p2->next;
        p2->next = p1;
        p1 =  p2;
        p2 = p3;
    }
    head->next =NULL;
    head = p1;
    return head;
}

int main(){
    node *head = creat();
    head = reverse(head);
    print(head);
    return 0;
}

