#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
};

struct node *createLinkedList(struct node*head,int n){
    int i,data;
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
    return head;
}

struct node *printLinkedList(struct node*head){
    struct node *ptr=head;

    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}


int main(){
    int n,j;
    printf("Enter number of nodes ");
    scanf("%d",&n);
    struct node * head = (struct node*)(malloc(sizeof(struct node)));
    struct node * q = createLinkedList(head,n);
    printLinkedList(head);
    struct node *duplicate=head;

    while(duplicate->next!=NULL){
        struct node * del;
        if(duplicate->data==duplicate->next->data){
            del=duplicate->next;
            duplicate->next=duplicate->next->next;
            free(del);
        }else{
        duplicate=duplicate->next;
        }
    }
    printLinkedList(head);

    return 0;
}