#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node *create(struct node*head,int n){
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

struct node *display(struct node*head){
    struct node *ptr=head;

    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

void mergeList(struct node*head1,struct node*head2){
    struct node*ptr1=head1;
    struct node*ptr2=head2;
    while(ptr1!=NULL){
        if((ptr1->data)>(ptr2->data)){
            //struct node * temp = (struct node*)(malloc(sizeof(struct node)));
            //temp->data=ptr1->data;
            ptr1->next=ptr2->next;
            ptr2->next=ptr1;
        }else{
            //struct node * temp = (struct node*)(malloc(sizeof(struct node)));
            //temp->data=ptr1->data;
            ptr1->next=ptr2;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
}


int main(){
    int n,j;
    printf("Enter number of nodes ");
    scanf("%d",&n);

    struct node * head1 = (struct node*)(malloc(sizeof(struct node)));
    printf("Enter data in sorted order for First Linked List\n");
    struct node * q = create(head1,n);
    display(head1);

    printf("Enter data in sorted order for Second Linked List\n");
    struct node * head2 = (struct node*)(malloc(sizeof(struct node)));
    struct node * k = create(head2,n);
    display(head2);

    mergeList(head1,head2);
    printf("The Merged Linked List Is \n");
    display(head2);


    return 0;
}