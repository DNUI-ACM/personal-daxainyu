#include<stdio.h>
int main()
{
	int a;
	int b;
	scanf("%d",&a);
	if(a>1000000)
	{
	b=39500+(a-1000000)/100;
    printf("%d",b);
    }
	else if(600000<a&&a<=1000000)
	{
	b=33500+(a-600000)*1.5/100;
	printf("%d",b);
    }
    else if(400000<a&&a<=600000)
	{
	b=27500+(a-400000)*3/100;
	printf("%d",b);
    }
    else if(200000<a&&a<=400000)
	{
	b=17500+(a-200000)*5/100;
	printf("%d",b);
    }
    else if(100000<a&&a<=200000)
	{
	b=10000+(a-100000)*7.5/100;
	printf("%d",b);
    }
    else if(0<a&&a<=100000)
	{
	b=0+(a)/10;
	printf("%d",b);
    }
    return 0;
 } 
