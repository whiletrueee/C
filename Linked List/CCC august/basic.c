#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node* insertAtStart(struct node* head, int value){
    if(head == NULL){
        struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
        newnode->data=value;
        newnode->next=NULL;
        head=newnode;
        newnode->prev=NULL;
        return head;
    }else{
        struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
        newnode->data=value;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
        return head;
        
    }
}

struct node* insertAtEnd(struct node* tail,int value){
    if(tail == NULL){
        struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        tail=newnode;
        return tail;
    }else{
        struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=tail;
        tail=newnode;
        return tail;
        
    }
    
}



int main()
{
    int n,i;
    printf("enter the number of element:- ");
    scanf("%d",&n);
    
    struct node* head=NULL;
    struct node* tail=NULL;
    
    
    for(i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        // head=insertAtStart(head,val);
        tail=insertAtEnd(tail,val);
    }
    
    struct node* ptr=tail;
    
    while(ptr){
        printf("%d",ptr->data);
        if(ptr->prev){
            printf("->");
        }else{
            printf("->null");
        }
        ptr=ptr->prev;
    }
    

    return 0;
}

