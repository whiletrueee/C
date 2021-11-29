#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
};

int main(){
    struct node *head=(struct node*)(malloc(sizeof(struct node)));
    int n,i,data;
    printf("Enter number of nodes");
    scanf("%d",&n);
    printf("Enter data for node 1 ");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    struct node*ptr=head;

    for(i=2;i<n+1;i++){
        struct node *temp=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter data for node %d ",i);
        scanf("%d",&temp->data);
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    }
    struct node*q=head;
    int count=0;
    while(q!=NULL){
        count++;
        q=q->next;
    }
    printf("Total number of nodes are %d",count);

    return 0;
}