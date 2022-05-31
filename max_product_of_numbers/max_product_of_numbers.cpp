#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int mpon(int* mas, int N)
{
	int product3, product2max, product2min, max, min;
	// product3 - наибольшее произведение трех чисел из заданного массива
	// product2max,  product2min - соответственно наибольшее и наименьшее произведение двух чисел из заданного массива
	// max, min - соответственно наибольшее и наименьшее число из заданного массива

	if (N == 3) return mas[0] * mas[1] * mas[2];
	else
	{
		product2min = mas[0] * mas[1];
		product2max = mas[0] * mas[1];
		product3 = mas[0] * mas[1] * mas[2];

		if (mas[0] > mas[1]) 
		{
			max = mas[0]; min = mas[1];
		}
		else
		{
			min = mas[0]; max = mas[1];
		}

		for (int i = 2; i < N; i++)
		{
			if (product3 > product2max * mas[i] && product3 > product2min * mas[i]) product3 = product3;
			else if (product2max * mas[i] > product3 && product2max * mas[i] > product2min * mas[i]) product3 = product2max * mas[i];
			else if (product2min * mas[i] > product3 && product2min * mas[i] > product2max * mas[i]) product3 = product2min * mas[i];

			if (product2max > max * mas[i] && product2max > min * mas[i]) product2max = product2max;
			else if (max * mas[i] > product2max && max * mas[i] > min * mas[i]) product2max = max * mas[i];
			else if (min * mas[i] > product2max && min * mas[i] > max * mas[i]) product2max = min * mas[i];

			if (product2min < max * mas[i] && product2min < min * mas[i]) product2min = product2min;
			else if (max * mas[i] < product2min && max * mas[i] < min * mas[i]) product2min = max * mas[i];
			else if (min * mas[i] < product2min && min * mas[i] < max * mas[i]) product2min = min * mas[i];

			if (max < mas[i]) max = mas[i]; 
			if (min > mas[i]) min = mas[i];
		}
	}
	return product3;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	//int N;
	//cout << "Введите размер массива (он должен быть больше 2) - ";
	//cin >> N;
	//int* list_of_ints = new int[N];
	//for (int i = 0; i < N; i++)
	//{
	//	cin >> list_of_ints[i];
	//}

	int N = 5;
	int* list_of_ints = new int[N];

	for (int i = 0; i < N; i++)
	{
		list_of_ints[i] = -30 + rand() % 61;	//случайное чилсо в диапозоне от -30 до 30
	}

	cout << "\n" << mpon(list_of_ints, N) << "\n";
	system("pause");
	return 0;
}

