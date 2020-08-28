#include <string>
#include <stack>

std::stack<int> BouerMur(std::string str, std::string obr){

    std::stack<int> ret;
    long int flag;
    long int pos;

    unsigned int array_d[256];
    for (auto & i : array_d)
        i = obr.length();

    // Составление массива d для образа
    for (long int i = obr.length() - 1; i >= 0; i--)
        if (array_d[obr[i]] == obr.length())
            array_d[obr[i]] = obr.length() - i - 1;

    for (int i = 0; i <= str.length() - obr.length();)
    {
        flag = -1;
        pos = 0;

        for (long int j = obr.length() - 1; j >= 0; j--){
            if (str[i + j] != obr[j]){
                flag = 1;
                pos = i + j;
                break;
            }
        }

        if(flag == -1)
        {
            ret.push(i + 1);
            i = i + obr.length();
        }
        else
            i = i + array_d[str[pos]];

    }

    return ret;
}
