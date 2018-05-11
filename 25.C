#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void preorder_traversal(struct node* node){
	if(node){
		printf("%d ",node->data);
		preorder_traversal(node->left);
		preorder_traversal(node->right);
	}
}

void postorder_traversal(struct node* node){
	if(node){
		postorder_traversal(node->left);
		postorder_traversal(node->right);
		printf("%d ",node->data);
	}
}

void inorder_traversal(struct node* node){
	if(node){
		inorder_traversal(node->left);
		printf("%d ",node->data);
		inorder_traversal(node->right);
	}
}

int main(){
	struct node *node1,*node2,*node3,*node4,*node5,*node6;
	node1 = newNode(10);
	node2 = newNode(20);
	node3 = newNode(30);
	node4 = newNode(40);
	node5 = newNode(50);
	node6 = newNode(60);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->right = node6;
	printf("PREORDER TRAVERSAL : \n");
	preorder_traversal(node1);
	printf("\nINORDER TRAVERSAL : \n");
	inorder_traversal(node1);
	printf("\nPOSTORDER TRAVERSAL : \n");
	postorder_traversal(node1);
	printf("\n");
	return 0;
}
