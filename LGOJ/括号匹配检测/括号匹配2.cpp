#include<iostream>
#include<string.h>
using namespace std; 
struct stack{
	char arr[105];
	int top;
};
void push(stack* s,char temp)
{
	s->top++;
	s->arr[s->top] = temp;
}
char pop(stack* s)
{
	if(s->top>=0){
		char temp = s->arr[s->top];
		s->top--;
		return temp;
	}
}
void check(stack* s)
{
	if(s->top>=1){
		int pre = s->top-1;
		if(s->arr[s->top]==')'&&s->arr[pre]=='(')
		{
			pop(s);
			pop(s);
		}
		else if(s->arr[s->top]==']'&&s->arr[pre]=='[')
		{
			pop(s);
			pop(s);
		}
		else if(s->arr[s->top]=='}'&&s->arr[pre]=='{')
		{
			pop(s);
			pop(s);
		}
	} 
}
int main()
{
	stack* s = new stack();
	s->top = -1;
	char c[105]={'\0'};
	gets(c);
	//int length = strlen(arr);
	//cout<<length;
	for(int i=0;c[i]!='\0';i++)
	{
		if(c[i]=='('||c[i]==')'||c[i]=='['||c[i]==']'||c[i]=='{'||c[i]=='}')
		{
			push(s,c[i]);
			check(s);
		}
	}
	if(s->top==-1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
		if(s->arr[s->top]=='('){
			cout<<')'<<endl;
		} 
		else if(s->arr[s->top]=='{'){
			cout<<'}'<<endl;
		}
		else if(s->arr[s->top]=='['){
			cout<<']'<<endl;
		}
		else if(s->arr[s->top]=='}'){
			cout<<'{'<<endl;
		}
		else if(s->arr[s->top]==']'){
			cout<<'['<<endl;
		}
		else if(s->arr[s->top]==')'){
			cout<<'('<<endl;
		}
	}
}
