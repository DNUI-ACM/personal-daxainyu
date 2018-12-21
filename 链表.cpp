#include<iostream>
#include<malloc.h>
typedef struct list{
	int base;
	list* next;
}node,*pnode;

pnode Creatlist(void){
	pnode head=(pnode)malloc(sizeof(node));
	head->next=NULL;
	return head;
}

void Addlist(pnode p,int a){//从前插入 
	pnode pnew=(pnode)malloc(sizeof(node));
	pnode pn=p;
	pnew->base = a;
	pnew->next = pn->next;
	pn->next= pnew;
}

void addlist(pnode p,int len,int a){//指向插入 
	int c=0;
	pnode pn = p;
	while(p != NULL && c < len-1 ){
		pn = pn->next;
		c++;
	}	
	pnode pnew = (pnode)malloc(sizeof(node));
	pnew->base = a;
	pnew->next = pn->next;
	pn->next = pnew;
}

pnode findlist(pnode p,int a){
	pnode pn = p;
	int len = 0;
	while(pn != NULL && pn->base != a){
		pn = pn->next;
		len++;
	}
	if(pn ==NULL)
		printf("找不到。");
	else
		printf("%d",len);
	printf("\n");
	return pn; 
}

void putlist(pnode p){
	pnode pn = p->next;
	if( pn == NULL)
		printf("链表为空。");
	while(pn != NULL){
		printf("%d ",pn->base);
		pn = pn->next;
	}
	printf("\n");
}

void deletelist(pnode p){//全删 
	pnode pn,pnew;
	pn = p->next;
	p->next = NULL;
	while(pn != NULL){
		pnew = pn->next;
		free(pn);
		pn = pnew;
	}
}

void Deletelist(pnode p,int a){//指向删除 
	int len = 0;
	pnode pn = p;
	while(pn != NULL && len<a-1){
		pn = pn->next;
		len++;
	}
	pnode pnew = pn->next;
	pn->next = pnew->next;
	free(pnew);
	pnew = NULL;
}

int main(){
	pnode lists = Creatlist();
	for(int c=1;c<10;c++){
		addlist(lists,c,c);
	} 
	putlist(lists);
	findlist(lists,5);
	Deletelist(lists,5);
	putlist(lists); 
	deletelist(lists);
	putlist(lists);
}
