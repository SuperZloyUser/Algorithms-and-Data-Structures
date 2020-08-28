#include <iostream>
#include <string>
#include "inputFunc.h"
#include "dfs.h"

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

    vector<int> data[temp];
    int visited[temp];
    for (int i = 0; i < temp; i++)
        visited[i] = 0;

    int flag = 0;
    int size = temp;
    int v = 0;
    int u = 0;
    getline(cin, str);

    while (true){
        cout << "Введите две вершины графа для создания ребра(для выхода введите -1):\n";

        temp = NUMBER_ERROR;

        while (temp == NUMBER_ERROR  || temp < 0 || temp > size) {
            cout << "1) ";
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
            cout << "2) ";
            getline(cin, str);
            temp = Checker(str);
            if (temp == NUMBER_ERROR || temp < 0 || temp > size)
                cout << "Некорректные данные\n";
        }
        u = temp - 1;

        data[v].push_back(u);
        data[u].push_back(v);

    }

    dfs(data, visited, size, 0);

    cout << "\nДоступные вершины из первой: ";
    for (int i = 0; i < size; i++)
        if (visited[i] != 0) cout << i + 1 << " ";

    return 0;

}
