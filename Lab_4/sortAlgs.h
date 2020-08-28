#ifndef LAB_3_SORTALGS_H
#define LAB_3_SORTALGS_H

struct Returner{
    int countOfSwaps;
    int countOfComparisons;
    int pos;
};

Returner ShakerSort(int*, int);
Returner FastSort(int*, int, int);
struct Returner partition(int*, int, int);

#endif //LAB_3_SORTALGS_H
