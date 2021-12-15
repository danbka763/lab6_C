#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <iomanip>

using namespace std;
int main()
{
    system("chcp 1251");
    system("cls");

    srand( time(NULL) ); // устанавливаем стартовое значение для рандома

    cout << "Работу выполнил Жигалин Данил Вадимович гр. 421-1\n" << endl;
    cout << "Введите размерность массива: ";
    
    unsigned n;
    cin >> n;

    int** mass = new int*[n];

    for (unsigned i = 0; i < n; i++)
    {
        mass[i] = new int[n];

        int count = 1;

        for (unsigned j = 0; j < n; j++)
        {
            mass[i][j] = rand();
            //cin >> mass[i][j];

            if (j != 0 && mass[i][j] < mass[i][j - 1])
                count++;

        }

        if (count == n)
        {
            cout << "В " << i+1 << " строке матрицы элементы расположены по невозрастанию : ";
            for (unsigned j = 0; j < n; j++)
                cout << " " << mass[i][j];
            
            cout << "\n";
        }   
    }


    cout << "\nМатрица до преобразований: " << endl;
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < n; j++)
        {
            cout << setw(5) << mass[i][j] << " ";
        }

        cout << endl;
    }


    int* sumLineMass = new int[n];
    int* helpMass = new int[n];

    for (unsigned i = 0; i < n; i++)
    {
        sumLineMass[i] = 0;

        for (unsigned j = 0; j < n; j++)
        {
            sumLineMass[i] += mass[i][j];
        }

        int sum = sumLineMass[i],
            k = i - 1;
        helpMass = mass[i];
        
        while (k >= 0 && sum < sumLineMass[k])
        {
            sumLineMass[k + 1] = sumLineMass[k];
            mass[k + 1] = mass[k];
            k--;
        }
        sumLineMass[k + 1] = sum;
        mass[k + 1] = helpMass;
    }

    cout << "\nПреобразованная матрица: " << endl;
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < n; j++)
        {
            if (j != 0) 
                cout << " + ";
            cout << setw(5) << mass[i][j];
        }

        cout << " = " << sumLineMass[i] << endl;
    }


    for (unsigned i = 0; i < n; i++)
        delete[] mass[i];

    delete[] mass, sumLineMass, helpMass;
}