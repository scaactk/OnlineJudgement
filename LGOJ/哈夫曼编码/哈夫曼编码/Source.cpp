#include<iostream>
#include<cstdio>
using namespace std;
struct Node {
	char data;
	int wight;
	Node* left_child;
	Node* right_child;
};
void create_huffman()
{

}
void encoding(char* a)
{

}
void decoding(char* a)
{

}
int main()
{
	int Q;//²Ù×÷´ÎÊý
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int T;
		cin >> T;
		if (T == 0) {
			create_huffman();
		}
		else if(T == 1) {
			char arr1[100];
			gets_s(arr1);
			encoding(arr1);
		}
		else if(T == 2) {
			char arr2[100];
			gets_s(arr2);
			decoding(arr2);
		}
	}
}