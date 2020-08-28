#ifndef LAB_6_DFS_H
#define LAB_6_DFS_H

#define MAX 999999999
#define MIN -9999999

#include <vector>

struct edge{
    int length;
    int u;
    int v;
    bool flag;
};
int dfs(std::vector<edge>, bool*, std::vector<int>*, int);

#endif //LAB_6_DFS_H
