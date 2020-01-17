#include <iostream>
#include <Windows.h>
#include <cstring>
#include <string>
#include <ctime>

//Функция вывода массива
void printArray1(int a[], size_t n) {

	printf("{ ");
	for (size_t i = 0; i < n; i++)
	{
		printf("%i ", a[i]);
	}
	printf("}");
	printf("%s", "\n");
}

//Функция вывода массива без тех, которые при делении на 3 в остатке 1
void printArray2(int a[], size_t n) {

	printf("{ ");
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] % 3 != 1)
		{
			printf("%i ", a[i]);
		}
	}
	printf("}");
	printf("%s", "\n");
}


int processArray(int a[], size_t n, int b, int q) {
	// Счетчик: Кол-во 3 значных элементов
	int cnt = 0;

	// Что бы первое вхождение было = b;
	a[0] = b;

	//цикл для построения прогресси до 10	
	for (int i = 1; i < n; ++i) {
		b = b * q;
		a[i] = b;
	}

	// Проверка массива на кол-во 3 значных 
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 100 && a[i] <= 999)
		{
			cnt++;
		}
	};
	return cnt;
}

int main()
{
	// Вовод и вывод русских символов 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// размер массива равен 10 (по заданию)
	const size_t N = 10;
	int a[N] = { 0 }; // создаем массив и инициализируем нулями
	int b, q; //b - начальный элемент, q - шаг

	printf("Введите начальный элемент: ");
	scanf_s("%d", &b);

	printf("Введите шаг: ");
	scanf_s("%d", &q);
	printf("%s", "\n\n");

	// Вызов функции
	int cnt = processArray(a, N, b, q);

	printArray1(a, N);
	printArray2(a, N);

	// вывод кол-ва  3 значных элементов
	printf("Кол-во 3 значных элементов: ");
	printf("%d", cnt);
	printf("%s", "\n\n");

	system("PAUSE");
	return 0;
}