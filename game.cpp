#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include "game.h"
#include "display.h"
#include "start.h"
#include "save.h"

using namespace std;

bool endflag = false;
int DEFAULT_HEALTH = 4, DEFAULT_ITEMS = 2, MAX_LIVES = 5, MAX_BLANKS = 5;
string sg_filename = "Shotgun_save_data.dat";
string player1_filename = "Player1_save_data.dat";
string player2_filename = "Player2_save_data.dat";
bool stopflag = false;

//save data of the gun and bullets
class Shotgun
{
public:
    int damage = 1;
    int live = 0;
    int blank = 0;
    vector<bool> shells = {};

    void doubleDamage()
    {
        damage = 2;
        return;
    }

    void resetDamage()
    {
        damage = 1;
        return;
    }

    void addShells()
    {
        live = rand() % MAX_LIVES + 1;
        blank = rand() % MAX_BLANKS + 1;

        sleep(1);
        displayBullet(live, blank);
        cout << "LIVE: " << live << "    BLANK: " << blank << endl;
        sleep(1);
        cout << "Bullets are randomly inserted into the gun." << endl;
        cout << endl;

        for (int i = 0; i < live; i++)
        {
            shells.push_back(true);
        }
        for (int i = 0; i < blank; i++)
        {
            shells.push_back(false);
        }
        random_device rd;
        mt19937 g(rd());
        shuffle(shells.begin(), shells.end(), g);
        return;
    }

    bool pickRound()
    {
        bool r = shells[shells.size() - 1];
        shells.pop_back();
        return r;
    }

    // save file
    void saveToFile()
    {
        ofstream file(sg_filename, ios::out | ios::binary);
        if (file.is_open())
        {
            file << damage << endl;
            file << live << endl;
            file << blank << endl;
            file << shells.size() << endl;
            for (bool round : shells)
            {
                file << round << " ";
            }
            file.close();
        }
        else
        {
            cout << "Error opening file for writing." << endl;
        }
    }

    // load file
    void loadFromFile()
    {
        ifstream file(sg_filename, ios::in | ios::binary);
        if (file.is_open())
        {
            file >> damage;
            file >> live;
            file >> blank;
            size_t size;
            file >> size;
            shells.clear();
            for (size_t i = 0; i < size; i++)
            {
                bool round;
                file >> round;
                shells.push_back(round);
            }
            file.close();
            cout << "Shotgun data loaded from file: " << sg_filename << endl;
        }
        else
        {
            cout << "Error opening file for reading." << endl;
        }
    }
};

// save data of the player
class Player
{
public:
    string name;
    int health;
    vector<string> items;
    int Waiting;
    bool ifComputer;
    Player(string playerName, int DEFAULT_HEALTH, bool ifC) : name(playerName), health(DEFAULT_HEALTH), Waiting(0), ifComputer(ifC) {}

    void displayHealth()
    {
        cout << name << "'s health: " << health << "/" << DEFAULT_HEALTH << endl;
        return;
    }

    void addHealth()
    {
        if (health < DEFAULT_HEALTH)
            health += 1;
        return;
    }

    void resetWaiting()
    {
        Waiting = 0;
        return;
    }

    void takeDamage(int dmg)
    {
        health -= dmg;
        if (health < 0)
            health = 0;
        return;
    }

    void displayItems()
    {
        cout << name << "'s inventory: ";
        for (int i = 0; i < items.size(); ++i)
            cout << items[i] << " ";
        cout << endl;
        return;
    }

    void addRandomItems()
    {
        cout << name << "'s new items: ";
        int n = DEFAULT_ITEMS;
        vector<string> item_type;
        item_type.push_back("BEER");
        item_type.push_back("CIGARETTE");
        item_type.push_back("HANDCUFFS");
        item_type.push_back("MAGNIFIER");
        item_type.push_back("SAW");
        for (int i = 0; i < n; i++)
        {
            int num = rand() % 5;
            cout << item_type[num] << " ";
            items.push_back(item_type[num]);
        }
        cout << endl;
        return;
    }

    int findItem(string item)
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (item == items[i])
                return i + 1;
        }
        return 0;
    }

    void saveToFile(const string player_filename)
    {
        ofstream file(player_filename, ios::out | ios::binary);
        if (file.is_open())
        {
            file << name << endl;
            file << health << endl;
            file << items.size() << endl;
            for (const string &item : items)
            {
                file << item.size() << " " << item << endl;
            }
            file << Waiting << endl;
            file << ifComputer << endl;
            file.close();
            cout << "Player data saved to file: " << player_filename << endl;
        }
        else
        {
            cout << "Error opening file for writing." << endl;
        }
    }

    void loadFromFile(const string player_filename)
    {
        ifstream file(player_filename, ios::in | ios::binary);
        if (file.is_open())
        {
            getline(file, name);
            file >> health;
            items.clear();
            size_t itemsSize;
            file >> itemsSize;
            file.ignore(); // Ignore the newline character
            for (size_t i = 0; i < itemsSize; i++)
            {
                size_t itemSize;
                file >> itemSize;
                file.ignore(); // Ignore the space character
                char *buffer = new char[itemSize + 1];
                file.read(buffer, itemSize);
                buffer[itemSize] = '\0';
                items.push_back(buffer);
                delete[] buffer;
            }
            file >> Waiting;
            file >> ifComputer;
            file.close();
            cout << "Player data loaded from file: " << player_filename << endl;
        }
        else
        {
            cout << "Error opening file for reading." << endl;
        }
    }
};

