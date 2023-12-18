#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;


void findNumbers(NODE *head1,NODE *head2,NODE *head3,int M);
NODE *rotateByRight(NODE *phead,int counter);
NODE *rotateByLeft(NODE *phead,int counter);
NODE *create_node();
void display(NODE *node);
void addRecord(NODE **phead,int N);

int main(){
	int N,M;
	int i;
	
	
	NODE *head1=NULL;
	NODE *head2=NULL;
	NODE *head3=NULL;
	
	printf("lutfen N sayisini giriniz(sayilarin deger aralýðýný yani)\n");
	scanf("%d",&N);
	
	printf("lutfen M sayisini giriniz(yani bir dizide olucak sayý adedi)\n");
	scanf("%d",&M);
	
	
	int choice=0;
	while(choice!=-1){
		printf("1-Add\n2-display\n3-Shýft\n4-Exit");
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1:	
			for(i=0;i<M;i++){
			
			addRecord(&head1,N);
			addRecord(&head2,N);
			addRecord(&head3,N);
		}
							break;
									case 2:
										printf("birinci dizimiz\n");
										display(head1);
										printf("ikinci dizimiz\n");
										display(head2);
										printf("ücüncü dizimiz\n");
										display(head3);
												break;
												case 3:findNumbers(head1,head2,head3,M);
												printf("birinci dizimiz\n");
												display(head1);
												
												break;
		}
	}
	
	



}
NODE *rotateByRight(NODE *phead,int counter){
	
	int i;
	for(i=0;i<counter;i++){
	NODE *current;
	NODE *prev=NULL;
	NODE *tmp;
	
	current=phead;
	while(current->next!=NULL){
		prev=current;
		current=current->next;
	}
	tmp=phead;
	
	prev->next=NULL;
	current->next=tmp;
	phead=current;
}
return phead;
}

NODE *rotateByLeft(NODE *phead,int counter){
	int i;
	
	NODE *current=phead;
	NODE *tmp;
	
	while(current->next!=NULL){
	
		current=current->next;
	}
	
	for(i=0;i<counter;i++){
	
	tmp=phead;
	
	current->next=phead;
	current=tmp;
	//(*phead)->next=NULL;
	phead=tmp->next;
	if(i==counter-1){
		current->next=NULL;
	}
	
	
	//*phead=tmp;	
	
}
return phead;
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
	NODE *svg1,*svg2;
	int i,j,k;
	int A1,A2,A3;
	int length1,length2,length3;
	int c1=0,c2=0;
	int counter1=0,counter2=0;
	
	for(i=0,tmp1=head1;tmp1!=NULL;tmp1=tmp1->next,i++){
		for(j=0,tmp2=head2;tmp2!=NULL;tmp2=tmp2->next,j++){
			for(k=0,tmp3=head3;tmp3!=NULL;tmp3=tmp3->next,k++){
				if((tmp1->data==tmp2->data)&&(tmp1->data==tmp3->data)){
					A1=i+1;
					A2=j+1;
					A3=k+1;
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
	
	printf("ikinci dizimiz sola %d kadar gidicek\n",counter1);
	
	svg1=rotateByLeft(head2,counter1);
	printf("ikinci dizimiz\n");
	display(svg1);
	
}
else{
	
	printf("ikinci dizimiz saða %d kadar gidicek\n",counter1);
	svg1=rotateByRight(head2,counter1);
	printf("ikinci dizimiz\n");
	display(svg1);

}
if(c2==1){
	
		
	printf("üçüncü dizimiz sola %d kadar gidicek\n",counter2);
	svg2=rotateByLeft(head3,counter2);
	printf("ucuncu dizimiz\n");
	display(svg2);

}else{
	
	printf("üçüncü dizimiz saga %d kadar gidicek\n",counter2);
	svg2=rotateByRight(head3,counter2);
	printf("ucuncu dizimiz\n");
	display(svg2);

	
}
	
	
	
}

