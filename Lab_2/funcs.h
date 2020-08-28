#ifndef LAB_2_FUNCS_H
#define LAB_2_FUNCS_H

#define MINIMAL_BORDER -9999999

#define NUMBER_ERROR -322

#define MAXIMAL_BORDER 9999999

#define ORDER 10

#define NEGATIVE -1

#define ASCII_CONST 48

#include <queue>
#include <string>

int MMemSearch(const int* array, int size, bool flag);
std::queue<int> ModSearch(int* array, int size);
int Checker(std::string tempForCheck);

#endif //LAB_2_FUNCS_H
