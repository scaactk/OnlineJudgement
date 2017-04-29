#include<stdio.h>
int main()
{
	long long int x,y;
	long long int p = 1000000007; 
	scanf("%lld %lld",&x,&y);
	int answer = 1;
	x = x%p;
	while(y!=0){ 
		if(y%2==1){
			answer = (answer*x)%p;
		} 
		x = (x*x)%p;
		y/=2;
	}
	printf("%lld\n",answer);
	return 0;
} 
