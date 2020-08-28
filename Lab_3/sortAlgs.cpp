#include <algorithm>
#include "sortAlgs.h"

Returner BubbleSort(int* tempArray, int size){

    int countOfSwaps = 0;
    int countOfComparisons = 0;
    int flag = 0;

    for (int i = 0; i < size; i++) {

        flag = 0;

        for (int j = size - 1; j > 0; j--) {
            if (tempArray[j] < tempArray[j - 1]) {
                std::swap(tempArray[j], tempArray[j - 1]);
                flag++;
                countOfSwaps++;
            }
            countOfComparisons++;
        }

    }

    struct Returner ret{tempArray, countOfComparisons, countOfSwaps};

    ret.array = tempArray;
    ret.countOfComparisons = countOfComparisons;
    ret.countOfSwaps = countOfSwaps;

    return ret;
}

Returner DISSort(int* tempArray, int size){

    int temp = 0;
    int countOfSwaps = 0;
    int countOfComparisons = 0;

    for (int i = 1; i <= size; i++){

        temp = tempArray[i];

        for (int j = 0; j < i; j++){
            if (temp < tempArray[j]) {
                for (int k = i; k > j; k--) {
                    std::swap(tempArray[k], tempArray[k - 1]);
                    countOfSwaps++;
                }

                countOfComparisons++;
                tempArray[j] = temp;

                break;
            }
        }
    }



    struct Returner ret{tempArray, countOfComparisons, countOfSwaps};

    return ret;

}
