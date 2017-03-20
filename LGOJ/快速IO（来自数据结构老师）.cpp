//这几天用OJ，找出了以前的一些代码片段，贴出来，供大家参考：
//
//
//1、重定向输入
#ifndef _OJ_
freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif


2、快速输入、输出
//仅适合纯数字输入
/*
int ScanDouble()     //输入正 double 
{
double dble=0, ch;
if(ch>='0' && ch<='9')
dble=ch-'0';
while((ch=getchar())>='0' && ch<='9')
dble=dble*10+ch-'0';
return dble;
}
*/
int ScanUInt()     //输入正 int
{
int unSignedInt=0, ch;
if(ch>='0' && ch<='9')
unSignedInt = ch-'0';
while((ch=getchar())>='0' && ch<='9')
unSignedInt = unSignedInt*10 + ch-'0';
return unSignedInt;
}


void OutputDouble(double a)     //输出 double 
{
if(a>9)
OutputDouble(a/10);
putchar((int)a %10+'0');
}


void OutputUSignedInt(int a)    //输出 int
{
if(a>9)
OutputUSignedInt(a/10);
putchar(a%10+'0');
}


void OutputLongLong(long long a)     //输出 double 
{
if(a>9)
OutputLongLong((int) a/10);
putchar((int)a %10+'0');
}






int N;
N=ScanUInt(); // scanf("%u",&N); //printf("%u\n", N);
//scanf("%d/n", &N); // int
//const int MAXS = 80000000; // 实际可读取  7999 9999 
char * buf; //char buf[MAXS]; 数组上限比较小 
buf=new char[N*20];
int len = fread(buf, 1, N*20, stdin);
buf[len] = '\0';


    // ... ...
delete []buf;




//代码片段，主要是大数据量时的快速输入，快速输出，在OJ竞赛时，
//常规的cin、cout，循环逐个读取和输出，时间效率上通常是不够的。

