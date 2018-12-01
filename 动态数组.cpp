#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>
typedef struct t_vector{
	int *m_base;
	int m_len;
	int m_capacity;
}vector;

void initvector(vector *v){
	v->m_len=0;
	v->m_base=NULL;
	v->m_capacity=0;
}

void destoryvector(vector *v){
	if(v->m_base!=NULL)
		free(v->m_base);
}

void pushbackvector(vector *v , int a){
	if(v->m_len<v->m_capacity){
		v->m_base[v->m_len]=a;
		v->m_len++;
	}
	else{
		if(v->m_capacity==0){
			v->m_base=(int *)malloc(sizeof(int ));
			v->m_capacity=1;
		}
		else{
			int *n_base=(int *)malloc(sizeof(int)*(v->m_capacity)*2);
			memcpy(n_base,v->m_base,sizeof(int)*(v->m_capacity));
			free(v->m_base);
			v->m_base=n_base;
			v->m_capacity*=2;
		}
		v->m_base[v->m_len]=a;
		v->m_len++;
	}
}

void popbackvector(vector *v){
	if(v->m_len==1){
		free(v->m_base);
		v->m_len=0;
		v->m_base=NULL;
		v->m_capacity=0;
	}
	else if(v->m_len-1==v->m_capacity/2){
		int *n_base=(int *)malloc(sizeof(int)*(v->m_len-1));
		memcpy(n_base,v->m_base,v->m_len-1); 
		free(v->m_base);
		v->m_base=n_base;
		v->m_len--;
		v->m_capacity=v->m_len;
	}
	else{
		v->m_len--;
	}
}

int *getvector(vector *v,int pos){
	if(pos>=v->m_len)//数组最后一个不存数 
		return NULL;
	return v->m_base+pos;
}

int sizevector(vector *v){
	return v->m_len;
}

int capacityvector(vector *v){
	return v->m_capacity;
}
int main(){
	vector v;
	initvector(&v);
		for(int j=0;j<=10;j++){
			pushbackvector(&v,j);
		printf("%d %d\n",sizevector(&v),capacityvector(&v));
	}
		for(int j=0;j<=10;j++){
			printf("%d\n",*getvector(&v,j));
		}
		for(int j=0;j<=10;j++){
			popbackvector(&v);
		printf("%d %d\n",sizevector(&v),capacityvector(&v));
	}
	
	
	return 0;
}
