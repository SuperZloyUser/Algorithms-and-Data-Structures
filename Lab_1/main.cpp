#include <iostream>
#include <string>
#include <stack>
#include <ctime>
#include "funcs.h"

using namespace std;

int main() {

    string str;
    string str_low;
    string str_ob;
    int flag = 0;
    int t = 0;
    char reg = 'x';

    cout <<"Введите строку: \n";
    getline(cin, str);
    cout << "Введите образ: \n";
    getline(cin, str_ob);
    cout << "Введите чусвствительность к регистру(+/-): \n";
    while (reg != '+' && reg != '-')
        reg = char(getchar());

    if (reg == '-') {

        for (long int i = 0; i < str.length(); i++)
            if (str[i] > 64 && str[i] < 91)
                str_low = str_low + char(str[i] + 32);
            else
                str_low = str_low + str[i];

        for (long int i = 0; i < str_ob.length(); i++)
            if (str_ob[i] > 64 && str_ob[i] < 91)
                str_ob[i] = char(str_ob[i] + 32);

    } else
        str_low = str;

    stack<int> output;
    t = time(nullptr);

    output = BouerMur(str_low, str_ob);

    int pos = 1;

    // cout << "Время работы алгоритма: " << time(0) - t << endl;

    if (output.empty()){
        cout << "Вхождений не найдено!";
        return 0;
    } else
        while(!output.empty()) {
            cout << pos << ") Позиция вхождения: " << output.top() << ";\n";
            pos++;
            output.pop();
        }


    return 0;
}
