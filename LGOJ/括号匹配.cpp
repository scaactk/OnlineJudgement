#include<iostream>
using namespace std;
struct stack{
	char a[100];
	int top;
};
stack* init_stack()
{
	stack* s = new stack();
	s->top = -1;
	return s;
}
stack* push(stack* s,char ch)
{
	s->top++;
	s->a[s->top] = ch;
	return s;
}
char pop(stack* s)
{
	if(s->top>=0){
		char temp = s->a[s->top];
		s->top--;
		return temp;
	}
}
void check(stack* s)
{
	if(s->top>=1){
		int pre = s->top-1;
		//cout<<s->a[pre]<<" "<<s->a[s->top];
		if(s->a[s->top]==')'&&s->a[pre]=='('){
			//cout<<"wocao"<<endl;
			pop(s);
			pop(s);
		}
	}
}

int main()
{
	char c[100]={'\0'};
	gets(c);
	//puts(c);
	stack* s = init_stack();
	for(int i=0;c[i]!='\0';i++)
	{
		//cout<<c[i]<<endl;
		if(c[i]=='('||c[i]==')'){
			//cout<<s->top<<endl;
			push(s,c[i]);
			check(s);
			//cout<<"check hou "<<s->top<<endl;
		}
	}
	if(s->top==-1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
