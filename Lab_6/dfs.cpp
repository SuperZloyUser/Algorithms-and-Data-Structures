#include <iostream>
#include "dfs.h"

using namespace std;

void dfs(vector<int>* data, int* visited, int size, int peak) {

    visited[peak] = 1;

    cout << "Просматриваем вершину " << peak << endl;

    for (int i = 0; i < data[peak].size(); i++)
        if (visited[data[peak][i]] == 0) dfs(data, visited, size, data[peak][i]);

    cout << "Возвращаемся на уровень выше\n";

}
