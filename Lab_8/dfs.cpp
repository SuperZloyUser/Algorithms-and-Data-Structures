#include <iostream>
#include "dfs.h"

using namespace std;

int dfs(vector<edge> data, bool* visited, vector<int>* way, int size) {

    int min = MAX;
    int res = 0;
    int temp = 0;
    int sum = 0;

    for (int j = 0; j < size - 1; j++){

        min = MAX;
        res = 0;
        temp = -1;

        for (int i = 0; i < data.size(); i++){
            if (visited[data[i].u] == 0 && visited[data[i].v] != 0 && min > data[i].length && data[i].flag == 0) {
                min = data[i].length;
                temp = data[i].u;
                res = i;
            }

            if (visited[data[i].v] == 0 && visited[data[i].u] != 0 && min > data[i].length && data[i].flag == 0) {
                min = data[i].length;
                temp = data[i].v;
                res = i;
            }
        }

        data[res].flag = true;
        visited[temp] = true;
        way->push_back(temp);
        sum += data[res].length;

    }

    return sum;

}
