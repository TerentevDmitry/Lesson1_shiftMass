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
void print_arr(int* arr, const int arr_size_row)
{
    std::cout << "[";
    for (int i = 0; i < arr_size_row - 1; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[arr_size_row - 1];
    std::cout << "]" << std::endl;
}

// Заполняем массив из файла
void fill_arr(int* arr, const int arr_size_row, int cursor_position)
{
    std::ifstream fileIn("in.txt");
    fileIn.seekg(cursor_position);

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
        std::cout << "Считываем данные из файла in.txt ..." << std::endl;
    }
    Sleep(1000); //Задержка инфо на экране консоли
    system("cls"); //Очищаем консоль

    int arr1_size_row = 0;

    fileIn >> arr1_size_row; // Считываем из файла размер массива 1.
    int cursor_position = fileIn.tellg();
    std::cout << "cursor_position1: " << fileIn.tellg() << ". " << std::endl;
    

    int* arr1 = create_arr(arr1_size_row); //создаем динамический массив 1.

    std::cout << "Размер массива 1: " << arr1_size_row << ". " << std::endl << "Массив 1 из файла:\t\t";
    
    fill_arr(arr1, arr1_size_row, cursor_position);
    print_arr(arr1, arr1_size_row); //печатаем исходный массив 1.
    
    std::cout << "Массив 1 со сдвигом влево:\t";
    shiftLeft_arr(arr1, arr1_size_row);
    print_arr(arr1, arr1_size_row);

    int arr2_size_row = 0;
    
    fileIn.seekg(arr1_size_row);
    int cursor_position2 = fileIn.tellg();
    
    std::cout << "cursor_position2: " << fileIn.tellg() << ". " << cursor_position2 << std::endl;
    fileIn >> arr2_size_row; // Считываем из файла размер массива 2.
    

    std::cout << "arr2_size_row: " << arr2_size_row << ". " << std::endl;
  






    /*std::cout << "Массив 2 со сдвигом вправо:\t";
    shiftRight_arr(arr1, arr1_size_row);
    print_arr(arr1, arr1_size_row);*/



    fileIn.close();
    delete[] arr1; // Удаление динамического массива
    //delete[] arr2; // Удаление динамического массива


}