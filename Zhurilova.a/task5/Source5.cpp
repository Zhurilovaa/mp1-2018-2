#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
//��������� ��� ������
struct dlfail
{
	char name[50];
	unsigned long long size;
};
int compare(struct dlfail f, struct dlfail l, int s)//��������� ���� ��������� �� ����������� ��� ��������(� ����������� �� ������ � ���������)
{
	if (s == 1)//�� �����������
	{
		if (f.size > l.size)
		{
			return 1;
		}
		else
			return 0;
	}
	if (s == 0)//�� ��������
	{
		if (f.size < l.size)
		{
			return 1;
		}
		else
			return 0;
	}
};
//���������� ���������
void puz_sort(int s, struct dlfail f[], long long size)
{
	long i, j;
	struct dlfail c;
	for (i = 0; i < size; i++)
	{
		for (j = size - 1; j < i; j--)
		{
			if (compare(f[j], f[j - 1], s) == 1)//���� ��������� ������ ������� � ��������� �������� � ��������
			{
				c = f[j - 1];
				f[j - 1] = f[j];
				f[j] = c;
			}

		}
	}
}
//
void vibor(int s, struct dlfail f[], long long size)
{
	long i, j, k;
	struct dlfail c;

}
main()
{
	setlocale(LC_ALL, "Rus");
	
}