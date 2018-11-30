#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>


void main()
{
	setlocale(LC_ALL, "Rus");
	int exit = 0, regim=0, func, flag0 = 0;
	printf("WELCOME!!!\nЖелаете посчитать что-то?\n");
	while (exit == 0)
	{
		printf("Выберите режим работы:\n1 - Однократный расчёт функции в заданной точке;\n2 - Серийный эксперимент;\n");
		scanf("%d", &regim);

		printf("Выберите функцию:\n1 - e^(x);\n2 - sin(x);\n3 - cos(x);\n4 - arccos(x);\n");
		while (flag0 == 0)
		{
			scanf("%d", &func);
			flag0 = 1;
			if (func < 1 || func>4)
			{
				printf("Пожалуйств введите номер функции, согласно предложенным ранее!\n");
				flag0 = 0;
			}
		}
	}
	
}