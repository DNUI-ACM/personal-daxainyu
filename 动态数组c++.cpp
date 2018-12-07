#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>
using namespace std;
template <class T>
class array{
	private:
		T *base;
		int len;
		int size;
	public:
		bool init();
		
		bool add(T item);
		
		bool pop();
		
		T getv(int p);
		
		int lenv();
		
		int sizev();
};

template<typename T> bool array<T>::init(){
	base=NULL;
	size=0;
	len=0;
	return true;
}

template<typename T> bool array<T>::add(T item){
	if(size==0){
		base=(T*)malloc(sizeof(T));
		size=1;
	}
	if(len >= size){
		int *newbase = (int *) malloc ( size * sizeof(int) * 2);
		memcpy(newbase , base , size * sizeof(int));
		free(base);
		base = newbase;
		size*=2;
	}
	base[len]=item;
	len++;
}

template<typename T> bool array<T>::pop(){
	if(len==1){
		free(base);
		len=0;
		size=0;
		base=NULL;
	}
	else if(len-1<=size/2){
		T *newbase = (T *)malloc (sizeof(T)*(len-1));
		memcpy(newbase, base , sizeof(T)*(len-1));
		free(base);
		base = newbase;
		size=len-1;
		len--;
	}
	else
		len--;
}

template <typename T>T array<T>::getv(int p){
	if(p>=len)
		return NULL;
	T *q=base;
	return *(q+p);
}

template <typename T> int array<T>::lenv(){
	return len;
}

template <typename T> int array<T>::sizev(){
	return size;
}

int main(){
	array<int> arr=*new array<int>;
	arr.init();
	for(int c=0;c<20;c++){
		arr.add(c);
		printf("%d %d\n",arr.getv(c),arr.sizev());
	}
	for(int c=0;c<20;c++){
		arr.pop();
		printf("%d %d\n",arr.lenv(),arr.sizev());
	}
}
