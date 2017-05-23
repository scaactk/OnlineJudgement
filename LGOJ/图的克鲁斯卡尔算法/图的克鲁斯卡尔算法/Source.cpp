#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, fat[200000];
long long int sum;

struct node
{
	int pre, next, w;
}edge[200000];

int father(int x) 
{
	if (fat[x] != x) 
	{
		fat[x] = father(fat[x]);
	}
	return fat[x];
}

void zip(int a, int b) 
{
	int fa = father(a);
	int fb = father(b);
	if (fa != fb) fat[fa] = fb;
}

int cmp(node a, node b) 
{
	if (a.w < b.w) return 1;
	return 0;
}

void kruskal() {
	int k = 0;
	for (int i = 1; i <= m; i++) {
		if (father(edge[i].pre) != father(edge[i].next)) {
			zip(edge[i].pre, edge[i].next);
			sum += edge[i].w;
			k++;
		}
		else if (k == n - 1) break;
	}
}

int main()
{
	cin >> n >> m;
	int a, b, w;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> w;
		edge[i].pre = a;
		edge[i].next = b;
		edge[i].w = w;
	}
	for (int i = 1; i <= n; i++) {
		fat[i] = i;
	}
	sort(edge + 1, edge + m + 1, cmp);
	kruskal();
	cout << sum << endl;
	system("pause");
	return 0;
}