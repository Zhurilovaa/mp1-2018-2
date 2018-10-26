#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void main()
{
	setlocale(LC_ALL, "Rus");
	int exit,i,j;
	int sh, prov=0, a,r=0;
	int shtrih[11][4] = { {1,2,3,4},{4,5,3,7},{7,8,9,3},{9,0,2,7},{1,3,6,4},{2,4,6,8},{3,0,6,5},{5,5,3,2},{6,7,3,4},{8,0,0,6},{0} };

	printf("1234\n4537\n7893\n9027\n1364\n2468\n3065\n5532\n6734\n8006\n0000\n");
	while (r == 0)
	{
		prov = 0;
		while (prov == 0)
		{
			printf("Введите необходимый штрих код\n");
			scanf("%d", &sh);
			a = 0;
			for (i = 0; i < 11; i++)
			{
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
				printf("Такого штрих кода нет в наличии\n");
			}
			else
				if(prov==1)
			{
				printf("Это все ваши продукты?\n Если да, введите 1, если нет, введите 0\n");
				scanf("%d", &r);
			}
		}

	}
	

	scanf("%d", &exit);
}