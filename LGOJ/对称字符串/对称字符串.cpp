#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char s[205]={'\0'};
	char s2[105]={'\0'};
	gets(s);
	int length = strlen(s);
	//cout<<length;
	if(length){
		for(int i=0;i<=(int)length/2-1;i++)
		{
			s2[i]=s[length-i-1];
			//cout<<s2[i];
		}
		//cout<<endl;
		int flag = 0;
		for(int j=0;j<(int)length/2;j++)
		{
			//cout<<s[j]<<" "<<s2[j]<<endl;
			if(s[j]!=s2[j]){
				flag = 1;
			}
		}
		if(flag==1){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
} 
