#include <stdio.h>
struct binary_tree
{
	struct bstnode *left;
	int info;
	struct bstnode *right;
}*root;
typedef struct binary_tree *bstnode;
int m;
bstnode bstmin(bstnode root)//for binary search tree
{
    bstnode curr = root;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}
bstnode bstmax(bstnode root)//for binary search tree
{
    bstnode curr = root;
    while (curr->right != NULL)
        curr = curr->right;
    return curr;
}
bstnode insert(bstnode root, int data)
{
	if (root==NULL)
	{
		bstnode node = (bstnode)malloc(sizeof(struct binary_tree));
		node->info=data;
		node->left=NULL;
		node->right=NULL;
		root=node;
	}
	else if (data < root->info)
	{
		root->left=insert(root->left,data);
	}
	else if (data > root->info)
	{
		root->right=insert(root->right,data);
	}
	return root;
}
bstnode delete(bstnode root,int data)
{
	if (root==NULL)
		printf("\nNot Found\n");
	else
	{
	if (data < root->info)
		root->left=delete(root->left,data);
	else if (data > root->info)
		root->right=delete(root->right,data);
	else//data==root->info
	{
		bstnode temp=root;
		if (root->left==NULL)
		{
			root=root->right;
		}
		else if (root->right==NULL)
		{
			root=root->left;
		}
		else
		{
			bstnode temp = bstmin(root->right);
        	root->info = temp->info;
        	root->right = delete(root->right, temp->info);
		}
	}
	}
	return root;
}
void inorder(bstnode root)
{
	if (root!=NULL)
	{
	inorder(root->left);
	printf("%d\t",root->info);
	inorder(root->right);
	}
}
void preorder(bstnode root)
{
	if (root!=NULL)
	{
	printf("%d\t",root->info);
	preorder(root->left);
	preorder(root->right);
	}
}
void postorder(bstnode root)
{
	if (root!=NULL)
	{
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->info);
	}
}
int search(bstnode root,int data)
{
	if (root==NULL)
		{
			printf("\nNot Found\n");
			return 0;
		}
	if (root->info==data)
		{
			printf("\nFound\n");
			return 1;
		}
	if (data < root->info)
		return search(root->left,data);
	if (data > root->info)
		return search(root->right,data);
}
int findmin(bstnode root)//for binary tree
{
    if (root == NULL)
        return 0;
    int m = root->info;
    if(root->left != NULL)
	 {
        int l = findmin(root->left);
        if(m > l)
            m = l;
     }
    if(root->right != NULL)
	 {
        int r = findmin(root->right);
        if(m > r)
            m = r;
    }
    return m;
}
int findmax(bstnode root)//for binary tree
{
    if (root == NULL)
        return 0;
    int m = root->info;
    if(root->left != NULL)
	 {
        int l = findmax(root->left);
        if(m < l)
            m = l;
     }
    if(root->right != NULL)
	 {
        int r = findmax(root->right);
        if(m < r)
            m = r;
    }
    return m;
}
main()
{
	int k;
	char a;
	root=NULL;
	while(1)
	{
		printf("\nEnter your choice\n");
		char o;
		int l,data,j;
		printf("\n1. Insert\n2. Delete\n3. Find minimum\n4. Find maximum\n5. Inorder traversal\n6. Preorder traversal\n7. Postorder traversal\n8. Exit\n");
		scanf("%d",&l);
		switch(l)
		{
			case 1:
				printf("\nEnter number to insert\n");
				scanf("%d",&data);
				root=insert(root,data);
				break;
			case 2:
				printf("\nEnter number to delete\n");
				scanf("%d",&data);
				root=delete(root,data);
				break;
			case 3:
				j=bstmin(root);
				printf("%d",j);
				break;
			case 4:
				j=bstmax(root);
				printf("%d",j);
				break;
			case 5:
				inorder(root);
				break;
			case 6:
				preorder(root);
				break;
			case 7:
				postorder(root);
				break;
			case 8:
				exit(0);
		}
	}
}
