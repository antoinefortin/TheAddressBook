#include "Menu.h"

int main()
{
    /*
        I designed a simple menu, but in a perfect world I would encapsulate both the menu and Adressbook into 
        a App.h and App.cpp class.  
    */
    AddressBook address_book;
    Menu menu(address_book);
    menu.Run();

    return 1;
}
