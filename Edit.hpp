#ifndef EDIT_HPP
#define EDIT_HPP

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

class Edit {
public:
    enum Color {
        Black,
        Blue,
        Green,
        Cyan,
        Red,
        Magenta,
        Yellow,
        White
    };

    Edit();

    Edit(const Edit& other);

    void setPosition(int x, int y);

    void setLength(int len);

    void setText(const std::string& txt);

    void setTextColor(Color color);

    void setBackgroundColor(Color color);

    std::string getText() const;

    void userText();

    void display();

private:
    int positionX;
    int positionY;
    int length;
    std::string text;
    Color textColor;
    Color backgroundColor;

    static void setCursorPosition(int x, int y);

    static void setConsoleColor(Color textColor, Color backgroundColor);
};

#endif // EDIT_HPP
