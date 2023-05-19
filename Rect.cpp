#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
//#include "Drob.h"

using namespace std;
//public private protected
class Point {
    int x, y;
public:
    //Point() = default;
    Point()
    {
        x = 0;
        y = 0;
        //cout << "Отработал конструктор по умолчанию\n";
    }
    Point(int u)
    {
        x = u;
        y = u;
        //cout << "Отработал конструктор c 1 параметром\n";
    }
    Point(int ux, int uy)
    {
        x = ux;
        y = uy;
        //cout << "Отработал конструктор c 2 параметрами\n";
    }
    //Point() : Point{0,0};
    void setX(int ux)
    {
        x = ux;
    }
    void setY(int uy)
    {
        y = uy;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void print()
    {
        cout << "(" << x << ";" << y << ")";
    }
    ~Point()
    {
        //cout << "Отработал деструктор\n";
    }
};

class Rect {
    int height; // Высота
    int wight;  // Ширина
    Point leftDown;
    
public:
    Rect() :height{ 5 }, wight{ 10 }, leftDown{ 0,0 } {}; //{ // 5:10 (0.0);
        /*height = 5;
        wight = 10;
        leftDown.setX(0);
        leftDown.setY(0);
    }*/

    Rect(int h, int w, Point p) {
        height = h;
        wight = w;
        leftDown.setX(p.getX());
        leftDown.setY(p.getY());
    }

    Rect(Point p1, Point p2) {
        if (p1.getX() > p2.getX()) {
            leftDown.setX(p2.getX());    //(p1.getX() - p2.getX());
            wight = p1.getX() - p2.getX();
        }
        else {
            leftDown.setX(p1.getX());    //(p2.getX() - p1.getX());
            wight = p2.getX() - p1.getX();
        }

        if (p1.getY() > p2.getY()) {
            leftDown.setY(p1.getY());    //(p1.getY() - p2.getY());
            height = p1.getY() - p2.getY();
        }
        else {
            leftDown.setY(p2.getY());    //p2.getY() - p1.getY());
            height = p2.getY() - p1.getY();
        }

    }

    void print() {
        cout << "Height: " << height << "\nwight: " << wight << "\nX: " << leftDown.getX() << "\nY: " << leftDown.getY() << "\n";
    }
};

class Array {
    int* arr;
    int size;
    int n = 0;
public:

    //Array() {
    //    size = 5;
    //    arr = new int[size];
    //    for (int i = 0; i < size; i++) {
    //        arr[i] = 1 + rand() % 10;//0;
    //    }
    //    cout << "\nМассив готов.\n";
    //    Sleep(1000);
    //}
    Array(int sizeA = 5) : arr{ arr = new int[size]}, size{ sizeA } {

        randomize(10, 20);
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
    
    /*Array arr;
    arr.print();
    arr.randomize(1,20);
    arr.print();
    arr.setArr(2, 5);
    arr.print();
    cout <<  "\nGet:" << arr.getArr(3) << endl;

    Array arr2{ 20 };
    arr2.print();
    arr2.randomize(5, 40);
    arr2.print();*/

    //Point p;
    //Point p2(10);
    //Point p3(10, 20);

    cout << "First:\n";
    Rect exc;
    exc.print();

    cout << "\nSecond:\n";
    Point emb{ 1,5 };
    Rect Rhino{ 20, 30, emb };
    Rhino.print();

    cout << "\nThird:\n";
    Point one{ 30,10 };
    Point two{ 60,20 };
    Rect Meg{ one,two };
    Meg.print();

    
}
