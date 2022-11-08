#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>

// Задача 1. Знакомство с Visual Studio 2022. Циклический сдвиг в массиве

// Функция создания динамического массива
int* create_arr(const int size_row)
{
    int* arr = new int[size_row] {};
    return arr;
}

// Функция печати массива
void print_arr(int* arr, const int size_row)
{
    std::cout << "[";
    for (int i = 0; i < size_row - 1; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[size_row - 1];
    std::cout << "]" << std::endl;
}



int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream fileIn("in.txt"); // Открываем файл и проверяем удалось ли открыть
    if (!fileIn)
    {
        std::cout << "Не удалось открыть файл in.txt" << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Считываем данные из файла in.txt ..." << std::endl;
    }
    Sleep(1000); //Задержка инфо на экране консоли
    system("cls"); //Очищаем консоль

    int arr1_size_row = 0;

    fileIn >> arr1_size_row; // Считываем размер массива

    int* arr1 = create_arr(arr1_size_row);

    std::cout << "Размер массива: " << arr1_size_row << ". " << std::endl << "Массив из файла:\t";
    
    print_arr(arr1, arr1_size_row);
    

    std::cout << "Массив со сдвигом:\t";

    print_arr(arr1, arr1_size_row);



}