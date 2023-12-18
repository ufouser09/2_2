#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;


void findNumbers(NODE *head1,NODE *head2,NODE *head3,int M);
void rotateByRight(NODE **phead);
void rotateByLeft(NODE **phead);
NODE *create_node();
void display(NODE *node);
void addRecord(NODE **phead,int N);

int main(){
	int N,M;
	int i,j;
	
	
	NODE *head1=NULL;
	NODE *head2=NULL;
	NODE *head3=NULL;
	
	printf("lutfen N sayisini giriniz(sayilarin deger aralýðýný yani)\n");
	scanf("%d",&N);
	
	printf("lutfen M sayisini giriniz(yani bir dizide olucak sayý adedi)\n");
	scanf("%d",&M);
	
	
	
	for(i=1;i<=3;i++){
	
	for(j=0;j<M;i++){
		if(i==1){
			addRecord(&head1,N);
		}
		else if(i==2){
			
			addRecord(&head2,N);
		}
		else{
			addRecord(&head3,N);
		}
		
		
	}
	if(i==1){
			display(head1);
		}
		else if(i==2){
			display(head2);
		}
		else{
			display(head3);
		}
		
}
findNumbers(head1,head2,head3,M);




}
void rotateByRight(NODE **phead){
	NODE *current;
	NODE *prev=NULL;
	
	current=*phead;
	while(current->next!=NULL){
		prev=current;
		current=current->next;
	}
	prev->next=NULL;
	current->next=*phead;
	*phead=current;
	
}

void rotateByLeft(NODE **phead){
	NODE *current;
	NODE *tmp;
	while(current->next!=NULL){
	
		current=current->next;
	}
	tmp=(*phead)->next;
	current->next=*phead;
	(*phead)->next=NULL;
	*phead=tmp;	
	
	
}

NODE* create_node(){
	NODE *ptr;
	
	ptr=(NODE*)malloc(sizeof(NODE));
	if(ptr==NULL){
		printf("Warnýng!");
		return;
	}
	
	
	return ptr;
	
}

void display(NODE *node){
	while(node!=NULL){
		printf("%d->",node->data);
		node=node->next;
	}
	printf("null\n");
}


void addRecord(NODE **phead,int N){
	int d;
	NODE *ptr=create_node(N);
	d=rand()%(N+1);
	ptr->data=d;
	ptr->next=NULL;
	
	
	printf("%d eklendi\n",d);
	
	
	ptr->next=*phead;
	*phead=ptr;
}
void findNumbers(NODE *head1,NODE *head2,NODE* head3,int M){
	NODE *tmp1,*tmp2,*tmp3;
	int i,j,k;
	int A1,A2,A3;
	int length1,length2,length3;
	int c1=0,c2=0;
	int counter1=0,counter2=0;
	
	for(i=0,tmp1=head1;tmp1!=NULL;tmp1=tmp1->next,i++){
		for(j=0,tmp2=head2;tmp2!=NULL;tmp2=tmp2->next,j++){
			for(k=0,tmp3=head3;tmp3!=NULL;tmp3=tmp3->next,k++){
				if((tmp1->data==tmp2->data)&&(tmp1->data==tmp3->data)){
					A1=i;
					A2=j;
					A3=k;
				}
			}
		}
	}
	if(A1>A2){
		length1=A1-A2;
		length2=M-A1+A2;
		if(length1<length2){
			c1=2;//2 sað demek
			counter1=length1;
		}
		else{
			c1=1;//1 sol demek
			counter1=length2;
		}
	}
	else{
		length1=A2-A1;
		length2=M-A2+A1;
		if(length1<length2){
			c1=1;
			counter1=length1;
		}
		else{
			c1=2;
			counter1=length2;
		}
	}
	if(A1>A3){
		length1=A1-A3;
		length2=M-A1+A3;
		if(length1<length2){
			c2=2;//2 sað demek
			counter2=length1;
		}
		else{
			c2=1;//1 sol demek
			counter2=length2;
		}
	}
	else{
		length1=A3-A1;
		length2=M-A3+A1;
		if(length1<length2){
			c2=1;
			counter2=length1;
		}
		else{
			c2=2;
			counter2=length2;
		}
	}
	
//-----------------------------------------------------------------
	if(c1==1){
	for(i=0;i<counter1;i++){
		
	
	rotateByLeft(&head2);
}
}
else{
	for(i=0;i<counter1;i++){
	
	rotateByRight(&head2);
}
}
if(c2==1){
	for(i=0;i<counter2;i++){
		
	
	rotateByLeft(&head3);
}
}else{
	for(i=0;i<counter2;i++){
	
	rotateByRight(&head3);
}
	
}
	
	
	
}

