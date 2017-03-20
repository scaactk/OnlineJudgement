#include<stdio.h>
int main()
{
	long long int x,y;
	long long int p = 1;
	for(int i=0;i<9;i++){
		p*=10;
	} 
	p+=7;
	//printf("%lld",p);
	scanf("%lld %lld",&x,&y);
	int answer = 1;
	for(int i=0;i<y;i++)
	{
		answer = (answer*x)%p;
	}
	printf("%lld\n",answer);
} 
