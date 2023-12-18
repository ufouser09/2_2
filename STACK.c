#include <stdio.h>
#include <stdlib.h>

int main(){
	
}
//STACK BOS MU ?
int isEmpty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
//STACK DOLU MU?
int isFull(){
	if(top==MAXSIZE){
		return 1;
	}
	else{
		return 0;
	}
}
//STACKÝN EN ÜSTTEKÝ ELEMANINI ALIRIZ
int peek(){
	return stack[top];
}
//STACK'E BÝR SEY ATMA
void push(int data){
	if(!isFull()){
		top=top+1;
		stack[top]=data;
	}
	else{
		printf("FULL");
	}
}
//STACKTEN BÝR ÞEY ÇEKME
int pop(){
	int data;
	if(!isEmpty()){
		data=stack[top];
		top=top-1;
		return data;
	}else{
		printf("empty\n");
	}
}
//LÝNKLÝ LÝSTE ÝLE STACK
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *ptr;
}*top,*top1,*temp;

int peek(void);
void push(int data);
int pop(void);
void isEmpty(void);
void destroy(void);
void stack_count(void);
void create(void);

int count=0;

void create(){
	top=NULL;
	
}
void stack_count(){
	printf("\n No. of elements in stack : %d",count);
}

int peek(){
	return(top->data);
}
int isEmpty(){
	if(top==NULL){
		printf("\n stack is empty");
		return 1;
	}
	else{
		printf("\n stack is not empty with %d elements",count);
		return 0;
	}
}
void push(int data){
	if(top==NULL){
		top=(struct node*)malloc(1*sizeof(struct node));
		top->ptr=NULL;
		top->data=data;
	}
	else{
		temp=(struct node*)malloc(1*sizeof(struct node));
		temp->ptr=top;
		temp->data=data;
		top=temp;
	}
	count++;
}
int pop(){
	int ret;
	top1=top;
	if(top1==NULL){
		printf("\n Error:trying to pop from empty stack");
		return -1;
	}
	else{
		top1=top1->ptr;
		ret=top->data;
		printf("\n Popped value:%d",top->data);
		free(top);
		top=top1;
		count--;
		return ret;
	}
}
void destroy(){
	top1=top;
	while(top1 != NULL){
		top1=top->ptr;
		free(top);
		top=top1;
		top1=top1->ptr;
	}
	free(top1);
	top=NULL;
	
	printf("\n All stack elements destroyed");
	count=0;
}



