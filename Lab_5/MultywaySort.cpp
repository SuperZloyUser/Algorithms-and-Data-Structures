#include "MultywaySort.h"

using namespace std;

void MultywaySort(const string& Name){

    int temp = 0;
    char str[2];
    str[1] = '\0';
    int last = MAX;
    int i;

    ifstream in(Name, ios::binary | ios::in);
    FILE *stream = nullptr;

    i = -1;

    for (int j = 0; j < COUNT_OF_CHANNELS; j++){
        str[0] = char(j % COUNT_OF_CHANNELS + 1 + '0');
        stream = fopen(str, "wb");
        fclose(stream);
    }

    while (in.read((char*) &temp, sizeof(temp))) {

        if (last > temp) {
            i++;
            str[0] = char(i % COUNT_OF_CHANNELS + 1 + '0');
            fclose(stream);
            stream = fopen(str, "ab+");
            fseek(stream, 0, SEEK_END);
        }

        last = temp;
        fwrite(&temp, 1, sizeof(int), stream);

    }

    fclose(stream);
    in.close();

    i = 0;
    int pool;
    int size;

    while(true){

        pool = 0;
        sortHelper(i % 2);
        i++;

        for (int j = 1; j < COUNT_OF_CHANNELS; j++){
            str[0] = char(j + 1 + '0' + COUNT_OF_CHANNELS * (i % 2));
            stream = fopen(str, "rb");
            fseek(stream, 0, SEEK_END);
            size = ftell(stream);
            if (size != 0) pool++;
            fclose(stream);
        }

//        stream = fopen("1", "rb");
//        cout << "\n1) ";
//        while (fread(&temp, 1, sizeof(int), stream)){
//            if (temp == 0) continue;
//            cout << temp << " ";
//        }
//        fclose(stream);
//
//        stream = fopen("2", "rb");
//        cout << "\n2) ";
//        while (fread(&temp, 1, sizeof(int), stream)){
//            cout << temp << " ";
//        }
//        fclose(stream);
//
//        stream = fopen("3", "rb");
//        cout << "\n3) ";
//        while (fread(&temp, 1, sizeof(int), stream)){
//            cout << temp << " ";
//        }
//        fclose(stream);
//
//        stream = fopen("4", "rb");
//        fseek(stream, 0, SEEK_SET);
//        cout << "\n\n4) ";
//        while (fread(&temp, 1, sizeof(int), stream)){
//            if (temp == 0) continue;
//            cout << temp << " ";
//        }
//        fclose(stream);
//
//        stream = fopen("5", "rb");
//        fseek(stream, 0, SEEK_SET);
//        cout << "\n5) ";
//        while (fread(&temp, 1, sizeof(int), stream)){
//            cout << temp << " ";
//        }
//        fclose(stream);
//
//        stream = fopen("6", "rb");
//        fseek(stream, 0, SEEK_SET);
//        cout << "\n6) ";
//        while (fread(&temp, 1, sizeof(int), stream)){
//            cout << temp << " ";
//        }
//        fclose(stream);
//        cout << endl;
//
//        for (int j = 0; j < 30; j++)
//            cout << "-----";

        if (pool == 0) return;

    }

}

