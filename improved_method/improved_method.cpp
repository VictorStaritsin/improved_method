#include <conio.h>
#include <iostream>
using namespace std;

    /*
     Написать программу, реализующую сортировку массива с 
    помощью усовершенствованной сортировки пузырьковым методом.
    Усовершенствование состоит в том, чтобы анализировать 
    количество перестановок на каждом шагу, если это количество 
    равно нулю, то продолжать сортировку нет смысла — массив 
    отсортирован.
    */

int main()
{
	setlocale(LC_ALL, "Rus");

    srand((int)time(NULL));
    int const Size = 10;
    int const limit = 20;
    int array[Size];
    int storage;
    int count = 0;

    cout << "Выведем случайный массив \n";

    //формируем массив из случайных чисел
    for (int i = 0; i < Size; i++)
    {
        array[i] = rand() % (limit + 1);
        cout << "Число[" << i << "] = " << array[i] << endl;
    }

    for (int i = 0; i < Size - 1; i++, count = 0)
    {
        for (int j = 1; j < Size - i; j++)
        {
            if (array[j] <array[j - 1])
            {
                storage = array[j];
                array[j] = array[j - 1];
                array[j - 1] = storage;
                count++;
            }
        }
        //если замен не было, то выходим из цикла
        if (count == 0)
        {
            break;
        }
    }

    cout << "Сортировка массива \n";

    //выводим отсортированный массив
    for (int i = 0; i < Size; i++)
    {
        cout << "Число[" << i << "] = " << array[i] << endl;
    }
}

