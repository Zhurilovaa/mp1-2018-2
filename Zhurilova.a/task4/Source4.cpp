#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<memory.h>
void main()
{
	setlocale(LC_ALL, "Rus");
	int exit, i, j;
	float sum1 = 0, sum2 = 0, oskid = 0;
	const int len = 50;
	int sh, prov=0, a,r=0;
	int shtrih[11][5] = { {1,2,3,4},{4,5,3,7},{7,8,9,3},{9,0,2,7},{1,3,6,4},{2,4,6,8},{3,0,6,5},{5,5,3,2},{6,7,3,4},{8,0,0,6},{1,3,5,0} };
	char tov[11][len] = { {"������� � ������"},{"������� � ��������"},{"������� � �����"},{"���������� ������"}, {"��������"}, {"������� �����"}, {"����������(��������)"}, {"����������� �����(��������)"}, {"���������� ������"}, {"�������"}, {"�� �������� ������ ^_^"} };
	float cena[11] = { 28,25,19,369,600,555,34,50,350,79,2000 };
	float kol[11][2] = { 0 };
	printf("����� ���������� � ������������\n1234\n4537\n7893\n9027\n1364\n2468\n3065\n5532\n6734\n8006\n1350\n");
	while (r == 0)
	{
		prov = 0;
		while (prov == 0)
		{
			printf("������� ����������� �����-���\n");
			scanf("%d", &sh);
			
			for (i = 0; i < 11; i++)
			{
				a = 0;
				for (j = 0; j < 4; j++)
				{
					a = a * 10 + shtrih[i][j];
				}
				if (sh == a)
				{
					prov = 1;
					break;
				}

			}
			if (prov == 0)
			{
				printf("������ �����-���� ��� � �������\n");
			}
			if(prov==1)
			{
				printf("��� �����:\n");
				puts(tov[i]);
				kol[i][0]++;
				kol[i][1] = rand() % (51);
				printf("���� �� �����: %.2f ���.\n", cena[i]);
				printf("��� ��� ���� ��������?\n ���� ��, ������� 1, ���� ���, ������� 0\n");
				scanf("%d", &r);
			}
		}

	}
	printf("�������� ���:\n");
	for (i = 0; i < 11; i++)
	{
		if (kol[i][0] != 0)
		{
			puts(tov[i]);
			printf("%.2f ��. x %.2f ���. ������ �� ����� %.0f%%\n", kol[i][0], cena[i], kol[i][1]);
			sum1 = sum1 + (kol[i][0] * cena[i]);
			sum2 = sum2 + (kol[i][0] *(cena[i]-(cena[i] * kol[i][1] / 100)));
			oskid = 100.0 -(sum2 * 100) / sum1;
			
		}
		
	}
	printf("�����:\n����� ���� ��� ������:%.2f ���.\n����� ������(������ �� ����� �������):%.2f%%\n���� �������:%.2f ���.\n", sum1, oskid, sum2);
	printf("�������, ��� ���������!\n");

	scanf("%d", &exit);
}