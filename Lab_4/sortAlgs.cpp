#include <algorithm>
#include <iostream>
//#include <ctime>
#include "sortAlgs.h"

Returner ShakerSort(int* tempArray, int size){

    int countOfSwaps = 0;
    int countOfComparisons = 0;
    int left = 0;
    int right = size - 1;
    int flag = 0;

    for (int i = 0; i < size; i++) {

        flag = 0;

        countOfComparisons++;
        if (i % 2 == 0){
            for (int j = right; j > left; j--) {
                if (tempArray[j] < tempArray[j - 1]) {
                    std::swap(tempArray[j], tempArray[j - 1]);
                    flag++;
                    countOfSwaps++;
                }
                countOfComparisons++;
            }
            left++;
            if (flag == 0) break;
        } else{
            for (int j = left; j < right; j++) {
                if (tempArray[j] > tempArray[j + 1]) {
                    std::swap(tempArray[j], tempArray[j + 1]);
                    flag++;
                    countOfSwaps++;
                }
                countOfComparisons++;
            }
            right--;
        }

        countOfComparisons++;
        if (flag == 0) break;
    }

    struct Returner ret{countOfComparisons, countOfSwaps};

    ret.countOfComparisons = countOfComparisons;
    ret.countOfSwaps = countOfSwaps;

    return ret;
}

Returner FastSort(int* tempArray, int left, int right){

    if (left < right) {

        struct Returner tempRet = partition(tempArray, left, right);
        std::cout << left << " " << right << ": ";
        for (int k = left; k <= right; k++){
            std::cout << tempArray[k] << " ";
        }
        std::cout << std::endl;
        int p = tempRet.pos;

        struct Returner ret = tempRet;

        tempRet = FastSort(tempArray, left, p);
        ret.countOfSwaps += tempRet.countOfSwaps;
        ret.countOfComparisons += tempRet.countOfComparisons;

        tempRet = FastSort(tempArray, p + 1, right);
        ret.countOfSwaps += tempRet.countOfSwaps;
        ret.countOfComparisons += tempRet.countOfComparisons;

        return ret;
    }

    struct Returner ret{0,0,0};
    return ret;

}

struct Returner partition(int* tempArray, int left, int right){

    int countOfSwaps = 0;
    int countOfComparisons = 0;

    srand(time(0));
    int temp = tempArray[(left + right) / 2];

    int i = left;
    int j = right;

    while (i <= j) {

        countOfComparisons++;
        while (tempArray[i] < temp) {
            i++;
            countOfComparisons++;
        }
        countOfComparisons++;
        while (tempArray[j] > temp) {
            j--;
            countOfComparisons++;
        }
        countOfComparisons++;
        if (i >= j) {
            break;
        }
        std::swap(tempArray[i++], tempArray[j--]);
        countOfSwaps++;
        countOfComparisons++;
    }

    struct Returner ret{countOfSwaps, countOfComparisons, j};

    return ret;

}
