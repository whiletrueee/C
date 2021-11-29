#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
};

struct node *createLinkedList(struct node*head,int n){
    int i;
    struct node*ptr=head;
    for(i=2;i<n+1;i++){
        struct node *temp=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter data for node %d ",i);
        scanf("%d",&temp->data);
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    }
    return head;
}
int main(){
    struct node *head=(struct node*)(malloc(sizeof(struct node)));
    int n,i,data;
    printf("Enter number of nodes");
    scanf("%d",&n);
    printf("Enter data for node 1 ");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;

    struct node*q=createLinkedList(head,n);
    n=n/2;
    while(n!=0){
        q=q->next;
        n--;
    }
    printf("The Middle Most element of linked list is %d",q->data);

    return 0;
}