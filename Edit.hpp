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
    // Konstruktor domyślny
    Edit();
    // Konstruktor kopiujący
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
    int positionX;    // Pozycja X pola tekstowego
    int positionY;    // Pozycja Y pola tekstowego
    int length;        // Długość pola tekstowego
    std::string text;     // Tekst pola tekstowego
    Color textColor;    // Kolor tekstu
    Color backgroundColor;    // Kolor tła

    static void setCursorPosition(int x, int y);

    static void setConsoleColor(Color textColor, Color backgroundColor);
};

#endif // EDIT_HPP
