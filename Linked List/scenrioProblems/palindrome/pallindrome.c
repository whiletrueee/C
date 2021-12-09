#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    char letter;
    struct node * next;
    struct node * prev;
};

struct node *create(struct node*head,int n){
    int i;
    char c;
    printf("Enter letter for node 1 ");
    scanf("%c",&c);
    head->letter=c;
    head->next=NULL;
    head->prev=NULL;
    struct node*ptr=head;
    for(i=2;i<n+1;i++){
        struct node *temp=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter data for node %d ",i);
        scanf("%c",&temp->letter);

        temp->next=NULL;   //initialize temp 'next' as NULL
        ptr->next=temp;    //added temp node address to ptr node
        temp->prev=ptr;    //added ptr node address to temp node
        ptr=ptr->next;     //moved pointer to temp node
    }
    return head;
}

struct node *display(struct node*head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d->",ptr->letter);
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
        printf("%d->",rev->letter);
        rev=rev->prev;
    }
    printf("NULL\n");
}

int pallindrome(struct node*head){
    int count;
    struct node *back=head;
    struct node *front=head;

    while(back->next!=NULL){
        back=back->next;
    }
    while(back!=NULL){
        if((back->letter)==(front->letter)){
            count++;
        }else{
            return 0;
        }
        front=front->next;
        back=back->prev;
    }
    return 1;

}


int main(){
    int n,j;
    printf("Enter number of nodes ");
    scanf("%d",&n);
    struct node * head = (struct node*)(malloc(sizeof(struct node)));
    create(head,n);
    printf("original list\n");
    display(head);
    printf("Reverse list\n");
    reverseDisplay(head);
    /* write your code below this */
    int result;
    result=pallindrome(head);
    if(result==1){
        printf("Yes it is pallindrome");
    }else{
        printf("No it is not a pallindrome number");
    }
    /* write your code above this */
    return 0;
}