#include <iostream>
#include <vector>
#include <sstream>
#include "start.h"
#include "display.h"
#include <unistd.h>
using namespace std;

// Setting interface
void setting(int &DEFAULT_HEALTH, int &DEFAULT_ITEMS, int &MAX_LIVES, int &MAX_BLANKS)
{
    string *set_list = new string [4];
    set_list[0]="DEFAULT_HEALTH";
    set_list[1]="DEFAULT_ITEMS";
    set_list[2]="MAX_LIVES";
    set_list[3]="MAX_BLANKS";
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter value of " << set_list[i] << " (Current value: ";
        switch (i){ 
            case 0:       
                cout<<DEFAULT_HEALTH<<"): ";
                break;
            case 1:       
                cout<<DEFAULT_ITEMS<<"): ";
                break;
            case 2:       
                cout<<MAX_LIVES<<"): ";
                break;
            case 3:       
                cout<<MAX_BLANKS<<"): ";
                break;
            default:
                break;
        }
        int value;
        // Check whether input is valid
        while (true)
        {
            cin >> value;
            if (value <= 0)
            {
                cout << "Invalid input! Input again: ";
                continue;
            }
            break;
        }

        // Give value to the corresponding variables
        DEFAULT_HEALTH = (i == 0) ? value : DEFAULT_HEALTH;
        DEFAULT_ITEMS = (i == 1) ? value : DEFAULT_ITEMS;
        MAX_LIVES = (i == 2) ? value : MAX_LIVES;
        MAX_BLANKS = (i == 3) ? value : MAX_BLANKS;
    }
    // Debug output after assignment
    cout << "After assignment - DEFAULT_HEALTH: " << DEFAULT_HEALTH << ", DEFAULT_ITEMS: " << DEFAULT_ITEMS << ", MAX_LIVES: " << MAX_LIVES << ", MAX_BLANKS: " << MAX_BLANKS << endl;
    delete [] set_list;
    return;
}

// initial interface: the start of a game
int initial_interface(int &DEFAULT_HEALTH, int &DEFAULT_ITEMS, int &MAX_LIVES, int &MAX_BLANKS)
{
    welcome(); 
    while (true)
    {
        cout << "(a) New game      (b) Continue      (c) Settings      (d) Quit" << endl;
        cout << "Your choice: ";
        char input;
        while (cin >> input)
        {
            if (input != 'a' && input != 'b' && input != 'c' && input != 'd')
            {
                cout << "Invalid input! Try again: ";
                continue;
            }
            break;
        }
        switch (input)
        {
        case 'a':
            cout << "Are you sure to start a new game? (y/n): ";
            char input;
            while (cin >> input)
            {
                if (input != 'y' && input != 'n')
                {
                    cout << "Invalid input! Try again: ";
                    continue;
                }
                break;
            }
            if (input == 'y')
            {
                return 1;
            }
            break;

        case 'b':
            return 2;
            break;

        case 'c':
            setting(DEFAULT_HEALTH, DEFAULT_ITEMS, MAX_LIVES, MAX_BLANKS);
            cout << "Your changes have been saved successfully." << endl << endl;
            break;

        case 'd':
            sleep(1);
            return 4;
            break;

        default:
            break;
        }
    }
}

// new game interface: where players choose the modes
int newgame_interface()
{
    cout << "Modes: (a) PVE      (b) PVP" << endl;
    cout << "Your choice: ";
    char input;
    while (cin >> input)
    {
        switch (input)
        {
        case 'a':
            return 1;
            break;

        case 'b':
            return 2;
            break;

        default:
            cout << "Invalid input! Try again: ";
        }
    }
    return 0;
}
