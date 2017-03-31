#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node {
	int data;
	node* next;
};
int priority[7][7] = {
	3,3,1,1,1,3,3,
	3,3,1,1,1,3,3,
	3,3,3,3,1,3,3,
	3,3,3,3,1,3,3,
	1,1,1,1,1,2,2,
	3,3,3,3,0,3,3,
	1,1,1,1,1,0,2,
};
int check_empty(node* top)
{
	return top ? 0 : 1;
}

node* push(node* top, int x)
{
	node* p = (node*)malloc(sizeof(node));
	if (p) {
		p->data = x;
		p->next = top;
		top = p;
	}
	return top;
}
node* pop(node* top, int& x)
{
	node* temp;
	if (check_empty(top)) {
		return NULL;
	}
	else {
		temp = top;
		x = top->data;
		top = top->next;
		free(temp);
		return top;
	}
}

int get_top(node* top)
{
	if (check_empty(top)) {
		return 0;
	}
	else return top->data;
}

int sub(int c)
{
	switch (c) {
	case '+':
		return 0;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 3;
	case '(':
		return 4;
	case ')':
		return 5;
	case '\n':
		return 6;
	}
}

int main()
{
	int x1, x2, i, j, op, temp;
	char ch;
	node* Op = NULL;
	node* Num = NULL;
	Op = push(Op, '\n');
	ch = getchar();
	while (!(ch == '\n'&&get_top(Op) == '\n')) {
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '\n') {
			i = sub(get_top(Op));
			j = sub(ch);
			if (priority[i][j] == 3) {
				Op = pop(Op, op);
				Num = pop(Num, x2);
				Num = pop(Num, x1);
				switch (op) {
				case '+':
					Num = push(Num, x1 + x2);
					break;
				case '-':
					Num = push(Num, x1 - x2);
					break;
				case '*':
					Num = push(Num, x1 * x2);
					break;
				case '/':
					Num = push(Num, x1 / x2);
					break;
				}
				continue;//跳出当前while循环，下一次while循环时，仍旧为当前的ch 
			}
			else if (priority[i][j] == 1) {
				Op = push(Op, ch);
			}
			else if (priority[i][j] == 2) {
				Op = pop(Op, temp);
			}
			else {
				Op = push(Op, ch);
			}
		}
		else {
			Num = push(Num, ch - 48);
		}
		ch = getchar();
	}
	cout << get_top(Num) << endl;
	return 0;
	//system("pause");
}