#include<stdio.h>
#include<stdlib.h>
#define N 10
int f(int *a,int *b){
	if(a+1>b)
	return 0;
	int mid=*a;
	int *x=a;
	int *y=b-1;
	while(y>x){
		while(y>x&&*y>=mid){//为啥要加等号 
			y--;
		} 
		*x=*y;
		while(y>x&&*x<=mid){
			x++;
		}
		*y=*x;
	}
	*x=mid;
	f(a,x);
	f(x+1,b);//为啥要加一，不加一会死在里面 
	
}
int main()
{
	int a[N];
	for(int c=0;c<N;c++){
		a[c]=rand()%N;
	}
	f(a,a+N);
	for(int c=0;c<N;c++){
		printf("%d\n",a[c]);
	}
	return 0;
 } 
