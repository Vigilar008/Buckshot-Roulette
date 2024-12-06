#include <iostream>
#include <string>
#include "display.h"

using namespace std;

// display string with art characters
void art_showmaker(string sentence)
{

    struct art_rec
    {
        string art1;
        string art2;
        string art3;
        string art4;
        string art5;
        string art6;
    };

    art_rec letter[36];
    letter[0].art1 = "█████╗  ";
    letter[0].art2 = "██╔══██╗";
    letter[0].art3 = "███████║";
    letter[0].art4 = "██╔══██║";
    letter[0].art5 = "██║  ██║";
    letter[0].art6 = "╚═╝  ╚═╝";
    letter[1].art1 = "██████╗ ";
    letter[1].art2 = "██╔══██╗";
    letter[1].art3 = "██████╔╝";
    letter[1].art4 = "██╔══██╗";
    letter[1].art5 = "██████╔╝";
    letter[1].art6 = "╚═════╝ ";
    letter[2].art1 = "███████╗";
    letter[2].art2 = "██╔════╝";
    letter[2].art3 = "██║     ";
    letter[2].art4 = "██║     ";
    letter[2].art5 = "╚██████╗";
    letter[2].art6 = " ╚═════╝";
    letter[3].art1 = "██████╗ ";
    letter[3].art2 = "██╔══██╗";
    letter[3].art3 = "██║  ██║";
    letter[3].art4 = "██║  ██║";
    letter[3].art5 = "██████╔╝";
    letter[3].art6 = "╚═════╝ ";
    letter[4].art1 = "███████╗";
    letter[4].art2 = "██╔════╝";
    letter[4].art3 = "█████╗  ";
    letter[4].art4 = "██╔══╝  ";
    letter[4].art5 = "███████╗";
    letter[4].art6 = "╚══════╝";
    letter[5].art1 = "███████╗";
    letter[5].art2 = "██╔════╝";
    letter[5].art3 = "█████╗  ";
    letter[5].art4 = "██╔══╝  ";
    letter[5].art5 = "██║     ";
    letter[5].art6 = "╚═╝     ";
    letter[6].art1 = "███████╗ ";
    letter[6].art2 = "██╔════╝ ";
    letter[6].art3 = "██║  ███╗";
    letter[6].art4 = "██║   ██║";
    letter[6].art5 = "╚██████╔╝";
    letter[6].art6 = " ╚═════╝ ";
    letter[7].art1 = "██╗  ██╗";
    letter[7].art2 = "██║  ██║";
    letter[7].art3 = "███████║";
    letter[7].art4 = "██╔══██║";
    letter[7].art5 = "██║  ██║";
    letter[7].art6 = "╚═╝  ╚═╝";
    letter[8].art1 = " ██╗ ";
    letter[8].art2 = " ██║ ";
    letter[8].art3 = " ██║ ";
    letter[8].art4 = " ██║ ";
    letter[8].art5 = " ██║ ";
    letter[8].art6 = " ╚═╝ ";
    letter[9].art1 = "     ██╗";
    letter[9].art2 = "     ██║";
    letter[9].art3 = "     ██║";
    letter[9].art4 = "██   ██║";
    letter[9].art5 = "╚█████╔╝";
    letter[9].art6 = " ╚════╝ ";
    letter[10].art1 = "██╗  ██╗";
    letter[10].art2 = "██║ ██╔╝";
    letter[10].art3 = "█████╔╝ ";
    letter[10].art4 = "██╔═██╗ ";
    letter[10].art5 = "██║  ██╗";
    letter[10].art6 = "╚═╝  ╚═╝";
    letter[11].art1 = "██╗     ";
    letter[11].art2 = "██║     ";
    letter[11].art3 = "██║     ";
    letter[11].art4 = "██║     ";
    letter[11].art5 = "███████╗";
    letter[11].art6 = "╚══════╝";
    letter[12].art1 = "███╗   ███╗";
    letter[12].art2 = "████╗ ████║";
    letter[12].art3 = "██╔████╔██║";
    letter[12].art4 = "██║╚██╔╝██║";
    letter[12].art5 = "██║ ╚═╝ ██║";
    letter[12].art6 = "╚═╝     ╚═╝";
    letter[13].art1 = "███╗   ██╗";
    letter[13].art2 = "████╗  ██║";
    letter[13].art3 = "██╔██╗ ██║";
    letter[13].art4 = "██║╚██╗██║";
    letter[13].art5 = "██║ ╚████║";
    letter[13].art6 = "╚═╝  ╚═══╝";
    letter[14].art1 = "█████╗  ";
    letter[14].art2 = "██╔══██╗";
    letter[14].art3 = "██║  ██║";
    letter[14].art4 = "██║  ██║";
    letter[14].art5 = "╚█████╔╝";
    letter[14].art6 = " ╚════╝ ";
    letter[15].art1 = "██████╗ ";
    letter[15].art2 = "██╔══██╗";
    letter[15].art3 = "██████╔╝";
    letter[15].art4 = "██╔═══╝ ";
    letter[15].art5 = "██║     ";
    letter[15].art6 = "╚═╝     ";
    letter[16].art1 = "██████╗  ";
    letter[16].art2 = "██╔══██╗ ";
    letter[16].art3 = "██║  ██║ ";
    letter[16].art4 = "██║▄▄ ██║";
    letter[16].art5 = "╚██████╔╝";
    letter[16].art6 = " ╚══▀▀═╝ ";
    letter[17].art1 = "██████╗ ";
    letter[17].art2 = "██╔══██╗";
    letter[17].art3 = "██████╔╝";
    letter[17].art4 = "██╔══██╗";
    letter[17].art5 = "██║  ██║";
    letter[17].art6 = "╚═╝  ╚═╝";
    letter[18].art1 = "███████╗";
    letter[18].art2 = "██╔════╝";
    letter[18].art3 = "███████╗";
    letter[18].art4 = "╚════██║";
    letter[18].art5 = "███████║";
    letter[18].art6 = "╚══════╝";
    letter[19].art1 = "████████╗";
    letter[19].art2 = "╚══██╔══╝";
    letter[19].art3 = "   ██║   ";
    letter[19].art4 = "   ██║   ";
    letter[19].art5 = "   ██║   ";
    letter[19].art6 = "   ╚═╝   ";
    letter[20].art1 = "██╗  ██╗";
    letter[20].art2 = "██║  ██║";
    letter[20].art3 = "██║  ██║";
    letter[20].art4 = "██║  ██║";
    letter[20].art5 = "╚█████╔╝";
    letter[20].art6 = "  ╚═══╝ ";
    letter[21].art1 = "██╗   ██╗";
    letter[21].art2 = "██║   ██║";
    letter[21].art3 = "██║   ██║";
    letter[21].art4 = "╚██╗ ██╔╝";
    letter[21].art5 = " ╚████╔╝ ";
    letter[21].art6 = "  ╚═══╝  ";
    letter[22].art1 = "██╗    ██╗";
    letter[22].art2 = "██║    ██║";
    letter[22].art3 = "██║ █╗ ██║";
    letter[22].art4 = "██║███╗██║";
    letter[22].art5 = "╚███╔███╔╝";
    letter[22].art6 = " ╚══╝╚══╝ ";
    letter[23].art1 = "██╗  ██╗";
    letter[23].art2 = "╚██╗██╔╝";
    letter[23].art3 = " ╚███╔╝ ";
    letter[23].art4 = " ██╔██╗ ";
    letter[23].art5 = "██╔╝ ██╗";
    letter[23].art6 = "╚═╝  ╚═╝";
    letter[24].art1 = "██╗   ██╗";
    letter[24].art2 = "╚██╗ ██╔╝";
    letter[24].art3 = " ╚████╔╝ ";
    letter[24].art4 = "  ╚██╔╝  ";
    letter[24].art5 = "   ██║   ";
    letter[24].art6 = "   ╚═╝   ";
    letter[25].art1 = "███████╗";
    letter[25].art2 = "╚══███╔╝";
    letter[25].art3 = "  ███╔╝ ";
    letter[25].art4 = " ███╔╝  ";
    letter[25].art5 = "███████╗";
    letter[25].art6 = "╚══════╝";
    letter[26].art1 = " ██████╗ ";
    letter[26].art2 = "██╔═████╗";
    letter[26].art3 = "██║██╔██║";
    letter[26].art4 = "████╔╝██║";
    letter[26].art5 = "╚██████╔╝";
    letter[26].art6 = " ╚═════╝ ";
    letter[27].art1 = "  ██╗ ";
    letter[27].art2 = " ███║ ";
    letter[27].art3 = " ╚██║ ";
    letter[27].art4 = "  ██║ ";
    letter[27].art5 = "  ██║ ";
    letter[27].art6 = "  ╚═╝ ";
    letter[28].art1 = " ██████╗ ";
    letter[28].art2 = " ╚════██╗";
    letter[28].art3 = "  █████╔╝";
    letter[28].art4 = " ██╔═══╝ ";
    letter[28].art5 = "███████╗ ";
    letter[28].art6 = "╚══════╝ ";
    letter[29].art1 = "██████╗  ";
    letter[29].art2 = "╚════██╗ ";
    letter[29].art3 = "  █████╔╝";
    letter[29].art4 = "  ╚═══██╗";
    letter[29].art5 = "██████╔╝ ";
    letter[29].art6 = "╚═════╝  ";
    letter[30].art1 = "██╗  ██╗";
    letter[30].art2 = "██║  ██║";
    letter[30].art3 = "███████║";
    letter[30].art4 = "╚════██║";
    letter[30].art5 = "     ██║";
    letter[30].art6 = "     ╚═╝";
    letter[31].art1 = "███████╗ ";
    letter[31].art2 = "██╔════╝ ";
    letter[31].art3 = "███████╗ ";
    letter[31].art4 = "╚════██║ ";
    letter[31].art5 = "███████║ ";
    letter[31].art6 = "╚══════╝ ";
    letter[32].art1 = " ██████╗ ";
    letter[32].art2 = "██╔════╝ ";
    letter[32].art3 = "███████╗ ";
    letter[32].art4 = "██╔═══██╗";
    letter[32].art5 = "╚██████╔╝";
    letter[32].art6 = " ╚═════╝ ";
    letter[33].art1 = "███████╗";
    letter[33].art2 = "╚════██║";
    letter[33].art3 = "    ██╔╝";
    letter[33].art4 = "   ██╔╝ ";
    letter[33].art5 = "   ██║  ";
    letter[33].art6 = "   ╚═╝  ";
    letter[34].art1 = " █████╗ ";
    letter[34].art2 = "██╔══██╗";
    letter[34].art3 = "╚█████╔╝";
    letter[34].art4 = "██╔══██╗";
    letter[34].art5 = "╚█████╔╝";
    letter[34].art6 = " ╚════╝ ";
    letter[35].art1 = " █████╗ ";
    letter[35].art2 = "██╔══██╗";
    letter[35].art3 = "╚██████║";
    letter[35].art4 = " ╚═══██║";
    letter[35].art5 = " █████╔╝";
    letter[35].art6 = " ╚════╝ ";

    int num = sentence.size();

    for (int j = 0; j < num; j++)
    {
        if (sentence[j] >= 'A' && sentence[j] <= 'Z')
        {
            int temp = sentence[j] - 'A';
            cout << letter[temp].art1;
        }
        if (sentence[j] >= '0' && sentence[j] <= '9')
        {
            int digit = sentence[j] - '0' + 26;
            cout << letter[digit].art1;
        }
        if (sentence[j] == ' ')
        {
            cout << "     ";
        }
        if (j < num - 1)
        {
            cout << " ";
        }
        if (j == num - 1)
        {
            cout << endl;
        }
    }
    for (int j = 0; j < num; j++)
    {
        if (sentence[j] >= 'A' && sentence[j] <= 'Z')
        {
            int temp = sentence[j] - 'A';
            cout << letter[temp].art2;
        }
        if (sentence[j] >= '0' && sentence[j] <= '9')
        {
            int digit = sentence[j] - '0' + 26;
            cout << letter[digit].art2;
        }
        if (sentence[j] == ' ')
        {
            cout << "     ";
        }
        if (j < num - 1)
        {
            cout << " ";
        }
        if (j == num - 1)
        {
            cout << endl;
        }
    }

    for (int j = 0; j < num; j++)
    {
        if (sentence[j] >= 'A' && sentence[j] <= 'Z')
        {
            int temp = sentence[j] - 'A';
            cout << letter[temp].art3;
        }
        if (sentence[j] >= '0' && sentence[j] <= '9')
        {
            int digit = sentence[j] - '0' + 26;
            cout << letter[digit].art3;
        }
        if (sentence[j] == ' ')
        {
            cout << "     ";
        }
        if (j < num - 1)
        {
            cout << " ";
        }
        if (j == num - 1)
        {
            cout << endl;
        }
    }

    for (int j = 0; j < num; j++)
    {
        if (sentence[j] >= 'A' && sentence[j] <= 'Z')
        {
            int temp = sentence[j] - 'A';
            cout << letter[temp].art4;
        }
        if (sentence[j] >= '0' && sentence[j] <= '9')
        {
            int digit = sentence[j] - '0' + 26;
            cout << letter[digit].art4;
        }
        if (sentence[j] == ' ')
        {
            cout << "     ";
        }
        if (j < num - 1)
        {
            cout << " ";
        }
        if (j == num - 1)
        {
            cout << endl;
        }
    }
    for (int j = 0; j < num; j++)
    {
        if (sentence[j] >= 'A' && sentence[j] <= 'Z')
        {
            int temp = sentence[j] - 'A';
            cout << letter[temp].art5;
        }
        if (sentence[j] >= '0' && sentence[j] <= '9')
        {
            int digit = sentence[j] - '0' + 26;
            cout << letter[digit].art5;
        }
        if (sentence[j] == ' ')
        {
            cout << "     ";
        }
        if (j < num - 1)
        {
            cout << " ";
        }
        if (j == num - 1)
        {
            cout << endl;
        }
    }

    for (int j = 0; j < num; j++)
    {
        if (sentence[j] >= 'A' && sentence[j] <= 'Z')
        {
            int temp = sentence[j] - 'A';
            cout << letter[temp].art6;
        }
        if (sentence[j] >= '0' && sentence[j] <= '9')
        {
            int digit = sentence[j] - '0' + 26;
            cout << letter[digit].art6;
        }
        if (sentence[j] == ' ')
        {
            cout << "     ";
        }
        if (j < num - 1)
        {
            cout << " ";
        }
        if (j == num - 1)
        {
            cout << endl;
        }
    }
}

