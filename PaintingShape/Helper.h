#pragma once

#include <iostream>
#include <string>

using namespace std;

class Error : public exception
{
public:
    Error(string const& phrase = "") throw() : phrase(phrase) {}

    virtual const char* what() const throw()
    {
        return phrase.c_str();
    }

    virtual ~Error() throw() {}

private:
    string phrase;
};

enum TextColor { red = 12, green = 10, blue = 9 };

void printColor(const string& message, bool newLine, TextColor color);
void printGreen(const string& message, bool newLine = false);
void printRed(const string& message, bool newLine = false);
void printBlue(const string& message, bool newLine = false);
void printTest();