// when player shoot oneself or other
bool shoot(Shotgun &sg, Player &p)
{
    sleep(2);

    bool r = sg.pickRound();
    if (r)
    {
        cout << "..." << endl;
        sleep(1);
        art_showmaker("BANG");
        sleep(1);
        cout << "..." << endl;
        p.takeDamage(sg.damage);
        p.displayHealth();
        sg.live -= 1;
        cout << endl;
        sg.resetDamage();
        return true;
    }
    else
    {
        cout << "..." << endl;
        sleep(1);
        cout << "*CLICK*" << endl;
        sleep(1);
        cout << "..." << endl;
        cout << "Nothing happened." << endl;
        sg.blank -= 1;
        cout << endl;
        sg.resetDamage();
        return false;
    }
    sleep(1);
}

// when player use item
bool useItem(string item, Shotgun &sg, Player &p1, Player &p2)
{
    sleep(1);

    int item_num = p1.findItem(item);
    if (!item_num)
        return false;

    if (p1.ifComputer == true)
    {
        p1.displayHealth();
        p1.displayItems();
        sleep(1);
        cout << p1.name << " is thinking..." << endl;
        sleep(rand() % 4 + 1);
    }

    p1.items.erase(p1.items.begin() + item_num - 1);
    cout << p1.name << " uses " << item << "." << endl;

    if (item == "BEER")
    {
        bool r = sg.pickRound();
        cout << "A shell is removed from the gun." << endl;
        sleep(1);
        cout << "The shell was..." << endl;
        sleep(2);
        cout << ((r) ? "LIVE." : "BLANK.") << endl;
    }
    else if (item == "CIGARETTE")
    {
        p1.addHealth();
    }
    else if (item == "HANDCUFFS")
    {
        p2.Waiting += 1;
        cout << p2.name << " will now miss a turn." << endl;
    }
    else if (item == "MAGNIFIER")
    {
        cout << "The next shell is..." << endl;
        sleep(2);
        cout << ((sg.shells.back()) ? "LIVE." : "BLANK.") << endl;
    }
    else if (item == "SAW")
    {
        sg.doubleDamage();
        cout << "Shotgun now does 2 demage." << endl;
    }
    cout << endl;
    sleep(1);
    return true;
}

// player moves
void playerTurn(Player &p1, Player &p2, Shotgun &sg, const int &round, const bool &turn, bool &check_leave)
{
    sleep(2);
    cout << "##### " << p1.name << "'S TURN #####" << endl;

    while (sg.shells.size())
    {
        string opt1, opt2;

        // Player's turn: choose using item or shoot
        if (true)
        {
            p1.displayHealth();
            p1.displayItems();
            cout << "(a) Use item      (b) Shoot      (c) Save and leave      (d) Help" << endl;
            cout << "Your choice: ";
            cin >> opt1;
            while (opt1 != "a" && opt1 != "b" && opt1 != "c" && opt1 != "d" && (opt1 == "b" && !p1.items.size()))
            {
                if (!p1.items.size() && opt1 == "b")
                {
                    cout << "Your inventory is empty! Try again: ";
                }
                else
                {
                    cout << "Invalid input! Try again: ";
                }
                cin >> opt1;
            }
        }

        // Player chooses to quit game
        if (opt1 == "c")
        {
            save(true, round, turn, DEFAULT_HEALTH, DEFAULT_ITEMS, MAX_LIVES, MAX_BLANKS);
            sg.saveToFile();
            p1.saveToFile(player1_filename);
            p2.saveToFile(player2_filename);
            check_leave = true;
            return;
        }

        if (opt1 == "d")
        {
            sleep(1);
            displayHelp();
        }

        // Player chooses to use items.
        if (opt1 == "a")
        {
            cout << "(a) BEER" << endl;
            cout << "(b) CIGARETTE" << endl;
            cout << "(c) HANDCUFFS" << endl;
            cout << "(d) MAGNIFIER" << endl;
            cout << "(e) SAW" << endl;
            cout << "Your choice: ";
            cin >> opt2;
            while (opt2 != "a" && opt2 != "b" && opt2 != "c" && opt2 != "d" && opt2 != "e")
            {
                cout << "Invalid input! Try again: ";
                cin >> opt2;
            }
            if (opt2 == "a")
            {
                if (!useItem("BEER", sg, p1, p2))
                    cout << "No BEER in your inventory! Try again: " << endl;
            }
            else if (opt2 == "b")
            {
                if (!useItem("CIGARETTE", sg, p1, p2))
                    cout << "No CIGARETTE in your inventory! Try again: " << endl;
            }
            else if (opt2 == "c")
            {
                if (!useItem("HANDCUFFS", sg, p1, p2))
                    cout << "No HANDCUFFS in your inventory! Try again: " << endl;
            }
            else if (opt2 == "d")
            {
                if (!useItem("MAGNIFIER", sg, p1, p2))
                    cout << "No MAGNIFIER in your inventory! Try again: " << endl;
            }
            else if (opt2 == "e")
            {
                if (!useItem("SAW", sg, p1, p2))
                    cout << "No SAW in your inventory! Try again: " << endl;
            }
        }

        // Player chooses to shoot
        else if (opt1 == "b")
        {
            cout << "(a) " << p2.name << endl;
            cout << "(b) " << p1.name << endl;
            cout << "Your choice: ";
            cin >> opt2;
            while (opt2 != "a" && opt2 != "b")
            {
                cout << "Invalid input! Try again: " << endl;
                cin >> opt2;
            }

            if (opt2 == "a")
            {
                shoot(sg, p2);
                return;
            }
            else if (opt2 == "b")
            {
                if (shoot(sg, p1))
                    return;
            }
        }
    }
}