// display welcome interface
void welcome()
{
    cout << endl;
    cout << "██╗    ██╗" << "███████╗" << "██╗     " << "███████╗" << "█████╗  " << "███╗   ███╗" << "███████╗" << endl;
    cout << "██║    ██║" << "██╔════╝" << "██║     " << "██╔════╝" << "██╔══██╗" << "████╗ ████║" << "██╔════╝" << endl;
    cout << "██║ █╗ ██║" << "█████╗  " << "██║     " << "██║     " << "██║  ██║" << "██╔████╔██║" << "█████╗  " << endl;
    cout << "██║███╗██║" << "██╔══╝  " << "██║     " << "██║     " << "██║  ██║" << "██║╚██╔╝██║" << "██╔══╝  " << endl;
    cout << "╚███╔███╔╝" << "███████╗" << "███████╗" << "╚██████╗" << "╚█████╔╝" << "██║ ╚═╝ ██║" << "███████╗" << endl;
    cout << " ╚══╝╚══╝ " << "╚══════╝" << "╚══════╝" << " ╚═════╝" << " ╚════╝ " << "╚═╝     ╚═╝" << "╚══════╝" << endl;
    cout << " " << endl;
    cout << "                     ████████╗" << "█████╗  " << endl;
    cout << "                     ╚══██╔══╝" << "██╔══██╗" << endl;
    cout << "                        ██║   " << "██║  ██║" << endl;
    cout << "                        ██║   " << "██║  ██║" << endl;
    cout << "                        ██║   " << "╚█████╔╝" << endl;
    cout << "                        ╚═╝   " << " ╚════╝ " << endl;
    cout << " " << endl;
    cout << "██████╗ " << "██╗  ██╗" << "███████╗" << "██╗  ██╗" << "███████╗" << "██╗  ██╗" << "█████╗  " << "████████╗" << endl;
    cout << "██╔══██╗" << "██║  ██║" << "██╔════╝" << "██║ ██╔╝" << "██╔════╝" << "██║  ██║" << "██╔══██╗" << "╚══██╔══╝" << endl;
    cout << "██████╔╝" << "██║  ██║" << "██║     " << "█████╔╝ " << "███████╗" << "███████║" << "██║  ██║" << "   ██║   " << endl;
    cout << "██╔══██╗" << "██║  ██║" << "██║     " << "██╔═██╗ " << "╚════██║" << "██╔══██║" << "██║  ██║" << "   ██║   " << endl;
    cout << "██████╔╝" << "╚█████╔╝" << "╚██████╗" << "██║  ██╗" << "███████║" << "██║  ██║" << "╚█████╔╝" << "   ██║   " << endl;
    cout << "╚═════╝ " << " ╚════╝ " << " ╚═════╝" << "╚═╝  ╚═╝" << "╚══════╝" << "╚═╝  ╚═╝" << " ╚════╝ " << "   ╚═╝   " << endl;
    cout << " " << endl;
    cout << "██████╗ " << "█████╗  " << "██╗  ██╗" << "██╗     " << "███████╗" << "████████╗" << "████████╗" << "███████╗" << endl;
    cout << "██╔══██╗" << "██╔══██╗" << "██║  ██║" << "██║     " << "██╔════╝" << "╚══██╔══╝" << "╚══██╔══╝" << "██╔════╝" << endl;
    cout << "██████╔╝" << "██║  ██║" << "██║  ██║" << "██║     " << "█████╗  " << "   ██║   " << "   ██║   " << "█████╗  " << endl;
    cout << "██╔══██╗" << "██║  ██║" << "██║  ██║" << "██║     " << "██╔══╝  " << "   ██║   " << "   ██║   " << "██╔══╝  " << endl;
    cout << "██║  ██║" << "╚█████╔╝" << "╚█████╔╝" << "███████╗" << "███████╗" << "   ██║   " << "   ██║   " << "███████╗" << endl;
    cout << "╚═╝  ╚═╝" << " ╚════╝ " << " ╚════╝ " << "╚══════╝" << "╚══════╝" << "   ╚═╝   " << "   ╚═╝   " << "╚══════╝" << endl;
    cout << endl;
}

