#include "Edit.h"

Edit::Edit() : positionX(0), positionY(0), length(0), textColor(White), backgroundColor(Black) {}

Edit::Edit(const Edit& other) {
    positionX = other.positionX;
    positionY = other.positionY;
    length = other.length;
    text = other.text;
    textColor = other.textColor;
    backgroundColor = other.backgroundColor;
}

void Edit::setPosition(int x, int y) {
    positionX = x;
    positionY = y;
}

void Edit::setLength(int len) {
    length = len;
}

void Edit::setText(const std::string& txt) {
    text = txt;
}

void Edit::setTextColor(Color color) {
    textColor = color;
}

void Edit::setBackgroundColor(Color color) {
    backgroundColor = color;
}

std::string Edit::getText() const {
    return text;
}

void Edit::userText() {
    char ch;
    while ((ch = _getch()) != 13) { // Enter key
        if (ch == 8 && !text.empty()) { // Backspace key
            text.pop_back();
            display();
        }
        else if (ch >= 32 && ch <= 126 && text.length() < length - 1) { // Valid characters
            text.push_back(ch);
            display();
        }
    }
}

void Edit::display() {
    setCursorPosition(positionX, positionY);
    setConsoleColor(textColor, backgroundColor);
    std::cout << text;
}

void Edit::setCursorPosition(int x, int y) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPos;
    cursorPos.X = x;
    cursorPos.Y = y;
    SetConsoleCursorPosition(console, cursorPos);
}

void Edit::setConsoleColor(Color textColor, Color backgroundColor) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, (WORD)((backgroundColor << 4) | textColor));
}
