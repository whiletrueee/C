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
    
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

struct node *reverseDisplay(struct node*head,int k){
    struct node *rev=head;
    while(rev->next!=NULL){
        rev=rev->next;
    }

    while(k!=0){
        printf("%d, ",rev->data);
        rev=rev->prev;
        k--;
    }
}


int reverseAndAdd(struct node* head1, struct node * head2){
    int num1=0,num2=0,count=0;
    struct node *rev=head1; 
    while(rev->next!=NULL){
        count++;
        rev=rev->next;
    }
    count++;
    while(rev!=NULL){
        num1+=(rev->data)*pow(10,count);
        rev=rev->prev;
        count--;
    }
    count=0;
    rev=head2; 
    while(rev->next!=NULL){
        count++;
        rev=rev->next;
    }
    count++;
    while(rev!=NULL){
        num2+=(rev->data)*pow(10,count);
        rev=rev->prev;
        count--;
    }

    return num1+num2;
}




int main(){
    int n;
    printf("Enter size of number ");
    scanf("%d",&n);

    printf("Enter First number \n");
    struct node * head1 = (struct node*)(malloc(sizeof(struct node)));
    create(head1,n);
    display(head1);

    printf("Enter second number \n");
    struct node * head2 = (struct node*)(malloc(sizeof(struct node)));
    create(head2,n);
    display(head2);
    /* write your code below this */
    reverse(head1);
    printf("addition of two numbers %d ",reverseAndAdd(head1,head2));
    
    
    /* write your code above this */
    return 0;
}