//display instructions
void displayHelp()
{
    cout << "\n+===============================================================+\n"
         << endl;
    cout << "INSTRUCTIONS:" << endl;
    cout << "    - OBJECTIVE: SURVIVE." << endl;
    cout << "    - A shotgun is loaded with a disclosed number of bullets, some of which will be blanks." << endl;
    cout << "    - Participants are given a set amount of lives (default = 4) to survive." << endl;
    cout << "    - Participants will take turns shooting." << endl;
    cout << "    - Aim at the enemy or at yourself - shooting yourself with a blank skips the enemy's turn." << endl;
    cout << "    - Participants are given items to help out. Use them wisely." << endl;
    cout << "\n"
         << endl;
    cout << "ITEMS:" << endl;
    cout << "    • CIGARETTE = Gives the user an extra life." << endl;
    cout << "    • BEER = Racks the shotgun and the bullet inside will be discarded." << endl;
    cout << "    • SAW = Shotgun will deal double damage for one turn." << endl;
    cout << "    • MAGNIFIER = User will see what bullet is in the chamber." << endl;
    cout << "    • HANDCUFFS = Handcuffs the other person so they miss their next turn." << endl;
    cout << "\nGood Luck.\n"
         << endl;
    cout << "+===============================================================+" << endl;
    cout << endl;
    return;
}

