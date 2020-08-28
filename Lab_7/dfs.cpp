#include <iostream>
#include "dfs.h"

using namespace std;

void dfs(vector<pair<int, int>>* data, int* wayLength, int size, int peak) {

    cout << "Просматриваем вершину " << peak + 1 << endl;

    for (int i = 0; i < data[peak].size(); i++)
        if (wayLength[data[peak][i].first] > wayLength[peak] + data[peak][i].second) {
            wayLength[data[peak][i].first] = wayLength[peak] + data[peak][i].second;
            dfs(data, wayLength, size, data[peak][i].first);
        }


    cout << "Возвращаемся на уровень выше\n";

}
