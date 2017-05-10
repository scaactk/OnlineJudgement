#include<iostream>
#include<cstdio>
using namespace std;
#define Max_weight 32767

struct Node {
	int weight;
	int parent;
	int left_child;
	int right_child;
	char data;
};
struct Hcode {
	char code[50];//存储哈夫曼编码 
	int start;
};
void create_ht(Node ht[], int n)
{
	int min1, min2;
	int left_node, right_node;

	//初始化节点
	for (int i = 0; i < 2 * n - 1; i++) {
		ht[i].weight = 0;
		ht[i].parent = -1;
		ht[i].left_child = -1;
		ht[i].right_child = -1;
	}

	for (int i = n; i<2 * n - 1; i++)
	{
		min1 = min2 = Max_weight;
		left_node = right_node = -1;//最小权重两个节点的位置
		for (int k = 0; k<i - 1; k++)
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
		ht[left_node].parent = i;
		ht[right_node].parent = i;
		ht[i].weight = ht[left_node].weight + ht[right_node].weight;
		ht[i].left_child = left_node;
		ht[i].right_child = right_node;
	}
}

void create_hcode(Node ht[], Hcode hcode[], int n)//将每个字符转换为相应的huffman编码存入数组中 
{
	Hcode hc;//临时的结构体变量 
	for (int i = 0; i < n; i++)
	{
		hc.start = n;
		int c = i;
		int f = ht[i].parent;
		while (f != -1) //循环直到树根
		{
			if (ht[f].left_child == c) {//判断是否为父节点的左孩子节点 
				hc.code[hc.start--] = '0';
				cout << "start  " << hc.start;
			}
			else {
				hc.code[hc.start--] = '1';
				cout << "start  " << hc.start;
			}
			c = f;
			f = ht[f].parent;
		}
		hc.start++;//start指向huffman编码最开始的字符
		hcode[i] = hc;//将当前字符的huffman编码存入编码数组中 
		//cout << hcode[i].code << "dididi";
	}
}
void print_hcode(Node ht[], Hcode hcode[], int n)
{
	for (int i = 0; i<n; i++)
	{
		int j = 0;
		for (int k = hcode[i].start; k <= n; k++)
		{
			cout << hcode[i].code[k] << endl;
			j++;
		}
	}
}
int main()
{
	int Q;//操作次数
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int T;
		cin >> T;
		if (T == 0) {
			int n;
			cin >> n;
			Node ht[100];
			Hcode hcode[50];
			for (int i = 0; i<n; i++) {
				cin >> ht[i].data;
			}
			for (int i = 0; i<n; i++) {
				cin >> ht[i].weight;
			}
			create_ht(ht, n);
			create_hcode(ht, hcode, n);
			print_hcode(ht, hcode, n);
		}
		else if (T == 1) {
			char arr1[100];
			gets_s(arr1);
			//encoding(arr1);
		}
		else if (T == 2) {
			char arr2[100];
			gets_s(arr2);
			//decoding(arr2);
		}
	}
	system("pause");
}
