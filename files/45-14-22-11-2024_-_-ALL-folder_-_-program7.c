#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
    int data;
    struct node *link;
};

struct node *first=NULL,*last=NULL,*next,*prev,*curr;

void create(){
    curr=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data :");
    scanf("%d",&curr->data);
    curr->link=NULL;
    first=curr;
    last=curr;
}

void insert(){
    int pos,c=1;
    curr=(struct node *)malloc(sizeof(struct node));
    printf("enter the data :");
    scanf("%d",&curr->data);
    printf("enter the position :");
    scanf("%d",&pos);
    if((pos==1)&&(first!=NULL)){
        curr->link=first;
        first=curr;
    }
    else{
        next=first;
        while(c<pos){
            prev=next;
            next=prev->link;
            c++;
        }
        if (prev==NULL){
            printf("invalid position \n");
        }
        else{
            curr->link=prev->link;
            prev->link=curr;
        }
    }
}

void delete(){
    int pos,c=1;
    printf("enter the position :");
    scanf("%d",&pos);
    if(first==NULL){
        printf("list is empty\n");
    }
    else if(pos==1&&first->link==NULL){
        printf("deleted item is %d\n",first->data);
        free(first);
        first=NULL;
    }
    else if(pos==1&&first->link!=NULL){
        curr=first;
        first=first->link;
        curr->link=NULL;
        printf("deleted item is %d\n",curr->data);
        free(curr);
    }
    else{
        next=first;
        while(c<pos){
            curr=next;
            next=next->link;
            c++;
        }
        curr->link=next->link;
        next->link=NULL;
        if(next==NULL){
            printf("invalid position\n");
        }
        else{
            printf("deleted item is %d\n",next->data);
            free(next);
        }
    }
}

void display(){
    curr=first;
    printf("the elements are :\n");
    while(curr!=NULL){
        printf("%d\n",curr->data);
        curr=curr->link;
    }
}


void main(){
    int ch;
    do{
        printf("\n1.create\n2.insert\n3.delete\n4.exit\n");
        printf("enter your choice :");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            create();
            display();
            break;
            case 2:
            insert();
            display();
            break;
            case 3:
            delete();
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("invalid choise\n");
        }
    }while(1);
    return;
}
