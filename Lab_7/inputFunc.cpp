#include "inputFunc.h"


int Checker(string tempForCheck)
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
