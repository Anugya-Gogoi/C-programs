#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node* next;
};

void print_l(struct node *ref){
    while(ref!=NULL) {
        printf("%d",ref->val);
        ref=ref->next;
    }
}

struct node* insert_beg(struct node *ref,int n) {
    struct node* new_n = (struct node *)malloc(sizeof(struct node));
    new_n->val = n;
    new_n->next=ref;
    ref=new_n;
    return ref;
};



void main() {
    struct node *first, *second, *third = NULL, start;

    //assign address to node pointers
    first = {struct node *}malloc(sizeof(struct node));
    second = {struct node *}malloc(sizeof(struct node));
    third = {struct node *}malloc(sizeof(struct node));

    first->val=1;
    first->next=second;

    second->val=2;
    second->next=third;

    third->val=3;
    third->next=NULL;

    start=first;
    print_l(start);
    start=insert_beg(start,8);
    printf("After insertion at beginning\n");
    print_l(start);
}
