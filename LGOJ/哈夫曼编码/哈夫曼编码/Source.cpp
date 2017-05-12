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