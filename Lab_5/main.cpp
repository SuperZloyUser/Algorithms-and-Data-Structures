#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include "MultywaySort.h"

using namespace std;

int main() {

    cout << "Введите имя сортируемого файла: \n";

    int asd = time(0);

    string str = "0";
    // getline(cin, str);

    ofstream outfile(str, ios::binary | ios::out);
    int temp = 0;
    srand(time(NULL));


    if (outfile)
    {
        for (int i = 0; i < COUNT_OF_NUMBERS; i++) {
            temp = rand() % MAX_RANGE;
            outfile.write((char *) &temp, sizeof(temp));
//            cout << temp << " ";
        }
    }

    outfile.close();

    MultywaySort(str);

    FILE* streamIn;
    FILE* streamOut;
    char str2[2];
    str2[1] = '\0';
    str2[0] = char(2 + '0');
    streamIn = fopen(str2, "rd");
    fseek(streamIn, 0, SEEK_END);
    int size = ftell(streamIn);
    fclose(streamIn);

    if (size == 0){
        streamIn = fopen("1", "rb");
        streamOut = fopen("Out", "wb");
        while (fread(&temp, 1, sizeof(int), streamIn)){
            fwrite(&temp, 1, sizeof(int), streamOut);
        }
        fclose(streamIn);
        fclose(streamOut);
    } else {
        str2[0] = char(COUNT_OF_CHANNELS + '0' + 1);
        streamIn = fopen(str2, "rb");
        streamOut = fopen("Out", "wb");
        while (fread(&temp, 1, sizeof(int), streamIn)){
            fwrite(&temp, 1, sizeof(int), streamOut);
        }
        fclose(streamIn);
        fclose(streamOut);
    }

    cout << (time(nullptr) - asd)/1000;

    return 0;
}
