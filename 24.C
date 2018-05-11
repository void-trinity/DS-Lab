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
	printf("CREATED NODE : %d\n", new->data);
	return (new);
}

void traversal(struct node* node){
	if(node){
		printf("\nNODE : %d\n",node->data);
		if (node->left)
			printf("LEFT NODE : %d\n",node->left->data);
		else
			printf("LEFT NODE : NULL \n");
		if (node->right)
			printf("RIGHT NODE : %d\n",node->right->data);
		else
			printf("RIGHT NODE : NULL \n");
		traversal(node->left);
		traversal(node->right);
	}
}

int main(){
	printf("Program Made by Mohith Khatri\n");
    printf("Roll Number : 16115043\n");
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
	traversal(node1);
	return 0;
}
