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

    vector<edge> data;
    vector<int> way;
    bool visited[temp];
    for (int i = 0; i < temp; i++)
        visited[i] = false;

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

        data.push_back(edge{temp, v, u, false});

    }

    visited[0] = true;
    way.push_back(0);
    cout << "Вес остова - " << dfs(data, visited, &way, size) << "Вершины, входящие в остов: ";

    for (int i : way)
        cout << i + 1 << " ";

    return 0;

}
