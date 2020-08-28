#ifndef LAB_3_SORTALGS_H
#define LAB_3_SORTALGS_H

struct Returner{
    int *array;
    int countOfSwaps;
    int countOfComparisons;
};

Returner BubbleSort(int*, int);
Returner DISSort(int*, int);

#endif //LAB_3_SORTALGS_H
