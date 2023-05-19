#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
//#include "Drob.h"

using namespace std;
//public private protected



class Array {
    int* arr;
    int size;
    int n = 0;
public:

    Array() {
        size = 5;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 1 + rand() % 10;//0;
        }
        cout << "\nМассив готов.\n";
        Sleep(1000);
    }
    Array(int sizeA) {
        size = sizeA;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 1 + rand() % 10;//0;
        }
        cout << "\nМассив готов.\n";
        Sleep(1000);
    }
    void print() {
        cout << "Print:\n";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        Sleep(1000);
    }
    void randomize(int min, int max) {
        for (int i = 0; i < size; i++) {
            arr[i] = min + rand() % (max-min + 1);
        }
        cout << "\nРандомизация завершена.\n";
        Sleep(1000);
    }

    void setArr(int index, int x) {
        cout << "\nЗначение " << arr[index + 1] << " было заменено на " << x << endl;
        arr[index + 1] = x;
    }
    int getArr(int index) {
        return arr[index + 1];
    }

    ~Array() {
        delete[] arr;
        cout << "\nМассив " << n++ << " завершил работу.\n";
    }
};

void main() {

    setlocale(0, "");
    srand(time(NULL));
    
    //Можно инициализировать без "="

    /*int a{ 5 };
    int mas[5]{ 5,7,9,6,4 };
    for (int i{ 0 }; i < 10; i++) {

    }*/

    Array arr;
    arr.print();
    arr.randomize(1,20);
    arr.print();
    arr.setArr(2, 5);
    arr.print();
    cout <<  "\nGet:" << arr.getArr(3) << endl;

    Array arr2{ 20 };
    arr2.print();
    arr2.randomize(5, 40);
    arr2.print();

    cout << "\n\nRandom:\n";
    for (int i = 0; i < 100; i++) {
        cout << 1 + rand() % 60 << " ";
    }
    
}