// display gun and bullets
void displayBullet(int usefull, int useless)
{
    string s1 = " ,______________________________________";
    string s2 = "|_________________,----------._ [____]  \"\"-,__  __....-----=====";
    string s3 = "              (_(||||||||||||)___________/   \"\"                 |";
    string s4 = "                  `----------' #$$$$$$[ ))\"-,                   |";
    string s5 = "                                       \"\"    `,  _,--....___    |";
    string s6 = "                                               `/           \"\"\"\"";
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;

    const int total = usefull + useless;

    struct bullet_rec
    {
        string b1;
        string b2;
        string b3;
        string b4;
        string b5;
    };
    bullet_rec bullet[20];

    for (int i = 0; i < total; i++)
    {
        int temp;
        if (usefull > 0)
        {
            temp = 1;
        }
        else
        {
            temp = 0;
        }
        if (temp == 1)
        {
            bullet[i].b1 = " __ ";
            bullet[i].b2 = "|##|";
            bullet[i].b3 = "|##|";
            bullet[i].b4 = "|##|";
            bullet[i].b5 = "****";
            usefull -= 1;
        }
        if (temp == 0)
        {
            bullet[i].b1 = " __ ";
            bullet[i].b2 = "|  |";
            bullet[i].b3 = "|  |";
            bullet[i].b4 = "|  |";
            bullet[i].b5 = "****";
            usefull -= 1;
        }
    }

    for (int i = 0; i < total; i++)
    {
        cout << bullet[i].b1;
        if (i == total - 1)
        {
            cout << endl;
        }
        else
        {
            cout << "  ";
        }
    }

    for (int i = 0; i < total; i++)
    {
        cout << bullet[i].b2;
        if (i == total - 1)
        {
            cout << endl;
        }
        else
        {
            cout << "  ";
        }
    }
    for (int i = 0; i < total; i++)
    {
        cout << bullet[i].b3;
        if (i == total - 1)
        {
            cout << endl;
        }
        else
        {
            cout << "  ";
        }
    }
    for (int i = 0; i < total; i++)
    {
        cout << bullet[i].b4;
        if (i == total - 1)
        {
            cout << endl;
        }
        else
        {
            cout << "  ";
        }
    }
    for (int i = 0; i < total; i++)
    {
        cout << bullet[i].b5;
        if (i == total - 1)
        {
            cout << endl;
        }
        else
        {
            cout << "  ";
        }
    }
}
