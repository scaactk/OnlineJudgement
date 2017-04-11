本文采用Markdown格式，原文地址https://github.com/scaactk/OnlineJudgement/tree/master/LGOJ/calculator/calculator
# 数据结构经典问题：带括号的计算器
---
问题描述:
>描述
从键盘输入一个算术表达式(保证是整数)并输出它的结果（保证数据中除法是整除）

>输入
输入一行字符串表示算术表达式包括0..9，+，-，*，/，(，)

>输出
每行输出计算结果

---

### 基本思路:
>规则：
>>1.自左至右扫描表达式，凡是遇到操作数一律进操作数栈。

>>2.当遇到运算符时如果它的优先级比运算符栈栈顶元素的优先级高就进栈。反之，取出栈顶运算符和操作数栈栈顶的连续两个操作数进行运算，并将结果存入操作数栈，然后继续比较该运算符与栈顶运算符的优先级。

 >>3.遇到左括号一律进运算符栈，右括号一律不进运算符栈。在遇到对应的右括号前，括号内运算按规则2进行，当遇到右括号时，将括号内运算结果进操作数栈，并取出左括号。

------

 ### 优先级处理
 >如果我们使用if结构处理这里的优先级问题，由于组合众多，必然是纷繁复杂。所以试图寻找相对简洁的办法

 >>思路一：
1. 我们知道，加减的优先级低于乘除，括号的优先级最高。。。。。那么是否意味着可以通过给运算符分配一个代表优先级的属性，每次比较该属性值的大小。加减法等级为5，乘除法为10，左括号为100  右括号为0 (给定的等级差距足够大)
2. 当两个运算符优先等级相同时(如加法遇上除法)，应当先算前面的，即可以是对 * front+1 * 和 * back * 进行比较，利用这个来处理同等级的优先级问题。
3. 左括号优先级最高，右括号优先级最低


>>思路二：
1. 将所有的优先级比较列入表中，每一对组合对应数组中的一个代表优先级关系的值，每次通过分析操作数的组合，然后根据坐标定位来确定操作。

### 负数处理
> 对于第一个数是负数，需要另外处理

>>思路一：
对于第一个数为负数，即最先入栈的是一个负号，可以在数字栈内补一个0

>>思路二：
当数字栈和符号栈内都为空时(代表读入的第一个为负数)，该负号不入栈，并且将下一个数字乘-1入数字栈

### 注意细节

1. 读取一行数据，若测试OJ最后没有输入'\n',则需要手动添加结束符

2. 对于确定取操作符的优先级表内的坐标时，对于非表内的字符，应当给一个合适的返回值

### 能AC的代码
```
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node {
	int data;
	node* next;
};
int priority[7][7] = { //优先级表
////+ - * / ( ) '\n'
	3,3,1,1,1,3,3,
	3,3,1,1,1,3,3,
	3,3,3,3,1,3,3,
	3,3,3,3,1,3,3,
	1,1,1,1,1,2,2,
	3,3,3,3,0,3,3,
	1,1,1,1,1,0,2,
};
int check_empty(node* top) //检查栈内是否为空
{
	return top ? 0 : 1;
}

node* push(node* top, int x) //压栈
{
	node* p = (node*)malloc(sizeof(node));
	if (p) {
		p->data = x;
		p->next = top;
		top = p;
	}
	return top;
}
node* pop(node* top, int& x) //弹栈
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

int get_top(node* top) //读取栈顶元素
{
	if (check_empty(top)) {
		return 0;
	}
	else return top->data;
}

int sub(int c)  //用于确定操作符在优先级表内的坐标
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
	return -1;
	//缺少这句导致之前一直报错 (本地所有组测试都能过，但是OJ一直过不了)，
	//推测是因为对于操作符空栈的情况，当读入一个操作符时 ,需要读取符号栈内当前的操作符进行优先级比较,而符号栈内现在为空
	//虽然不会触发priority==3或者==1或者==2,按照程序的逻辑这是属于else情况，直接将此操作符入栈。
	//但是这里是一个不稳的因素，当前的操作符对应的优先级是一个随机的数，这会造成严重的后果。
	//以及如果第一输入的个数为负数 ，并且下一个输入的操作符使得当前操作符栈内的负号能够进行计算的话，需要从数据栈内提取出两个数，
	//但是数据栈内目前只有一个数，会出现越界。这里提供另一种简明的解决思路：在数据栈内先压入一个0.
}

int main()
{
	int x1, x2, i, j, op, temp;
	char ch;               //存储读入字符的临时变量
	node* Op = NULL;         //建立操作符栈
	node* Num = NULL;       //建立数字栈
	Op = push(Op, '\n');   //给操作符栈底部先压入一个\n
	ch = getchar();       //读取第一个字符
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
			else if (priority[i][j] == 1) { //优先级低的话，当前操作符入栈
				Op = push(Op, ch);
			}
			else if (priority[i][j] == 2) { //优先级相等的话，弹栈
				Op = pop(Op, temp);
			}
			else {               // 其他情况，将操作符入栈，，，，这里适合于处理第一个数为负数
				Op = push(Op, ch);
			}
		}
		else {      //数字字符转换为数字入栈
			Num = push(Num, ch - 48);
		}
		ch = getchar(); //读取下一个字符
	}
	cout << get_top(Num);
	return 0;
	//system("pause");
}
```
> Writen by Scaactk

> Guided by Ms Dong
