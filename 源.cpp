#define _CRT_SECURE_NO_WARNINGS_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
typedef struct dian
{
	int m[10];
	int l;
}di;
void chuang(int a[], di *k, int n);
void zeng(di *k, int a, int b);
void shan(di *k, int b);
void cha(di *k, int b);
void gai(int i, di *k, int b);
void print(di *k);
void yong(int i,di *k);
int  mian()
{
	printf("1.创建链表\n");
	printf("2.增\n");
	printf("3.删\n");
	printf("4.查\n");
	printf("5.改\n");
	printf("6.遍历链表\n");
	int i;
	scanf_s("%d", &i);
	return i;

}
void chuang(int a[], int n, di *k)
{

	k->l = n;
	int i;
	for (i = 0; i <n; i++)
	{
		k->m[i] = a[i];
	}
}
void zeng(di *k, int a, int b)
{
	int c;
	if (b < 1 || b>(k->l) + 1)
		printf("插入位置错误");
	if (k->l == 100 + 1)
		printf("表已满");
	for (c = k->l; c > b; c--)
	{
		k->m[c] = k->m[c - 1];
	}
	k->m[b] = a;
	k->l += 1;
}
void shan(di *k, int b)
{
	if (b < 1 || b>(k->l) + 1)
		printf("删除位置错误");
	if (k->l == 0)
		printf("表为空");
	for (int i = b; i <= k->l; i++)
	{
		k->m[i] = k->m[i + 1];
	}
	k->l -= 1;
}
void cha(di *k, int b)
{
	if (b < 1 || b>(k->l) + 1)
		printf("查询位置错误");
	if (k->l == 0)
		printf("表为空");
	printf("%d", k->m[b-1]);
}
void gai(int i, di *k, int b)
{
	if (b < 1 || b>(k->l) + 1)
		printf("更改位置错误");
	if (k->l == 0)
		printf("表为空");
	k->m[b] = i;
}
void print(di *k)
{
	for (int i = 0;i<=k->l-1; i++)
	{
		printf("%d", k->m[i]);
	}
}
void yong(int i,di *k)
{
	if (i == 1);
	else if (i == 2) {
		zeng(k, 8, 2); print(k);
	}
	else if (i == 3) {
		shan(k, 2); print(k);
	}
	else if (i == 4) {
		cha(k, 3);
	}
	else if (i == 5) {
		gai(9, k, 2); print(k);
	}
	else if (i == 6) { print(k); }
}
int main(void)
{
	di *k;
	k = (di *)malloc(sizeof(di));
	int a[3] = { 1,2,3 };
	chuang(a, 3, k);
	int i=mian();
	yong(i, k);
	printf("\n");
	int l;
	printf("如果结束请输入“0”否则输入任意值");
	scanf_s("%d", &l);
	while(l)
	{
		yong(l, k);
		printf("\n如果结束请输入“0”否则输入任意值");
		scanf_s("%d", &l);
	}
	system("pause");
}
