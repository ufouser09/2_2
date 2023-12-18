#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
	int kod;
	int syfBak;
	int sayici
	struct node *next;
}NODE;

void addRecord(EMPLOYEE **phead);
void removeRecord(EMPLOYEE **phead);
void delete_from_end()
void printRecords(NODE *head);

int main(){
	NODE *head=NULL;
	int K,N;
	int count=0;
	
	printf("lutfen K sayisini giriniz\n");
	scanf("%d",&K);
	printf("lutfen N sayisini giriniz\n");
	scanf("%d",&N);
	
	
	
	int i=0;
	
	while(i!=2){
	
	printf("1-Add\n2-Exit");
	scanf("%d",&choice);
	
	if(i==1){
	
		
		
	NODE *node=createNode();
	if(node->syfBak==0){
		addRecord(&head,node);
	}
	if(count==N){
		delete_from_end();
	}
	
	
}
}
head=NULL;
free(head);
}

NODE *createNode(){
	
	EMPLOYEE *node;
	
	
	node=(NODE*)malloc(sizeof(NODE));
																																	
																																	
	printf("lutfen kod numarasýný giriniz\n");
	scanf("%d",&node->kod,&node->syfBak);
	
	printf("eleman olusturuldu\n");
	
	return node;
	
	
}

void addRecord(NODE **phead,NODE *node){

	
	
	
	
	
	node->next=*phead;
	
	
	*phead=node; 
	
}
void delete_from_end(){
	
	NODE *tmp,*u;
	
	int n;
	
	if(head==NULL){
		printf("List is empty");
		return;
	}
	if(head->next==NULL){
		n=head->data;
		free(head);
		head=NULL;
		printf("%d was deleted",n);
		return;
	}
	
	tmp=head;
	while(tmp->next!=NULL){
		u=tmp;
		tmp=tmp->next;
		
	}
	n=tmp->data;
	u->next=NULL;
	free(tmp);
	printf("%d was deleted",n);
	
}
//TRAVERSE
void printRecords(NODE *head){
	NODE *tmp=head;
	
	while(tmp!=NULL){
		
		tmp=tmp->next;
		printf("%d\t",tmp->kod,tmp->syfBak);
		node->sayici++;
		if(nod->sayici==K){
			
			removeRecord(tmp);
			addRecord(&head,tmp);
		}
	}
}

void removeRecord(NODE **phead,NODE *node){
	
	
	NODE *current=*phead;
	NODE *prev=NULL;
	int found=0;
	
	
	
	
	
	while(current!=NULL && !found){
		
		if(current->kod==kod){
			found=1;
			
			if(prev==NULL){
				*phead=current->next;
			}
			
			else{
				prev->next=current->next;
			}
			
			free(current);
		}
		
		else{
			prev=current;
			current=current->next;
		}
	}
	
}