// computer moves
void computerTurn(Player &p1, Player &p2, Shotgun &sg)
{
    sleep(2);
    cout << "##### " << p1.name << "'S TURN #####" << endl;

    while (sg.shells.size())
    {
        if (find(sg.shells.begin(), sg.shells.end(), false) == sg.shells.end())
        {
            useItem("SAW", sg, p1, p2);
            sleep(1);
            cout << p1.name << " shoots at " << p2.name << "." << endl;
            shoot(sg, p2);
            return;
        }

        if (find(sg.shells.begin(), sg.shells.end(), true) == sg.shells.end())
        {
            sleep(1);
            cout << p1.name << " shoots at himself." << endl;
            shoot(sg, p1);
            continue;
        }

        if (p1.health < DEFAULT_HEALTH)
            if (useItem("CIGARETTE", sg, p1, p2))
                continue;

        int roundsLeft = sg.shells.size();
        if (0 < roundsLeft < 5)
        {
            double dou = count(sg.shells.begin(), sg.shells.end(), true) / roundsLeft;
            if (dou >= 0.5)
            {
                if (useItem("HANDCUFF", sg, p1, p2))
                    continue;

                if (!(p2.Waiting) && useItem("MAGNIFIER", sg, p1, p2))
                    continue;

                if ((sg.shells[rand() % (sg.shells.size())]) && useItem("SAW", sg, p1, p2))
                    continue;

                sleep(1);
                cout << p1.name << " shoots at " << p2.name << "." << endl;
                shoot(sg, p2);
                return;
            }
        }

        if (rand() % 2)
        {
            string temp = p1.items[rand() % (p1.items.size())];
            if (temp != "CIGARETTE")
                useItem(temp, sg, p1, p2);
            continue;
        }

        bool test = sg.shells[rand() % (sg.shells.size())];
        if (test)
        {
            sleep(1);
            cout << p1.name << " shoots at " << p2.name << "." << endl;
            shoot(sg, p2);
            return;
        }
        else
        {
            sleep(1);
            cout << p1.name << " shoots at himself." << endl;
            if (shoot(sg, p1))
                return;
        }
    }
    return;
}