void sortHelper(bool flag){

    if (!flag){

        char str[2];
        str[1] = '\0';

        FILE *stream;

        int i = 0;

        int temp[COUNT_OF_CHANNELS];
        int indents[COUNT_OF_CHANNELS];
        for (int & indent : indents)
            indent = 0;

        int last = MAX;
        int pool = 0;

        for (int j = 0; j < COUNT_OF_CHANNELS; j++){
            str[0] = char(j + 1 + '0' + COUNT_OF_CHANNELS);
            stream = fopen(str, "wb");
            fclose(stream);
        }

        for (int j = 0; j < COUNT_OF_CHANNELS; j++){
            str[0] = char(j + 1 + '0');
            stream = fopen(str, "rb");
            fseek(stream, 4 * indents[j], SEEK_SET);
            if (fread(&temp[j], 1, sizeof(int), stream)) pool++;
            fclose(stream);
        }

        if (pool == 0) return;

        int min;
        int second_min;
        int pos = 0;
        int size;

        while (true) {

            pool = 0;
            min = MAX;

            for (int j = 0; j < COUNT_OF_CHANNELS; j++)
            {
                if (min > temp[j]) {
                    min = temp[j];
                    pos = j;
                }

            }

            if (min < last){
                second_min = MAX;
                for (int j = 0; j < COUNT_OF_CHANNELS; j++){
                    if (temp[j] > last && second_min > temp[j]) {
                        second_min = temp[j];
                        pos = j;
                    }
                }
            }


            if (last > temp[pos] && last != MAX) {
                i++;
            }


            str[0] = char(i % COUNT_OF_CHANNELS + 1 + '0' + COUNT_OF_CHANNELS);
            stream = fopen(str, "ab+");
            fseek(stream, 0, SEEK_END);
            last = temp[pos];
            fwrite(&last, 1, sizeof(int), stream);
            fclose(stream);

            str[0] = char(pos + 1 + '0');
            stream = fopen(str, "rb");
            indents[pos]++;
            fseek(stream, 4 * indents[pos], SEEK_SET);
            fread(&temp[pos], 1, sizeof(int), stream);
            fseek(stream, 0, SEEK_END);
            size = ftell(stream);

            if (size / 4 <= indents[pos]) {
                temp[pos] = MAX;
                last = temp[pos];
            }
            fclose(stream);

            for (int j = 0; j < COUNT_OF_CHANNELS; j++){
                if (temp[j] != MAX) pool++;
            }

            if (pool == 0) break;

        }


    } else {

        char str[2];
        str[1] = '\0';

        FILE *stream;
        //FILE *streamOut = nullptr;

        int i = 0;

        int temp[COUNT_OF_CHANNELS];
        int indents[COUNT_OF_CHANNELS];
        for (int & indent : indents)
            indent = 0;

        int last = MAX;
        int pool = 0;

        for (int j = 0; j < COUNT_OF_CHANNELS; j++){
            str[0] = char(j + 1 + '0');
            stream = fopen(str, "wb");
            fclose(stream);
        }

        for (int j = 0; j < COUNT_OF_CHANNELS; j++){
            str[0] = char(j + 1 + '0' + COUNT_OF_CHANNELS);
            stream = fopen(str, "rb");
            fseek(stream, 4 * indents[j], SEEK_SET);
            if (fread(&temp[j], 1, sizeof(int), stream)) pool++;
            fclose(stream);
        }

        if (pool == 0) return;

        int min;
        int pos = 0;
        int size;
        int second_min;

        while (true) {

            pool = 0;
            min = MAX;

            for (int j = 0; j < COUNT_OF_CHANNELS; j++)
            {
                if (min > temp[j]) {
                    min = temp[j];
                    pos = j;
                }
            }

            if (min < last){
                second_min = MAX;
                for (int j = 0; j < COUNT_OF_CHANNELS; j++){
                    if (temp[j] > last && second_min > temp[j]) {
                        second_min = temp[j];
                        pos = j;
                    }
                }
            }

            if (last > temp[pos] && last != MAX) {
                i++;
            }

            str[0] = char(i % COUNT_OF_CHANNELS + 1 + '0');
            stream = fopen(str, "ab+");
            fseek(stream, 0, SEEK_END);
            last = temp[pos];
            fwrite(&last, 1, sizeof(int), stream);
            fclose(stream);

            str[0] = char(pos + 1 + '0' + COUNT_OF_CHANNELS);
            stream = fopen(str, "rb");
            indents[pos]++;
            fseek(stream, 4 * indents[pos], SEEK_SET);
            fread(&temp[pos], 1, sizeof(int), stream);
            fseek(stream, 0, SEEK_END);
            size = ftell(stream);

            if (size / 4 <= indents[pos]) {
                temp[pos] = MAX;
                last = temp[pos];
            }
            fclose(stream);

            for (int j = 0; j < COUNT_OF_CHANNELS; j++){
                if (temp[j] != MAX) pool++;
            }

            if (pool == 0) break;

        }

    }


}
