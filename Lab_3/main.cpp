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
    int *arrayForBubble = new int[size];
    int *arrayForDIS = new int[size];

    for (int i = 0; i < size; i++){

        temp = -322;

        while(temp == -322){
            cout << "Введите " << i + 1 << " элемент массива: ";
            getline(cin, str);
            temp = Checker(str);
            if (temp == -322) cout << "Некорректный ввод, повторите попытку!\n";
        }

        arrayForBubble[i] = temp;
        arrayForDIS[i] = temp;

    }

    struct Returner tempStruct{};

    tempStruct = BubbleSort(arrayForBubble, size);

    cout << "Отсортированный массив:\n";
    for (int i = 0; i < size; i++){
        cout << arrayForBubble[i] << " ";
    }

    cout << "\nКоличество перестановок и сравнений алгоритма "
            "сортировки с помощью прямого обмена(пузырькового) соответственно:"
            "\n" << tempStruct.countOfSwaps << " " << tempStruct.countOfComparisons << endl;

    tempStruct = DISSort(arrayForDIS, size);

    cout << "\nКоличество перестановок и сравнений алгоритма "
            "сортировки с помощью прямого включения соответственно:"
            "\n" << tempStruct.countOfSwaps << " " << tempStruct.countOfComparisons << endl;

    delete[] arrayForBubble;
    delete[] arrayForDIS;

    return 0;
}
