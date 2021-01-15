//солённый язык, исходная строка читается из файла "StringIn.txt"
//на вход принимаются только буквы латинского алфавита
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    //Шифрование
    cout << "    Encryption    " << endl;
    const int n(40);         //максимальное количесвто символов во входной строке
    char Vowel_Letters[12] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'u', 'i', 'o','y'}; //массив "гласных" букв английского алфавита
    char StringOut[3 * n];   //выходная строка

    ifstream StringIn("C:\\1\\StringIn.txt"); //открываем файл StringIn с исходной строкой
                                              // проверяем, открылся ли файл
    if (!StringIn)
    {
        cout << "Error! The File can't be read";
        return -1;
    }
    else
    {
        int i;
        cout << "Input String: ";
        char *Line = new char[n];     //выделяем память для n символов строки входного файла
        StringIn.getline(Line, n + 1);  //считывание строки из входного файла в массив символов Line
        cout << Line << endl;
        for (i = 0; Line[i] != '\0'; i++);    //определяет сколько символов в массиве.
        //--------------------------//
        int j(0);     //счётчик прохода по входной строке
        int t(0);     //положение символа входной строки в выходной
        while (j <= i) {
            int k(0); //счётчик прохода по массиву гласных букв
            bool flag(false);
            while ((k <= 11) && !flag)
            {
                if (Line[j] == Vowel_Letters[k])
                {
                    if ((0 <= k) && (k <= 5)) //если гласная буква в строке - заглавная, то зашифрованная строка будет иметь вид ...Asa...
                        k = k + 6;
                    StringOut[t] = Line[j];
                    StringOut[t + 1] = 's';
                    StringOut[t + 2] = Vowel_Letters[k];
                    t = t + 3;
                    flag = true;
                }
                k++;
            }
            if (!flag)
            {
                StringOut[t] = Line[j];
                t = t + 1;
            }
            j++;
        }
        cout << "Output String: " << StringOut << endl;
        ofstream Out("C:\\1\\StringOut.txt");
        if (!Out)
        {
            cout << "Error! The File can't be open";
            return -1;
        }
        else
        {
            Out << StringOut << endl;
        }
    }

    //Дешифрование
    cout << "    Decryption    " << endl;
    const int m(3*n);         //максимальное количесвто символов во входной строке
    char StringOut_1[n];      //выходная строка
    int i;

    ifstream Out("C:\\1\\StringOut.txt");
    if (!Out)
    {
        cout << "Error! The File can't be open";
        return -1;
    }
    else
    {
        cout << "Input String: ";
        char *Line = new char[m];         //выделяем память для m символов строки входного файла
        Out.getline(Line, m+1);    //считывание строки из входного файла в массив символов Line
        cout << Line << endl;
        for (i = 0; Line[i] != '\0'; i++);//определяет сколько символов в массиве.
        //--------------------------//
        int j(0);//счётчик прохода по входной строке
        int t(0);//положение символа входной строки в выходной
        while (j <= i) {
            int k(0); //счётчик прохода по массиву гласных букв
            bool flag(false);
            while ((k <= 11) && !flag) {
                if (Line[j] == Vowel_Letters[k]) {
                    StringOut_1[t] = Line[j];
                    t = t + 1;
                    flag = true;
                }
                k++;
            }
            if (!flag) {
                StringOut_1[t] = Line[j];
                t = t + 1;
                j++;
            } else j = j + 3;
        }
        cout << "Output String: " << StringOut_1 << endl;
    }

}