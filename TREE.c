#include <stdio.h>
int main(){
	
	
	
}

tree del(tree root,char data){
	if(root==NULL){
		return root;
	}
	if(data<root->data){
		root->left=del(root->left,data);
	}
	else if(data>root->right){
		root->right=del(root->right,data);
	}
	else{
		if(root->left==NULL){
			tree tmp=root->right;
			free(root);
			return tmp;
		}
		else if(root->right==NULL){
			tree tmp=root->left;
			free(root);
			return tmp;
		}
		tree tmp=minValue(root->right);
		root->data=tmp->data;
		
		root->right=del(root->right,tmp->data);
	}
	return root;
}

tree insert(tree node,char data){
	if(node==NULL){
		return createTree(data);
	}
	if(data<node->data){
		node->left=insert(node->left,data);
	}
	else if(data>node->data){
		node->right=insert(node->right,data);
	}
	return node;
}

tree del(tree root,char data){
	if(root==NULL){
		return root;
	}
	if(data<root->data){
		root->left=del(root->left,data);
	}
	else if(data>root->data){
		root->right=del(root->right,data);
	}
	else{
		if(root->left==NULL){
			tree tmp=root->right;
			free(root);
			return tmp;
		}
		else if(root->right==NULL){
			tree tmp=root->left;
			free(root);
			return tmp;
		}
		tree tmp=minValue(root->right);
		root->data=tmp->data;
		
		root->right=del(root->right,tmp->data);
	}
	return root;
}

tree find(tree root,char data){
	if(root->data->data){
		return find(root->left,data);
	}
	else if(root->right<data){
		return find(root->right,data);
	}
	else{
		return root;
	}
	
}
tree insert(tree node,char data){
	if(node==NULL){
		return createTree(data);
	}
	if(data<node->data){
		node->left=insert(node->left,data);
	}
	else if(node>node->data){
		node->right=insert(node->right,data);
	}
	return node;
}

tree findMin(tree T){
	if(T && T->left){
		return findMin(T->left);
	}
	else{
		return T;
	}
	
}

tree findMax(tree T){
	if(T && T->right){
		return findmax(T->right);
	}
	else{
		return T;
	}
}

tree delete(tree T,char data){
	if(T==NULL){
		return NULL;
	}
	if(data<T->data){
		root->left=del(root->left,data);
	}
	else if(data>T->data){
		root->right=del(root->right,data);
	}
	else if(T->left!=NULL && T->right!=NULL){
		T->data=findMin(root->right)->data;
		T->right=del(T->right,T->data);
	}
	else {
		T=(T->left!=NULL) ? T->left :T->right;
		
		return T;
	}
	
}



tree del(tree root,char data){
	if(root==NULL){
		return root;
	}
	if(data<root->data){
		root->left=del(root->left,data);
	}
	else if(data>root->data){
		root->right=del(root->right,data);
	}
	else if(root->left!=NULL && root->right!=NULL){
		root->data=findMin(root->right)->data;
		root->right=del(root->right,root->data);
	}
	else{
		root=(root->right!=NULL) ? root->right: root->left;
		
		return root;
	}
	
}


//�K�L� A�A� OLUSTURMA D�Z� �LE
#define MAX 100

typedef struct node{
	int data;
	int left;
	int right;
}node;


node tree[MAX];
int root;
int bos;
//left child=2j+1;
//right child=2j+2;
//parent: floor((j-1)/2)


//�K�L� A�A� OLUSTURMA ��ARET�� �LE

typedef struct node *tree;

typedef struct node{
	int data;
	tree left,right;
}node;

tree createTree(int data){
	tree T=(tree*)malloc(sizeof(tree));
	T->data=data;
	T->left=NULL;
	T->right=NULL;
	
	return T;
}

void visit(tree t){
	printf("%c\n",t->data);
}
//�K�L� A�A� ELEMAN EKLEME
tree insert(Tree node,int data){
	if(node==NULL){
		return createTree(data);
	}
	if(data<node->data){
		node->left=insert(node->left,data);
	}
	else if(data>node->data){
		node->right=insert(node->right,data);
	}
	return node;
}


//�K�L� A�A� ELEMAN S�LME
tree del(tree root,int data){
	if(root==NULL){
		return root;
	}
	if(data<root->data){
		root->left=del(root->left,data);
	}
	else if(data>root->data){
		root->right=del(root->right,data);
	}
	else{
		if(root->left==NULL){
			tree tmp=root->right;
			free(root);
			return tmp;
		}
		else if(root->right==NULL){
			tree tmp=root->left;
			free(root);
			return tmp;
		}
		tree tmp=minValue(root->right);
		root->data=tmp->data;
		
		root->right=del(root->right,tmp->data);
	}
	return root;
}
//A�A� KOPYALAMA
tree copyTree(tree orig){
	tree tmp;
	if(orig){
		tmp=(tree)malloc(sizeof(tree));
		tmp->left=copyTree(orig->left);
		tmp->right=copyTree(orig->right);
		tmp->data=orig->data;
		return tmp;
	}
	return NULL;
}
//A�A�LAR E��T M� ?
int isEqualTree(tree first,tree second){
	return ((!first && !second) ||
	(
	(first) &&
	(second) &&
	(first->data ==second->data) &&
	isEqualTree(first->left,second->left) &&
	isEqualTree(first->right,second->right)
	)
	);
	
}


tree find(tree root,char data ){
	if(root->data>data){
		root->left=find(root->left,data);
	}
	else if(root->data<data){
		root->right=find(root->right,data);
	}
	else{
		return root;
	}
}

tree insert(tree node,char data){
	if(node==NULL){
		return createTree(data);
	}
	if(node->data>data){
		node->left=insert(node->left,data);
	}
	else if(node->data<data){
		node->right=insert(node->right,data);
	}
	return node;
}
//M�N�MUM DEGER� BULMA
tree findMin(tree T){
	if(T && T->left){
		return findMin(T->left);
	}
	else{
		return T;
	}
}
//MAXIMUM DEGER� BULMA
tree findMax(tree T){
	if(T && T->right){
		return findMax(T->right);
	}
	else{
		return T;
	}
}

