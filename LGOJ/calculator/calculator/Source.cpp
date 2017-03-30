#include<iostream>
#include<cstdlib>
using namespace std;
struct node {
	int data;
	node* next;
};
int priority[6][6] = {
	3,3,1,1,1,3,
	3,3,1,1,1,3,
	3,3,3,3,1,3,
	3,3,3,3,1,3,
	1,1,1,1,1,2,
	3,3,3,3,0,3,
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


int main()
{
	return 0;
	system("pause");
}