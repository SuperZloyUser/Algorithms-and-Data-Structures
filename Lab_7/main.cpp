#include <iostream>
#include <string>
#include "inputFunc.h"
#include "dfs.h"

#define MAX 999999999
using namespace std;

int main() {


    int temp = NUMBER_ERROR;
    string str;
    while (temp == NUMBER_ERROR) {
        cout << "Введите количество вершин: ";

        cin >> str;
        temp = Checker(str);
        if (temp == NUMBER_ERROR) cout << "Некорректные данные\n";
    }

    vector<pair <int, int>> data[temp];
    int wayLength[temp];
    for (int i = 0; i < temp; i++)
        wayLength[i] = MAX;

    int size = temp;
    int v = 0;
    int u = 0;
    getline(cin, str);

    while (true){
        cout << "Введите две вершины графа и длинну ребра для его создания(для выхода введите -1):\n";

        temp = NUMBER_ERROR;

        while (temp == NUMBER_ERROR  || temp < 0 || temp > size) {
            cout << "Первая вершина: ";
            getline(cin, str);
            temp = Checker(str);
            if (temp == -1) break;
            if (temp == NUMBER_ERROR || temp < 0 || temp > size)
                cout << "Некорректные данные\n";
        }
        if (temp == -1) break;
        v = temp - 1;
        temp = NUMBER_ERROR;

        while (temp == NUMBER_ERROR  || temp < 0 || temp > size) {
            cout << "Вторая вершина: ";
            getline(cin, str);
            temp = Checker(str);
            if (temp == NUMBER_ERROR || temp < 0 || temp > size)
                cout << "Некорректные данные\n";
        }
        u = temp - 1;

        temp = NUMBER_ERROR;

        while (temp == NUMBER_ERROR  || temp < 0) {
            cout << "Вес: ";
            getline(cin, str);
            temp = Checker(str);
            if (temp == NUMBER_ERROR || temp < 0)
                cout << "Некорректные данные\n";
        }

        data[v].emplace_back(u, temp);

    }

    wayLength[0] = 0;
    dfs(data, wayLength, size, 0);

    cout << "\nРасстояния до каждой из вершин от первой:\n";
    for (int i = 0; i < size; i++)
        if (wayLength[i] == MAX) cout << i+1 << ") Пути нет!\n";
        else
            cout << i + 1 << ") " << wayLength[i] << endl;

    return 0;

}
