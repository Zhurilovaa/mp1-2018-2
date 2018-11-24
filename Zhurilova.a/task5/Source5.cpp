#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<io.h>
//структура для файлов
struct dlfail
{
	unsigned long size;
	char name[50];
};
int compare(struct dlfail f, struct dlfail l, int s)//сравнение двух элементов по возрастанию или убыванию(в зависимости от выбора в программе)
{
	if (s == 1)//по возрастанию
	{
		if (f.size > l.size)
		{
			return 1;
		}
		else
			return 0;
	}
	if (s == 0)//по убыванию
	{
		if (f.size < l.size)
		{
			return 1;
		}
		else
			return 0;
	}
}
//сортировка пузырьком
void puz_sort(struct dlfail f[], long size, int s)
{
	long i, j;
	struct dlfail c;
	for (i = 0; i < size; i++)
	{
		for (j = (size - 1); j > i; j--)
		{
			if (compare(f[j], f[j - 1], s) == 1)//Если сравнение прошло успешно и требуются действия с массивом
			{
				c = f[j];
				f[j] = f[j-1];
				f[j-1] = c;
			}

		}
	}
}
//сортировка выбором
void vibor(struct dlfail f[], long size, int s)
{
	long i, j, index;
	struct dlfail m;//min или max 
	for (i = 0; i < size; i++)
	{
		index = i; 
		m = f[i];
		for (j = (i + 1); j < size; j++)
		{
			if (compare(f[j], m, s) == 1)
			{
				index = j;
				m = f[j];
			}
		}
		f[index] = f[i];
		f[i] = m;
	}
}
//сортировка вставка
void vstavka(struct dlfail f[], long size, int s)
{
	long i, j;
	struct dlfail c;
	for (i = 0; i < size; i++)
	{
		c = f[i];
		for (j =( i - 1 ); (j >= 0) && (compare(c, f[j], s)==1); j--)
		{
			f[j + 1] = f[j];
		}
		f[j + 1] = c;
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	struct dlfail f[5000];//Массив для файлов
	long kol=0;//Число файлов в наличии
	clock_t t1, t2;
	double tt;
	int sort=0, prov=0, vid=-1, exit=0;
	long i;
	while (1!= 0)
	{
		if (exit == 0) {
			printf("WELCOME!!!\nВведите путь до необходимого вам директория:\nпожалуйства вводите путь в таком виде: C:\\Zhurilova.a\\mp1-2018-2\\Zhurilova.a\\* \n");
			gets_s(path, 200);
		}
		if ((hFile = _findfirst(path, &c_file)) == -1L)
			printf("Здесь совсем нет файлов :((\n");
		else
		{
			//Для начала, посчитать количество файлов директории
			kol = 0;
			printf("FILE            SIZE\n", ' ');
			printf("----            ----\n", ' ');
			do {
				strncpy(f[kol].name, c_file.name, 50);
				f[kol].size = c_file.size;
				printf("%-12.12s %10u\n", f[kol].name, f[kol].size);
				kol++;
			} while (_findnext(hFile, &c_file) == 0);
			_findclose(hFile);
			printf("\nЧисло файлов: %d\n", kol);
			printf("Пожалуйства выберите сортировку...\n1 = Пузырёк\n2 = Выбор\n3 = Вставка\n");
			prov = 1;
			do {
				
				if (prov == 1)
				{
					scanf("%d", &sort);
					prov = 0;
				}
				else
				{
					printf("Введите номер сотировки верно!\n");
					prov = 1;
				}

			} while (sort < 1 || sort > 3);
			printf("Сортировка по возрастанию = 0\nСортировка по убыванию = 1\n");
			prov = 1;
			do {

				if (prov == 1)
				{
					scanf("%d", &vid);
					prov = 0;
				}
				else
				{
				    prov = 1;
					printf("Введите способ сортировки правильно!\n");
				}
			} while (vid > 1 || vid < 0);
			switch (sort)
			{
			case 1:
				t1 = clock();
				puz_sort(f, kol, vid);
				t2 = clock();
				break;
			case 2:
				t1 = clock();
				vibor(f, kol, vid);
				t2 = clock();
				break;
			case 3:
				t1 = clock();
				vstavka(f, kol, vid);
				t2 = clock();
				break;
			}
			tt = double(t2 - t1) / CLOCKS_PER_SEC;
			printf("FILE               SIZE\n", ' ');
			printf("----               ----\n", ' ');
			for (i = 0; i < kol; i++) {
				printf("%-12.12s %10u\n", f[i].name, f[i].size);
			}
			printf("Затрачено времени на сортировку %f", tt);
		}
		
		printf("\nЖелаете закончить работу?\nВведите 0, если да\n 1, если нет\n");
		scanf("%d", &exit);
		getchar();
		if (exit == 0)
			break;
		printf("Желаете сменить сортировку?\n 0 - нет\n 1 - да\n");
		prov = 0;
		do
		{
			if (prov == 1)
				printf("Вы неправильно ввели номер, повторите попытку\n");
			else
				prov = 1;
			scanf_s("%d", &exit);
		} while (exit < 0 || exit > 1);
		getchar();
	}
		
}