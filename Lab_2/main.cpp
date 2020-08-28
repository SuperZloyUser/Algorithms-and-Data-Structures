#include <iostream>
#include <string>
#include <queue>
#include <ctime>

#include "funcs.h"

#define LOCAL_ERROR -322
#define ENDLESS_LOOP_CONDITION 0
#define ANOTHER_VALUE 54
using namespace std;

int main()
{
    int size = LOCAL_ERROR;
    string str;

    cout << "Введите размер массива: ";
    while(size == LOCAL_ERROR)
    {
        getline(cin, str);
        size = Checker(str);
        if (size == LOCAL_ERROR) cout << "Некорректный ввод! Повторите попытку.\n";
    }

    int *array = new int[size];

    int temp;

    cout << "Введите элементы массива:\n";

    for (int i = 0; i < size; i++)
    {

        temp = LOCAL_ERROR;

        while (temp == LOCAL_ERROR)
        {
            getline(cin, str);
            temp = Checker(str);
            if (temp == LOCAL_ERROR) cout << "Некорректный ввод! Повторите попытку.\n";
        }

        array[i] = temp;

    }

    int loop = 0;
    char let = 0;
    queue<int> ans;
    int time_val = 0;

    while(loop == ENDLESS_LOOP_CONDITION)
    {
        temp = LOCAL_ERROR;
        cout << "Выберите действие: \n1 - Вычисление максимального/минимальн"
                "ого элемента массива\n2 - Вычисление моды массива\n0 - Выход\n";
        while (temp == LOCAL_ERROR)
        {
            cin >> str;
            temp = Checker(str);
            if (temp == LOCAL_ERROR) cout << "Некорректный ввод! Повторите попытку.\n";
        }

        time_val = time(0);

        if (temp == 1) {
            cout << "Введите \"-\" для поиска минимального элемента массива/"
                    " \"+\" - максимального\n";

            temp = LOCAL_ERROR;

            while(temp == LOCAL_ERROR)
            {
                let = getchar();
                if (let != '+' && let != '-') cout << "Некорректный ввод! Повторите попытку.\n";
                else
                    temp = ANOTHER_VALUE;
            }

            if (let == '+') cout << "Максимальный элемент массива - " << MMemSearch(array, size, false) << endl;
            if (let == '-') cout << "Минимальный элемент массива - " << MMemSearch(array, size, true) << endl;
            cout << "Время выполнения алгоритма - " << time(0) - time_val << endl << endl;

        }

        if (temp == 2)
        {
            ans = ModSearch(array, size);

            cout << "Моды данного массива: ";

            while(!ans.empty()){
                cout << ans.front() << "; ";
                ans.pop();
            }
            cout << endl;
            cout << "Время выполнения алгоритма - " << time(nullptr) - time_val << endl << endl;
        }

        if (temp == 0) return 0;

    }

    delete[] array;
    return 0;

}
