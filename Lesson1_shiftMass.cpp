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

// Функция печати массива в файл
void print_arr(int* arr, const int arr_size_row)
{

    std::ofstream fileOut("out.txt", std::ios_base::app);
    fileOut << "Размер массива: " << arr_size_row << std::endl << "Массив:\t";

    fileOut << "[";
    for (int i = 0; i < arr_size_row - 1; i++)
    {
        fileOut << arr[i] << ", ";
    }
    fileOut << arr[arr_size_row - 1];
    fileOut << "]" << std::endl;
    fileOut.close();
}

// Заполняем массив из файла
void fill_arr(int* arr, const int arr_size_row) //, int cursor_position)
{
    std::ifstream fileIn("in.txt");
    //fileIn.seekg(cursor_position);

    for (int i = 0; i < arr_size_row; i++)
    {
        fileIn >> arr[i];
    }
    fileIn.close();   
}

// Функция сдвига массива влево
void shiftLeft_arr(int* arr, const int arr_size_row)
{
    int tmp = arr[0];
    for (int i = 0; i < arr_size_row - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[arr_size_row - 1] = tmp;
}

// Функция сдвига массива вправо
void shiftRight_arr(int* arr, const int arr_size_row)
{
    int tmp = arr[arr_size_row - 1];
    for (int i = arr_size_row - 1; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = tmp;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream fileIn("in.txt"); // Открываем файл и проверяем удалось ли открыть
    if (!fileIn)
    {
        std::cout << "Ошибка открытия файла in.txt" << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Данные из файла in.txt считаны." << std::endl;
    }
    
    int arr1_size_row = 0;
    fileIn >> arr1_size_row; // Считываем из файла размер массива 1
    //std::cout << "fileIn.tellg() = " << fileIn.tellg() << std::endl;
    int cursor_position_in = fileIn.tellg(); // Запоминаем положение указателя в файле in.txt
    //std::cout << "cursor_position_in = " << cursor_position_in << std::endl;


    int* arr1 = create_arr(arr1_size_row); //Cоздаем динамический массив 1
    fill_arr(arr1, arr1_size_row, cursor_position_in); // Заполняем динамический массив 1

    /*for (int i = 0; i < arr1_size_row; i++)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;*/



    shiftLeft_arr(arr1, arr1_size_row); // Функция сдвига массива 1 влево
    
    int arr2_size_row = 0;
    //fileIn.seekg(sizeof(arr1[0]) * arr1_size_row - 1); // Перемещаем указатель в файле in.txt на позицию считывания размера массива 2
    fileIn >> arr2_size_row; // Считываем из файла размер массива 2
    //cursor_position_in = fileIn.tellg(); // Запоминаем положение указателя в файле in.txt
    fileIn.close();
    
    int* arr2 = create_arr(arr2_size_row); // Cоздаем динамический массив 2
    fill_arr(arr2, arr2_size_row); // Заполняем динамический массив 2
    shiftRight_arr(arr2, arr2_size_row); // Функция сдвига массива 2 вправо
 
    std::ofstream fileOut("out.txt", std::ios_base::trunc); // Очищаем файл out.txt
    fileOut.close();

    print_arr(arr2, arr2_size_row); // Выводим массив 2
    print_arr(arr1, arr1_size_row); // Выводим массив 1

    std::cout << "Результат работы программы смотри в файле out.txt." << std::endl;

    
    delete[] arr1; // Удаление динамического массива 1
    delete[] arr2; // Удаление динамического массива 2
}