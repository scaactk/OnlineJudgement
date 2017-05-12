## 题目描述 

利用哈夫曼编码进行信息通信可以大大提高信道利用率，缩短信息传输时间，降低传输成本。但是，这要求在发送端通过一个编码系统对待传输数据预先编码，在接收端将传来的数据进行译码。对于双工信道，每端都需要一个完整的编码/译码系统。试为这样的信息收发站写一个哈夫曼的编/译码系统。
一个完整的系统具有以下几种操作：
0：初始化(Initialization)。从终端读入字符集大小n，以及n个字符和n个权值，建立哈夫曼树。
1：编码(Encoding)。输入一个字符串，利用已建好的哈夫曼树对字符串进行编码，并输出编码后的结果。
2：译码(Decoding)。输入一个二进制数字串，利用已建好的哈夫曼树将数字串进行译码，并输出结果。
为了保证通信顺利进行，编码要求按统一规范进行，构造哈夫曼树的原则是选两个权值最小的，构造一个父结点，其中最小的结点为左孩子，次小的为右孩子，如果选中的两个结点权值相等，则取排在前一个位置的为左孩子。编码原则是左孩子为0，右孩子为1。
现在给出一连串操作，要求根据操作指令和输入数据输出相应结果。

## 输入

首先是一个整数Q，表示操作的次数。
接下来Q行，每行表示一次操作，由一个整数X表示操作类型。
T=0时，输入一个整数n以及n个字符和n个权值，由空格隔开；
T=1时，输入一个待编码字符串；
T=2时，输入一个二进制数字串，表示已编码的字符串。

## 输出 

当T=1时，输出一行编码结果；
当T=2是，输出一行译码结果。

### 样例输入

3
0 3 a b c 1 2 4
1 abcabc
2 0001100011

### 样例输出

0001100011
abcabc

### 提示 
OJ提交的程序不要输出菜单或者其他无关内容。
由于通常哈夫曼树构造可能不唯一，注意题目要求中哈夫曼树的编码规范。
字符仅限大小写字母和数字，大小写敏感。

## 题目分析
主要分为四个步骤
> 1. 根据给定字符的权值建立起huffman树
> 2. 根据已建立的Huffman树，从每个叶子往根节点走，
	 记录下自己是父节点的左孩子(0)还是右孩子(1)，
	 以此为依据建立当前字符对应的编码，
	 并且按照原始叶子节点的顺序存入编码数组中
> 3. 输入一串待编码的字符。依次进行匹配为叶子节点中的第几个，
	 正确匹配后，输出叶子节点对应的Huffman编码。
> 4. 对输入的一串编码进行解码，从huffman树的根节点出发，遇到0则前往左子树，遇到1则前往右子树。
	 直到遇到叶子节点为止，输出该叶子节点的字符。
	 
## AC代码

