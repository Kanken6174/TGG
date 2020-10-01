#include "tgg.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <dirent.h>
#ifndef WIN32
    #include <sys/types.h>
#endif

#define true 1

#define false 0




// En-dessous, c'est des lignes de code quasi-inutiles pour contrôler le terminal.
void dterm(int*tw0, int*th0)
{

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    *tw0=columns;
    *th0=rows;
}

void adjustWindowSize()
{
    struct SMALL_RECT;

    HANDLE hStdout;
    COORD coord;
    BOOL ok;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = 100;
    coord.Y = 50;
    ok = SetConsoleScreenBufferSize(hStdout, coord);


} //end adjustWindowSize

void cls( HANDLE hConsole )
{
   COORD coordScreen = { 0, 0 };    // home for the cursor
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   DWORD dwConSize;

// Get the number of character cells in the current buffer.

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

   // Fill the entire screen with blanks.

   if( !FillConsoleOutputCharacter( hConsole,        // Handle to console screen buffer
                                    (TCHAR) ' ',     // Character to write to the buffer
                                    dwConSize,       // Number of cells to write
                                    coordScreen,     // Coordinates of first cell
                                    &cCharsWritten ))// Receive number of characters written
   {
      return;
   }

   // Get the current text attribute.

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   // Set the buffer's attributes accordingly.

   if( !FillConsoleOutputAttribute( hConsole,         // Handle to console screen buffer
                                    csbi.wAttributes, // Character attributes to use
                                    dwConSize,        // Number of cells to set attribute
                                    coordScreen,      // Coordinates of first cell
                                    &cCharsWritten )) // Receive number of characters written
   {
      return;
   }

   // Put the cursor at its home coordinates.

   SetConsoleCursorPosition( hConsole, coordScreen );
}

//On arrive au code utile

int namesc(char* plname)
{

    printf("\t\t\t      Welcome player, please enter your name (15 max)");
    putchar('\n');
    printf("\t\t\t\t\t");
    fgets(plname,15,stdin);
    return(0);

}

void characterdatatest()
{
    struct Data
{
    char firstname[10];
    char familyname[10];
    char title[25];
    int level;
    int ID;
    int relation;

    int health;
    int basehealth;
    int mana;
    int basemana;
    int stamina;
    int basestamina;

    int strenght;
    int intelligence;
    int agility;
    int wisdom;
    int speech;

    int race;
    int blessing;
    int job;

    bool dead;
    bool poisonned;
    bool sleeping;
    bool male;
    bool ennemy;
    bool follower;

};
struct Data data = {"Kanken", "Russel", "HARBRINGER OF BUGS", 999, 6174, 69, 99999, 99999, 9999, 9999, 999, 999, 100, 100, 100, 0, 100, 99, 0, 99, 0, 0, 0, 1, 0, 0};
FILE* output;
system("MD DATASHEETS\\CHARACTER_DATASHEETS");
DIR* dir = opendir("./DATASHEETS/CHARACTER_DATASHEETS");
if (dir)
{
        /* Directory exists. Do stuff. */
        output = fopen("./DATASHEETS/CHARACTER_DATASHEETS/last.dat", "ra");
            fwrite(&data, sizeof(data), 1, output);

    if (output == NULL) {
        perror("Failed: ");

    }


    closedir(dir);
}
if(errno == "ENOTDIR")
{
    puts("Kanken : Wow... je sais pas trop ce qu'il s'est passé, j'ai essayé d'avoir acces a un dossier mais a la place j'ai eu un fichier... °-°");
}


fclose(output);
}

void ZAWARUDOinit(char poulet)
{
        int maxseed=100;
        char answer='n';
    if (poulet == 'n')
    {


        puts("Veuillez choisir un nombre d'arret pour la creation de personnages (100-99999) [obviously 99K prendra des plombes et sera hyper lent]");
        scanf("%d%*c", &maxseed);
        printf("Seed d'arret choisie: %d, est-ce correct? (y/n)", maxseed);
        scanf("%c%*c", &answer);


        puts("Debut de l'initialisation du monde...");
        int x;
        char name[15];
        for(x=1; x<=maxseed; x++)
        {
            name=pullrandom();

            StructA_t x
            x.firstname = name;
            x.familyname = pullrandom();
            x.title = "A random title";
            x.level = 1;
            x.id = x;
            x.relation = 0;
            x.hp = 100;
            x.bhp = 100;
            x.mana = 1;
            x.bmana = 1;
            x.stamina = 10;
            x.bstamina = 10;
            x.str = 0;
            x.intel = 0;
            x.wise = 0;
            x.speech = 0;
            x.race = 1;
            x.bless = 0;
            x.job = 0;
        }
        }

   // else
       // load();
}

void pullrandom()
{
char **reservoir_sample(const char *filename, int count) {
    FILE *file;
    char **lines;
    char buf[21986];
    int i, n;

    file = fopen(filename, "r");
    lines = calloc(count, sizeof(char *));
    for (n = 1; fgets(buf, 400, file); n++) {
        if (n <= count) {
            lines[n - 1] = strdup(buf);
        } else {
            i = random() % n;
            if (i < count) {
                free(lines[i]);
                lines[i] = strdup(buf);
            }
        }
    }
    fclose(file);

    return lines;
}
}














