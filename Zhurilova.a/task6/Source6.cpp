#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

//Функция экспоненты
long double myexp(long double x, int& N, long double eps)
{
	int i;
	long double a=1, y=1;
	long double zn = exp(x);
	for (i = 2; i <= N; i++)
	{
		a = (a*x) / (i - 1);//Считаем каждый следующий через предыдущий
		y = y + a;
		if (fabsl(zn - y) < eps)
		{
			N = i-1;
			return y;
		}			
	}
	return y;
}
//Функция sin
long double mysin(long double x, int& N, long double eps)
{
	int i,j;
	x = fmod(x, 2 * M_PI);
	long double a = x, y = x;
	long double zn = sin(x);
	for (i = 2,j=0; i <= N; i++,j++)
	{
		a = (a*x*x) / ((i + j)*(i + (j + 1)));
		if (i % 2 == 0)
			y = y - a;
		else
			y = y + a;
		if (fabsl(zn - y) < eps)
		{
			N = i - 1;
			return y;
		}
	}
	return y;
}
//Функция cos
long double mycos(long double x, int& N, long double eps)
{
	int i, j;
	x = fmod(x, 2 * M_PI);
	long double a = 1, y = 1;
	long double zn = cos(x);
	for (i = 2, j = -1; i <= N; i++, j++)
	{
		a = (a*x*x) / ((i + j)*(i + (j + 1)));
		if (i % 2 == 0)
			y = y - a;
		else
			y = y + a;
		if (fabsl(zn - y) < eps)
		{
			N = i - 1;
			return y;
		}
	}
	return y;
}
//Функция арккосинуса
long double myacos(long double x, int& N, long double eps)
{
	int i;
	long double a = x, y = (M_PI / 2) - x;
	long double zn = acos(x);
	for (i = 2; i <= N; i++)
	{
		a = a * (x*x*(2 * i + 1)*(2 * i + 1)) / (2 * (i + 1)*(2 * i + 3));
		y = y - a;
		if (fabsl(zn - y) < eps)
		{
			N = i - 1;
			return y;
		}
	}
	return y;
}
void main()
{
	setlocale(LC_ALL, "Rus");
	int exit = 0, regim = 0, func, flag0 = 0;
	int N = 0, i;
	long double x, eps;
	long double(*myfunc[4])(long double, int&, long double);
	myfunc[0] = myexp;
	myfunc[1] = mysin;
	myfunc[2] = mycos;
	myfunc[3] = myacos;
	double(*ITfunc[4])(double);
	ITfunc[0] = exp;
	ITfunc[1] = sin;
	ITfunc[2] = cos;
	ITfunc[3] = acos;
	long double result, myresult;
	printf("WELCOME!!!\nЖелаете посчитать что-то?\n");
	while (exit == 0)
	{
		do {
			printf("Выберите режим работы:\n1 - Однократный расчёт функции в заданной точке;\n2 - Серийный эксперимент;\n");
			scanf("%d", &regim);
			if (regim < 1 || regim>2)
				printf("Вы ввели режим неверно! Попробуйте ещё раз\n");
		} while (regim < 1 || regim>2);//Ввод режима, пока не будет введено верно
		if (regim == 1)//Выбран 1 режим
		{
			printf("Выберите функцию:\n0 - e^(x);\n1 - sin(x);\n2 - cos(x);\n3 - arccos(x);\n");
			flag0 = 0;
			while (flag0 == 0)//Ввод номера функции
			{
				scanf("%d", &func);
				flag0 = 1;
				if (func < 0 || func>3)//Если функция введена неверно
				{
					printf("Пожалуйстa введите номер функции, согласно предложенным ранее!\n");
					flag0 = 0;
				}
			}
			printf("Введите X, который хотите посчитать...\n");
			scanf("%lf", &x);
			do {
				printf("Выберите точность вычислений\nВНИМАНИЕ! Точность вычислений >=0,000001\nP.S:Введите пожалуйста с ','\n");
				scanf("%lf", &eps);
				if (eps < 0.000001)
				{
					printf("Вы ввели точность вычислений неверно! Попробуйте ещё раз\n");
				}
			} while (eps < 0.000001);//Ввод точности, пока не будет введено верно
			do {
				printf("Выберите число элементов ряда для выполнения расчета\nВНИМАНИЕ! Чичло элементов ряда находится в промежутке от 1 до 10000\n");
				scanf("%d", &N);
				if (N < 1 || N>1000)
					printf("Вы ввели число элементов неверно! Попробуйте ещё раз\n");
			} while (N < 1 || N>1000);//Ввод числа элементов, пока не будет введено верно
			//Расчёт
			result = ITfunc[func](x);
			myresult = myfunc[func](x, N, eps);
			eps = fabsl(result - myresult);
			printf("Итог:\nЭталонное значение:                    %lf\n", result);
			printf("Оценка значения функции:                      %lf\n", myresult);
			printf("Разницу между оценкой и эталонным значением:  %lf\n", eps);
			printf("Количество слагаемых, которое было вычислено: %d\n", N);
		}
		if (regim == 2)//Выбран 2 режим
		{
			N = 0;
			eps = -1;
			printf("Выберите функцию:\n0 - e^(x);\n1 - sin(x);\n2 - cos(x);\n3 - arccos(x);\n");
			flag0 = 0;
			while (flag0 == 0)//Ввод номера функции
			{
				scanf("%d", &func);
				flag0 = 1;
				if (func < 0 || func>3)//Если функция введена неверно
				{
					printf("Пожалуйстa введите номер функции, согласно предложенным ранее!\n");
					flag0 = 0;
				}
			}
			printf("Введите X, который хотите посчитать...\n");
			if (func == 3)
				printf("Введите x с 2 знаками после запятой в диапазоне от -1 до 1!\n");
			scanf("%lf.2", &x);
			do {
				printf("Выберите число экспериментов для выполнения расчета\nВНИМАНИЕ! Чичло экспериментов находится в промежутке от 1 до 25\n");
				scanf("%d", &N);
				if (N < 1 || N>25)
					printf("Вы ввели элементов неверно! Попробуйте ещё раз\n");
			} while (N < 1 || N>25);//Ввод числа элементов, пока не будет введено верно
			result = ITfunc[func](x);
			printf("N      Эталон         Оценка         Разница\n");
			printf("-      ------         ------         -------\n");
			for (i = 1; i <= N; i++)
			{
				myresult = myfunc[func](x, i, eps);			
				printf("%.2d %16.10lf %16.10lf %16.10lf\n", i, result, myresult, fabsl(result - myresult));
			}
		}
		printf("Желаете выйти из программы:0-нет, 1-да\n");
		scanf("%d", &exit);
	}
}
