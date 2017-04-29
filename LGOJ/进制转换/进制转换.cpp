#include<iostream>
using namespace std;
struct stack{
	char arr[100];
	int top;
};
#define A 10
#define B 11
#define C 12
#define D 13
#define E 14
#define F 15
#define G 16
#define H 17
#define I 18
#define J 19
#define K 20
#define L 21
#define M 22
#define N 23
#define O 24
#define P 25
#define Q 26
#define R 27
#define S 28
#define T 29
#define U 30
#define V 31
#define W 32
#define X 33
#define Y 34
#define Z 35
void change(stack* s,int temp)
{
	//cout<<temp;
	if(temp==0){
		s->arr[s->top] = '0';
	}
	else if(temp==1){
		s->arr[s->top] = '1';
	}
	else if(temp==2){
		s->arr[s->top] = '2';
	}
	else if(temp==3){
		s->arr[s->top] = '3';
	}
	else if(temp==4){
		s->arr[s->top] = '4';
	}
	else if(temp==5){
		s->arr[s->top] = '5';
	}
	else if(temp==6){
		s->arr[s->top] = '6';
	}
	else if(temp==7){
		s->arr[s->top] = '7';
	}
	else if(temp==8){
		s->arr[s->top] = '8';
	}
	else if(temp==9){
		s->arr[s->top] = '9';
	}
	else if(temp==A){
		s->arr[s->top] = 'A';
	}
	else if(temp==B){
		s->arr[s->top] = 'B';
	}
	else if(temp==C){
		s->arr[s->top] = 'C';
	}
	else if(temp==D){
		s->arr[s->top] = 'D';
	}
	else if(temp==E){
		s->arr[s->top] = 'E';
	}
	else if(temp==F){
		s->arr[s->top] = 'F';
	}
	else if(temp==G){
		s->arr[s->top] = 'G';
	}
	else if(temp==H){
		s->arr[s->top] = 'H';
	}
	else if(temp==I){
		s->arr[s->top] = 'I';
	}
	else if(temp==J){
		s->arr[s->top] = 'J';
	}
	else if(temp==K){
		s->arr[s->top] = 'K';
	}
	else if(temp==L){
		s->arr[s->top] = 'L';
	}
	else if(temp==M){
		s->arr[s->top] = 'M';
	}
	else if(temp==N){
		s->arr[s->top] = 'N';
	}
	else if(temp==O){
		s->arr[s->top] = 'O';
	}
	else if(temp==P){
		s->arr[s->top] = 'P';
	}
	else if(temp==Q){
		s->arr[s->top] = 'Q';
	}
	else if(temp==R){
		s->arr[s->top] = 'R';
	}
	else if(temp==S){
		s->arr[s->top] = 'S';
	}
	else if(temp==T){
		s->arr[s->top] = 'T';
	}
	else if(temp==U){
		s->arr[s->top] = 'U';
	}
	else if(temp==V){
		s->arr[s->top] = 'V';
	}
	else if(temp==W){
		s->arr[s->top] = 'W';
	}
	else if(temp==X){
		s->arr[s->top] = 'X';
	}
	else if(temp==Y){
		s->arr[s->top] = 'Y';
	}
	else if(temp==Z){
		s->arr[s->top] = 'Z';
	}
}
int main()
{
	int num;
	int n;
	cin>>num>>n;
	stack* s = new stack();
	s->top = -1;
	while(num){
		s->top++;
		change(s,num%n);
		num = num/n;
	}
	for(int i=s->top;i>=0;i--)
	{
		cout<<s->arr[i];
	}
	return 0;
} 
