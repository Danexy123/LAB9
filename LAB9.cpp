#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void fileSizeF1F2()
{

    int fileSize; //заносим счетчик байтов в функцию

    ifstream input("F1.txt");

    input.seekg(0, ios::end); //ставит указатель ввода в конец (ios::end) файла и перемещает его к началу через каждый символ
    fileSize = input.tellg(); //определяет текущую позицию указателя ввода и зоносит каждый символ в счетчик
    input.close();

    cout << "Файл F1 весит " << fileSize << " Байт" << endl;

    fileSize = 0;

    ifstream output("F2.txt");

    output.seekg(0, ios::end);
    fileSize = output.tellg();
    output.close();

    cout << "Файл F2 весит " << fileSize << " Байт" << endl;

}

void CopyRowsToF2()
{
    string row;

    ifstream input("F1.txt");

    ofstream output("F2.txt"); //присваиваем файлу "F2.txt" класс выходных потоков

    int rowNum = 1; //вводим значение номера строки

    while (!input.eof()) //вводим цикл проверки строки на четность (условие: пока не закончится файл)
    {
        getline(input, row); //считываем одну строку из файла "F1.txt" в переменную string

        if (rowNum % 2 == 0) //оператор ветвления с условием четности строки 
        {
            output << row << endl; //если строка имеет четный порядоковый номеер, записываем строку в файл "F2.txt"

            rowNum++; //переходим на следующую строку файла 
        }
        else
        {
            rowNum++; //если строка не четная, переходим на следующую сторку
        }
    }

    output.close(); //закрывем файл выходных потоков "F2.txt"
}

int main()
{
    setlocale(LC_ALL, "Rus");

    ifstream input("F1.txt"); //присваиваем файлу "F1.txt" класс входных потоков

    if (input.is_open()) //проверка открывается файл или нет
    {
        CopyRowsToF2();
    }
    else
    {
        cout << "Не удалось открыть файл" << endl; //вывдим сообщение на экран, если не удалось открыть файл "F1.txt"
    }

    input.close(); //закрывем файл входных потоков "F1.txt"

    fileSizeF1F2(); //функция, выводящая на экран размер файлов "F1.txt" и "F2.txt"

    return 0;
}