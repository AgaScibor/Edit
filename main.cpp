#include "Edit.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

int main() {
    Edit e;
    e.setLength(25);
    e.setBackgroundColor(Edit::Black);
    std::string s = "Ala ma kota";
    std::cout << "Pole tekstowe nr. 1" << std::endl;
    std::cout << "Zawartość pola tekstowego: " << s << std::endl;
    _getch();


    // Lista kolorów
    Edit::Color colors[] = { Edit::Blue, Edit::Green, Edit::Red, Edit::Yellow, Edit::Magenta, Edit::Cyan, Edit::White };
    int numColors = sizeof(colors) / sizeof(colors[0]);

    // Wyświetlenie tekstu dla każdego koloru
    for (int i = 0; i < numColors; ++i) 
    {
        e.setTextColor(colors[i]);
        e.setPosition(7, 3 + i);
        e.setText(s);
        e.display();
    }
  
    // Oddzielająca linia
    std::cout <<std::endl;
    

    // Utworzenie i obsługa drugiego pola tekstowego
    std::cout << "Pole tekstowe nr. 2" << std::endl;
    Edit e2;
    e2.setLength(25);
    e2.setTextColor(Edit::Blue);
    e2.setBackgroundColor(Edit::White);
    _getch();

    for (int i = 0; i < numColors; ++i)
    {
        e2.setPosition(7, 12 + i); // Pozycja pola tekstowego nr. 2
        e2.setText(s);
        e2.display();
    }
    
    e2.userText(); // Obsługa tekstu wprowadzanego przez użytkownika (while {kbhit{getch}})
    system("cls");
    s = e2.getText();
    std::cout << "Zawartość pola tekstowego: " << s;
    _getch();

    return 0;
}
