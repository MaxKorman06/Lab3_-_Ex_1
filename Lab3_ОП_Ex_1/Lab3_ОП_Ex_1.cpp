#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;
double min_arr(int*, int);
double sum_arr(int*, int);
void modul_arr(int*, int);

int main()
{
    SetConsoleOutputCP(1251);
	int n, a = 0;
	int i;
	cout << "Введіть кількість чисел масиву :";
	cin >> n;
	int* arr = new int[n];
	cout << "Введіть числа масиву :" << '\n';
	for (i = 0; i < n; i++)
	{
		cout << "Число " << ++a << ": ";
		cin >> arr[i];
	}
	cout << "Мінімальне число:" << min_arr(arr, n) << '\n';
	cout << "Сума елементів ммасиву що розташовані між першим та другим відємним елементом: " << sum_arr(arr, n) << '\n';
	cout << "Масив ввідсортований так щоб спочатку були числа модуль яких не перевищує 10: \n";
	modul_arr(arr, n);
}

double min_arr(int arr [], int n)
{
	int min;
	min = arr[0];

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
double sum_arr(int arr[], int n)
{
	int  sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			i++;
			for (; i < n; i++)
			{
				if (arr[i] < 0)
				{
					break;
				}
				else
				{
					sum += arr[i];
				}
			}
		}
		
	}
	return sum;
}
void modul_arr(int arr[], int n)
{
	int* arr_h = new int[n];
	int a = 0;
	for (size_t i = 0; i < n; i++)
	{
		arr_h[i] = arr[i];
		if (abs(arr_h[i]) <= 10)
		{
			arr[a] = arr_h[i];
			++a;
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		if (abs(arr_h[i]) > 10)
		{
			arr[a] = arr_h[i];
			++a;
		}
	}
	a = 0;
	for (size_t i = 0; i < n; i++)
	{
		cout << "Число " << ++a << ": " << arr[i] << '\n';
	}
}