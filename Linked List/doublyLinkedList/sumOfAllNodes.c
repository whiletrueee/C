#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node *create(struct node*head,int n){
    int i,data;
    printf("Enter data for node 1 ");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    head->prev=NULL;
    struct node*ptr=head;
    for(i=2;i<n+1;i++){
        struct node *temp=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter data for node %d ",i);
        scanf("%d",&temp->data);

        temp->next=NULL;   //initialize temp 'next' as NULL

        ptr->next=temp;    //added temp node address to ptr node

        temp->prev=ptr;    //added ptr node address to temp node

        ptr=ptr->next;     //moved pointer to temp node
    }
    return head;
}

struct node *display(struct node*head){
    struct node *ptr=head;
    struct node *q=head->next->next;
    printf("q data->%d\n",q->data);
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

struct node *reverseDisplay(struct node*head){
    struct node *rev=head;
    while(rev->next!=NULL){
        rev=rev->next;
    }
    while(rev!=NULL){
        printf("%d->",rev->data);
        rev=rev->prev;
    }
    printf("NULL\n");
}


int main(){
    int n,j;
    printf("Enter number of nodes ");
    scanf("%d",&n);
    struct node * head = (struct node*)(malloc(sizeof(struct node)));
    create(head,n);
    display(head);
    reverseDisplay(head);
    /* write your code below this */

    
    
    /* write your code above this */
    return 0;
}