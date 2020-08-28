#include <iostream>

#include "inputFunc.h"
#include "sortAlgs.h"

using namespace std;

int main() {

    int size = -322;
    string str;

    while(size == -322){
        cout << "Введите размер массива: \n";
        getline(cin, str);
        size = Checker(str);
    }

    int temp;
    int *arrayForShaker = new int[size];
    int *arrayForFast = new int[size];

    for (int i = 0; i < size; i++){

        temp = -322;

        while(temp == -322){
            cout << "Введите " << i + 1 << " элемент массива: ";
            getline(cin, str);
            temp = Checker(str);
            if (temp == -322) cout << "Некорректный ввод, повторите попытку!\n";
        }

        arrayForShaker[i] = temp;
        arrayForFast[i] = temp;

    }

    struct Returner tempStruct{};

    tempStruct = ShakerSort(arrayForShaker, size);

    cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < size; i++){
        cout << arrayForShaker[i] << " ";
    }

    cout << "\n\nКоличество перестановок и сравнений алгоритма "
            "сортировки с помощью прямого обмена(пузырькового) соответственно:"
            "\n" << tempStruct.countOfSwaps << " " << tempStruct.countOfComparisons << endl << endl;

    tempStruct = FastSort(arrayForFast, 0, size - 1);

    cout << "\nКоличество перестановок и сравнений алгоритма "
            "сортировки с помощью прямого включения соответственно:"
            "\n" << tempStruct.countOfSwaps << " " << tempStruct.countOfComparisons << endl;

    delete[] arrayForShaker;
    delete[] arrayForFast;

    return 0;
}
