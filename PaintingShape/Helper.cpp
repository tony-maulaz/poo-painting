#include "pch.h"
#include <windows.h>
#include "Helper.h"


using namespace std;

void printColor(const string& message, bool newLine, TextColor color);

void printGreen(const string& message, bool newLine) {
    printColor(message, newLine, TextColor::green);
}

void printRed(const string& message, bool newLine) {
    printColor(message, newLine, TextColor::red);
}

void printBlue(const string& message, bool newLine) {
    printColor(message, newLine, TextColor::blue);
}

void printTest() {
    for (int i = 0; i < 20; i++) {
        string mes = "Test color : " + to_string(i);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
        cout << mes << endl;
    }
}

void printColor(const string& message, bool newLine, TextColor color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout << message << static_cast<string>(newLine ? "\n" : "");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}