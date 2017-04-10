#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
/*
int  fun(char *s)
{
	if (*s == '-') {
		s += 1;
		if (*(s + 1) != '\0')
		{
			return  (pow((double)10, (double)strlen(s) - 1)*(*s - '0') + fun(s + 1))*-1;
		}
		else
		{
			return (*s - '0')*-1;
		}
	}
	else {
		if (*(s + 1) != '\0')
		{
			return  pow((double)10, (double)strlen(s) - 1)*(*s - '0') + fun(s + 1);
		}
		else
		{
			return (*s - '0');
		}
	}
}
*/	
void change(char *s) {
	int a[100];
	int i = 0;
	while (*s != '\0') {
		a[i] = *s - '0';
		cout << a[i];
		i++;
		s++;
	}
}
int main() {
	char ch[100];
	gets_s(ch);
	change(ch);
	system("pause");
	return 0;
}