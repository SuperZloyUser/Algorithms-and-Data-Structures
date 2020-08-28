#include "funcs.h"
#include <queue>
#include <map>
#include <string>

int MMemSearch(const int* array, int size, bool flag)
{

   int result = 0;

    if (flag == 0)
    {
        result = MINIMAL_BORDER;
        for (int i = 0; i < size; i++)
            if (result < array[i]) result = array[i];
    } else
    {
        result = MAXIMAL_BORDER;
        for (int i = 0; i < size; i++)
            if (result > array[i]) result = array[i];
    }

    return result;
}

std::queue<int> ModSearch(int* array, int size)
{

    std::map <int, int> temp;
    int maxCount = 0;
    std::queue<int> ret;

    for (int i = 0; i < size; i++)
    {
        temp[array[i]]++;
        if (maxCount < temp[array[i]]) maxCount = temp[array[i]];
    }

    for (auto & i : temp)
        if (i.second == maxCount) ret.push(i.first);

    return ret;
}

int Checker(std::string tempForCheck)
{
    int number = 0;
    int flag = 0;

    for (unsigned int i = 0; i < tempForCheck.length(); i++)
    {
        if (i == 0 && tempForCheck[0] == '-')
        {
            flag++;
            continue;
        }

        if (tempForCheck[i] == '0' || tempForCheck[i] == '1' || tempForCheck[i] == '2' || tempForCheck[i] == '3' ||
            tempForCheck[i] == '4' || tempForCheck[i] == '5' || tempForCheck[i] == '6' ||
            tempForCheck[i] == '7' || tempForCheck[i] == '8' || tempForCheck[i] == '9') number = number * ORDER +
                                                                                                 (tempForCheck[i] - ASCII_CONST);
        else
            return NUMBER_ERROR;
    }

    if (flag > 0) number *= NEGATIVE;

    return number;
}