// play 1 game time
void game(Player p1, Player p2)
{
    int round = 1, temp_a;
    bool turn = 0, temp_b;
    load(stopflag, temp_a, temp_b, DEFAULT_HEALTH, DEFAULT_ITEMS, MAX_LIVES, MAX_BLANKS);
    while (p1.health && p2.health)
    {
        sleep(2);

        Shotgun sg;
        if (stopflag)
        {
            sg.loadFromFile();
            stopflag = !stopflag;
            round = temp_a;
            turn = 0;
            art_showmaker("ROUND " + to_string(round));
            cout << endl;
            displayBullet(sg.live, sg.blank);
            cout << "LIVE: " << sg.live << "    BLANK: " << sg.blank << endl;
            sleep(1);
            cout << "Bullets are randomly inserted into the gun." << endl;
            cout << endl;
        }
        else
        {
            art_showmaker("ROUND " + to_string(round));
            cout << endl;
            sg.addShells();
            sleep(1);
            p1.addRandomItems();
            p2.addRandomItems();
            cout << endl;
            round += 1;
        }

        while (sg.shells.size() && p1.health && p2.health)
        {
            turn = !turn;
            if ((turn && (!p1.Waiting)) || (p2.Waiting))
            {
                cout << endl
                     << "check point!" << endl;
                if (p2.Waiting && !turn)
                {
                    cout << "\033[31m";
                    sleep(2);
                    cout << "##### " << p2.name << "'S TURN #####" << endl;
                    sleep(1);
                    cout << p2.name << " is cuffed." << endl;
                    cout << endl;
                    turn = !turn;
                    p2.Waiting -= 1;
                    cout << "\33[0m";
                }
                if (p1.ifComputer)
                {
                    cout << "\033[32m";
                    computerTurn(p1, p2, sg);
                    cout << "\033[0m";
                }
                else
                {
                    cout << "\033[32m";
                    bool check_flag = false;
                    playerTurn(p1, p2, sg, round, turn, check_flag);
                    if (check_flag)
                    {
                        endflag = true;
                        return;
                    }
                    cout << "\033[0m";
                }
            }
            else
            {
                cout << endl
                     << "check point!" << endl;
                if (p1.Waiting && turn)
                {
                    cout << "\033[32m";
                    sleep(2);
                    cout << "##### " << p1.name << "'S TURN #####" << endl;
                    sleep(1);
                    cout << p1.name << " is cuffed." << endl;
                    cout << endl;
                    turn = !turn;
                    p1.Waiting -= 1;
                    cout << "\033[0m";
                }
                if (p2.ifComputer)
                {
                    cout << "\033[31m";
                    computerTurn(p2, p1, sg);
                    cout << "\033[0m";
                }
                else
                {
                    cout << "\033[31m";
                    bool check_flag = false;
                    playerTurn(p2, p1, sg, round, turn, check_flag);
                    if (check_flag)
                    {
                        endflag = true;
                        return;
                    }
                    cout << "\033[0m";
                }
            }
        }

        p1.resetWaiting();
        p2.resetWaiting();
    }

    if (p1.health <= 0)
    {
        sleep(4);
        art_showmaker(p2.name + " WIN");
        sleep(1);
        for (int i = 0; i < 20; i++)
        {
            cout << endl;
        }
    }
    else
    {
        sleep(1);
        art_showmaker(p1.name + " WIN");
        sleep(1);
        for (int i = 0; i < 20; i++)
        {
            cout << endl;
        }
    }

    save(false, 0, 0, DEFAULT_HEALTH, DEFAULT_ITEMS, MAX_LIVES, MAX_BLANKS); // finish a game, so "delete" the saving files
}

//player vs computer
void pve()
{
    string name;
    cout << "Enter player's Name: ";
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    Player p1(name, DEFAULT_HEALTH, false);

    name = "DEALER";
    Player dealer(name, DEFAULT_HEALTH, true);

    p1.saveToFile(player1_filename);
    dealer.saveToFile(player2_filename);
    cout << endl;

    game(p1, dealer);
}

// player vs player
void pvp()
{
    string name;
    cout << "Enter player1's Name: ";
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    Player p1(name, DEFAULT_HEALTH, false);

    cout << "Enter player2's Name: ";
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    Player p2(name, DEFAULT_HEALTH, false);

    p1.saveToFile(player1_filename);
    p2.saveToFile(player2_filename);
    cout << endl;

    game(p1, p2);
}

void run_game()
{
    srand(time(NULL));
    while (true)
    {
        if (endflag)
        {
            sleep(1);
            cout << "See you!" << endl;
            sleep(1);
            return;
        }
        sleep(2);
        int temp = initial_interface(DEFAULT_HEALTH, DEFAULT_ITEMS, MAX_LIVES, MAX_BLANKS);

        // quit the game
        if (temp == 4)
        {

            cout << "See you!" << endl;
            sleep(1);
            return;
        }
        else
            // start a new game and choose the mode.
            if (temp == 1)
            {
                temp = newgame_interface();
                save(false, 0, (rand() % 2), DEFAULT_HEALTH, DEFAULT_ITEMS, MAX_LIVES, MAX_BLANKS);
                if (temp == 1)
                    pve();
                else
                    pvp();
            }
            else
                // resume a game
                if (temp == 2)
                {
                    int temp_a;
                    bool temp_b;
                    load(stopflag, temp_a, temp_b, DEFAULT_HEALTH, DEFAULT_ITEMS, MAX_LIVES, MAX_BLANKS);
                    if (!stopflag)
                    {
                        sleep(1);
                        cout << "No previous game exists!" << endl;
                        continue;
                    }
                    Player p1("name", 0, false), p2("name", 0, false);
                    p1.loadFromFile(player1_filename);
                    p2.loadFromFile(player2_filename);
                    game(p1, p2);
                }
    }
}
