#include<cstdio>
int i;//记录步数
void move(int n, char from, char to)
{
	printf("The %d step: move %c to %c\n", i++, from, to);
}

//汉诺塔递归问题
//n表示要将多少个盘子从起始移动到目标
void Hanio(int n, char start_pos, char tran_pos, char end_pos)
{
	if (n == 1) {//当n==1时，只需要将最大的盘子从起始移动到目标即可
		move(n, start_pos, end_pos);
	}
	else {
		Hanio(n - 1, start_pos, end_pos, tran_pos);//递归处理，一开始的时候，先将n-1个盘子移动到过渡柱上，这里的终点目标为过渡柱
		move(n, start_pos, end_pos);//然后再将底下的大盘子移动到目标柱子
		Hanio(n - 1, tran_pos, start_pos, end_pos);//然后重复上述步骤，此时在过渡柱上的n-1个盘子，这时，原来的起始柱变为过渡柱，过渡柱变为起始柱
	}
}

int main()
{
	int n;
	while (scanf_s("%d", &n) == 1 && n) {
		i = 0;
		Hanio(n, 'a', 'b', 'c');
		printf("Total steps: %d\n", i);
	}
	return 0;
}
//最小步数通项公式为2^n -1；