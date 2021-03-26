#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;

};

 struct node* Node(int x)
 {
     struct node* temp=(struct node *)malloc(sizeof(struct node));
     temp->data=x;
     temp->left=NULL;
     temp->right=NULL;
     return temp;
 };

 void print_inorder(struct node* root)
 {
     if(root==NULL)
     return;
     print_inorder(root->left);
     printf("%d\t",root->data);
     print_inorder(root->right);
     return;
 }

void print_preorder(struct node* root)
{
        if(root==NULL)
        return;
        printf("%d\t",root->data);
        print_preorder(root->left);
        print_preorder(root->right);
        return;
}

void print_postorder(struct node* root)
{
    if(root==NULL)
    return;
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d\t",root->data);
    return;
}

void main()
{
 struct node* root=NULL;
      root=Node(99);
      root->left=Node(177);
      root->right=Node(142);
      root->left->left=Node(7);
      root->left->right=Node(5);
      root->left->right->left=Node(47);
      root->left->right->right=Node(10);
      root->right->right=Node(82);
      root->right->right->left=Node(13);
      printf("Inorder display: \n");
      print_inorder(root);
      printf("\nPreorder display: \n");
      print_preorder(root);
      printf("\nPostorder display: \n");
      print_postorder(root);

}