VS 2015版本 C++17  DEV下需自行调整部分函数
```
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
using namespace std;
#define Max_weight 32767

struct Node {//原节点结构体
	int weight;
	int parent;
	int left_child;
	int right_child;
	char data;
};
struct Hcode {//编码结构体
	char code[50];//存储哈夫曼编码 
	int start;
};
void create_ht(Node ht[], int n)//根据原节点的权值构造huffman树
{
	int min1, min2;
	int left_node, right_node;

	//初始化节点
	for (int i = 0; i < 2 * n - 1; i++) {
		ht[i].parent = -1;
		ht[i].left_child = -1;
		ht[i].right_child = -1;
	}

	for (int i = n; i < 2 * n - 1; i++)
	{
		min1 = min2 = Max_weight;
		left_node = right_node = -1;//最小权重两个节点的位置
		for (int k = 0; k < i; k++)
		{
			if (ht[k].parent == -1) {
				if (ht[k].weight < min1) {
					min2 = min1;
					right_node = left_node;
					left_node = k;
					min1 = ht[k].weight;
				}
				else if (ht[k].weight < min2) {
					min2 = ht[k].weight;
					right_node = k;
				}
			}
		}
		//cout << "当前选中" << ht[left_node].data << "&" << ht[right_node].data << endl;
		ht[left_node].parent = i;
		ht[right_node].parent = i;
		ht[i].weight = ht[left_node].weight + ht[right_node].weight;
		ht[i].left_child = left_node;
		ht[i].right_child = right_node;
		//cout << "生成新节点权重：" << ht[i].weight << endl;
	}
}

void create_hcode(Node ht[], Hcode hcode[], int n)//将每个字符转换为相应的huffman编码存入编码数组中 
{
	Hcode hc;//临时的结构体变量 
	for (int i = 0; i < n; i++)
	{
		hc.start = n;
		int c = i;
		int f = ht[i].parent;
		//由于这里是从叶子节点往根节点走，而实际的Huffman编码为从根节点到叶子结点
		//所以下面的start为从n开始递减，输出是按照start到n正序输出
		while (f != -1) //循环直到树根
		{
			if (ht[f].left_child == c) {//判断是否为父节点的左孩子节点 
				hc.code[hc.start--] = '0';
			}
			else {
				hc.code[hc.start--] = '1';
			}
			c = f;
			f = ht[f].parent;
		}
		hc.start++;//start指向huffman编码最开始的字符
		hcode[i] = hc;//将当前字符的huffman编码存入编码数组中 
	}
}
void encoding(Node ht[], Hcode hcode[], char* arr, int n)//对传入字符串进行编码
{
	Node temp[100];
	for (int i = 0; i<strlen(arr); i++)
	{
		//cout << arr[i] << "编码为" << endl;
		for (int j = 0; j < n; j++)
		{
			if (ht[j].data == arr[i])
			{
				for (int k = hcode[j].start; k <= n; k++)
				{
					cout << hcode[j].code[k];
				}
			}
		}
	}
	cout << endl;
}

void decoding(Node ht[], char* arr, int n)//对传入编码进行解码
{
	int i = 0;
	while (i < strlen(arr))
	{
		//cout << "ddd" << strlen(arr) << endl;
		int temp = 2 * n - 2;
		//cout << "aaa" << ht[temp].left_child << endl;
		while ((ht[temp].left_child != -1) && (ht[temp].right_child != -1))//判断哈夫曼树是否走到了叶子节点
		{
			if (arr[i] == '0')
			{
				temp = ht[temp].left_child;
			}
			else if (arr[i] == '1')
			{
				temp = ht[temp].right_child;
			}
			i++;
		}
		cout << ht[temp].data;
	}
	cout << endl;
}

void print_hcode(Hcode hcode[], int n)//测试用，用于检测是否正常将原节点进行编码
{
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		for (int k = hcode[i].start; k <= n; k++)
		{
			cout << hcode[i].code[k];
			j++;
		}
		cout << endl;
	}
}

int main()
{
	int Q;//操作次数
	cin >> Q;
	Node ht[200];
	Hcode hcode[100];
	int n;
	for (int i = 0; i < Q; i++) {
		int T;
		cin >> T;
		if (T == 0) {
			cin >> n;
			for (int i = 0; i<n; i++) {
				cin >> ht[i].data;
			}
			for (int i = 0; i<n; i++) {
				cin >> ht[i].weight;
			}
			create_ht(ht, n);
			create_hcode(ht, hcode, n);
			//print_hcode(hcode, n);
		}
		else if (T == 1) {
			char arr1[200];
			getchar();
			gets_s(arr1);//由于这里是gets，在测试的时候要注意输完一行数据再回车
			encoding(ht, hcode, arr1, n);
		}
		else if (T == 2) {
			char arr2[200];
			getchar();
			gets_s(arr2);
			//cout << arr2 << endl;
			decoding(ht, arr2, n);
		}
	}
	system("pause");
	return 0;
}
```

github原文地址 > https://github.com/scaactk/OnlineJudgement/tree/master/LGOJ/%E5%93%88%E5%A4%AB%E6%9B%BC%E7%BC%96%E7%A0%81